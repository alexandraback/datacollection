import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("A-large.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        int caseLength = in.nextInt();
        in.nextLine();

        for (int caseNumber = 1; caseNumber <= caseLength; caseNumber++) {
            int[] chars = new int[26];
            int[] answers = new int[10];
            char[] inputs = in.nextLine().toCharArray();

            for (char c : inputs) {
                chars[c - 'A']++;
            }

            System.out.println(Arrays.toString(chars));

            // 0
            answers[0] += chars[25];
            chars[4] -= answers[0];
            chars[14] -= answers[0];
            chars[17] -= answers[0];

            // 2
            answers[2] += chars[22];
            chars[14] -= answers[2];
            chars[19] -= answers[2];

            // 6
            answers[6] += chars[23];
            chars[8] -= answers[6];
            chars[18] -= answers[6];

            // 7
            answers[7] += chars[18];
            chars[21] -= answers[7];
            chars[13] -= answers[7];
            chars[4] -= answers[7] * 2;

            // 8
            answers[8] += chars[6];
            chars[19] -= answers[8];
            chars[7] -= answers[8];
            chars[8] -= answers[8];
            chars[4] -= answers[8];

            // 3
            answers[3] += chars[19];
            chars[17] -= answers[3];
            chars[7] -= answers[3];
            chars[4] -= answers[3] * 2;

            // 4
            answers[4] += chars[20];
            chars[17] -= answers[4];
            chars[14] -= answers[4];
            chars[5] -= answers[4];

            // 5
            answers[5] += chars[21];

            // 1
            answers[1] += chars[14];

            // 9
            answers[9] += (chars[13] - answers[1]) / 2;

            out.write(String.format("Case #%d: ", caseNumber));

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < answers[i]; j++) {
                    out.write(String.valueOf(i));
                }
            }

            out.newLine();
        }

        out.close();
    }
}
