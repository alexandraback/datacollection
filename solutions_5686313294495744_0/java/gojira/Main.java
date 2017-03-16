import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = in.nextInt();
            String[][] entries = new String[n][2];
            for(int i = 0; i < n; i++) {
                entries[i][0] = in.next();
                entries[i][1] = in.next();
            }
            System.out.println("Case #" + t + ": " + solve(entries));
        }
    }

    static int solve(String[][] entries) {
        int n = entries.length;
        int[] most = new int[1 << n];
        for(int i = 0; i < 1 << n; i++) {
            for(int j = 0; j < n; j++) {
                if (((1 << j) & i) > 0) continue;
                boolean fakeFirst = false;
                boolean fakeSecond = false;
                for(int k = 0; k < n; k++) {
                    if (((1 << k) & i) == 0) continue;
                    if (entries[j][0].equals(entries[k][0])) fakeFirst = true;
                    if (entries[j][1].equals(entries[k][1])) fakeSecond = true;
                }
                int fake = fakeFirst && fakeSecond ? 1 : 0;
                most[i | (1 << j)] = Math.max(most[i | (1 << j)], most[i] + fake);
            }
        }
        return most[(1 << n) - 1];
    }

}