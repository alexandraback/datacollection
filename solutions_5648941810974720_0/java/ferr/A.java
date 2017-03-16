import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Collectors;


public class A {
    static PrintWriter pw;
    static Scanner sc;

    public static void main(String[] args) {
        pw = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        new A().run();
        pw.flush();
    }

    private void run() {
        int T = sc.nextInt();
        for (int t = 0; t < T; ++t) {
            System.err.printf("Case %d of %d\n", t + 1, T);
            pw.printf("Case #%d: %s\n", t + 1, nextCase(t));
        }
    }

    List<String> words = Arrays.asList("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE");

    int CHARS = 26;

    char findUnique(List<String> names) {
        int[] qty = new int[CHARS];
        for (String name : names) {
            for (char c : name.toCharArray()) {
                qty[c - 'A']++;
            }
        }
        for (int i = 0; i < CHARS; ++i) {
            if (qty[i] == 1) {
                return (char)('A' + i);
            }
        }
        throw new RuntimeException();
    }

    private String nextCase(int caseNum) {
        String s = sc.next();
        int[] qty = new int[26];
        for (char c : s.toCharArray()) {
            qty[c - 'A']++;
        }
        List<String> names = words;
        List<Integer> res = new ArrayList<>();
        while (names.size() > 0) {
            char U = findUnique(names);
            String cand = names.stream().filter(x -> x.contains("" + U)).findFirst().get();
            int idx = words.indexOf(cand);
            while (qty[U - 'A'] > 0) {
                for (char c : cand.toCharArray()) {
                    qty[c - 'A']--;
                }
                res.add(idx);
            }
            names = names.stream().filter(x -> !x.equals(cand)).collect(Collectors.toList());
        }
        Collections.sort(res);
        StringBuilder ans = new StringBuilder();
        for (int x : res){
            ans.append(x);
        }
        return ans.toString();
    }
}