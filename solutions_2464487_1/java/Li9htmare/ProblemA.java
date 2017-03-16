
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

/**
 *
 * @author Li9htmare
 */
public class ProblemA {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("A-large.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int caseCount = Integer.parseInt(in.readLine());

        for (int caseI = 1; caseI <= caseCount; caseI++) {
            String[] tokens = in.readLine().split(" ");
            BigInteger r = new BigInteger(tokens[0]);
            BigInteger t = new BigInteger(tokens[1]);
            
            BigInteger left = new BigInteger("1");
            BigInteger right = new BigInteger(tokens[1]);
            BigInteger one = new BigInteger("1");
            BigInteger two = new BigInteger("2");
            BigInteger middle = (left.add(right).divide(two));
            
            BigInteger base = r.add(r).add(one);
            
            BigInteger currentResult;
            while (!left.equals(right.subtract(one))){
                currentResult = middle.subtract(one);
                currentResult = currentResult.multiply(two);
                currentResult = currentResult.add(base);
                currentResult = currentResult.multiply(middle);
                if (currentResult.compareTo(t) > 0) {
                    right = middle;
                } else if (currentResult.compareTo(t) < 0) {
                    left = middle;
                } else {
                    left = middle;
                    right = middle.add(one);
                }
                middle = left.add(right).divide(two);
            }
            
            resultBuilder.append("Case #").append(caseI).append(": ").append(middle).append("\n");
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
