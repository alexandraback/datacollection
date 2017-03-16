import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeSet;

public class Osmos {

    /**
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        // Input and output files
        File inputFile = new File(args[0]);
        File outputFile = new File(inputFile.getAbsolutePath() + ".output");
        if (outputFile.exists()) {
            System.out.println("Warning, output file already exists. Deleting");
            outputFile.delete();
        }
        outputFile.createNewFile();
        PrintWriter writer = new PrintWriter(outputFile);
        Scanner s = new Scanner(inputFile);

        int testCases = s.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            BigInteger size = s.nextBigInteger();
            int totalNodes = s.nextInt();
            ArrayList<BigInteger> sortedNodes = new ArrayList<BigInteger>();
            for(int nodeIndex = 0; nodeIndex < totalNodes; nodeIndex++){
                sortedNodes.add(s.nextBigInteger());
            }
            Collections.sort(sortedNodes);
            int finalResult = totalNodes; //Can Always just drop everything
            int stepsToConsume = 0;
            int remainingNodes = totalNodes;
            exit: for(BigInteger node : sortedNodes){
                remainingNodes--;
                while(!(size.compareTo(node) > 0)){
                    stepsToConsume++;
                    if(stepsToConsume >= finalResult){
                        break exit;
                    }
                    size = size.add(size.subtract(BigInteger.ONE));
                }
                size = size.add(node);
                int totalSteps = stepsToConsume + remainingNodes;
                if(totalSteps < finalResult){
                    finalResult = totalSteps;
                }
            }
            writer.println("Case #" + testCase + ": " + finalResult);
        }

        writer.close();
    }
}
