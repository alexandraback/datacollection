import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * 
 */

/**
 * @author joelmanning
 *
 */
public class RevengeOfThePancakes
{

    /**
     * @param args
     */
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("pancakes.in"));
        PrintWriter pw = new PrintWriter("pancakes.out");
        int t = Integer.parseInt(br.readLine());
        for(int i = 1; i <= t; i++){
            String line = br.readLine();
            char prev = ' ';
            int flips = 0;
            for(int j = 0; j < line.length(); j++){
                if(line.charAt(j) != prev){
                    flips++;
                    prev = line.charAt(j);
                }
            }
            if(prev == '+'){
                flips--;
            }
            pw.println("Case #" + i + ": " + flips);
        }
        pw.close();
        br.close();
        System.exit(0);
    }

}
