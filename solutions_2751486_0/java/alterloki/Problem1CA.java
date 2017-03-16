package jam.jam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 12.05.13
 * Time: 13:07
 */
public class Problem1CA {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("input/2013-R1C-A-small.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output/2013-R1C-A-small.out"));
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for (int i = 0; i < cases; i++) {
            line = br.readLine();
            String[] parts = line.split(" ");
            String result = calculate(parts[0], Integer.parseInt(parts[1]));
            System.out.println("Case #" + (i + 1) + ": " + result);
            bw.write("Case #" + (i + 1) + ": " + result);
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static String calculate(String name, int n) {
        int result = 0;
        for(int i = 0; i < name.length(); i++) {
            for(int j = i + 1; j < name.length() + 1; j++) {
                String subname = name.substring(i, j);
                int c = countCons(subname);
                if(c >= n) {
                    result++;
                }
            }
        }
        return Integer.toString(result);
    }

    private static int countCons(String s) {
        int maxResult = 0;
        int curResult = 0;
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if(!isVowel(chars[i])) {
                curResult++;
            } else {
                if(maxResult < curResult) {
                    maxResult = curResult;
                }
                curResult = 0;
            }
        }
        if(maxResult < curResult) {
            maxResult = curResult;
        }
        return maxResult;
    }

    public static boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');  
    }
}
