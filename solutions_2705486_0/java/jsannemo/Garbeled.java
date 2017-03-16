package gcj13.oneb;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

/**
 *
 * @author Johan Sannemo
 */
public class Garbeled {

    static TrieNode root = new TrieNode(null);

    public static void main(String[] args) throws FileNotFoundException, IOException {
        System.setIn(new FileInputStream("C:\\Users\\Johan Sannemo\\Downloads\\C-small-attempt0.in"));
        System.setOut(new PrintStream("C:\\Users\\Johan Sannemo\\Downloads\\C-small.out"));
        BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\Johan Sannemo\\Downloads\\dictionary.txt"));

        int maxLen = 0;
        String word;
        while ((word = reader.readLine()) != null) {
            addWord(word);
            maxLen = Math.max(maxLen, word.length());
        }
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; ++i) {
            s = sc.next();
            dp = new int[s.length()][6][12];
            System.out.println("Case #" + i + ": " + dp(0, 5, 0, root));
        }
    }
    static String s;
    static int[][][] dp;

    public static int dp(int at, int lastChange, int progress, TrieNode node) {
        if (at == s.length()) {
            return 0;
        }
        if (at + progress >= s.length()) {
            return 1000000;
        }
        if (lastChange > 5) {
            lastChange = 5;
        }
        if (progress == 0 && dp[at][lastChange][progress] != 0) {
            return dp[at][lastChange][progress] - 1;
        }
        int best = 1000000;
        char ch = s.charAt(at + progress);
        if (node.children != null && node.children.containsKey(ch)) {
            //No change
            best = Math.min(best, dp(at, lastChange + 1, progress + 1, node.children.get(ch)));
            //End the word
            if (node.children.get(ch).leaf) {
                best = Math.min(best, dp(at + progress + 1, lastChange + 1, 0, root));
            }
        }
        if (lastChange == 5 && node.children != null) {
            for (Entry<Character, TrieNode> child : node.children.entrySet()) {
                best = Math.min(best, dp(at, 1, progress + 1, child.getValue()) + 1);
                if(child.getValue().leaf)
                    best = Math.min(best, dp(at + progress + 1, 1, 0, root) + 1);
            }
        }
        if (progress == 0) {
            dp[at][lastChange][progress] = best + 1;
        }
        return best;
    }

    public static void addWord(String word) {
        TrieNode at = root;
        for (int i = 0; i < word.length(); ++i) {
            at = at.get(word.charAt(i));
        }
        at.leaf = true;

    }

    static class TrieNode {

        TrieNode parent;
        HashMap<Character, TrieNode> children;
        boolean leaf;

        public TrieNode(TrieNode parent) {
            this.leaf = false;
            this.parent = parent;
        }

        public TrieNode get(char ch) {
            if (children == null) {
                children = new HashMap<>();
            }
            if (!children.containsKey(ch)) {
                children.put(ch, new TrieNode(this));
            }
            return children.get(ch);
        }
    };
}
