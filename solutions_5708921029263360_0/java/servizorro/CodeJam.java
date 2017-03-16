import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Pavel
 * Date: 09.04.2016
 * Time: 17:26
 */
public class CodeJam {



    public static void main(String[] argv) {
        System.out.println("Run");

        Scanner scanner = new Scanner(System.in);

        int count = scanner.nextInt();

        //int i = 1;

        for (int i = 1; i <= count; i++) {

            System.out.print("Case #" + i + ": " + getResult(scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt()));
        }
    }



    private static String getResult(int J, int P, int S, int K) {




        int[][] gen = new int[J * P * S][3];

        int pos = 0;

        for (int i = 1; i <= J; i++) {
            for (int j = 1; j <= P; j++) {
                for (int k = 1; k <= S; k++) {
                    gen[pos][0] = i;
                    gen[pos][1] = j;
                    gen[pos++][2] = k;
                }
            }
        }

        String rets = "";
        int counts = 0;

        for (int j = 0; j < gen.length; j++) {


            String ret = "";

            int count = 0;
            HashMap<String, Integer> JP = new HashMap<>();
            HashMap<String, Integer> JS = new HashMap<>();
            HashMap<String, Integer> PS = new HashMap<>();
            for (int i = j; i < gen.length; i++) {
                int[] aGen = gen[i];

                String JPS = aGen[0] + " " + aGen[1];
                String JSS = aGen[0] + " " + aGen[2];
                String PSS = aGen[1] + " " + aGen[2];

                int JPViolation = 0;
                int JSViolation = 0;
                int PSViolation = 0;

                if (JP.containsKey(JPS))
                    JPViolation = JP.get(JPS);

                if (JS.containsKey(JSS))
                    JSViolation = JS.get(JSS);

                if (PS.containsKey(PSS))
                    PSViolation = PS.get(PSS);

                if (JPViolation < K && JSViolation < K && PSViolation < K) {
                    ret += aGen[0] + " " + aGen[1] + " " + aGen[2] + '\n';
                    count++;

                    if (JP.containsKey(JPS))
                        JP.put(JPS, JP.get(JPS) + 1);
                    else
                        JP.put(JPS, 1);

                    if (JS.containsKey(JSS))
                        JS.put(JSS, JS.get(JSS) + 1);
                    else
                        JS.put(JSS, 1);

                    if (PS.containsKey(PSS))
                        PS.put(PSS, PS.get(PSS) + 1);
                    else
                        PS.put(PSS, 1);
                }
            }

            if (count > counts) {
                counts = count;
                rets = ret;
            }

        }

        return "" + counts + '\n' + rets;
    }

}
