import java.io.*;
import java.util.Arrays;

public class TypewriterMonkey {
    public static void main(String[] args) throws Exception {
        String filename = "B-small-attempt0.in";
        File file = new File("/Users/tanin/Downloads/" + filename);
        File outFile = new File("/Users/tanin/Downloads/" + filename + ".out");
        BufferedReader br = new BufferedReader(new FileReader(file));
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
        int testCases = Integer.parseInt(br.readLine());
        for(int t=1;t<=testCases;t++){
            String[] tokens = br.readLine().split(" ");
            int K = Integer.parseInt(tokens[0]);
            int L = Integer.parseInt(tokens[1]);
            int S = Integer.parseInt(tokens[2]);

            char[] keys = br.readLine().toCharArray();
            char[] lword = br.readLine().toCharArray();

            double result = solve(S, keys, lword);
            String outputLine = "Case #" + t + ": " + result + "\n";

            System.out.print(outputLine);
            bw.write(outputLine);
        }
        br.close();
        bw.close();
    }

    private static double expectedGiveAwayBanana = 0.0;
    private static int maxBanana = 0;
    private static double solve(int S, char[] keys, char[] lword) {
        maxBanana = 0;
        expectedGiveAwayBanana = 0.0;

        char[] sword = new char[S];

        int numberOfAllPossibilities = 1;
        for (int i=0;i<S;i++) {
            numberOfAllPossibilities *= keys.length;
        }

        generate(0, sword, keys, lword, (double) numberOfAllPossibilities);

//        System.out.println(maxBanana);
//        System.out.println(expectedGiveAwayBanana);
        return (double) maxBanana - expectedGiveAwayBanana;
    }

    private static void generate(int index, char[] sword, char[] keys, char[] lword, double denominator) {
        if (index == sword.length) {
            int giveAwayBanana = 0;
            for (int s=0;s<=(sword.length - lword.length);s++) {
                boolean valid = true;
                for (int l=0;l<lword.length;l++) {
                    if (sword[s + l] != lword[l]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) { giveAwayBanana += 1; }
            }

            if (giveAwayBanana > maxBanana) { maxBanana = giveAwayBanana; }
            expectedGiveAwayBanana += (double) giveAwayBanana / denominator;
        } else {
            for (int k=0;k<keys.length;k++) {
                sword[index] = keys[k];
                generate(index + 1, sword, keys, lword, denominator);
            }
        }
    }


}
