import java.io.IOException;

/**
 * Copyright - Arghya Sur
 * Created by sur on 4/9/16.
 */
public class QRC {
    public static void main(String[] args) throws IOException {

        java.io.BufferedReader r = new java.io.BufferedReader
                (new java.io.InputStreamReader (System.in));

        String line;
        int c = 0;
        int t = Integer.parseInt(r.readLine());

        while(t > 0) {
            line = r.readLine();
            String nj[] = line.split(" ");
            int n = Integer.parseInt(nj[0]);
            int j = Integer.parseInt(nj[1]);

            System.out.println("Case #1:");
            int m = n/2;
            long divisors[] = new long[9];
            for(int i = 2; i <= 10; i++) {
                divisors[i - 2] = (long)Math.pow(i, m) + 1;
            }
            for(int i = 0; i < j; i++) {
                String binaryStr = Integer.toBinaryString(i);
                int l = m - 2;
                if(binaryStr.length() < l) {
                    String prep = "";
                    for(int k = 0; k < l - binaryStr.length(); k++) {
                        prep = prep + "0";
                    }
                    binaryStr = prep + binaryStr;
                }
                String str = "1" + binaryStr + "1";
                str = str + str;
                String printStr = str;
                for(int k = 0; k < 9; k++) {
                    printStr = printStr + " " + divisors[k];
                }
                System.out.println(printStr);
            }
            t--;
            c++;
        }
    }
}
