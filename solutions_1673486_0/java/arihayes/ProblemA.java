import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ari
 */
public class ProblemA {
    static String in = "src/a.in";
    static String out = "src/a.out";
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        int lettersTyped;
        int totalLength;
        double minStrokes;
        double tempBest;
        double tempWorst;
        double runningProb;
        double tempExpected;
        DecimalFormat df = new DecimalFormat("#.000000");
        for(int x = 0; x < numlines; x++) {
            lettersTyped = scan.nextInt();
            totalLength = scan.nextInt();
            
            minStrokes = totalLength + 2;//cost of simple redo
            runningProb = 1;
            tempBest = totalLength + lettersTyped + 1;//backspace all, success
            tempWorst = tempBest + totalLength + 1;//backspace all, fail
            for(int y = 0; y < lettersTyped; y++) {
                runningProb = runningProb * scan.nextDouble();
                tempBest-=2;//backspace one less
                tempWorst-=2;
                tempExpected = (runningProb * tempBest) + ((1 - runningProb) * tempWorst);
                if(tempExpected < minStrokes) {
                    minStrokes = tempExpected;
                }
            }
            
            write.write("Case #" + (x+1) + ": ");
            write.write(df.format(minStrokes));
            write.newLine();
        }
        scan.close();
        write.close();
    }
}
