package at.jaki.round1B.B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class B {

    //private static final String INPUT = "B-large.in";
    private static final String INPUT = "B-small-attempt0.in";
    //private static final String INPUT = "B-test.in";
    //private static final String OUTPUT = "B-large.out";
    private static final String OUTPUT = "B-small-attempt0.out";
    //private static final String OUTPUT = "B-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] temp = br.readLine().split(" ");
            int a = Integer.parseInt(temp[0]);
            int b = Integer.parseInt(temp[1]);
            int k = Integer.parseInt(temp[2]);

            long res = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    int x = i & j;
                    if (x < k) res++;
                }
            }


            pw.print("Case #" + testNo + ": ");
            pw.println(res);

            System.out.println(res);
        }

        pw.flush();
        pw.close();

    }
}
