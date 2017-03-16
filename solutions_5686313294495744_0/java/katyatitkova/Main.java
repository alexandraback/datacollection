import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C-small-attempt0.in"));
        //Scanner in = new Scanner(new File("C-small.in"));
        PrintWriter out = new PrintWriter("out.txt");
        int t = in.nextInt();
        for (int cases = 1; cases <= t; cases++) {
            int n = in.nextInt();
            String[] first = new String[n];
            HashMap<String, Integer> firstMap = new HashMap<String, Integer>();
            String[] second = new String[n];
            HashMap<String, Integer> secondMap = new HashMap<String, Integer>();
            for (int i = 0; i < n; i++) {
                first[i] = in.next();
                second[i] = in.next();
                if (firstMap.containsKey(first[i])) {
                    firstMap.put(first[i], firstMap.get(first[i]) + 1);
                } else {
                    firstMap.put(first[i], 1);
                }
                if (secondMap.containsKey(second[i])) {
                    secondMap.put(second[i], secondMap.get(second[i]) + 1);
                } else {
                    secondMap.put(second[i], 1);
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (firstMap.get(first[i]) >= 2 && secondMap.get(second[i]) >= 2) {
                    res++;
                    firstMap.put(first[i], firstMap.get(first[i]) - 1);
                    secondMap.put(second[i], secondMap.get(second[i]) - 1);
                }
            }
            out.println("Case #" + cases + ": " + res);
        }
        out.close();
    }
}