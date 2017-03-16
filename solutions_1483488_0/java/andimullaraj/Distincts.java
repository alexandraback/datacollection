import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Distincts {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("input7.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("output1.txt"));
        int cases = Integer.parseInt(reader.readLine());
        
        for (int cs = 1; cs <= cases; cs++) {
            String line = reader.readLine();
            String[] tokens = line.split(" ");
            
            int count = 0;
            for (int i = Integer.parseInt(tokens[0]); i <= Integer.parseInt(tokens[1]); i++) {
                count += getGreaterRecycles(i, Integer.parseInt(tokens[1]));
            }
            writer.write("Case #" + cs + ": " + count + "\r\n");
        }
        
        writer.close();
    }
    
    static int getGreaterRecycles(int number, int max) {
        String ns = number + "";
        Set<Integer> result = new HashSet<Integer>();
        for (int i = 0; i < ns.length() - 1; i++) {
            ns = ns.substring(ns.length() - 1) + ns.substring(0, ns.length() - 1);
            int nr = Integer.parseInt(ns);
            if (nr > number && nr <= max) {
                result.add(nr);
            }
        }
        return result.size();
    }
}
