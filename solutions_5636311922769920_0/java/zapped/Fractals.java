/**
 * Created by iainws on 9/04/16.
 */

import java.io.*;
import java.util.StringTokenizer;

public class Fractals {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        //InputStream inputStream = System.in;
        InputStream inputStream = new FileInputStream(new File("./src/D-small-attempt0.in"));
        OutputStream outputStream = new FileOutputStream(new File("./src/D-small-attempt0.out"));
        InputReaderFractals in = new InputReaderFractals(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskFractals solver = new TaskFractals();
        solver.solve(1, in, out);
        out.close();
    }
}
class TaskFractals {
    public void solve(int taskNumber, InputReaderFractals in, PrintWriter out) {
           int T = in.nextInt();
           for(int times = 1; times <= T; ++times){
               int K = in.nextInt();
               int C = in.nextInt();
               int S = in.nextInt();
               String numbers = "";
               for(int i = 1; i <= K; ++i){
                   numbers += Integer.toString(i);
                   if(i!=K){
                       numbers += " ";
                   }
               }
               out.println("Case #" + times + ": " + numbers);
           }
    }
}

class InputReaderFractals {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReaderFractals(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}