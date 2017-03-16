import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;

public class HelloWorld {
    
    public static void main(String[] args) {
        try {
//            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/a.txt"));
//            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            
//          BufferedReader br = new BufferedReader(new FileReader("D:/codejam/D-large-practice.in"));
//          BufferedWriter bw = new BufferedWriter(new FileWriter("D:/codejam/D-large-result.txt"));
            
            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/A-small-attempt0.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("D:/codejam/A-small-result.txt"));
//            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/A-small-attempt1.in"));
            
//            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/C-large.in"));
//            BufferedWriter bw = new BufferedWriter(new FileWriter("D:/codejam/C-large-result.txt"));

            String line;
            
            line = br.readLine();
            int T = Integer.parseInt(line);
            
            for (int cas = 1; cas <= T; cas++) {
                line = br.readLine();
                String[] pq = line.split("/");
                int p = Integer.parseInt(pq[0]);
                int q = Integer.parseInt(pq[1]);
                
                int factor = gcd(p,q);
                q /= factor;
                p /= factor;
                
                if (count(q) > 1) {
                    bw.write("Case #" + cas + ": impossible");
                } else {
                    int ret = 0;
                    while (q > p) {
                        ret++;
                        q /= 2;
                    }
                    bw.write("Case #" + cas + ": " + ret);
                }
                bw.newLine();
                bw.flush();
            }
            
            br.close();
            bw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
      }
    
    private static int count(int set) {
        int ret = 0;
        while (set > 0) {
            ret++;
            set &= (set-1);
        }
        return ret;
    }

}
