package p1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;

public class Main {
    
    private static DecimalFormat df = new DecimalFormat("#.#######");
    
    private static String k;
    private static String l;
    private static int s;
    
    private static int max;
    private static double total;
    
    public static double solve(String r) {
        
        if (r.length() == s) {
            
            int count = 0;
            int begin = 0;
            
            while (r.indexOf(l, begin) != -1) {
                count += 1;
                begin = r.indexOf(l, begin) + 1;
            }
            
            if (count > max) {
                max = count;
            }
            total += count;
        } else {
            for (int i = 0; i < k.length(); i++) {
                solve(r + k.charAt(i));
            }
        }

        return max - (total / Math.pow(k.length(), s));
    }
    
    public static void main(String[] args) {
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter("output.txt");
            int count = Integer.valueOf(br.readLine());
            
            for (int ii = 0; ii < count; ii++) {
                String line = br.readLine();
                String[] tmp = line.split(" ");
                int[] values = new int[tmp.length];
                for (int i = 0; i < tmp.length; i++) {
                    values[i] = Integer.valueOf(tmp[i]);
                }
                k = br.readLine();
                l = br.readLine();
                s = values[2];
                
                max = 0;
                total = 0;
                
                //System.out.println("Case #" + (ii+1) + ": " + df.format(solve("")));
                writer.println("Case #" + (ii+1) + ": " + df.format(solve("")));
            }
            
            br.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
    
}
