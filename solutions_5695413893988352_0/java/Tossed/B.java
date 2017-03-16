package google.code.jam.round1b;

import com.sun.tools.javac.util.Pair;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by chen on 4/15/16.
 */
public class B {

    public static String relation(String s1, String s2) {
        for (int i = 0; i < s1.length(); i ++) {
            if (s1.charAt(i) == '?' || s2.charAt(i) == '?') {
                return "?";
            }
            else if (s1.charAt(i) > s2.charAt(i)) {
                return ">";
            }
            else if (s1.charAt(i) < s2.charAt(i)) {
                return "<";
            }
        }

        return "=";
    }

    public static boolean possible(String s1, String s2) {
        for (int i = 0; i < s1.length(); i ++) {
            if (s1.charAt(i) == '?' || s2.charAt(i) == '?') {
                continue;
            }
            else if (s1.charAt(i) != s2.charAt(i)) {
                return false;
            }
        }

        return true;
    }

    public static String minimizePossible(String s1, String s2) {
        String ans = "";

        for (int i = 0; i < s1.length(); i ++) {
            if (s1.charAt(i) == '?' && s2.charAt(i) == '?') {
                ans += "0";
            }
            else if (s1.charAt(i) == '?') {
                ans += s2.charAt(i);
            }
            else if (s2.charAt(i) == '?') {
                ans += s1.charAt(i);
            }
            else {
                ans += s1.charAt(i);
            }
        }

        return ans;
    }

    public static List<String> addPrefix(List<String> res, String pre) {
        List<String> a = new ArrayList<>();
        a.add(pre + res.get(0));
        a.add(pre + res.get(1));

        return a;
    }

    public static List<String> minimize(String s1, String s2) {
        String relation = relation(s1, s2);

        if (relation == ">") {
            return minimizeGreater(s1, s2);
        }
        else if (relation == "<") {
            List<String> se = minimizeGreater(s2, s1);
            List<String> ans = new ArrayList<>();
            ans.add(se.get(1));
            ans.add(se.get(0));
            return ans;
        }
        else {
            for (int i = 0; i < s1.length(); i ++) {
                if (s1.charAt(i) == '?' && s2.charAt(i) == '?') {
                    int min = Integer.MAX_VALUE;
                    List<String> minAns = null;

                    String news1 = '0' + s1.substring(i + 1);
                    String news2 = '0' + s2.substring(i + 1);
                    List<String> res = minimizeAll(news1, news2);
                    if (min > diff(res)) {
                        min = diff(res);
                        minAns = res;
                    }

                    news1 = '0' + s1.substring(i + 1);
                    news2 = '1' + s2.substring(i + 1);
                    res = minimizeAll(news1, news2);
                    if (min > diff(res)) {
                        min = diff(res);
                        minAns = res;
                    }

                    news1 = '1' + s1.substring(i + 1);
                    news2 = '0' + s2.substring(i + 1);
                    res = minimizeAll(news1, news2);
                    if (min > diff(res)) {
                        min = diff(res);
                        minAns = res;
                    }

                    return addPrefix(minAns, s1.substring(0, i));
                }
                else if (s1.charAt(i) == '?') {
                    int min = Integer.MAX_VALUE;
                    List<String> minAns = null;

                    String news2 = s2.substring(i);
                    String news1 = null;
                    List<String> res = null;

                    if (s2.charAt(i) > '0') {
                        news1 = (char) (s2.charAt(i) - 1) + s1.substring(i + 1);
                        res = minimizeAll(news1, news2);
                        if (min > diff(res)) {
                            min = diff(res);
                            minAns = res;
                        }
                    }

                    news1 = (char) s2.charAt(i) + s1.substring(i + 1);
                    res = minimizeAll(news1, news2);
                    if (min > diff(res)) {
                        min = diff(res);
                        minAns = res;
                    }

                    if (s2.charAt(i) < '9') {
                        news1 = (char) (s2.charAt(i) + 1) + s1.substring(i + 1);
                        res = minimizeAll(news1, news2);
                        if (min > diff(res)) {
                            min = diff(res);
                            minAns = res;
                        }
                    }

                    return addPrefix(minAns, s1.substring(0, i));
                }
                else if (s2.charAt(i) == '?') {
                    int min = Integer.MAX_VALUE;
                    List<String> minAns = null;
                    List<String> res = null;

                    String news1 = s1.substring(i);
                    String news2 = null;

                    if (s1.charAt(i) > '0') {
                        news2 = (char) (s1.charAt(i) - 1) + s2.substring(i + 1);
                        res = minimizeAll(news1, news2);
                        if (min > diff(res)) {
                            min = diff(res);
                            minAns = res;
                        }
                    }

                    news2 = (char) s1.charAt(i) + s2.substring(i + 1);
                    res = minimizeAll(news1, news2);
                    if (min > diff(res)) {
                        min = diff(res);
                        minAns = res;
                    }

                    if (s1.charAt(i) < '9') {
                        news2 = (char) (s1.charAt(i) + 1) + s2.substring(i + 1);
                        res = minimizeAll(news1, news2);
                        if (min > diff(res)) {
                            min = diff(res);
                            minAns = res;
                        }
                    }

                    return addPrefix(minAns, s1.substring(0, i));
                }
            }

            return null;
        }
    }

    public static List<String> minimizeGreater(String s1, String s2) {
        String ans1 = "";
        String ans2 = "";

        for (int i = 0; i < s1.length(); i ++) {
            if (s1.charAt(i) == '?' && s2.charAt(i) == '?') {
                ans1 += '0';
                ans2 += '9';
            }
            else if (s1.charAt(i) == '?') {
                ans1 += '0';
                ans2 += s2.charAt(i);
            }
            else if (s2.charAt(i) == '?') {
                ans1 += s1.charAt(i);
                ans2 += '9';
            }
            else {
                ans1 += s1.charAt(i);
                ans2 += s2.charAt(i);
            }
        }

        List<String> ans = new ArrayList<>();
        ans.add(ans1);
        ans.add(ans2);
        return ans;
    }

    public static List<String> minimizeAll(String s1, String s2) {
        if (possible(s1, s2)) {
            String ans = minimizePossible(s1, s2);
            List<String> res = new ArrayList<>();
            res.add(ans);
            res.add(ans);
            return res;
        }
        else {
            return minimize(s1, s2);
        }
    }

    public static int diff(List<String> sts) {
        return Math.abs(Integer.parseInt(sts.get(0)) - Integer.parseInt(sts.get(1)));
    }

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("B.in"));
        PrintWriter out = new PrintWriter(new FileWriter("B.out"));

        int T = Integer.parseInt(in.readLine());

        for (int k = 1; k <= T; k ++) {
            String line = in.readLine();

            String s1 = line.split(" ")[0];
            String s2 = line.split(" ")[1];

            List<String> sts = minimizeAll(s1, s2);
            out.printf("Case #%d: %s %s\n", k, sts.get(0), sts.get(1));

        }

        in.close();
        out.close();
    }
}
