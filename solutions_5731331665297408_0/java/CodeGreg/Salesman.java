package salesman;

import deceitfulWar.DeceitfulWar;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Salesman {

    public static int N, M;
    public static City[] cities;
    public static List<List<Integer>> g;
    public static boolean[] DFSbool = new boolean[50];
    static int indTo[] = new int[50];
    static boolean[] chosen = new boolean[50];
    static boolean[] active = new boolean[50];
    static int[] chosenInd = new int[50];
    static int[] chosenTime = new int[50];

    public static void DFS(int s) {
//        System.out.println("DFS(" + s + " -> " + (cities[s].index + 1) + ")");
        for (Integer to : g.get(s))
            if (!chosen[to] && !DFSbool[to]) {
                DFSbool[to] = true;
                DFS(to);
            }
    }

    public static void printg() {
        for (int i = 0; i < N; ++i) {
            System.out.print((cities[i].index + 1) + ":");
            for (Integer j : g.get(i))
                System.out.print(" " + (cities[j].index + 1));
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(new BufferedReader(new FileReader("case2.in")));
            Writer w = new BufferedWriter(new FileWriter("case2.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t) {
                N = s.nextInt();
                M = s.nextInt();

                g = new ArrayList<>();
                for (int i = 0; i < N; ++i)
                    g.add(new ArrayList<Integer>());

                cities = new City[N];

                for (int i = 0; i < N; ++i)
                    cities[i] = new City(s.next(), i);

                Arrays.sort(cities);

                for (int i = 0; i < N; ++i)
                    indTo[cities[i].index] = i;

                for (int i = 0; i < M; ++i) {
                    int a = indTo[s.nextInt() - 1];
                    int b = indTo[s.nextInt() - 1];
                    g.get(a).add(b);
                    g.get(b).add(a);
                }

                for (int i = 0; i < N; ++i)
                    Collections.sort(g.get(i));

                for (int i = 0; i < N; ++i)
                    chosen[i] = false;
                for (int i = 0; i < N; ++i)
                    active[i] = false;

                int ccity = 0;

//                System.out.println("first: " + first);

                String code = cities[0].zip;


                chosen[0] = true;
                active[0] = true;
                chosenInd[0] = 0;
                chosenTime[0] = 0;

                /*                for (int i = 0; i < N; ++i)
                 System.out.println((i + 1) + " zip: " + cities[i].zip);
                 */
                for (int n = 1; n < N; ++n)
//                    printg();
                    for (int c = 0; c < N; ++c) {
                        if (chosen[c])
                            continue;
//                        System.out.println("checking: " + (cities[c].index + 1));
                        int found = -1;
                        for (int i = g.get(c).size() - 1; i >= 0; --i) {
                            int to = g.get(c).get(i);
                            if (active[to])
                                if (found == -1 || chosenTime[to] > chosenTime[found])
                                    found = to;
                        }
                        if (found == -1)
//                            System.out.println("c = " + (cities[c].index + 1) + ", found = -1");
                            continue;
                        //           System.out.println("found: " + found);
                        for (int i = 0; i < N; ++i)
                            DFSbool[i] = false;
                        for (int i = 0; chosenInd[i] != found; ++i) {
                            DFSbool[chosenInd[i]] = true;
                            DFS(chosenInd[i]);
                        }
                        DFSbool[found] = true;
                        DFS(found);
//                        System.out.println("checking(" + c + " -> " + (cities[c].index + 1) + ")");
                        DFSbool[c] = true;
                        DFS(c);
                        boolean val = true;
                        for (int i = 0; i < N; ++i)
                            if (!chosen[i] && !DFSbool[i]) {
                                val = false;
//                                System.out.println("val = false (" + (cities[i].index + 1) + ")");
                                break;
                            }
                        if (val) {
                            g.get(c).remove((Integer) ccity);
                            g.get(ccity).remove((Integer) c);
                            ccity = c;
                            chosen[ccity] = true;
                            chosenInd[n] = c;
                            chosenTime[c] = n;
                            active[c] = true;
                            for (int i = chosenTime[found] + 1; i < n; ++i)
                                active[chosenInd[i]] = false;
                            code += cities[c].zip;
//                            System.out.println("choose: " + (cities[c].index + 1));
                            break;
                        }
                    }

                w.write("Case #" + (t + 1) + ": " + code + "\n");
//                System.out.println("Case #" + (t + 1) + ": " + code);
            }
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(DeceitfulWar.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static class City implements Comparable<City> {

        String zip;
        int index;

        public City(String zip, int index) {
            this.zip = zip;
            this.index = index;
        }

        @Override
        public int compareTo(City o) {
            return zip.compareTo(o.zip);
        }
    }
}
