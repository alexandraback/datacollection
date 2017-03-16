import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;


public class Main
{

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
    {
        //Scanner scan = new Scanner(System.in);
        //PrintStream out = System.out;
        
        Scanner scan = new Scanner(new BufferedReader(new FileReader("/Users/guillaumederval/Desktop/B-small-attempt0.in")));
        PrintWriter out = new PrintWriter (new BufferedWriter(new OutputStreamWriter( new FileOutputStream("/Users/guillaumederval/Desktop/out2.txt"), "utf-8")));
        scan.useLocale(Locale.US);
        int nbTests = scan.nextInt();
        
        for (int test = 0; test < nbTests; test++)
        {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int k = scan.nextInt();
            int total = 0;
            for(int i = 0; i < a; i++)
                for(int j = 0; j < b; j++)
                    if((i&j) < k)
                        total++;
            out.println("Case #"+(test+1)+": "+total);
        }
        out.close();
    }

}
