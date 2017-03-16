
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class A {

    String PATH = "C:\\Users\\XiaoweiChen\\Desktop\\Jam\\";
    String inPath = PATH + "A-small-attempt2.in";
    String outPath = PATH + "A-small-attempt2.out";
    BufferedReader reader = null;
    BufferedWriter writer = null;
    StringTokenizer tokenizer = null;

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String ns() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    String nline() throws IOException {
        tokenizer = null;
        return reader.readLine();
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        new A().solve();
    }

    public A() throws FileNotFoundException, IOException {
        reader = new BufferedReader(new FileReader(inPath));
        writer = new BufferedWriter(new FileWriter(outPath));
    }

    public void solve() throws IOException {
        java.text.DecimalFormat myformat = new java.text.DecimalFormat();
        myformat.setMaximumFractionDigits(6);
        myformat.setMinimumFractionDigits(1);
        int round = ni();
        for (int ccase = 1; ccase <= round; ccase++) {
            int n = ni();
            int number[] = new int[n];
            long sum = 0;
            
            for (int i = 0; i < n; i++) {
                number[i] = ni();
                sum += number[i];
                
            }
            float mu = sum * 2 / n;
            float percent[] = new float[n];
            

            boolean flag = true;
            ArrayList exclude = new ArrayList();
            float fmean = 0;
            while(flag) {
                float mean = 2*sum;
                for(int i=0; i <exclude.size(); i++) {
                    mean -= number[(Integer)exclude.get(i)];
                }
                mean = mean / (n-exclude.size());
                
                boolean finished = true;
                for(int i = 0; i <n; i++) {
                    if(!exclude.contains(i) && number[i] > mean) {
                        percent[i] = 0;
                        exclude.add(i);
                        finished = false;
                        break;
                    }
                }
                if(finished) {
                    flag = false;
                    fmean = mean;
                }
            }
            
            for(int i = 0; i <n; i++) {
                if(!exclude.contains(i)) {
                    percent[i] = 100f *(fmean - number[i])/sum;
                }
            }


            StringBuilder s = new StringBuilder();
            s.append(myformat.format(percent[0]));
            for (int i = 1; i < n; i++) {
                s.append(" ");
                s.append(myformat.format(percent[i]));
            }

            String print = "Case #" + ccase + ": " + s.toString() + "\n";
            System.out.print(print);
            writer.write(print, 0, print.length());
        }
        writer.close();
    }

    
}
