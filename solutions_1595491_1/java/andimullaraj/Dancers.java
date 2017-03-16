import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Dancers {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("input6.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("output1.txt"));
        int cases = Integer.parseInt(reader.readLine());
        
        for (int cs = 1; cs <= cases; cs++) {
            String line = reader.readLine();
            String[] tokens = line.split(" ");
            
            int i = 0;
            int n = Integer.parseInt(tokens[i++]);
            int surprises = Integer.parseInt(tokens[i++]);
            int p = Integer.parseInt(tokens[i++]);
            int count = 0;
            
            while (i < tokens.length) {
                int s = Integer.parseInt(tokens[i++]);
                if (p == 0) {
                    count++;
                    continue;
                }
                if (p == 1) {
                    if (s > 0) {
                        count++;
                    }
                    continue;
                }
                    
                if (p * 3 - 2 <= s) {
                    count++;
                } else if ((p * 3 - 4 <= s) && surprises > 0) {
                    count++;
                    surprises--;
                }
            }
            
            writer.write("Case #" + cs + ": " + count + "\r\n");
        }
        
        writer.close();
    }
}
