/**
 * Created with IntelliJ IDEA.
 * User: den
 * Date: 5/4/13
 * Time: 6:55 PM
 * To change this template use File | Settings | File Templates.
 */


import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskC extends Thread {
    private void solve() throws IOException {
        int T = _int();
        for (int t=1; t<=T; t++){
            int answer = 0;
            int ar = _int();
            int N = _int();
            int[] a = new int[N];
            for (int i =0; i<N; i++){
                a[i] = _int();
            }
            Arrays.sort(a);

            long sum = ar;

            int added = 0;
            int deleted = N;
            int min = N;

            if (ar == 1){
                out.println("Case #" + t + ": " + min);
                continue;
            }
            int i=0;
            while (i < N){
                if (a[i] < sum){
                    sum += a[i];
                    deleted--;
                } else{
                    sum += sum-1;
                    added++;
                    i--;
                }
                if (min > added + deleted){
                    min = added + deleted;
                }
                i++;
            }

            out.println("Case #" + t + ": " + min);
            out.flush();
        }
    }

    public void run() {
        try {
            solve();
        } catch (Exception e) {
            System.out.println("System exiting....");
            e.printStackTrace();
            System.exit(888);
        } finally {
            out.flush();
            out.close();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        new TaskC().run();
    }

    public TaskC() throws FileNotFoundException {
        in = new BufferedReader(new FileReader("A-large.in"));
        out = new PrintWriter(new File("A-large.out"));
//        in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);
        setPriority(Thread.MAX_PRIORITY);
    }

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    private int _int() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private double _double() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private long _long() throws IOException {
        return Long.parseLong(nextToken());
    }

    private char[] _chars() throws IOException {
        return nextToken().toCharArray();
    }

    private String nextToken() throws IOException {
        if (st == null || !st.hasMoreElements())
            st = new StringTokenizer(in.readLine(), " \t\r\n");
        return st.nextToken();
    }

//    private long bsearch(int left, int right, long value, long[] array){
//        if (left > right)
//            return -1;
//        int mid = left + (right - left)/2;
//        if (array[mid] == value){
//            return mid;
//        } else if (array[mid]<)
//    }
}

