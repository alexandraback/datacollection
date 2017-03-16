
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
public class ProblemA {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("A-small-attempt0.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int caseCount = Integer.parseInt(in.readLine());

        for (int caseI = 1; caseI <= caseCount; caseI++) {
            String[] tokens = in.readLine().split(" ");
            int r = Integer.parseInt(tokens[0]);
            int t = Integer.parseInt(tokens[1]);
            
            int number = 0;
            int nextNeed = r + r + 1;
            t -= nextNeed;
            
            for (; t >= 0; t = t - nextNeed) {
                number++;
                nextNeed = nextNeed + 4;
            }
            
            resultBuilder.append("Case #").append(caseI).append(": ").append(number).append("\n");
        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }


    private static void writeFile(String s) throws IOException {
        FileWriter output = new FileWriter("result.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
