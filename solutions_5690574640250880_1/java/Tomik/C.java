/*
 * Copyright (c) 2009-2014, Inmite s.r.o. (www.inmite.eu). All rights reserved.
 *
 * This source code can be used only for purposes specified by the given license contract
 * signed by the rightful deputy of Inmite s.r.o. This source code can be used only
 * by the owner of the license.
 *
 * Any disputes arising in respect of this agreement (license) shall be brought
 * before the Municipal Court of Prague.
 */

package qualification;

import java.util.*;

/**
 * Created by tomas on 12.04.14.
 */
public class C {

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();

            boolean inv = false;
            if (R > C) {
                inv = true;
                int tmp = R;
                R = C;
                C = tmp;
            }
            boolean possible = true;

            char[][] a = new char[R][C];
            for (int j = 0; j < a.length; j++) {
                Arrays.fill(a[j], '*');
            }

            int empty = R*C - M;

            if (M == 0) {
                for (int j = 0; j < a.length; j++) {
                    Arrays.fill(a[j], '.');
                }
                a[0][0] = 'c';
            } else if (empty == 1) {
                a[0][0] = 'c';
            } else {

                if (R == 1) {
                    a[0][0] = 'c';
                    for (int j = 1; j < C - M; j++) {
                        a[0][j] = '.';
                    }
                } else if (R == 2) {
                    if (empty > 2 && empty%2 == 0) {
                        for (int j = 0; j < empty/2; j++) {
                            a[0][j] = a[1][j] = '.';
                        }
                        a[0][0] = 'c';
                    } else {
                        possible = false;
                    }
                } else {
                    if (empty < 4) {
                        possible = false;
                    } else {
                        possible = fill(a, empty);
                    }
                }
            }


            if (inv) {
                a = transpose(a);
            }

            System.out.println("Case #" + i + ":");
            if (!possible) {
                System.out.println("Impossible");
            } else {
                for (int j = 0; j < a.length; j++) {
                    for (int k = 0; k < a[j].length; k++) {
                        System.out.print(a[j][k]);
                    }
                    System.out.println();
                }
            }
        }
    }

    static final int[][] movesOpen = {{1,0}, {0,1}, {1,1}};

    static boolean fill(char[][] a, int empty) {
        a[0][0] = 'c';
        a[0][1] = a[1][0] = a[1][1] = '.';
        empty -= 4;

        if (empty == 0) {
            return true;
        }

        LinkedList<P> stack = new LinkedList<P>();
        stack.addLast(new P(0, 1, empty, a));
        stack.addLast(new P(1, 0, empty, a));

        boolean[][] seen = new boolean[a.length][a[0].length];
        seen[0][0] = seen[0][1] = seen[1][0] = true;

        o:
        while (!stack.isEmpty()) {
            P act = stack.removeLast();
            if (act.empty == 1) {
                if (act.x == 0 || act.y == 0) {
                    continue o;
                }
            }

//            print(act);

            int ty = (act.y + 1 < a.length) ? ty = act.y + 1 : act.y;
            int tx = (act.x + 1 < a[0].length) ? tx = act.x + 1 : act.x;
            if (act.y + 1 < a.length) {
                for (int i = 0; i < act.x; i++) {
                    if (act.a[ty][i] != '.') {
                        continue o;
                    }
                }
            }
            if (act.x + 1 < a[0].length) {
                for (int i = 0; i < act.y; i++) {
                    if (act.a[i][tx] != '.') {
                        continue o;
                    }
                }
            }

            int nempty = act.empty;
            for (int i = 0; i < movesOpen.length; i++) {
                int ny = act.y + movesOpen[i][0];
                int nx = act.x + movesOpen[i][1];
                if (ny < a.length && nx < a[0].length) {
                    if (act.a[ny][nx] != '.') {
                        act.a[ny][nx] = '.';
                        nempty -= 1;
                    }
                }
            }

            if (nempty < 0) {
                continue o;
            }

            if (nempty == 0) {
                for (int i = 0; i < a.length; i++) {
                    for (int j = 0; j < a[0].length; j++) {
                        a[i][j] = act.a[i][j];
                    }
                }
                return true;
            }


            if (act.y + 2 < a.length) {
                if (act.a[act.y+2][1] != '.') {
                    stack.addLast(new P(act.y + 1, 0, nempty, act.a));
                } else {
                    int lx = 1;
                    for (int i = lx+1; i <= act.x; i++) {
                        if (act.a[act.y+2][i] == '.') {
                            lx = i;
                        }
                    }
                    stack.addLast(new P(act.y + 1, lx, nempty, act.a));
                }
            }
            if (act.x + 2 < a[0].length) {
                if (act.a[1][act.x+2] != '.') {
                    stack.addLast(new P(0, act.x + 1, nempty, act.a));
                } else {
                    int ly = 1;
                    for (int i = ly+1; i <= act.y; i++) {
                        if (act.a[i][act.x+2] == '.') {
                            ly = i;
                        }
                    }
                    stack.addLast(new P(ly, act.x + 1, nempty, act.a));
                }
            }
        }

        return false;
    }

    static class P {
        public int y;
        public int x;
        public int empty;
        public char[][] a;

        P(int y, int x, int empty, char[][] a) {
            this.y = y;
            this.x = x;
            this.empty = empty;
            this.a = new char[a.length][a[0].length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    this.a[i][j] = a[i][j];
                }
            }
        }
    }

    static char[][] transpose(char[][] a) {
        char[][] b = new char[a[0].length][a.length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                b[j][i] = a[i][j];
            }
        }
        return b;
    }

    static void print(P p) {
        System.out.println("empty: " + p.empty);
        for (int i = 0; i < p.a.length; i++) {
            for (int j = 0; j < p.a[0].length; j++) {
                if (i == p.y && j == p.x) {
                    System.out.print('#');
                } else {
                    System.out.print(p.a[i][j]);
                }
            }
            System.out.println();
        }
    }
}
