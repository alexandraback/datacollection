
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class TaskC {

    final static int[] nums = {
        1, 2, 3, 11, 22, 101, 111, 121, 202, 212,
        1001, 1111, 2002, 10001, 10101, 10201, 11011,
        11111, 11211, 20002, 20102, 100001, 101101, 
        110011, 111111, 200002, 1000001, 1001001, 
        1002001, 1010101, 1011101, 1012101, 1100011,
        1101011, 1102011, 1110111, 1111111, 2000002, 
        2001002, 10000001};
    final static String path = "data\\C-small.in";
    final static String output = "data\\C-small.out";
    static Scanner scanner;

    static int solve(long m) {
        int index = Arrays.binarySearch(nums, (int)(Math.sqrt(m)));
        if (index < 0) {
            index = -index - 1;
        } else {
            index++;
        }
        return index;
    }

    public static void main(String[] args)
            throws FileNotFoundException, IOException {
        scanner = new Scanner(new File(path));
        BufferedWriter out = new BufferedWriter(new FileWriter(output));
        int nTests = scanner.nextInt();
        for (int i = 1; i <= nTests; ++i) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            out.write("Case #" + i + ": " + (solve(b) - solve(a - 1)));
            out.newLine();
        }
        out.close();
        scanner.close();
    }
}