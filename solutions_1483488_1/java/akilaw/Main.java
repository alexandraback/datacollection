/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author akila
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        ArrayList<String> testCases = new ArrayList<String>();
        boolean isCaseNo = true;
        int testCount = 0;
        FileReader fr = new FileReader("C-large.in");
        BufferedReader br = new BufferedReader(fr);
        String s;

        while ((s = br.readLine()) != null) {
            if (isCaseNo) {
                testCount = Integer.parseInt(s);
                isCaseNo = false;
            } else {
                testCases.add(s);
            }
        }
        fr.close();
        Solve(testCount, testCases);
    }

    public static void Solve(int testCount, ArrayList<String> testCases) throws IOException {


        FileWriter fstream = new FileWriter("out.txt");
        BufferedWriter out = new BufferedWriter(fstream);

        for (int i = 0; i < testCount; i++) {
            int A = 0, B = 0, count = 0;
            String s = testCases.get(i);
            String[] ar = s.split(" ");
            A = Integer.parseInt(ar[0]);
            B = Integer.parseInt(ar[1]);

            for(int j = A; j <= B; j++) {
                ArrayList<NumberPair> nums = new ArrayList<NumberPair>();
                String num = String.valueOf(j);
                for(int k =0; k < num.length(); k++) {
                    String num1 = num.substring(0, k);
                    String num2 = num.substring(k, num.length());

                    String newNum = num2 + num1;
                    int newI = Integer.parseInt(newNum);

                    NumberPair np = new NumberPair(j, newI);
                    if (newI >= A && newI <= B 
                            && newNum.equals(String.valueOf(newI))
                            && !num.equals(newNum)
                            && !nums.contains(np)) {
                        count++;
                        nums.add(np);
                    }                       
                }
            }

            out.write("Case #" + (i + 1) + ": " + count/2 + "\n");
        }
        out.close();
    }
}

class NumberPair {
   int m, n;

    public NumberPair(int m, int n) {
        this.m = m;
        this.n = n;
    }
  
    @Override
    public boolean equals(Object obj) {
        NumberPair np = (NumberPair)obj;
        return (np.m == this.m && np.n == this.n) || (np.m == this.n && np.n == this.m);
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 61 * hash + this.m;
        hash = 61 * hash + this.n;
        return hash;
    }

}
