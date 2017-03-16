import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
//import java.util.HashSet;

/**
 * 
 */

/**
 * @author joelmanning
 *
 */
public class CountingSheep
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("sheep.in"));
        PrintWriter pw = new PrintWriter("sheep.out");
        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++)
        {
            //HashSet<Integer> past = new HashSet<Integer>();
            boolean[] complete = new boolean[10];
            int n = Integer.parseInt(br.readLine());
            if(n == 0){
                pw.println("Case #" + i + ": INSOMNIA");
            } else {
                int current = 0;
                while(true){
                    current += n;
                    //System.out.println("Examining " + current);
                    int j = 1;
                    while(j <= current){
                        int next = j * 10;
                        int index = (current % next) / j;
                        //System.out.println("setting " + index + " to true from " + current);
                        complete[index] = true;
                        j = next;
                    }
                    if(complete(complete)){
                        pw.println("Case #" + i + ": " + current);
                        //System.out.println("Solved as " + n);
                        break;
                    }
                    /*past.add(current);
                if(current % 10 == 0){
                    int check = current/10;
                    while(check > n && check % 10 == 0){
                        check /= 10;
                    }
                    if(check == n){
                        pw.println("Case #" + i + " INSOMNIA");
                        System.out.println("INSOMNIA");
                        break;
                    }
                }*/
                    /*if(current % 10 == 0 && past.contains(current / 10)){
                    pw.println("Case #" + i + " INSOMNIA");
                    System.out.println("INSOMNIA");
                    break;
                }*/
                }
            }
        }
        pw.close();
        br.close();
        System.exit(0);
    }
    private static boolean complete(boolean[] complete){
        for(boolean b: complete){
            if(!b){
                return false;
            }
        }
        return true;
    }
}
