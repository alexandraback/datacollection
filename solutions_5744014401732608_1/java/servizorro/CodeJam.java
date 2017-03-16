import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Pavel
 * Date: 09.04.2016
 * Time: 17:26
 */
public class CodeJam {



    public static void main(String[] argv) {
        System.out.println("Run");

        Scanner scanner = new Scanner(System.in);

        int count = scanner.nextInt();

        //int i = 1;

        for (int i = 1; i <= count; i++) {

            System.out.println("Case #" + i + ": " + getResult(scanner.nextInt(), scanner.nextLong()));
        }
    }


    private static String getResult(int size, long target) {
        String ret = "";



        long maxCount = 1 << size - 2;

        if (target > maxCount)
            return "IMPOSSIBLE";

        long mask = target << 1;

        int[][] matrix = new int[size][size];

        for (int i = 0; i < matrix.length; i++) {
            for (int j = i + 1; j < matrix.length; j++) {
                matrix[i][j] = 1;
            }
        }

        if (target == maxCount) {
            for (int i = 1; i < matrix.length; i++) {
                matrix[0][i] = 1;
            }
        } else
            for (int i = 0; i < matrix.length; i++) {
                matrix[0][i] = (int) ((mask >> (matrix.length - i - 1)) & 1);
            }

        ret = "POSSIBLE\n";

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
               ret+=matrix[i][j];
            }
            if (i != matrix.length - 1)
                ret+="\n";
        }

        return ret;
    }

}
