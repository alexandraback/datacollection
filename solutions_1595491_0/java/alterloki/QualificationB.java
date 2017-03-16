/**
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 14.04.12
 * Time: 11:17
 */
package codejam.codejam2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

/**
 * @author ashevenkov
 */
public class QualificationB {

    public static void main(String[] args) throws Exception {
        new QualificationB().calculate(
                "/home/ashevenkov/projects/codejam/B-small-attempt0.in",
                "/home/ashevenkov/projects/codejam/B-small-attempt0.out");
    }

    public void calculate(String in, String out) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(in));
        FileWriter fw = new FileWriter(out);
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for(int i = 0; i < cases; i++) {
            line = br.readLine();
            String[] parts = line.split(" ");
            int N = Integer.parseInt(parts[0]);
            int S = Integer.parseInt(parts[1]);
            int p = Integer.parseInt(parts[2]);
            int[] t = new int[N];
            for(int j = 3; j < parts.length; j++) {
                t[j - 3] = Integer.parseInt(parts[j]);
            }
            String result = dance(S, p, t);
            System.out.println("Case #" + (i + 1) + ": " + result);
            fw.write("Case #" + (i + 1) + ": " + result);
            fw.write("\n");
        }
        fw.flush();
        fw.close();
    }

    private String dance(int s, int p, int[] t) {
        int result = 0;
        int a1 = p + p - 1 + p - 1;
        int a2 = p + p - 2 + p - 2;
        if(p == 0) {
            return Integer.toString(t.length);
        }
        if(p == 1) {
            a1 = 1;
            a2 = 1;
        }
        Arrays.sort(t);
        boolean firstPhase = true;
        boolean secondPhase = false;
        int leftSurprise = s;
        for(int i = t.length - 1; i >= 0; i--) {
            int num = t[i];
            if(firstPhase) {
                if(num >= a1) {
                    result++;
                } else {
                    firstPhase = false;
                    secondPhase = true;
                }
            }
            if(secondPhase) {
                if(num >= a2 && leftSurprise > 0) {
                    result++;
                    leftSurprise--;
                } else {
                    return Integer.toString(result);
                }
            }
        }
        return Integer.toString(result);
    }

}
