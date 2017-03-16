/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package problem.b;
import java.util.Scanner;
import java.io.*;

/**
 *
 * @author Jason
 */
public class ProblemB {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        System.out.println("Enter name of input file: ");
        File inputFile = new File(input.next());
        File outputFile = new File("output.txt");
        Scanner file = null;
        PrintWriter output = null;
        while(file == null)
        {
            try{
                file = new Scanner(inputFile);
                output = new PrintWriter(outputFile);
            }
            catch(Exception E){
                System.out.println("invalid file");
            }
        }
        int cases = file.nextInt();
        file.nextLine();
        for(int i = 0; i < cases;)
        {
            int numGooglers = file.nextInt();
            int numSurprises = file.nextInt();
            int bestResult = file.nextInt();
            int numHighScores = 0;
            for(int j = 0; j < numGooglers;j++)
            {
                int tempScore = file.nextInt();
                if (tempScore >= (bestResult*3)-2)
                    numHighScores++;
                else if (tempScore >= (bestResult*3)-4 && numSurprises > 0 && tempScore > 0)
                {
                    numHighScores++;
                    numSurprises--;
                }
            }
            output.println("Case #" + ++i + ": " + numHighScores);
        }
        output.close();
    }
}
