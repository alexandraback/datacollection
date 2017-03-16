/**
 * Created by iainws on 9/04/16.
 */
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
public class CoinJam {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        //InputStream inputStream = System.in;
        //OutputStream outputStream = System.out;
        InputStream inputStream = new FileInputStream(new File("./src/C-small-attempt0.in"));
        OutputStream outputStream = new FileOutputStream(new File("./src/C-small-attempt0.out"));
        InputReaderCoinJam in = new InputReaderCoinJam(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskCoinJam solver = new TaskCoinJam();
        solver.solve(1, in, out);
        out.close();
    }
}
class TaskCoinJam {
    public String first(int N){
        int [] arr = new int[N];
        for(int i=0;i<N;++i){
            arr[i]=0;
        }
        arr[0]=1;
        arr[N-1]=1;
        String t = "";
        for(int i=0;i<N;i++){
            if(arr[i]==0){
                t+='0';
            }
            else t+='1';
        }
        return t;
    }
    public String last(int N){
        String s="";
        for(int i=0;i<N;++i){
            s+='1';
        }
        return s;
    }
    public boolean isJamCoin(long N){
        String s = Long.toString(N, 2);
        if(s.charAt(0)=='1' && s.charAt(s.length() - 1) == '1')return true;
        else return false;
    }
    public void solve(int taskNumber, InputReaderCoinJam in, PrintWriter out) {
        //Integer t = Integer.parseInt("1001", 9);
        int T = in.nextInt();
        for(int times = 1; times <= T; ++times) {
            int N = in.nextInt();
            int J = in.nextInt();
            int start = Integer.parseInt(first(N), 2);
            int end = Integer.parseInt(last(N), 2);
            int cnt = 0;
            out.println("Case #1:");
            while (cnt < J) {
                for (int i = start; i <= end; ++i) {
                    if (!isJamCoin(i)) continue;
                    String coin = Long.toString(i, 2);
                    boolean okay = true;
                    for (int j = 2; j <= 10; ++j){
                        Long t = Long.parseLong(coin, j);
                        BigInteger tp = new BigInteger(t.toString());
                        if(tp.isProbablePrime(1)==true)okay=false;
                    }
                    if (okay) {
                        out.print(coin + " ");
                        for (int j = 2; j <= 10; ++j) {
                            Long t = Long.parseLong(coin, j);
                            for (int divisor = 2; divisor < t; ++divisor) {
                                if (t % divisor == 0) {
                                    out.print(divisor + " ");
                                    break;
                                }
                            }
                        }
                        out.println();
                    }
                    else continue;
                    cnt++;
                    if (cnt >= J) return;
                }
            }
        }
    }
}

class InputReaderCoinJam {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReaderCoinJam(InputStream stream) {
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