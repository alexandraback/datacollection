import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created with IntelliJ IDEA.
 * User: gouravr
 * Date: 5/11/14
 * Time: 3:14 PM
 */
public class B {

    static String[] train;
    static long res = 0;
    static HashMap<Character, Integer> start, end;

    static void brute(int visited, List<String> list) {
        if (list.size() == train.length) {
            HashMap<Character, Integer> s = new HashMap<Character, Integer>();
            HashMap<Character, Integer> e = new HashMap<Character, Integer>();
            boolean valid = true;
            //System.out.println(list);
            //s.put(list.get(0).charAt(0), 1);
            char ch = list.get(list.size() - 1).charAt(list.get(list.size() - 1).length() - 1);
            // e.put(ch, 1);
            int trainSize = 1;
            for (int i = 1; i < list.size(); ++i) {
                char sc = list.get(i).charAt(0);
                char ec = list.get(i - 1).charAt(list.get(i - 1).length() - 1);
                if (sc != ec) {
                    if (trainSize == 1) {
                        valid = false;
                        break;
                    }
                    if (!s.containsKey(sc)) {
                        s.put(sc, 0);
                    }
                    if (!e.containsKey(ec)) {
                        e.put(ec, 0);
                    }
                    s.put(sc, s.get(sc) + 1);
                    e.put(ec, e.get(ec) + 1);
                    trainSize = 1;
                } else {
                    trainSize++;
                }
            }

            if (trainSize == 1) {
                valid = false;
            }

            if (valid)
            for (Map.Entry<Character, Integer> et : s.entrySet()) {
                if (e.containsKey(et.getKey())) {
                    valid = false;
                }
            }

            if (valid)
            for (Map.Entry<Character, Integer> et : e.entrySet()) {
                if (s.containsKey(et.getKey())) {
                    valid = false;
                }
            }
            if (valid) {
             //   System.out.println(list);
                res++;
            }
            return;
        }

        for (int i = 0; i < train.length; ++i) {
            if ((visited & (1 << i)) == 0) {
                List<String> l = new ArrayList<String>(list);
                l.add(train[i]);
                brute(visited | (1 << i), l);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int T;
        long P, Q;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine().trim());
        int index = 0;
        while (T-- > 0) {
            start = new HashMap<Character, Integer>();
            end = new HashMap<Character, Integer>();

            index++;
            System.out.print(String.format("Case #%d: ", index));
            int N = Integer.parseInt(br.readLine().trim());
            int visited = 0;
            train = br.readLine().trim().split(" ");
            for (String str : train) {
                if (!start.containsKey(str.charAt(0))) {
                    start.put(str.charAt(0), 0);
                }
                if (!end.containsKey(str.charAt(str.length() - 1))) {
                    end.put(str.charAt(str.length() - 1), 0);
                }
                char s = str.charAt(0);
                char e = str.charAt(str.length() - 1);
                start.put(s, start.get(s) + 1);
                end.put(e, end.get(e) + 1);
            }

            res = 0;
            for (int i = 0; i < N; ++i) {
                List<String> list = new ArrayList<String>();
                list.add(train[i]);
                brute(visited | (1 << i), list);
            }
            System.out.print(res + "\n");
        }
    }
}
