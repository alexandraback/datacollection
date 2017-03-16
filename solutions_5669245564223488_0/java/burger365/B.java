import java.io.*;
import java.util.Scanner;

/**
 * Created by burger on 5/11/14.
 */
public class B {
    boolean[][] isConnected;
    boolean[] has, visited;
    public void dfs(int c) {
        System.out.print((char)(c + 'a'));
        visited[c] = true;
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && isConnected[c][i])
                dfs(i);
        }
    }

    public int solve(int N, String[] trains) {
        final int MOD = 1000000007;

        int[] numTrains = new int[26];
        isConnected = new boolean[26][26];
        has = new boolean[26];
        visited = new boolean[26];

        boolean[] hasSuffix = new boolean[26];
        boolean[] hasPrefix = new boolean[26];
        boolean[] inMiddle = new boolean[26];
        boolean[] checked = new boolean[trains.length];

        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < trains.length; i++) {
                String s = trains[i];

                if (checked[i] || !s.contains(String.valueOf(c))) continue;
                checked[i] = true;

                for (int j = 0; j < s.length(); j++) {
                    for (int k = j + 1; k < s.length(); k++) {
                        int ji = s.charAt(j) - 'a';
                        int ki = s.charAt(k) - 'a';
                        isConnected[ji][ki] = isConnected[ki][ji] = true;
                    }
                }

                int index = c - 'a';
                if (inMiddle[index]) return 0;

                char lastChar = 'z' + 1;
                boolean[] hasChar = new boolean[26];
                boolean single = true;
                for (int j = 0; j < s.length(); j++) {
                    int charIndex = s.charAt(j) - 'a';
                    has[charIndex] = true;

                    if (s.charAt(j) != c) {
                        single = false;
                        if (j == 0) {
                            if (hasPrefix[charIndex]) return 0;
                            hasPrefix[charIndex] = true;
                        }
                        else if (j == s.length() - 1) {
                            if (hasSuffix[charIndex]) return 0;
                            hasSuffix[charIndex] = true;
                        }
                    }

                    // Pattern like "aacaa"
                    if (lastChar != s.charAt(j) && lastChar != s.charAt(0) && j - 1 > 0) {

                        if (inMiddle[lastChar - 'a']) return 0;
                        inMiddle[lastChar - 'a'] = true;
                    }

                    // Pattern like "cac"
                    if (s.charAt(j) != lastChar && hasChar[charIndex]) return 0;
                    hasChar[charIndex] = true;
                    lastChar = s.charAt(j);
                }
                if (single)
                    numTrains[index]++;
                else {
                    if (s.charAt(0) == c && hasPrefix[index]) return 0;
                    if (s.charAt(s.length() - 1) == c && hasSuffix[index]) return 0;
                }
            }
        }

        int numSets = 0;
        for (int i = 0; i < 26; i++)
            if (has[i] && !visited[i]) {
                numSets++;
                dfs(i);
                System.out.println();
            }

        for (int i = 0; i < 26; i++)
            if (numTrains[i] > 0)
                System.out.println((char)('a' + i) + " = " + numTrains[i]);
        System.out.println("numSets = " + numSets);

        long res = 1;
        for (int p : numTrains)
            while (p > 0) res = (res * p--) % MOD;
        while (numSets > 0)
            res = (res * numSets--) % MOD;

        return (int)res;
    }

    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("small.in");
            //inputStream = new FileInputStream("sample.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("answer.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            in.nextLine();
            String[] trains = in.nextLine().split(" ");
            out.write("Case #" + t + ": " + new B().solve(N, trains) + "\n");
        }

        out.close();
    }
}
