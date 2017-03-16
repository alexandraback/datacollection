package codejam.y2012.r0;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Ilya Lantuh
 */
public class Task3 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int A = input.nextInt();
        int B = input.nextInt();
        Set<String> res = new HashSet<String>();
        for (int i = A; i < B; i++) {
            String num = String.valueOf(i);
            for (int j = 1; j < num.length(); j++) {
                int num2 = Integer.parseInt(getRecycled(num, j));
                if (num2 > i && num2 <= B) {
                    res.add("(" + num + ", " + num2 + ")");
                }
                
            }
        }
        return String.valueOf(res.size());
    }
    
    public static String getRecycled(String source, int digits) {
        String firstPart = source.substring(0, source.length() - digits);
        String secondPart = source.substring(source.length() - digits);
        return secondPart + firstPart;
    }
    
}
