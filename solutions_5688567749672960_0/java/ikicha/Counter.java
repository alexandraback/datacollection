import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Counter {

    public static void main(String[] args) {
        map.put(1, 1);
        try (Scanner sc = new Scanner(new File("input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")))) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                String answer = "Case #" + (i + 1) + ": " + solve(sc.nextInt());
                bw.write(answer);
                bw.newLine();
                System.out.println(answer);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static Map<Integer, Integer> map = new HashMap<>();

    private static int solve(int n) {
        if (map.containsKey(n)) {
            return map.get(n);
        }
        for (int i = 2; i <= n; i++) {
            if (map.containsKey(i)) {
                continue;
            }
            boolean canReverse = !divideBy10(i) && map.containsKey(reverse(i));
            map.put(i, Math.min(map.get(i - 1) + 1, canReverse ? map.get(reverse(i)) + 1 : Integer.MAX_VALUE));
        }
        return map.get(n);
    }

    private static boolean divideBy10(int n) {
        return n % 10 == 0;
    }

    private static int reverse(int n) {
        String reserveValue = new StringBuffer(String.valueOf(n)).reverse().toString();
        return Integer.parseInt(reserveValue);
    }

}
