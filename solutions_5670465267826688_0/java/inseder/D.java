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

    public static int multiply(int a, int b) {
        int sign = 1;
        if (a < 0 && b < 0) {
            sign = 1;
        } else if (a < 0 || b < 0) {
            sign = -1;
        }
        a = Math.abs(a);
        b = Math.abs(b);
        switch (a) {
            case 1:
                return sign * b;
            case 2:
                switch (b) {
                    case 1:
                        return sign * 2;
                    case 2:
                        return sign * (-1);
                    case 3:
                        return sign * 4;
                    case 4:
                        return sign * (-3);
                }
            case 3:
                switch (b) {
                    case 1:
                        return sign * 3;
                    case 2:
                        return sign * (-4);
                    case 3:
                        return sign * (-1);
                    case 4:
                        return sign * 2;
                }
            case 4:
                switch (b) {
                    case 1:
                        return sign * 4;
                    case 2:
                        return sign * 3;
                    case 3:
                        return sign * (-2);
                    case 4:
                        return sign * (-1);
                }
        }
        return -10000;
    }

    public static int solve(int a, int b) {
        int sign = 1;
        if (a < 0 && b < 0) {
            sign = 1;
        } else if (a < 0 || b < 0) {
            sign = -1;
        }
        a = Math.abs(a);
        b = Math.abs(b);
        switch (a) {
            case 1:
                return sign * b;
            case 2:
                switch (b) {
                    case 1:
                        return sign * 2;
                    case 2:
                        return sign * (-1);
                    case 3:
                        return sign * 4;
                    case 4:
                        return sign * (-3);
                }
            case 3:
                switch (b) {
                    case 1:
                        return sign * 3;
                    case 2:
                        return sign * (-4);
                    case 3:
                        return sign * (-1);
                    case 4:
                        return sign * 2;
                }
            case 4:
                switch (b) {
                    case 1:
                        return sign * 4;
                    case 2:
                        return sign * 3;
                    case 3:
                        return sign * (-2);
                    case 4:
                        return sign * (-1);
                }
        }
        return -10000;
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
            int v[] = readArrayLine(br.readLine(), 2);
            int L = v[0];
            int X = v[1];
            String s = br.readLine();

            int p[] = new int[L * X];
            List<Integer> posPref = new ArrayList<>();
            p[0] = map.get(s.charAt(0));
            if(p[0] == 2) {
                posPref.add(0);
            }
            for (int i = 0; i < X; i++) {
                for (int j = i == 0 ? 1 : 0; j < L; j++) {
                    int a = p[i * L + j - 1];
                    int b = map.get(s.charAt(j));
                    int sign  = 1;
                    String query = a + "_" + b;
                    if(a < 0){
                        sign = -1;
                        query = query.substring(1);
                    }
                    p[i * L + j] = multiply(a,b);
                    if( multiply(a,b) != sign * mul.get(query)){
                        System.err.println(a+"_"+b + " " + (sign * mul.get(a+"_"+b)) + " | " + multiply(a,b));
                    }
//                    System.out.println((i * L + j) + " -> " + p[i * L + j]);
                    if(p[i*L + j] == 2) {
                        posPref.add(i*L + j);
                    }
                }
            }

//            System.out.println("delim");

            List<Integer> posSuf = new ArrayList<>();
            int suf[] = new int[L * X];
            suf[L * X - 1] = map.get(s.charAt(L - 1));
            if(suf[L * X - 1] == 4) {
                posSuf.add(L * X - 1);
            }
            for (int i = X - 1; i >= 0; i--) {
                for (int j = i == X - 1 ? L - 2 : L - 1; j >= 0; j--) {
                    suf[i * L + j] = multiply(map.get(s.charAt(j)), suf[i * L + j + 1]);
//                    System.out.println((i * L + j) + " -> " + suf[i * L + j]);
                    if (suf[i * L + j] == 4) {
                        posSuf.add(i * L + j);
                    }
                }
            }
            Collections.reverse(posSuf);
            boolean pos = false;

            for (int pp : posPref) {
                for(int sp: posSuf) {
                    if(sp <= pp + 1){
                        continue;
                    }else {
                        int a = p[pp];
                        int b = p[sp-1];
                        int sign  = 1;
                        String query = a + "_" + b;
                        if(a < 0){
                            sign = -1;
                            query = query.substring(1);
                        }

                        int val = sign * sol.get(query);
//                        System.out.println(start + " " + end + " -> " + val);
                        if(val==3){
                            pos = true;
                            break;
                        }
                    }
                }
                if(pos){
                    break;
                }
            }

            sb.append("Case #" + x + ": " + (pos ? "YES":"NO")+ "\n");
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outDJam.txt"));
        bw.write(sb.toString());
        bw.close();
        System.out.println(sb.toString());
    }

    public static int[] readArrayLine(String line, int n) {
        int[] ret = new int[n];
        int start = 0;
        int end = line.indexOf(' ', start);
        for (int i = 0; i < n; i++) {
            if (end > 0)
                ret[i] = Integer.parseInt(line.substring(start, end));
            else
                ret[i] = Integer.parseInt(line.substring(start));
            start = end + 1;
            end = line.indexOf(' ', start);
        }
        return ret;
    }
}
