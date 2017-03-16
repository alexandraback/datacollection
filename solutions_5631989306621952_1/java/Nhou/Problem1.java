package round1;

/**
 * Created by ninghou on 4/15/16.
 */
public class Problem1 {

    public String nhou(String str) {
        StringBuilder sb = new StringBuilder();
        char[] s = str.toCharArray();

        Character first = s[0];
        sb.append(s[0]);
        for (int i = 1; i < s.length; i++) {
            if (s[i] < first) {
                sb.append(s[i]);
            } else {
                sb.insert(0, s[i]);
                first = s[i];
            }
        }
        return sb.toString();
    }



}
