/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.text.*;

public class DeceitfulWar {

    static BufferedReader br;
    static Scanner sc;
    static PrintWriter out;

    public static void initA() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            sc = new Scanner(System.in);
            out = new PrintWriter(System.out);
        } catch (Exception e) {
        }
    }
public static void initB() {
        try {
            String in = "d:\\MT.in";
            String of = "d:\\out.txt";
            br = new BufferedReader(new FileReader(in));
            sc = new Scanner(new FileReader(in));
            out = new PrintWriter(of);
        } catch (Exception e) {
        }
    }
    public static Double[] getDouble() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Double temp2[] = new Double[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Double.parseDouble(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    static boolean next_permutation(Integer[] p) {
        for (int a = p.length - 2; a >= 0; --a) {
            if (p[a] < p[a + 1]) {
                for (int b = p.length - 1;; --b) {
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static String getString() {
        try {
            return br.readLine();
        } catch (Exception e) {
        }
        return "";
    }

    public static Integer getInt() {
        try {
            return Integer.parseInt(br.readLine());
        } catch (Exception e) {
        }
        return 0;
    }

    public static Integer[] getIntArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Integer temp2[] = new Integer[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Integer.parseInt(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static Long[] getLongArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            Long temp2[] = new Long[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = Long.parseLong(temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static String[] getStringArr() {
        try {
            StringTokenizer temp = new StringTokenizer(br.readLine());
            int n = temp.countTokens();
            String temp2[] = new String[n];
            for (int i = 0; i < n; i++) {
                temp2[i] = (temp.nextToken());
            }
            return temp2;
        } catch (Exception e) {
        }
        return null;
    }

    public static void print(Object a) {
        out.println(a);
    }

    public static void print(String s, Object... a) {
        out.printf(s, a);
    }

    public static int nextInt() {
        return sc.nextInt();
    }

    public static double nextDouble() {
        return sc.nextDouble();
    }

    public static void main(String[] ar) {
        initB();
        DeceitfulWar c = new DeceitfulWar();
        c.solve();
        out.flush();
    }

    void solve() {
        int tc = getInt();
        for (int kasus = 1; kasus <= tc; kasus++) {
            print("Case #%d: ", kasus);
            int n = getInt();
            Double[] naomi = getDouble();
            Double[] ken = getDouble();

            TreeSet<Double> pohon_ken = new TreeSet<Double>(Arrays.asList(ken));
            int a = 0;
            Arrays.sort(naomi);

            Arrays.sort(ken);

            for (int i = 0; i < n; i++) {
                double pilihan_naomi = naomi[i];
                Double temp = pohon_ken.ceiling(pilihan_naomi);
                if (temp == null) {
                    a++;
                } else {
                    pohon_ken.remove(temp);
                }
            }
            int b = 0;
            //print(Arrays.asList(naomi));
            //print(Arrays.asList(ken));
            int j = 0;
            for (int i = 0; i < n;i++) {
                double pilihan_ken = ken[i];
                for (; j < n; j++) {
                    double pilihan_naomi = naomi[j];
                    if (pilihan_naomi > pilihan_ken) {
                        //print("MENANG " + pilihan_ken + " " + pilihan_naomi);
                        b++;
                        j++;
                        break;
                    }
                }
            }
            print(b + " " + a);
        }
    }
}
