import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class A {

    private static List<Integer>[] m;

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("a.in")));
        PrintStream out = new PrintStream(new FileOutputStream("a.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String ans = "Draw";
            String[] board = new String[4];
            String[] v = new String[4];
            String d1 = "";
            String d2 = "";
            List<String> lines = new ArrayList<String>();
            for (int i = 0; i < board.length; i++) {
                board[i] = in.readLine();
                lines.add(board[i]);
                v[i] = "";
            }
            in.readLine();
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board.length; j++) {
                    v[i] += board[j].charAt(i);
                }
                d1 += board[i].charAt(i);
                d2 += board[i].charAt(3 - i);
            }
            for (int i = 0; i < board.length; i++) {
                lines.add(v[i]);
            }
            lines.add(d1);
            lines.add(d2);

            for (String line : lines) {
                int score = score(line);
                if (score < 0) {
                    ans = "Game has not completed";
                    continue;
                }
                if (score < 300) {
                    ans = "O won";
                    break;
                }
                if (score % 239 == 0) {
                    ans = "X won";
                    break;
                }
            }

            out.print("Case #" + (cas + 1) + ": ");
            out.print(ans);
            out.println();
        }
        out.flush();
        out.close();
    }

    static int score(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            switch (ch) {
                case '.':
                    ans += -1000000;
                    break;
                case 'T':
                    ans += 239;
                    break;
                case 'O':
                    ans += 1;
                    break;
                case 'X':
                    ans += 239 * 11;
                    break;
            }
        }
        return ans;
    }

    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
