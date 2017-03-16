
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.text.ParseException;
import java.util.Arrays;

public class CodeJamD {

    public static void main(String[] args) throws FileNotFoundException, IOException, ParseException {
        CodeJamD jam = new CodeJamD();
        jam.solve("D-large.in");
    }

    public void solve(String file) throws FileNotFoundException, IOException, ParseException {
        File f = new File(file);
        FileReader fin = new FileReader(f);
        BufferedReader in = new BufferedReader(fin);
        int cases = Integer.parseInt(in.readLine());
        File outF = new File("resultsD_large.txt");
        PrintStream out = new PrintStream(outF);
        for (int i = 1; i <= cases; i++) {
            int blocks = Integer.parseInt(in.readLine());
            double[] p1 = new double[blocks];
            double[] p2 = new double[blocks];
            String[] p1Tokens = in.readLine().split(" ");
            String[] p2Tokens = in.readLine().split(" ");
            for (int j = 0; j < blocks; j++) {
                p1[j] = Double.parseDouble(p1Tokens[j]);
                p2[j] = Double.parseDouble(p2Tokens[j]);
            }
            Arrays.sort(p1);
            Arrays.sort(p2);
            int score1 = 0;
            int score2 = 0;
            int p2Counter = blocks - 1;
            int p1Counter;
            for (p1Counter = blocks - 1; p1Counter >= 0; p1Counter--) {
                if (p1[p1Counter] > p2[p2Counter]) {
                    score1++;
                } else {
                    p2Counter--;
                }
            }
            p2Counter = 0;
            for (p1Counter = 0; p1Counter < p1.length; p1Counter++) {
                if (p1[p1Counter] > p2[p2Counter]) {
                    score2++;
                    p2Counter++;
                }
            }
            out.println("Case #" + i + ": " + score2 + " " + score1);
        }
    }
}
