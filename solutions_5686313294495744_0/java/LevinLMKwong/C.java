package gcj2016.roundOneA;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by LevinLMKwong on 1/5/16.
 */
public class C {
    private static class topic {
        String left = "";
        String right = "";
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            int N = in.nextInt();
            topic[] input = new topic[N];
            Map<String, Integer> word_left = new HashMap<>();
            Map<String, Integer> word_right = new HashMap<>();
            for (int i = 0; i < N; i++) {
                input[i] = new topic();
                input[i].left = in.next();
                input[i].right = in.next();
                if (word_left.containsKey(input[i].left)) {
                    word_left.put(input[i].left, word_left.get(input[i].left)+1);
                } else {
                    word_left.put(input[i].left, 1);
                }
                if (word_right.containsKey(input[i].right)) {
                    word_right.put(input[i].right, word_right.get(input[i].right)+1);
                } else {
                    word_right.put(input[i].right, 1);
                }
            }
            int ans = 0;
            for (int i = 0; i < N; i++) {
                if (word_left.get(input[i].left) > 1 && word_right.get(input[i].right) > 1) {
                    ans++;
                    word_left.put(input[i].left, word_left.get(input[i].left)-1);
                    word_right.put(input[i].right, word_right.get(input[i].right)-1);
                }
            }
            System.out.format("Case #%d: %d\n", t, ans);
        }
    }
}
