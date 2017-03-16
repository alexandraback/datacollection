
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Li9htmare
 */
public class ProblemB {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("B-small-attempt3.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int caseCount = Integer.parseInt(in.readLine());

        for (int caseI = 1; caseI <= caseCount; caseI++) {
            String[] tokens = in.readLine().split(" ");
            int E = Integer.parseInt(tokens[0]);
            int R = Integer.parseInt(tokens[1]);
            int N = Integer.parseInt(tokens[2]);

            tokens = in.readLine().split(" ");
            int[] v = new int[N];
            for (int i = 0; i < tokens.length; i++) {
                v[i] = Integer.parseInt(tokens[i]);
            }

            int result = 0;
            int currentE = E;
            int used = 0;
            for (int i = 0; i < v.length; i++) {
                if (i == v.length - 1) {
                    used = currentE;
                } else if (v[i] < v[i + 1]) {
                    if (E - currentE < R) {
                        used = currentE + R - E;
                    } else {
                        used = 0;
                    }
                } else {
                    int lookAhead = E / R;
                    int j;
                    for (j = i; j < i + lookAhead && j < v.length; j++) {
                        if (v[j] > v[i]) {
                            break;
                        }
                    }
                    if (j == i + lookAhead || j == v.length) {
                        used = currentE;
                    } else if (currentE > E - (j - i) * R ){
                        used = currentE - (E - (j - i) * R);
                    } else {
                        used = 0;
                    }
                }
                result += used * v[i];
                currentE = currentE - used;
                currentE = refill(currentE, E, R);
            }
            /*resultBuilder.append(E + ", " + R + ", " + N).append("\n");
            for (int i = 0; i < v.length; i++) {
                resultBuilder.append(v[i]).append(" ");                
            }
            resultBuilder.append("\n");*/
            resultBuilder.append("Case #").append(caseI).append(": ").append(result).append("\n");
        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }
    
    private static int refill(int currentE, int E, int R) {
        if (E - currentE < R) {
            return E;
        } else {
            return currentE + R;
        }
    }

    private static void writeFile(String s) throws IOException {
        FileWriter output = new FileWriter("result.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
