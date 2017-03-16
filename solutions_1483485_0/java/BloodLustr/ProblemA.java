/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package problem.a;
import java.util.Scanner;
import java.io.*;

/**
 *
 * @author Jason
 */
public class ProblemA {

    /**
     * @param args the command line arguments
     */
    private static char [] translation = {'y', 'n', 'f', 'i', 'c', 'w', 'l',
        'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j',
        'g', 't', 'h', 'a', 'q'};
    private static char [] alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z'};
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
        for (int i = 0; i < cases;)
        {
            String sentence = file.nextLine();
            char[] sentenceChar = sentence.toCharArray();
            for (int j = 0; j < sentenceChar.length; j++)
            {
                if (sentenceChar[j] != ' ')
                    for (int k = 0; k < translation.length; k++)
                    {
                        if (translation[k] == sentenceChar[j])
                        {
                            sentenceChar[j] = alphabet[k];
                            break;
                        }
                }
            }
            sentence = new String(sentenceChar);
            output.println("Case #" + ++i + ": " + sentence);
        }
        output.close();
    }
}
