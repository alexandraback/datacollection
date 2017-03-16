import java.util.Scanner;

public class CloseScores {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kase = 1, kases = scanner.nextInt(); kase <= kases; kase++) {
            String ss = "";
            while (ss.isEmpty()) {
                ss = scanner.nextLine();
            }
            String[] ab = ss.trim().split("\\s+");
            int bestDiff = 1000, bestA = 1000, bestB = 1000;
            final int mx = (int) Math.pow(10, ab[0].length());
            for (int i = 0; i < mx; i++) {
                for (int j = 0; j < mx; j++) {
                    if (fits(i, ab[0]) && fits(j, ab[1])) {
                        int diff = Math.abs(i - j);
                        if (diff < bestDiff ||
                            (diff == bestDiff && i < bestA) ||
                            (diff == bestDiff && i == bestA && j < bestB)) {
                            bestDiff = diff;
                            bestA = i;
                            bestB = j;
                        }
                    }
                }
            }

            String ansA = "" + bestA;
            while (ansA.length() < ab[0].length()) ansA = "0" + ansA;

            String ansB = "" + bestB;
            while (ansB.length() < ab[0].length()) ansB = "0" + ansB;

            System.out.println("Case #" + kase + ": " + ansA + " " + ansB);
        }
    }

    private static boolean fits(int number, String s) {
        String a = "" + number;
        while (a.length() < s.length()) a = "0" + a;
        for (int i = 0; i < a.length(); i++) {
            if (s.charAt(i) != '?' && s.charAt(i) != a.charAt(i))
                return false;
        }
        return true;
    }
}
