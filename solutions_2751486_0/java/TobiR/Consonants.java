/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam.Round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Consonants {
    public static void main(String[] args) throws IOException {
        String filename = "input/A-small.in";
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename.substring(0, filename.length()-3)+ ".out"));
        
        int T = Integer.parseInt(reader.readLine());
        for (int i = 0; i < T; i++) {
            String[] line = reader.readLine().split(" ");
            String name = line[0];
            int n = Integer.parseInt(line[1]);
            
                        
            writer.write("Case #" + (i+1) + ": " + calcNValue(name, n)+ "\n");
        }
        writer.flush();
    }

    private static int calcNValue(String name, int n) {
        int v = 0;
        
        for (int i = 0; i < name.length()+1; i++) {
            for (int j = i; j < name.length()+1; j++) {
                if (calcCons(name.substring(i, j)) >= n)
                    v++;
            }
        }
        
        return v;
    }
    
    private static int calcCons(String str)
    {
        int consmax = 0;
        int conscurr = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                if (conscurr > consmax) consmax = conscurr;
                conscurr = 0;
            } else {
                conscurr++;
            }
        }
        
        return Math.max(consmax, conscurr);
        
    }
    
}
