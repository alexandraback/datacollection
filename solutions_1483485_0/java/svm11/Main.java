import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("SpeakingInTongues-Small.out"));

        SpeakingInTongues solver = new SpeakingInTongues();
        int testCases = Integer.parseInt(in.nextLine());
        for (int i = 1; i <= testCases; ++i) {
            solver.solve(i, in, out);
        }

        in.close();
        out.close();
    }
}

class SpeakingInTongues {
    final int MAX_CHARACTERS = 26;
    char[] mappingFromGtoS = new char[MAX_CHARACTERS];

    public SpeakingInTongues() {
        String[] S = {"q", "a zoo", "our language is impossible to understand",
                "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
        String[] G = {"z", "y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};

        Arrays.fill(mappingFromGtoS, '$');
        for (int i = 0; i < G.length; ++i) {
            for (int j = 0; j < G[i].length(); ++j) {
                if (G[i].charAt(j) == ' ') continue;
                mappingFromGtoS[G[i].charAt(j) - 'a'] = S[i].charAt(j);
            }
        }
    }

    public String convertFromGtoS(String G) {
        String S = "";
        for (int i = 0; i < G.length(); ++i) {
            S += G.charAt(i) == ' ' ? ' ' : mappingFromGtoS[G.charAt(i) - 'a'];
        }
        return S;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        String G = in.nextLine();
        String S = convertFromGtoS(G);
        out.println("Case #" + testNumber + ": " + S);
    }
}
