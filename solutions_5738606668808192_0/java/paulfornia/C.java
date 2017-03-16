import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class C
{
    public static void main(String[] args) throws IOException 
    {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("./input_small.txt"));
        PrintWriter writer = new PrintWriter("./output_small.txt");
        int nTests = scanner.nextInt();
        scanner.nextLine(); //skip line (i.e., next line)
        int n = scanner.nextInt();
        int j = scanner.nextInt();
        
        writer.println("Case #1: ");
        
        JamCoin jamCoin = new JamCoin(n);
        int jamCounter = 0;

        while(jamCounter < j)
        {   
            //System.out.println(jamCoin);
           // System.out.println(jamCoin.divisorString());
            
            if(jamCoin.isValidJam()) 
            {
                //System.out.println("Yep");
                writer.println(jamCoin + " " + jamCoin.divisorString());
                jamCounter++;
            }
            jamCoin.incrementJam();
        }
        
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
}
