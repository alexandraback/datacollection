package ro.hasna.codejam;

import java.io.*;
import java.util.*;

public class ReorderingTrainCars {


    public static void perm2(List<String> a) {
        List<String> sub = new LinkedList<String>();
        perm2(sub, a);
    }

    public static void perm2(List<String> sub, List<String> a) {
        int L = a.size();
        if (L == 0) {
            if (check(sub)){
                nr++;
            }
        } else {
            for (int i = 0; i < L; i++) {
                List<String> ab = new LinkedList<String>(sub);
                ab.add(a.get(i));
                List<String> bc = new LinkedList<String>(a);
                bc.remove(i);
                perm2(ab, bc);
            }
        }
    }

    public static boolean check(List<String> list) {
        Set<Character> map = new HashSet<Character>(30);
        Character prev = null;
        for (String s : list) {
            Character first = s.charAt(0);
            if (prev != first && map.contains(first)) {
                return false;
            }
            map.add(first);
            for (int j = 1; j < s.length(); j++) {
                if (s.charAt(j - 1) != s.charAt(j)) {
                    if (map.contains(s.charAt(j))) {
                        return false;
                    }
                    map.add(s.charAt(j));
                }
            }
            prev = s.charAt(s.length() - 1);
        }
        return true;
    }

    static String[] v;
    static int nr;

    public static void main(String[] args) throws IOException {
//        BufferedReader reader = new BufferedReader(new FileReader("in.txt"));
        BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt0.in"));
//        BufferedWriter writer = new BufferedWriter(new PrintWriter("A-large.out"));
        BufferedWriter writer = new BufferedWriter(new PrintWriter("out.txt"));
        int t = Integer.parseInt(reader.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(reader.readLine());
            v = reader.readLine().split(" ");
            nr = 0;

            perm2(Arrays.asList(v));
            writer.append("Case #");
            writer.append((i + 1) + ": ");
            writer.append("" + nr);

            writer.append("\r\n");
            writer.flush();
        }

        writer.close();
        reader.close();
    }

}
