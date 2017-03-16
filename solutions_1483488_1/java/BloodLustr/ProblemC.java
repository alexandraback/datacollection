/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package problem.c;
import java.util.Scanner;
import java.io.*;

/**
 *
 * @author Jason
 */
public class ProblemC {

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
        for (int i = 0; i < cases;)
        {
            int pairs = 0;
            int A = file.nextInt();
            int B = file.nextInt();
            for(;A < B;A++)
            {
                int[] newA = null;
                if (A>999999)
                    newA = new int[7];
                else if (A>99999)
                    newA = new int[6];
                else if (A>9999)
                    newA = new int[5];
                else if (A>999)
                    newA = new int[4];
                else if (A>99)
                    newA = new int[3];
                else if (A>9)
                    newA = new int[2];
                else
                    newA = new int[1];
                int tempA = A;
                for(int j = newA.length-1; j >= 0;j--)
                {
                    newA[j] = tempA % 10;
                    tempA = tempA / 10;
                }
                int[] savedFound = {0, 0, 0, 0, 0, 0};
                int foundIterator = 0;
                for(int j = 0; j < newA.length-1; j++)
                {
                    int temp = newA[newA.length-1];
                    for(int k = 0; k < newA.length; k++)
                    {
                        int temp2 = newA[k];
                        newA[k] = temp;
                        temp = temp2;
                    }
                    temp = 0;
                    for(int k =  newA.length-1, tens = 1; k >= 0;k--,tens*=10)
                    {
                        temp += newA[k]*tens;
                    }
                    if (temp > A && temp <= B && temp != savedFound[0] && temp
                            != savedFound[1] && temp != savedFound[2] && temp
                            != savedFound[3] && temp != savedFound[4] && temp
                            != savedFound[5] )
                    {
                        pairs++;
                        savedFound[foundIterator++] = temp;
                    }
                }
            }
            output.println("Case #" + ++i + ": " + pairs);
        }
        output.close();
    }
}