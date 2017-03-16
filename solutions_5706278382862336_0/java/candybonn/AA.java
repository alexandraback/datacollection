import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;

import java.io.FileNotFoundException;
import java.io.IOException;

import java.util.StringTokenizer;

public class AA {
    private Pipe pipe = null;
    
    public AA(String args[]) throws FileNotFoundException, IOException {
        this.pipe = new Pipe(args);
    }

    public static void main(String args[]) throws FileNotFoundException, IOException {
        new AA(args).start();    
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
        String input = pipe.nline();
        String v[] = input.split("/");
        int p = Integer.parseInt(v[0]);
        int q = Integer.parseInt(v[1]);
        
        String res = count(p, q, 0);
        if(res.equals("impossible")) {
            return "impossible";
        } else {
            int i = 0;
            while(p < q && i <= 40) {
                p = p*2;
                i++;
            }
            return ""+i;
        }
        
    }

    private String count(int p, int q, int i) {
        while(p < q && i <= 40) {
            p = p*2;
            i++;
        }
        
        p = p - q;
        if(p == 0 && i <= 40) {
            return "" + i;
        } else if(p != 0 && i <= 40) {
            return count(p, q, i);
        } else {
            return "impossible";
        }
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
