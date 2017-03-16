import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by colander on 4/9/16.
 */
public class ProblemBB {
    public static void main(String[] args) {
        new ProblemBB();
    }

    int min = 0;
    String minString = "";

    public ProblemBB() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int tests = Integer.parseInt(br.readLine());
            for (int i = 0; i < tests; i++) {
                min = Integer.MAX_VALUE;
                String or = br.readLine();
                String a = or.split(" ")[0];
                String b = or.split(" ")[1];
                String test = a + b;
                tryThis("", test);
                //System.out.println(minString);
                System.out.println("Case #" + (i + 1) + ": " + minString.substring(0, minString.length() / 2) + " " + minString.substring(minString.length() / 2));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void tryThis(String got, String rest) {
        if (rest.length() == 0) {
            int thisCalc = Math.abs(Integer.parseInt(got.substring(0, got.length() / 2)) - Integer.parseInt(got.substring(got.length() / 2)));
            if (thisCalc < min) {
                //System.out.println(got + " " + rest + " " + thisCalc);
                min = thisCalc;
                minString = got;
            }
        } else {
            if (rest.charAt(0) == '?') {
                for (int i = 0; i < 10; i++) {
                    tryThis(got + i, rest.substring(1));
                }
            } else {
                tryThis(got + rest.charAt(0), rest.substring(1));
            }
        }
    }
}
