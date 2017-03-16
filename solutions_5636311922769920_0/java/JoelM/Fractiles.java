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
public class Fractiles
{

    /**
     * @param args
     */
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("fractiles.in"));
        PrintWriter pw = new PrintWriter("fractiles.out");
        int t = Integer.parseInt(br.readLine());
        for (int caseNum = 1; caseNum <= t; caseNum++)
        {
            //System.out.println("Case " + caseNum);
            String line = br.readLine();
            int space1 = line.indexOf(' ');
            int space2 = line.lastIndexOf(' ');
            int k = Integer.parseInt(line.substring(0, space1));//length of original sequence
            int c = Integer.parseInt(line.substring(space1 + 1, space2));//number of times to transform
            int s = Integer.parseInt(line.substring(space2 + 1));//limit of tiles to choose
            String out = "Case #" + caseNum + ":";
            if(k > s * c){
                out += " IMPOSSIBLE";
                //System.out.println("Impossible");
            } else {
                int maxChecked = 0;
                long end = pow(k, c);
                while(maxChecked < k){
                    long pos = 0;
                    for(int i = 0; i < c; i++){
                        //System.out.println("maxChecked " + maxChecked + " pos " + pos);
                        if(maxChecked >= k){
                            maxChecked = k - 1;
                        }
                        pos = pos * k + maxChecked;
                        maxChecked++;
                    }
                    pos++;
                    //System.out.println("done maxChecked " + maxChecked + " pos " + pos);
                    if(pos > end){
                        pos = end;
                        System.out.println("BORKEN");
                    }
                    //System.out.println("final maxChecked " + maxChecked + " pos " + pos);
                    out += " " + pos;
                }
            }
            pw.println(out);
        }
        pw.close();
        br.close();
        System.exit(0);
    }
    
    private static long pow(int base, int power){
        if(power == 0){
            return 1;
        }
        return ((long) base) * pow(base, power - 1);
    }
}
