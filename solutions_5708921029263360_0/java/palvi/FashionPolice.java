import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by pallavi on 8/5/16.
 */
public class FashionPolice {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter writer = new PrintWriter("out.txt");
        int t = scanner.nextInt();
        for (int i = 1; i <= t; i++) {
            writer.print("Case #" + i + ": ");
            int j = scanner.nextInt();
            int p = scanner.nextInt();
            int s = scanner.nextInt();
            int k = scanner.nextInt();
            writer.println((long) Math.min(j, k) * p * Math.min(s, k));
            int ln = Math.min(j, k);
            List<Integer> list = new ArrayList<>();
            for (int ll = 0; ll < s*k; ll++) {
                list.add(ll%s + 1);
            }
            for (int m = 1; m <= p; m++) {
                int nn = Math.min(s, k);
                for (int n = 0; n < nn; n++) {
                    int pn = list.remove(0);
                    for (int l = 1; l <= ln; l++) {
                        writer.println(l + " " + m + " " + pn);
                    }
                }
            }
        }
        writer.close();
        scanner.close();
    }
}
