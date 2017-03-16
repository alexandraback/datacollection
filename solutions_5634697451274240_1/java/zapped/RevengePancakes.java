/**
 * Created by iainws on 9/04/16.
 */

import java.io.*;
import java.util.StringTokenizer;

public class RevengePancakes {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        //InputStream inputStream = System.in;
        //OutputStream outputStream = System.out;
        InputStream inputStream = new FileInputStream(new File("./src/B-large.in"));
        OutputStream outputStream = new FileOutputStream(new File("./src/B-large.out"));
        InputReaderRevengePancakes in = new InputReaderRevengePancakes(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskRevengePancakes solver = new TaskRevengePancakes();
        solver.solve(1, in, out);
        out.close();
    }
}
class TaskRevengePancakes {
    public int answer(String S){
        int cnt = 0;
        for(int i=S.length() - 1;i >= 0; i--){
            if(cnt%2==0 && S.charAt(i) == '-')cnt++;
            else if(cnt%2!=0 && S.charAt(i) == '+')cnt++;
        }
        return cnt;
    }
    public void solve(int taskNumber, InputReaderRevengePancakes in, PrintWriter out) {
        int T = in.nextInt();
        for(int times = 1; times <= T; ++times){
            String S = in.next();
            out.println("Case #" + times + ": " + answer(S));
        }
    }
}
class InputReaderRevengePancakes {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReaderRevengePancakes(InputStream stream) {
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