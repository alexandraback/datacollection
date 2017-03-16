import java.io.*;
import java.math.BigInteger;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C {
    private Map<BigInteger, BigInteger> hash = new HashMap<BigInteger, BigInteger>();
    public static void main(String[] args) {
        C instance = new C();
        instance.hashAll();
        instance.start();
    }

    private void hashAll() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("TT.out"));
            String line = reader.readLine();
            while (line!=null && line.length() > 0){
                String[] strs = line.trim().split(";");
                hash.put(new BigInteger(strs[0]), new BigInteger(strs[1]));
                line = reader.readLine();
            }
            reader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void start() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("C-small.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("C-small.out"));
            String s = reader.readLine().trim();
            int t = Integer.parseInt(s);
            for(int i = 0; i < t; ++i){
                String[] strs = reader.readLine().trim().split(" +");
                BigInteger n = new BigInteger(strs[0]);
                BigInteger m = new BigInteger(strs[1]);

                int result = 0;
                for (Map.Entry<BigInteger, BigInteger> entry:hash.entrySet()) {
                      if(entry.getValue().compareTo(n) >= 0 && entry.getValue().compareTo(m)<= 0  ){
                              result++;
                      }

                }
                writer.write("Case #" + (i + 1) + ": " + result);
                if (i < t - 1) {
                    writer.write("\n");
                }
            }
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}