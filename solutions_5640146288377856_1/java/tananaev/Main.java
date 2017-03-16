package p1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class Main {
    
    public static int solve(int r, int c, int w) {
        int result = (c / w) * r;
        result += (w - 1 - (c % w));
        if ((c % w) != 0) {
            result += 1;
        }
        result += c % w;
        return result;
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
                
                //System.out.println("Case #" + (ii+1) + ": " + solve(values[0], values[1], values[2]));
                writer.println("Case #" + (ii+1) + ": " + solve(values[0], values[1], values[2]));
            }
            
            br.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
    
}
