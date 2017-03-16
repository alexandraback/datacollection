import java.io.*;

public class CounterCulture {

    private static int[] d = new int[1000001];

    public static void main(String[] args) throws Exception {

        d[1] = 1;
        for (int i=2;i<d.length;i++) {
            d[i] = d[i - 1] + 1;

            int reversedI = reverse(i);

            if (reversedI >= 1 && reversedI <= 1000000 && reversedI < i) {
                if ((d[reversedI] + 1) < d[i]) {
                    d[i] = d[reversedI] + 1;
                }
            }
        }

        String filename = "A-small-round1.in";
        File file = new File("/Users/tanin/Downloads/" + filename);
        File outFile = new File("/Users/tanin/Downloads/" + filename + ".out");
        BufferedReader br = new BufferedReader(new FileReader(file));
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
        int testCases = Integer.parseInt(br.readLine());
        for(int t=1;t<=testCases;t++){
            int N = Integer.parseInt(br.readLine());

            int result = d[N];
            bw.write("Case #" + t + ": " + result + "\n");
        }
        br.close();
        bw.close();
    }

    private static int reverse(int i) {
        if ((i % 10) == 0) { // not possible to reverse
            return -1;
        }

        int reversedI = 0;

        while (i > 0) {
            int digit = i % 10;
            i = i / 10;

            reversedI = reversedI * 10 + digit;
        }

        return reversedI;
    }
}
