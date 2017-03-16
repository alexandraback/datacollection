package B;

import jdk.internal.util.xml.impl.Pair;

import java.util.*;

public class Big {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            final int T = in.nextInt();
            for (int i = 0; i < T; i++) {
                System.out.printf("Case #%d: %d\n", i + 1, solve(in.next()));
            }
        }
    }

    private static int solve(String input) {
        final Map<String, Integer> distance = new HashMap<>();
        final Queue<String> q = new LinkedList<>();
        
        if (!input.contains("-")) {
            return 0;
        }
        
        distance.put(input, 0);
        q.add(input);
        
        while (!q.isEmpty()) {
            final String current = q.poll();
            int distanceToCurrent = distance.get(current);
            
            for (int i = 0; i < input.length(); ++i) {
                String possibleNext = process(current.subSequence(0, i + 1)) 
                        + current.subSequence(i + 1, current.length());
                if (distance.containsKey(possibleNext)) {
                    continue;
                }
                distance.put(possibleNext, distanceToCurrent + 1);
                q.add(possibleNext);
                
                if (!possibleNext.contains("-")) {
                    return distanceToCurrent + 1;
                }
            }
        }
        
        throw new AssertionError();
    }

    private static String process(CharSequence charSequence) {
        StringBuilder result = new StringBuilder(charSequence);
        result.reverse();
        for (int i = 0; i < result.length(); ++i) {
            result.setCharAt(i, (char)('+' + '-' - result.charAt(i)));
        }
//        System.err.println(charSequence + "=>" + result);
        return result.toString();
    }
}
