import java.io.*;
import java.util.*;

public class B {
    public static void main(String[]args) throws IOException {
        BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(x.readLine());
        for (int cases = 1; cases <= t; cases++) {
            StringTokenizer st = new StringTokenizer(x.readLine());
            String one = st.nextToken();
            String two = st.nextToken();
            int len = one.length();
            long maxdiff = Long.MAX_VALUE;
            LinkedList<Pair> q = new LinkedList<Pair>();
            LinkedList<Pair> best = new LinkedList<Pair>();
            q.add(new Pair("", "", 0));
            while (!q.isEmpty()) {
                Pair cur = q.pop();
                if (cur.index == len) {
                    long diff = Math.abs(Long.parseLong(cur.a) - Long.parseLong(cur.b));
                    if (diff <= maxdiff) {
                        if (diff < maxdiff) best = new LinkedList<Pair>();
                        maxdiff = diff;
                        best.add(cur);
                    }
                } else if (cur.a.compareTo(cur.b) == 0) { //equality
                    if (one.charAt(cur.index) == '?') {
                        if (two.charAt(cur.index) == '?') {
                            q.add(new Pair(cur.a+"0", cur.b+"0", cur.index+1));
                            q.add(new Pair(cur.a+"0", cur.b+"1", cur.index+1));
                            q.add(new Pair(cur.a+"1", cur.b+"0", cur.index+1));
                        } else {
                            char next = two.charAt(cur.index);
                            String z = Character.toString(next);
                            String plus = Character.toString((char) (next + 1));
                            String minus = Character.toString((char) (next - 1));
                            if (next != '0') q.add(new Pair(cur.a+minus, cur.b+z, cur.index+1));
                            q.add(new Pair(cur.a+z, cur.b+z, cur.index+1));
                            if (next != '9') q.add(new Pair(cur.a+plus, cur.b+z, cur.index+1));
                        }
                    } else {
                        if (two.charAt(cur.index) == '?') {
                            char next = one.charAt(cur.index);
                            String z = Character.toString(next);
                            String plus = Character.toString((char) (next + 1));
                            String minus = Character.toString((char) (next - 1));
                            if (next != '0') q.add(new Pair(cur.a+z, cur.b+minus, cur.index+1));
                            q.add(new Pair(cur.a+z, cur.b+z, cur.index+1));
                            if (next != '9') q.add(new Pair(cur.a+z, cur.b+plus, cur.index+1));
                        } else {
                            q.add(new Pair(cur.a+Character.toString(one.charAt(cur.index)), cur.b+Character.toString(two.charAt(cur.index)), cur.index+1));
                        }
                    }
                } else if (cur.a.compareTo(cur.b) > 0) {
                    for (int i = cur.index; i < len; i++) {
                        if (one.charAt(i) == '?') {
                            if (two.charAt(i) == '?') {
                                cur.b += '9'; cur.a += '0';
                            } else {
                                cur.a += '0'; cur.b += two.charAt(i);
                            }
                        } else {
                            if (two.charAt(i) == '?') {
                                cur.a += one.charAt(i); cur.b += '9';
                            } else {
                                cur.a += one.charAt(i); cur.b += two.charAt(i);
                            }
                        }
                    }
                    long diff = Math.abs(Long.parseLong(cur.a) - Long.parseLong(cur.b));
                    if (diff <= maxdiff) {
                        if (diff < maxdiff) best = new LinkedList<Pair>();
                        maxdiff = diff;
                        
                        best.add(cur);
                    }
                } else {
                    for (int i = cur.index; i < len; i++) {
                        if (one.charAt(i) == '?') {
                            if (two.charAt(i) == '?') {
                                cur.b += '0'; cur.a += '9';
                            } else {
                                cur.a += '9'; cur.b += two.charAt(i);
                            }
                        } else {
                            if (two.charAt(i) == '?') {
                                cur.a += one.charAt(i); cur.b += '0';
                            } else {
                                cur.a += one.charAt(i); cur.b += two.charAt(i);
                            }
                        }
                    }
                    long diff = Math.abs(Long.parseLong(cur.a) - Long.parseLong(cur.b));
                    if (diff <= maxdiff) {
                        if (diff < maxdiff) best = new LinkedList<Pair>();
                        maxdiff = diff;
                        
                        best.add(cur);
                    }
                }
            }
            String a = best.getFirst().a;
            String b = best.getFirst().b;
            for (Pair cur: best) {
                int cmp = cur.a.compareTo(a);
                if (cmp < 0) {
                    a = cur.a;
                    b = cur.b;
                } else if (cmp == 0 && cur.b.compareTo(b) < 0) {
                    a = cur.a;
                    b = cur.b;
                }
            }
            System.out.println("Case #" + cases + ": " + a + " " + b);
        }
    }
}
class Pair {
    public String a;
    public String b;
    public int index;
    Pair (String a, String b, int index) {
        this.a = a;
        this.b = b;
        this.index = index;
    }
}