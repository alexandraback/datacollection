import java.util.*;

public class BA {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer cases = in.nextInt();
        in.nextLine();
        for (Integer i = 0; i < cases; i ++) {
            char[] chars = in.nextLine().toCharArray();
            int[] nums = new int[10];
            HashMap<Character, Integer> m = new HashMap<>();
            for (char c : chars) {
                if (!m.containsKey(c)) {
                    m.put(c, 0);
                }
                m.put(c, m.get(c) + 1);
//                switch (c) {
//                    case 'Z':
//                        nums[0]++;
//                        break;
//                    case 'W':
//                        nums[2]++;
//                        break;
//                    case 'X':
//                        nums[6]++;
//                        break;
//                    case 'G':
//                        nums[8]++;
//                        break;
//                    case 'U':
//                        nums[4]++;
//                        nums[5]--;
//                    case 'F':
//                        nums[5]++;
//                }
            }
            nums[0] = m.containsKey('Z') ? m.get('Z') : 0;
            nums[2] = m.containsKey('W') ? m.get('W') : 0;
            nums[4] = m.containsKey('U') ? m.get('U') : 0;
            nums[6] = m.containsKey('X') ? m.get('X') : 0;
            nums[8] = m.containsKey('G') ? m.get('G') : 0;

            String[] strs = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


//            System.out.println(m);

            int index = 0;
            for (String s : strs) {
                char[] chars2 = s.toCharArray();
                for (char c : chars2) {
                    if (!m.containsKey(c)) {
                        continue;
                    }
//                    if (c == 'E') {
//                        System.out.println(s + " : " + nums[index]);
//                    }
                    m.put(c, m.get(c) - nums[index]);
                }
                index++;
            }

//            System.out.println(m);

            nums[1] = m.containsKey('O') ? m.get('O') : 0;
            nums[3] = m.containsKey('R') ? m.get('R') : 0;
            nums[5] = m.containsKey('F') ? m.get('F') : 0;
            nums[7] = m.containsKey('S') ? m.get('S') : 0;

            String[] strs2 = {"ONE", "THREE", "FIVE", "SEVEN"};


            index = 0;
            for (String s : strs2) {
                char[] chars2 = s.toCharArray();
                for (char c : chars2) {
                    if (!m.containsKey(c)) {
                        continue;
                    }
                    m.put(c, m.get(c) - nums[index*2+1]);
                }
                index++;
            }

//            System.out.println(m);

            nums[9] = m.containsKey('I') ? m.get('I') : 0;
            String out = "Case #" + (i + 1) + ": ";
            for (int k = 0; k <= 9; k++) {
                for (int j = 0; j < nums[k]; j++) {
                    out += String.valueOf(k);
                }
            }
            System.out.println(out);
        }
    }
}
