import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Deer {

    static class Pair {
        final int left, right;

        Pair(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")))) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int t = sc.nextInt();
                List<Pair> pairs = new ArrayList<>();
                for (int j = 0; j < t; j++) {
                    int a = sc.nextInt();
                    int b = sc.nextInt();
                    int c = sc.nextInt();
                    for (int k = 0; k < b; k++) {
                        pairs.add(new Pair(a, c + k));
                    }
                }
                String answer = "Case #" + (i + 1) + ": " + solve(pairs);
                bw.write(answer);
                bw.newLine();
                System.out.println(answer);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int solve(List<Pair> pairs) {
        int n1 = pairs.get(0).left;
        int s1 = pairs.get(0).right;
        int n2 = pairs.get(1).left;
        int s2 = pairs.get(1).right;
        if (s1 == s2) {
            return 0;
        }
        boolean isBig = (360 - (n1 - n2)) / (s1 - s2) > 0;
        return isBig | (360 - (n2 - n1)) / (s2 - s1) > 0 ? 0 : 1;
    }
}
