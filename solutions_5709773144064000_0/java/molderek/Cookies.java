package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Cookies {
    
    public static CookiesTestCase[] testCases;
    public static String[] results;
    
    public static void main(String[] args) {
        
        if (args.length != 1) {
            System.out.println("usage: java StoreCredit <input.file>");
            return;
        }
        
        readInput(args[0]);
        
        results = new String[testCases.length];
        for (int i = 0; i < testCases.length; i++) {
            results[i] = solveCase(testCases[i]);
        }
        
        writeOutput();
        
        System.out.println("done!");
    }

    private static String solveCase(CookiesTestCase testCase) {
        System.out.println("solving " + testCase);
        
        final double c = testCase.cost;
        final double f = testCase.factoryOutput;
        final double x = testCase.winningScore;
        
        double totalTime = 0.0;
        double currentOutput = 2.0;
        
        // if time to finish is more than build one more factory and then time to finish, then build one more factory 
        double timeToFinish = x / currentOutput; 
        double timeToFinishWithOneMoreFactory = (x / (currentOutput + f)) + (c / currentOutput); 
        
        while (timeToFinish > timeToFinishWithOneMoreFactory) {
            // time of building the factory
            totalTime += c / currentOutput;
            currentOutput += f;

            //System.out.println("building factory, currentTime: " + totalTime + ", currentOutput: " + currentOutput);

            timeToFinish = x / currentOutput; 
            timeToFinishWithOneMoreFactory = (x / (currentOutput + f)) + (c / currentOutput);
            
        }

        //System.out.println("current time: " + totalTime);
        totalTime += timeToFinish;
        
        //System.out.println("totalTime: " + totalTime);
        return String.format("%.7f" , totalTime);
    }

    private static void writeOutput() {

        Path file = Paths.get("output.out") ;
        Charset charset = Charset.forName("US-ASCII");

        System.out.println("writing to path: " + file.toUri());

        try (BufferedWriter writer = Files.newBufferedWriter(file, charset)) {
            
            for (int i = 0; i < results.length; i++) {
                writer.write("Case #" + (i + 1) + ": " + results[i] + "\n");
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }

    private static void readInput(String fileName) {
        
        Path file = Paths.get(fileName) ;
        Charset charset = Charset.forName("US-ASCII");

        System.out.println("reading from path: " + file.toUri());

        try (BufferedReader reader = Files.newBufferedReader(file, charset)) {
            String line = reader.readLine();
            int testCaseNumber = Integer.valueOf(line);
            testCases = new CookiesTestCase[testCaseNumber];
            
            int testCaseCount = 0;
            while ((line = reader.readLine()) != null) {
                CookiesTestCase testCase = new CookiesTestCase();

                String[] split = line.split(" ");
                testCase.cost = Double.valueOf(split[0]);
                testCase.factoryOutput = Double.valueOf(split[1]);
                testCase.winningScore = Double.valueOf(split[2]);
                
                testCases[testCaseCount++] = testCase;
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }

}

class CookiesTestCase {
    
    double cost;
    double factoryOutput;
    double winningScore;
    
    @Override
    public String toString() {
        return "c: " + cost + ", f: " + factoryOutput + ", x: " + winningScore;
    }
    
}
