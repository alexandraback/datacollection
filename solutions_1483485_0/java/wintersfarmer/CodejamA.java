import java.io.*;
import java.util.*;

class CodejamA {
    public static char[] map;
    public static void main (String [] args) throws IOException {
        init();
        BufferedReader in = new BufferedReader(new FileReader("E:/inA.txt"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("E:/outA.txt")));
        int n = Integer.parseInt(in.readLine());
        for (int testIndex = 0; testIndex < n; testIndex++) {
            out.print("Case #" + (testIndex + 1) + ": ");
            String s = in.readLine();
            int len = s.length();
            for (int i = 0; i < len; i++) {
                //System.out.print(s.charAt(i));
                // System.out.print(map[s.charAt(i)]);
                out.print(map[s.charAt(i)]);
            }
            out.println();
        }
        out.close();
    }
    public static void init() {
        map = new char['z' + 1];
        String a = "a zoo" + "our language is impossible to understand"
            + "there are twenty six factorial possibilities"
            + "so it is okay if you want to just give up";
        String b = "y qee" + "ejp mysljylc kd kxveddknmc re jsicpdrysi"
            + "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
            + "de kr kd eoya kw aej tysr re ujdr lkgc jv";
        int length = a.length();
        for (int i = 0; i < length; i++) {
            map[b.charAt(i)] = a.charAt(i);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            System.out.print(c);
        }
        map['z'] = 'q';
        System.out.println();
        for (char c = 'a'; c <= 'z'; c++) {
            System.out.print(map[c]);
        }
        System.out.println();
        /*
        Arrays.sort(map);
        for (char c = 'a'; c <= 'z'; c++) {
            System.out.print(map[c]);
        }
        */
        map[' '] = ' ';
    }
}