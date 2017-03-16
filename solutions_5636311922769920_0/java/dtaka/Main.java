import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            line = stdin.readLine();
            String[] prms = line.split(" ");
            
            int k = Integer.parseInt(prms[0]);
            int c = Integer.parseInt(prms[1]);
            int s = Integer.parseInt(prms[2]);
            
            System.out.printf("Case #%d:", t);
            for (int i = 1; i <= k; i++) {
                System.out.printf(" %d", i);
            }
            System.out.println();
        }
    }
}
