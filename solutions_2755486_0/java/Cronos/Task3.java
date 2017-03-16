package codejam.y2013.r1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task3 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    static class Attack implements Comparable<Attack> {
        int d;
        int w;
        int e;
        int s;

        Attack(int d, int w, int e, int s) {
            this.d = d;
            this.w = w;
            this.e = e;
            this.s = s;
        }

        public int compareTo(Attack o) {
            return d - o.d;
        }
    }

    static class Wall implements Comparable<Wall> {
        int w;
        int e;

        Wall(int w, int e) {
            this.w = w;
            this.e = e;
        }

        public int compareTo(Wall o) {
            return w - o.w;
        }
    }

    public static String getResult() {
        int N = input.nextInt();
        int[] d = new int[N];
        int[] n = new int[N];
        int[] w = new int[N];
        int[] e = new int[N];
        int[] s = new int[N];
        int[] delta_d = new int[N];
        int[] delta_p = new int[N];
        int[] delta_s = new int[N];
        for (int i = 0; i < N; i++) {
            d[i] = input.nextInt();
            n[i] = input.nextInt();
            w[i] = input.nextInt();
            e[i] = input.nextInt();
            s[i] = input.nextInt();
            delta_d[i] = input.nextInt();
            delta_p[i] = input.nextInt();
            delta_s[i] = input.nextInt();
        }

        List<Attack> attacks = new ArrayList<Attack>(100);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < n[i]; j++) {
                attacks.add(new Attack(d[i] + j * delta_d[i], w[i] + j * delta_p[i], e[i] + j * delta_p[i], s[i] + j * delta_s[i]));
            }
        }
        Collections.sort(attacks);

        long res = 0;
        o:
        for (int i = 0; i < attacks.size(); i++) {
            Attack attack = attacks.get(i);
            List<Wall> walls = new ArrayList<Wall>(i);
            for (int j = 0; j < i; j++) {
                Attack attack2 = attacks.get(j);
                if (attack2.d >= attack.d) continue;
                if (attack2.s >= attack.s) walls.add(new Wall(attack2.w, attack2.e));
            }
            Collections.sort(walls);
            int he = attack.w;
            for (int j = 0; j < walls.size(); j++) {
                Wall wall = walls.get(j);
                if (wall.w > he) {
                    res++;
                    continue o;
                }
                he = Math.max(he, wall.e);
                if (he >= attack.e) continue o;
            }
            if (he < attack.e) res++;
        }

        return "" + res;
    }
}
