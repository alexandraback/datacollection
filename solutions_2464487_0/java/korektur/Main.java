
import java.util.*;
import java.io.*;

public class Main {

 
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        for(int tt = 0; tt < t; tt++){
            long r =  in.nextLong();
            long m = in.nextLong();
            long r1 = r;
            long r2 = r1 + 1;
            long ans = 0;
            while(m > 0){
                m -= (r2 * r2 - r1 * r1);
                if(m < 0) break;
                r1 += 2;
                r2 += 2;
                ans++;
            }
            out.print("Case #" + (tt + 1) + ": ");
            out.println(ans);
        }
        out.close();
    }
}