package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class A {

    private static final String fname = "./tests/jam/A-large.in";

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(fname));
        BufferedWriter writer = new BufferedWriter(new FileWriter(fname + ".out"));
        int T = Integer.parseInt(reader.readLine());
        for (int t = 1; t <= T; t++) {
            String[] splits = reader.readLine().trim().split("[ ]");
            int A = Integer.parseInt(splits[0]);
            int B = Integer.parseInt(splits[1]);
            splits = reader.readLine().trim().split("[ ]");
            double[] ps = new double[A];
            for (int i = 0; i < splits.length; i++) {
                ps[i] = Double.parseDouble(splits[i]);
            }

            double[] backspace = new double[A+1];
            double allcorrect = 1.0d;
            for (int i = 0; i < A; i++) {
                allcorrect *= ps[i];
            }

            for (int i = 0; i < A+1; i++) {
                double allcorrecttilli = 1.0d;
                for (int j = 0; j < A-i; j++) {
                    allcorrecttilli *= ps[j];
                }
                backspace[i] = allcorrecttilli * (2 * i + (B - A) + 1) + (1 - allcorrecttilli) * (2 * i + (B - A) + 1 + B + 1);
//                System.out.println(backspace[i]);
            }

            double enterrightaway = (B+2) + allcorrect*(B-A == 0 ? 1 : 0);
//            System.out.println(enterrightaway);
            double answer = enterrightaway;
            for (int i =0; i < A; i++) {
                answer = Math.min(answer, backspace[i]);
            }
            writer.write("Case #" + t + ": " + answer + "\n");
//            System.out.println("---------");
        }
        reader.close();
        writer.close();
    }
}
