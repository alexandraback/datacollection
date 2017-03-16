import java.util.*;
import java.io.*;

public class solveOvation {
    public static void main(String[] args) {
        String name = args[0];
        try {
            Scanner in = new Scanner(new File(name));
            try {
                 PrintWriter writer = new PrintWriter("ovation.txt", "UTF-8");
                 int n = Integer.parseInt(in.nextLine());
                 for (int l=0; l<n; l++) {
                     String[] s= in.nextLine().split(" ");
                     int level = Integer.parseInt(s[0]);
                     int ret = 0;
                     int ppl = 0;
                     for (int i=0; i<= level; i++) {
                         if (ppl < i) {
                             ret += (i-ppl);
                             ppl = i;
                         }
                         ppl += Integer.parseInt(s[1].substring(i, i+1));
                     }
                     writer.println("Case #"+(l+1)+": "+ret);
                 }
                 writer.close();
            }
            catch(IOException e) {
            }
            in.close();
        }
        catch (FileNotFoundException e) {
        }
    }
}