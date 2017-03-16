package round3;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class pb1 {

    /**
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File(args[0]));
        BufferedWriter out = new BufferedWriter(new FileWriter(
                new File("output")));

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            String name = sc.next();
            int n = sc.nextInt();
            solveTest(out, name.toCharArray(), n, i + 1);
        }

        out.close();

    }

    private static void solveTest(BufferedWriter out, char[] name,
            int n, int usecase) throws IOException {

        int c1 = -1, c2 = 0, consec = 0, score = 0, nons = 0;

//        out.write(name + " ");

        for (int i = 0; i < name.length; i++) {

//            out.write("i = " + i + " score = " + score + ";");
            if (iscons(name[i])) {
                consec++;
            } else {
                consec = 0;
            }

            if (consec == n) {
                c1 = i - n + 1;
                score += (c1 + 1);
                consec--;
            } else {
                if (c1 != -1)
                    score += (c1 + 1);
            }

        }

        out.write("Case #" + usecase + ": " + score);
        out.newLine();

    }

    private static boolean iscons(char c) {

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return false;
        return true;
    }

}
