import java.io.*;
import java.util.*;
import java.lang.*;

public class Pancake {

    public static void print(Object o) {
        System.out.println(o);
    }

    // debugging
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void flip(char[] p, int k) {
        // flip top k pancakes
        int o = k - 1;
        for (int i = 0; i < k; i++) {
            char temp = p[i];
            p[i] = p[o - i];
            p[o] = temp;
        }
        for (int i = 0; i < k; i++) {
            if (p[i] == '-') {
                p[i] = '+';
            }
            else {
                p[i] = '-';
            }
        }
    }

    public static String nextState(String state, int k) {
        char[] p = state.toCharArray();
        flip(p, k);
        int plu = p.length - 1;
        while (plu >= 0 && p[plu] == '+') { plu--; }
        char[] p2 = (new String(p).substring(0,plu+1)).toCharArray();
        // remove common blocks
        ArrayList<Character> fin = new ArrayList<>();
        char prev = 0;
        for (Character c : p2) {
            if (c != prev) {
                fin.add(c);
            }
            prev = c;
        }
        StringBuilder sb = new StringBuilder();
        for (Character c : fin) {
            sb.append(c);
        }
        return sb.toString();
    }

    public static HashMap<String,Integer> dp() {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("", 0);
        int len = 0;
        while (len < 100) {
            len++;
            char[] p = new char[len];
            for (int i = len-1; i >= 0; i--) {
                if ((len-1-i) % 2 == 0) {
                    p[i] = '-';
                } else {
                    p[i] = '+';
                }
            }
            String st = new String(p);
            map.put(st, 1000000);
            for (int i = 1; i <= len; i++) {
                String next = nextState(st, i);
                int score = 1 + map.get(nextState(st, i));
                map.put(st, Math.min(score, map.get(st)));
            }
        }
        return map;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner sc;
        HashMap<String,Integer> val = dp();
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            String s = br.readLine();
            int score = val.get(nextState(s, 0));
            print(String.format("Case #%d: %d", i, score));
        }
    }
}
