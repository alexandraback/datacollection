
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.StringTokenizer;

public class BB {
    private Pipe pipe = null;
    
    public BB(String args[]) throws FileNotFoundException, IOException {
        this.pipe = new Pipe(args);
    }

    public static void main(String args[]) throws FileNotFoundException, IOException {
        new BB(args).start();    
    }
   
    public void start() throws FileNotFoundException, IOException {
        int roundCount = pipe.ni();
        for(int round = 1; round <= roundCount; round++) {
            String result = solve();
            String outStr = "Case #" + round + ": " + result + "\n";
            pipe.print(outStr);
//            pipe.nline();
        }
        pipe.close();
    }
    
    public String solve() throws IOException {
        double C = pipe.nd();
        double f = pipe.nd();
        double X = pipe.nd();
        
        int n = 0;
        double minT = Double.POSITIVE_INFINITY;
        while(true) {
            double t = probe(n, C, f, X);
            if(t < minT) {
                minT = t;
                n++;
            } else {
                break;
            }
        }
        NumberFormat formatter = new DecimalFormat("#0.0000000");
        return formatter.format(minT);
    }

    private double probe(int n, double C, double f, double X) {
        double sum = 0; 
        for(int i = 0; i < n; i++) {
            sum += C/(2+i*f);
        }
        sum += X/(2+n*f);
        return sum;
    }

    
    private class Pipe {
        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Pipe(String args[]) throws FileNotFoundException, IOException {
            if(args != null && args.length >= 1) {
                reader = new BufferedReader(new FileReader(args[0]));
                if(args.length == 2) {
                    writer = new BufferedWriter(new FileWriter(args[1]));
                }
            } else {
                reader = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        public String nline() throws IOException {
            tokenizer = null;
            return reader.readLine();
        }

        public String ns() throws IOException {
            while(tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();            
        }

        public int ni() throws IOException {
            return Integer.parseInt(ns());
        }

        public long nl() throws IOException {
            return Long.parseLong(ns());
        }

        public float nf() throws IOException {
            return Float.parseFloat(ns());
        }

        public double nd() throws IOException {
            return Double.parseDouble(ns());
        }

        public void print(String str) throws IOException {
            System.out.print(str);
            if(writer != null) {
                writer.write(str, 0, str.length());
            }
        }

        public void close() throws IOException {
            if(writer != null) {
                writer.close();
            }
        }
    }
}
