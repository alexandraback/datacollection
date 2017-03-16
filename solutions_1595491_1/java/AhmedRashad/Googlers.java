
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Googlers {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));

        int T = Integer.parseInt(in.readLine());


        for (int q = 1; q <= T; q++) {

            StringTokenizer st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken());
            int S = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            int SurCount = 0;
            int[] sum = new int[N];
            int res = 0;
            for (int i = 0; i < sum.length; i++) {
                sum[i] = Integer.parseInt(st.nextToken());
                if (sum[i] >= 2 && (sum[i] + 1) % 3 == 0 && (sum[i] + 1) / 3 >= P) {
                    res++;
                } else if (sum[i] >= 1 && (sum[i] + 2) % 3 == 0 && (sum[i] + 2) / 3 >= P) {
                    res++;
                } else if (sum[i] % 3 == 0) {
                    if (sum[i] / 3 >= P) {
                        res++;
                    } else if (sum[i] >= 3  && SurCount < S && (sum[i] + 3) / 3 >= P) {
                        res++;
                        SurCount++;
                    }
                
                } else if (sum[i] >= 2 && (sum[i] + 4) % 3 == 0 && SurCount < S && (sum[i] + 4) / 3 >= P) {
                    res++;
                    SurCount++;
                }
            //    System.out.println(i + " : " + res + " : " + SurCount);



            }
            out.write("Case #" + q + ": " + res + "\n");
           // System.out.println("BE");

        }
        out.close();
    }
}
