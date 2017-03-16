package codejam2015.round1.C.TypewriterMonkey;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by cheto on 5/10/2015.
 */
public class TypewriterMonkey {
    static long total;
    static long count;
    static long max;
    static String target;
    static List<String> keys;
    static int L;
    static int S;
    static String keywords;
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        BufferedWriter writer = new BufferedWriter(new FileWriter(args[0].substring(0, args[0].length() - 2) + "out"));
        int testCases = Integer.parseInt(reader.readLine());
        System.out.println("Test cases: " + testCases);
        for (int test = 0; test < testCases; test++) {
            count = 0;
            total = 0;
            max = 0;
            String[] splitLine = reader.readLine().split(" ");
            int K = Integer.parseInt(splitLine[0]);
            L = Integer.parseInt(splitLine[1]);
            S = Integer.parseInt(splitLine[2]);
            keys = new ArrayList<String>();
            keywords = reader.readLine();
            for (int i = 0; i < keywords.length(); i++) {
                keys.add(keywords.substring(i, i + 1));
            }
            target = reader.readLine();
            if(!validate(target, keys)){
                writer.write("Case #" + (test + 1) + ": 0.0\n");
                System.out.println("Case #" + (test + 1) + ": 0.0\n");
                continue;
            }
            find(0,new StringBuilder(S));
            int chances = chancesPerLetter();
            double res = max - ((double)count / (double)total);
            writer.write("Case #" + (test + 1) + ": " + res + "\n");
            System.out.println("Case #" + (test + 1) + ": " + res + "\n");
        }
        reader.close();
        writer.flush();
        writer.close();
    }

    static int chancesPerLetter() {
        int val = 0;
        for (int i = 0; i < target.length(); i++) {
            for (int j = 0; j < keywords.length(); j++) {
                if (target.substring(i, i + 1).equals(keywords.substring(j, j + 1))) {
                    val++;
                }
            }
        }
        return val - target.length() +1;
    }

    static void find(int pos, StringBuilder sb) {
        if (pos == S) {
            count += parseString(sb);
        }else {
            Iterator<String> it = keys.iterator();
            while(it.hasNext()) {
                find(pos+1,sb.replace(pos, pos + 1, it.next()));
            }
        }
    }

    static int parseString(StringBuilder sb) {
        int val = 0;
        total++;
        for (int i = 0; i < sb.length() - (L-1); i++) {
            if(sb.substring(i,i+L).equals(target))
                val++;
        }
        max = max > val ? max : val;
        return val;
    }

    public static boolean validate(String target, List<String> keys) {
        for (int i = 0; i < target.length(); i++) {
            if (!keys.contains(target.substring(i, i + 1))) {
                return false;
            }
        }
        return true;
    }
}
