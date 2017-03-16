/**
 * Created by kronenthaler on 08/04/16.
 */

import java.io.*;
import java.util.*;

public class A {
    static HashMap<Character, Integer>[] l = new HashMap[10];
    static String[] seed = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    static char[] key = new char[]{'Z','O','W','R','U','F','X','S','G','I'};
    public static void main(String args[]) throws IOException {
        for (int i=0;i<10;i++) {
            l[i] = new HashMap<>();
            for(int j=0;j<seed[i].length();j++){
                char c = seed[i].charAt(j);
                if(l[i].get(c) == null)
                    l[i].put(c, 0);
                l[i].put(c, l[i].get(c)+1);
            }
        }

        Scanner in = new Scanner(new FileInputStream("A-small-attempt1.in"));
        System.setOut(new PrintStream(new FileOutputStream("A.out")));

        int T = in.nextInt();
        for (int cases = 1; cases <= T; cases++) {
            System.out.printf("Case #%d: ", cases);
            doit(in);
        }
    }

    static void doit(Scanner in) throws IOException{
        String line = in.nextLine();
        if(line.length() == 0)
            line = in.nextLine();

        HashMap<Character, Integer> f = new HashMap<>();
        for(int i=0;i<line.length();i++){
            if (f.get(line.charAt(i)) == null)
                f.put(line.charAt(i), 0);
            f.put(line.charAt(i), f.get(line.charAt(i)) + 1);
        }

        ArrayList<Integer> buffer = new ArrayList<>();
        int[] p = new int[]{0,2,4,6,8,1,3,5,7,9};
        for(int i=0; i<p.length; i++){
            if(f.get(key[p[i]]) == null || f.get(key[p[i]]) == 0) continue;
            int t = f.get(key[p[i]]);
            for(int j=0;j<t;j++) {
                buffer.add(p[i]);
            }
            //remove the letters of this number t times
            for(char c : l[p[i]].keySet()){
                f.put(c, f.get(c) - (l[p[i]].get(c) * t));
            }
        }
        Collections.sort(buffer);
        String out = "";
        for(int i : buffer)
            out+=i;
        System.out.println(out);
    }
}