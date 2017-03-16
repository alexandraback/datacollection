import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C_1A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("1A/C-small-1-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("1A/c.out"));
        in.nextInt();
        in.nextInt();
        in.nextInt();
        in.nextInt();
        in.nextInt();

        out.println("Case #1: ");
        for (int i = 0; i < 100; i++) {
            int[] k = new int[7];
            for (int j = 0; j < 7; j++) {
                k[j] = in.nextInt();
            }
            List<Integer> ans = new ArrayList<Integer>(3);
            for (int j = 0; j < 7; j++) {
                while (k[j] % 3 == 0) {
                    ans.add(3);
                    k[j] /= 3;
                }
            }
            for (int j = 0; j < 7; j++) {
                while (k[j] % 5 == 0) {
                    ans.add(5);
                    k[j] /= 5;
                }
            }
            Arrays.sort(k);
            if (ans.size() == 3) {
                out.println(ans.get(0) + "" + ans.get(1) + "" + ans.get(2));
            } else if (ans.size() == 2) {
                if (Arrays.binarySearch(k, 2) >= 0) {
                    out.println(ans.get(0) + "" + ans.get(1) + "" + 2);
                } else {
                    out.println(ans.get(0) + "" + ans.get(1) + "4");
                }
            } else {
                out.println("222");
            }
        }
        out.close();
    }
}
