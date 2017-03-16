import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

import static java.util.Arrays.asList;

public class C {
    static String _tn = "C";
    static Scanner in = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    static class Trie {
        boolean end;
        HashMap<Character, Trie> nodes = new HashMap<>();
        Trie go(char c) {
            return nodes.get(c);
        }
    }

    static void insert(Trie trie, String w) {
        for (char c : w.toCharArray()) {
            if (trie.nodes.containsKey(c))
                trie = trie.nodes.get(c);
            else {
                Trie node = new Trie();
                trie.nodes.put(c, node);
                trie = node;
            }
        }
        trie.end = true;
    }

    static Trie trieroot = new Trie();
    static void pre() throws FileNotFoundException {
        Scanner in = new Scanner(new File("garbled_email_dictionary.txt"));
        while (in.hasNext()) {
            String w = in.next();
            insert(trieroot, w);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        pre();
        in = new Scanner(new File(_tn+".in"));
        out = new PrintWriter(new File(_tn+".out"));
        int T = in.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: %d\n", I + 1, solve());
            out.flush();
        }
        out.close();
    }
    static int  solve() {
        String s = in.next();
        int n = s.length();
        HashSet<Trie> dp[][][] = new HashSet[n+1][2+n/5][5];
        dp[0][0][0] = new HashSet(asList(trieroot));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1+(i+4) / 5; j++) {
                for (int k = 0; k < 5; k++) {
                    Set<Trie> cur = dp[i][j][k];
                    if (cur != null) {
                        Set<Trie> next = new HashSet<>();
                        // no changes:
                        for (Trie t : cur) {
                            Trie t1 = t.go(s.charAt(i));
                            if (t1 != null) {
                                next.add(t1);
                                if (t1.end)
                                    next.add(trieroot);
                            }
                        }
                        int kk = Math.max(0, k-1);
                        if (!next.isEmpty()) {
                            if (dp[i+1][j][kk]==null)
                                dp[i+1][j][kk] = new HashSet<>();
                            for (Trie t : next)
                                dp[i+1][j][kk].add(t);
                        }
                        if (k==0) {
                            next = new HashSet<>();
                            for (Trie t : cur) {
                                for (Map.Entry<Character, Trie> e : t.nodes.entrySet()) {
                                    if (e.getKey()!=s.charAt(i))
                                        next.add(e.getValue());
                                }
                            }
                            if (!next.isEmpty()) {
                                if (dp[i+1][j+1][4]==null)
                                    dp[i+1][j+1][4] = new HashSet<>();
                                for (Trie t : next)
                                    dp[i+1][j+1][4].add(t);
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < dp[n].length; j++)
            for (int k = 0; k < 5; k++)
                if (dp[n][j][k]!=null) {
                    for (Trie t : dp[n][j][k])
                        if (t.end)
                            return j;
                }
        System.exit(1);
        return -1;
    }
}
