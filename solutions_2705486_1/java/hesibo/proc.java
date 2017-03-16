import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class proc {
    private static Set<String> suffix = new HashSet<String>();

    private static Set<String> dictionary = new HashSet<String>();

    private static String[] chars = new String[] {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    public static int solve(String s, Writer writer) throws Exception {
        List<Map<State, Integer>> f = new ArrayList<Map<State, Integer>>();
        for (int i = 0; i < 2; i++) {
            f.add(new HashMap<State, Integer>());
        }
        int cur = 0;
        f.get(cur).put(new State("", -100), 0);
        for (int i = 0; i < s.length(); i++) {
            for (Entry<State, Integer> element : f.get(cur).entrySet()) {
                State key = element.getKey();
                //writer.write(i + " " + key.pattern + " " + key.previous + " " + element.getValue() + "\n");
                String curChar = s.substring(i, i + 1);
                String pattern = new String(key.pattern).concat(curChar);
                if (suffix.contains(pattern)) {
                    State newState = new State(pattern, key.previous);
                    if (!f.get(1-cur).containsKey(newState) || f.get(1-cur).get(newState) > element.getValue()) {
                        f.get(1-cur).put(newState, element.getValue());
                    }
                }
                if (dictionary.contains(pattern)) {
                    State newState = new State("", key.previous);
                    if (!f.get(1-cur).containsKey(newState) || f.get(1-cur).get(newState) > element.getValue()) {
                        f.get(1-cur).put(newState, element.getValue());
                    }
                }
                if (i - key.previous >= 5) {
                    for (String change : chars) {
                        if (!change.equals(curChar)) {
                            String newString = new String(key.pattern).concat(change);
                            if (suffix.contains(newString)) {
                                State changeState = new State(newString, i);
                                if (!f.get(1-cur).containsKey(changeState) || f.get(1-cur).get(changeState) > element.getValue() + 1) {
                                    f.get(1-cur).put(changeState, element.getValue() + 1);
                                }
                            }
                            if (dictionary.contains(newString)) {
                                State changeState = new State("", i);
                                if (!f.get(1-cur).containsKey(changeState) || f.get(1-cur).get(changeState) > element.getValue() + 1) {
                                    f.get(1-cur).put(changeState, element.getValue() + 1);
                                }
                            }
                        }
                    }
                }
            }
            f.get(cur).clear();
            cur = 1 - cur;
        }
        int ans = s.length();
        for (Entry<State, Integer> element : f.get(cur).entrySet()) {
            if (element.getKey().pattern.equals("")) {
                ans = Math.min(ans, element.getValue());
            }
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
        String s;

        while ((s = reader.readLine()) != null) {
            dictionary.add(s);
            for (int i = 1; i < s.length(); i++) {
                suffix.add(s.substring(0, i));
            }
        }
        reader.close();
        reader = new BufferedReader(new FileReader("C-large.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
        s = reader.readLine();
        int t = Integer.parseInt(s);
        for (int task = 1; task <= t; task++) {
            s = reader.readLine();
            writer.write(String.format("Case #%d: %d\n", task, solve(s, writer)));
        }
        reader.close();
        writer.close();
    }
}
