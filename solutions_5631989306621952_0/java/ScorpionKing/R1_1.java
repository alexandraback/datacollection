package google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class R1_1 {
    public R1_1() {
        super();
    }
    
    private static String convert(String line) {
        
        
        StringBuilder sb = new StringBuilder();
        sb.append(line.charAt(0));
        int l = line.length();
        
        for(int i=1;i<l;i++)
            if(line.charAt(i)>=sb.charAt(0))
                sb.insert(0, line.charAt(i));
            else
                sb.append(line.charAt(i));
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2016\\A.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2016\\A.out"));

            //... Loop as long as there are input lines.
            String line = null;
            reader.readLine();
            int i=1;
            
            while ((line=reader.readLine()) != null) {
                writer.write("Case #"+i+": "+convert(line));
                writer.newLine();   // Write system dependent end of line.
                i++;
            }

            //... Close reader and writer.
            reader.close();  // Close to unlock.
            writer.close();  // Close to unlock and flush to disk.

    }
        catch(Exception ex) {
            ex.printStackTrace();
        }
    }
}
