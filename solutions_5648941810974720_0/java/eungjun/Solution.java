import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
    }
}

class Solver {
    String[] nums = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    int size(Map<Character, Integer> map) {
        int sum = 0;
        for(int v : map.values()) {
            sum += v;
        }
        return sum;
    }

    String solve(int last, Map<Character, Integer> map) {
        // copy
        if (size(map) == 0) {
            return "";
        }

        for(int i = last; i < nums.length; i++) {
            Map<Character, Integer> m = new HashMap<>(map);
            String num = nums[i];
            boolean got = true;
            for(int j = 0; j < num.length(); j++) {
                Integer cnt = m.get(num.charAt(j));
                if (cnt == null || cnt <= 0) {
                    got = false;
                    break;
                }
            }

            System.err.println(last + " " + num);

            if (!got) {
                continue;
            }

            for(int j = 0; j < num.length(); j++) {
                m.put(num.charAt(j), m.get(num.charAt(j)) - 1);
            }

            String result = solve(i, m); 
            if (result != null) {
                return "" + i + result;
            }
        }

        return null;
    }

    String solve(String s) {
        // nondecreasing order.
        // 1. 문자열 빈도 map을 만든다.
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            Integer num = map.get(s.charAt(i));
            if (num == null) num = 0;
            map.put(s.charAt(i), num + 1);
        }
        // 2. 모든 숫자를 시도해본다. (작은 수 부터)
        return solve(0, map);
    }

    void solve() {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int j = 0; j < t; j++) {
            System.err.printf("Case #%d%n", j + 1);
            System.out.printf("Case #%d: %s%n", j + 1, solve(sc.next()));
        }
    }

}
