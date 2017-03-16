package codejam15;

import java.io.*;
import java.util.*;

public class D {

    static Map<String, Integer> mul = new HashMap<>();
    static Map<String, Integer> sol = new HashMap<>();
    static {
        mul.put("1_-4", -4);sol.put("1_-4", -4);
        mul.put("1_-3", -3);sol.put("1_-3", -3);
        mul.put("1_-2", -2);sol.put("1_-2", -2);
        mul.put("1_-1", -1);sol.put("1_-1", -1);
        mul.put("1_1", 1);sol.put("1_1", 1);
        mul.put("1_2", 2);sol.put("1_2", 2);
        mul.put("1_3", 3);sol.put("1_3", 3);
        mul.put("1_4", 4);sol.put("1_4", 4);

        mul.put("2_-4", 3);sol.put("2_3", -4);
        mul.put("2_-3", -4);sol.put("2_-4", -3);
        mul.put("2_-2", 1);sol.put("2_1", -2);
        mul.put("2_-1", -2);sol.put("2_-2", -1);
        mul.put("2_1", 2);sol.put("2_2", 1);
        mul.put("2_2", -1);sol.put("2_-1", 2);
        mul.put("2_3", 4);sol.put("2_4", 3);
        mul.put("2_4", -3);sol.put("2_-3", 4);

        mul.put("3_-4", -2);sol.put("3_-2", -4);
        mul.put("3_-3", 1);sol.put("3_1", -3);
        mul.put("3_-2", 4);sol.put("3_4", -2);
        mul.put("3_-1", -3);sol.put("3_-3", -1);
        mul.put("3_1", 3);sol.put("3_3", 1);
        mul.put("3_2", -4);sol.put("3_-4", 2);
        mul.put("3_3", -1);sol.put("3_-1", 3);
        mul.put("3_4", 2);sol.put("3_2", 4);

        mul.put("4_-4", 1);sol.put("4_1", -4);
        mul.put("4_-3", 2);sol.put("4_2", -3);
        mul.put("4_-2", -3);sol.put("4_-3", -2);
        mul.put("4_-1", -4);sol.put("4_-4", -1);
        mul.put("4_1", 4);sol.put("4_4", 1);
        mul.put("4_2", 3);sol.put("4_3", 2);
        mul.put("4_3", -2);sol.put("4_-2", 3);
        mul.put("4_4", -1);sol.put("4_-1", -4);
    }

    private static int multiply(int a, int b) {
        int sign = 1;
        String query;
        if (a < 0) {
            sign = -1;
            query = (-a) + "_" + b;
        } else {
            query = a + "_" + b;
        }
        return sign * mul.get(query);
    }

    private static int solveEq(int a, int b) {
        int sign = 1;
        String query;
        if (a < 0) {
            sign = -1;
            query = (-a) + "_" + b;
        } else {
            query = a + "_" + b;
        }

        return sign * sol.get(query);
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {

        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in), 1024 * 1024 * 2);

        int t = Integer.parseInt(br.readLine());

        Map<Character, Integer> map = new HashMap<>();
        map.put('i', 2);
        map.put('j', 3);
        map.put('k', 4);
        StringBuilder sb = new StringBuilder();
        for (int x = 1; x <= t; x++) {
            long v[] = readArrayLine(br.readLine(), 2);
            int L = (int) v[0];
            int X = (int) Math.min(v[1], 12 + v[1]%4);
//            int X = v[1];
            String s = br.readLine();
            int position;

            int prefixes[] = new int[L * X];
            List<Integer> posPref = new ArrayList<>();
            prefixes[0] = map.get(s.charAt(0));
            if (prefixes[0] == 2) {
                posPref.add(0);
            }
            for (int i = 0; i < X; i++) {
                for (int j = i == 0 ? 1 : 0; j < L; j++) {
                    position = i * L + j;
                    prefixes[position] = multiply(prefixes[position - 1], map.get(s.charAt(j)));
                    if (prefixes[position] == 2) {
                        posPref.add(position);
                    }
                }
            }

            List<Integer> posSuf = new ArrayList<>();
            int suffixes[] = new int[L * X];
            suffixes[L * X - 1] = map.get(s.charAt(L - 1));
            if (suffixes[L * X - 1] == 4) {
                posSuf.add(L * X - 1);
            }
            for (int i = X - 1; i >= 0; i--) {
                for (int j = i == X - 1 ? L - 2 : L - 1; j >= 0; j--) {
                    position = i * L + j;
                    suffixes[position] = multiply(map.get(s.charAt(j)), suffixes[position + 1]);
                    if (suffixes[position] == 4) {
                        posSuf.add(position);
                    }
                }
            }

//            System.out.println(Arrays.toString(prefixes));
//            System.out.println(Arrays.toString(suffixes));

            Collections.reverse(posSuf);
            boolean possible = false;

            for (int pp : posPref) {
                for (int sp : posSuf) {
                    if (sp <= pp + 1) {
                        continue;
                    } else {
                        int interval = solveEq(prefixes[pp], prefixes[sp - 1]);
                        if (interval == 3) {
                            possible = true;
                            break;
                        }
                    }
                }
                if (possible) {
                    break;
                }
            }

            sb.append("Case #" + x + ": " + (possible ? "YES" : "NO") + "\n");
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outDJam.txt"));
        bw.write(sb.toString());
        bw.close();
        System.out.println(sb.toString());
    }

    public static long[] readArrayLine(String line, int n) {
        long[] ret = new long[n];
        int start = 0;
        int end = line.indexOf(' ', start);
        for (int i = 0; i < n; i++) {
            if (end > 0)
                ret[i] = Long.parseLong(line.substring(start, end));
            else
                ret[i] = Long.parseLong(line.substring(start));
            start = end + 1;
            end = line.indexOf(' ', start);
        }
        return ret;
    }
}
