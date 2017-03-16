package codejam;

import java.util.*;

public class B {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        scanner.nextLine();
        for (int t = 1; t <= T; t++) {
            String solution = solve(scanner);
            System.out.println("Case #" + t + ": " + solution);
        }
    }

    private static String solve(Scanner scanner) {
        String S = scanner.nextLine();
        int N = (int) Math.pow(2, S.length());

        Map<String, Integer> distances = new HashMap<>(N);
        Queue<String> queue = new ArrayDeque<>(N);
        String target = "";

        for (int i = 0; i < S.length(); i++) {
            target += "+";
        }
        if (S.equals(target))
            return "0";

        queue.add(S);
        distances.put(S, 0);

        while (true) {
            String current = queue.poll();
            int distance = distances.get(current) + 1;

            for (String flip : flips(current)) {
                if (flip.equals(target))
                    return "" + (distance);

                Integer old = distances.get(flip);
                if (old == null || old > distance) {
                    distances.put(flip, distance);
                    queue.add(flip);
                }
            }
        }
    }

    private static String[] flips(String s) {
        String[] flips = new String[s.length()];
        for (int i = 0; i < s.length(); i++) {
            flips[i] = flip(s, i);
        }
        return flips;
    }

    private static String flip(String s, int f) {
        String flip = "";
        for (int i = f; i >= 0; i--) {
            String pancake = s.charAt(i) + "";
            flip += pancake.equals("+") ? "-" : "+";
        }
        flip += s.substring(f + 1);
        return flip;
    }

}
