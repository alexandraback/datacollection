package c2014_c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Z3_5 {

    public static List<Set<Integer>> subsets(int n, int min, int max) {
        if (n == 0) {
            return new ArrayList<Set<Integer>>();
        }
        if (min > max) {
            return new ArrayList<Set<Integer>>();
        }
        List<Set<Integer>> l = new ArrayList<Set<Integer>>();
        List<Set<Integer>> sts = subsets(n - 1, min + 1, max);
        for (Set<Integer> st : sts) {
            st.add(min);
        }
        l.addAll(sts);
        l.addAll(subsets(n, min + 1, max));
        if (n == 1) {
            Set<Integer> s = new HashSet<Integer>();
            s.add(min);
            l.add(s);
        }
        return l;
    }

    public static void main(String[] args) throws Exception {
        //List<Set<Integer>> sts = subsets(13, 1, 25);
        //System.out.println(sts.size());
        //System.out.println(sts);
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\2014\\z3.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-large.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        /*for (int r = 1; r < 50; r++) {
            System.out.println(r);
            for (int c = 1; c < 50; c++) {
                for (int m = 1; m < r * c - 1; m++) {
                    test_rcm(out, 0, r, c, m, false);
                }
            }
        }*/
        for (int ti = 1; ti <= tn; ti++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int m = scanner.nextInt();
            test_rcm(out, ti, r, c, m, true);
        }
        out.close();
    }

    private static void test_rcm(BufferedWriter out, int ti, int r, int c, int m, boolean show) throws IOException {
        String s;
        s = "Case #" + ti + ": ";
        int[][] map = new int[r][c];
        if (show) {
            System.out.println(s + " " + r + " " + c + " " + m);
            out.write(s);
            out.write("\n");
        }
        boolean flag = false;
        if (m == r * c - 1) {
            for (int i = 0; i < r - 1; i++) {
                for (int j = 0; j < c; j++) {
                    map[i][j] = 1;
                }
            }
            for (int j = 0; j < c - 1; j++) {
                map[r - 1][j] = 1;
            }
            map[r - 1][c - 1] = 2;
        } else if (c == 1) {
            for (int i = 0; i < m; i++) {
                map[i][0] = 1;
            }
            map[m][0] = 0;
            map[m + 1][0] = 2;
            for (int i = m + 2; i < r - 1; i++) {
                map[i][0] = 0;
            }
        } else if (r == 1) {
            for (int i = 0; i < m; i++) {
                map[0][i] = 1;
            }
            map[0][m] = 0;
            map[0][m + 1] = 2;
            for (int i = m + 2; i < c - 1; i++) {
                map[0][i] = 0;
            }
        } else if ((r * c - m < 4) || (r * c - m == 5) || (r * c - m == 7)) {
            flag = true;
            if (show) {
                s = "Impossible\n";
                System.out.println();
                out.write(s);
            }
        } else if (((r * c - m) % 2 == 1) && ((r == 2) || (c == 2))) {
            flag = true;
            if (show) {
                s = "Impossible\n";
                System.out.println();
                out.write(s);
            }
        } else if (r * c - m == 9) {
            if ((r < 3) || (c < 3)) {
                flag = true;
                if (show) {
                    s = "Impossible\n";
                    System.out.println();
                    out.write(s);
                }
            } else {
                for (int i = 0; i < r; i++) {
                    if (i < r - 3) {
                        for (int j = 0; j < c; j++) {
                            map[i][j] = 1;
                        }
                    } else if (i < r - 1) {
                        for (int j = 0; j < c; j++) {
                            if (j < c - 3) {
                                map[i][j] = 1;
                            } else {
                                map[i][j] = 0;
                            }
                        }
                    } else if (i == r - 1) {
                        for (int j = 0; j < c; j++) {
                            if (j < c - 3) {
                                map[r - 1][j] = 1;
                            } else {
                                if (j == c - 1) {
                                    map[r - 1][j] = 2;
                                } else {
                                    map[r - 1][j] = 0;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            boolean reverse = r < c;
            map[r-1][c-1] = 2;
            int fc = r;
            int sc = c;
            if (reverse) {
                fc = c;
                sc = r;
            }
            if (m % sc == sc - 1 && m < sc * (fc - 2)) {
                int n = m / sc;
                int k = 0;
                int lx = -1;
                int ly = -1;
                for (int i = 0; i < fc; i++) {
                    for (int j = 0; j < sc; j++) {
                        if (k < m - 1) {
                            k++;
                            set(map, i, j, reverse, 1);
                            lx = i;
                            ly = j;
                        }
                    }
                }
                set(map, lx + 1, 0, reverse, 1);
                if (lx + 1 == fc - 2) {
                    set(map, lx + 2, 0, reverse, 1);
                    set(map, lx, ly, reverse, 0);
                }
            } else {
                int k = 0;
                int d = m - (fc - 2) * sc;
                if (d % 2 == 0 || d<0) {
                    for (int i = 0; i < fc - 2; i++) {
                        for (int j = 0; j < sc; j++) {
                            if (k < m) {
                                k++;
                                set(map, i, j, reverse, 1);
                            }
                        }
                    }
                    for (int j = 0; j < sc; j++) {
                        if (k < m && j < d / 2) {
                            k++;
                            set(map, fc - 2, j, reverse, 1);
                        }
                    }
                    for (int j = 0; j < sc; j++) {
                        if (k < m && j < d / 2) {
                            k++;
                            set(map, fc - 1, j, reverse, 1);
                        }
                    }
                } else {
                    d = m - (fc - 3) * sc;
                    for (int i = 0; i < fc - 3; i++) {
                        for (int j = 0; j < sc; j++) {
                            if (k < m) {
                                k++;
                                set(map, i, j, reverse, 1);
                            }
                        }
                    }
                    for (int j = 0; j < sc; j++) {
                        if (k < m && j < d / 3) {
                            k++;
                            set(map, fc - 3, j, reverse, 1);
                        }
                    }
                    for (int j = 0; j < sc; j++) {
                        if (k < m && j < d / 3) {
                            k++;
                            set(map, fc - 2, j, reverse, 1);
                        }
                    }
                    for (int j = 0; j < sc; j++) {
                        if (k < m && j < d / 3) {
                            k++;
                            set(map, fc - 1, j, reverse, 1);
                        }
                    }
                    int d3 = d/3;
                    if (k<m) {
                        set(map,fc-3,d3,reverse,1);
                        k++;
                    }
                    if (k<m) {
                        set(map,fc-3,d3+1,reverse,1);
                    }
                }
            }
        }
        if (!flag) {
            int[][] cnt = new int[r][c];
            int cc = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] == 1) {
                        cc++;
                    }
                    if (i > 0 && j > 0 && map[i - 1][j - 1] == 1) {
                        cnt[i][j]++;
                    }
                    if (i > 0 && map[i - 1][j] == 1) {
                        cnt[i][j]++;
                    }
                    if (i > 0 && j < c - 1 && map[i - 1][j + 1] == 1) {
                        cnt[i][j]++;
                    }
                    if (j > 0 && map[i][j - 1] == 1) {
                        cnt[i][j]++;
                    }
                    if (j < c - 1 && map[i][j + 1] == 1) {
                        cnt[i][j]++;
                    }
                    if (i < r - 1 && j > 0 && map[i + 1][j - 1] == 1) {
                        cnt[i][j]++;
                    }
                    if (i < r - 1 && map[i + 1][j] == 1) {
                        cnt[i][j]++;
                    }
                    if (i < r - 1 && j < c - 1 && map[i + 1][j + 1] == 1) {
                        cnt[i][j]++;
                    }
                }
            }
            if (show) {
                /*for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        s = String.valueOf(cnt[i][j]);
                        System.out.print(s);
                        out.write(s);
                    }
                    s = "\n";
                    System.out.print(s);
                    out.write(s);
                }*/
            }
            if (cc != m) {
                System.out.println("PIZDEZ" + r + " " + c + " " + m);
                show = true;
            }
            x:
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] != 1) {
                        if (cnt[i][j] > 0) {
                            int k = 0;
                            if (i > 0 && j > 0 && cnt[i - 1][j - 1] == 0) {
                                k++;
                            }
                            if (i > 0 && cnt[i - 1][j] == 0) {
                                k++;
                            }
                            if (i > 0 && j < c - 1 && cnt[i - 1][j + 1] == 0) {
                                k++;
                            }
                            if (j > 0 && cnt[i][j - 1] == 0) {
                                k++;
                            }
                            if (j < c - 1 && cnt[i][j + 1] == 0) {
                                k++;
                            }
                            if (i < r - 1 && j > 0 && cnt[i + 1][j - 1] == 0) {
                                k++;
                            }
                            if (i < r - 1 && cnt[i + 1][j] == 0) {
                                k++;
                            }
                            if (i < r - 1 && j < c - 1 && cnt[i + 1][j + 1] == 0) {
                                k++;
                            }
                            if (k == 0 && r * c != m + 1) {
                                System.out.println("ZHOPA" + r + " " + c + " " + m);
                                show = true;
                                break x;
                            }
                        }
                    }
                }
            }
            if (show) {
                printMap(out, r, c, map);
            }
        }
    }

    private static void set(int[][] map, int i, int j, boolean reverse, int v) {
        if (reverse) {
            map[j][i] = v;
        } else {
            map[i][j] = v;
        }
    }

    private static void printMap(BufferedWriter out, int r, int c, int[][] map) throws IOException {
        String s;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                s = map[i][j] == 1 ? "*" : (map[i][j] == 2 ? "c" : ".");
                System.out.print(s);
                out.write(s);
            }
            s = "\n";
            System.out.print(s);
            out.write(s);
        }
    }

}
