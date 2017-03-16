
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.text.NumberFormat;
import java.text.ParseException;


public class CodeJamB {
public static void main(String[] args) throws FileNotFoundException, IOException, ParseException {
        CodeJamB jam = new CodeJamB();
        jam.solve("B-large.in");
    }
    
    public void solve(String file) throws FileNotFoundException, IOException, ParseException {
        File f = new File(file);
        FileReader fin = new FileReader(f);
        BufferedReader in = new BufferedReader(fin);
        int cases = Integer.parseInt(in.readLine());
        File outF = new File("resultsB_large.txt");
        PrintStream out = new PrintStream(outF);
        for (int i = 1; i <= cases; i++) {
            String cur = in.readLine().replace(".", ",");
            String[] tokens = cur.split(" ");
            double rate = 2;
            double cost = NumberFormat.getInstance().parse(tokens[0]).doubleValue();
            double addedRate = NumberFormat.getInstance().parse(tokens[1]).doubleValue();
            double target = NumberFormat.getInstance().parse(tokens[2]).doubleValue();
            double time = 0;
            while(target / rate > cost / rate + target / (rate + addedRate)) {
                time += cost / rate;
                rate += addedRate;
            }
            time += target / rate;
            out.print("Case #" + i + ": ");
            out.println(time);
        }
    }
}
