/**
 * Created by iainws on 9/04/16.
 */

import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

public class CountingSheep {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReaderCountingSheep in = new InputReaderCountingSheep(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskCountingSheep solver = new TaskCountingSheep();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskCountingSheep {
    public void check(boolean [] arr, long N){
        long t=N;
        while(t!=0){
            int r=(int)(t%10);
            arr[r]=true;
            t/=10;
        }
    }
    public boolean ok(boolean [] arr){
        for(int i=0;i<10;++i){
            if(arr[i]==false)return false;
        }
        return true;
    }
    public long answer(int N){
        boolean arr [] = new boolean[10];
        for(int i=0;i<10;++i){
            arr[i] = false;
        }
        for(int i=1;i<=100000;++i){
            long t = N*i;
            check(arr, t);
            if(ok(arr)==true)return i*N;
        }
        return -1;
    }
    public void solve(int taskNumber, InputReaderCountingSheep in, PrintWriter out) {
        int T = in.nextInt();
        for(int times = 1; times <= T; ++times){
            int N = in.nextInt();
            if(N == 0){
                out.println("Case #" + times + ": INSOMNIA");
            }
            else{
                out.println("Case #" + times + ": " + answer(N));
            }
        }
    }
}
class InputReaderCountingSheep {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReaderCountingSheep(InputStream stream) {
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