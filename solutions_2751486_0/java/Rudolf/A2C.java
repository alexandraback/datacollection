import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class A2C {
    static Set<Character> vow = Collections.unmodifiableSet(new HashSet<Character>()
    {{
            add('a');
            add('e');
            add('i');
            add('o');
            add('u');
    }});

    public static void main(String ... args) throws FileNotFoundException {
        String name = "A-small-attempt0";
        System.setIn(new FileInputStream(name + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(name + ".out")));
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int ti = 0; ti < t; ti++) {
            String nm = sc.next();
            int n = sc.nextInt();
            sc.nextLine();

            long res = solve(nm, n);
            System.out.println("Case #"+(ti + 1)+": " + res);
        }
    }

    private static long solve(String nm, int n) {
        List<Integer> l = new ArrayList<Integer>();
        char[] name = nm.toCharArray();
        long result = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += !vow.contains(name[i])?1:0;
        }
        if(count == n) {
            l.add(0);
        }
        for(int start = 0;start + n < name.length; start++) {
            count -= !vow.contains(name[start])?1:0;
            count += !vow.contains(name[start + n])?1:0;
            if(count == n) {
                l.add(start+1);
            }
        }
        for(int i = 0; i < l.size(); i++) {
            int b = (i == 0)?0:(l.get(i-1) + 1);
            result += (l.get(i) - b + 1) * (name.length - l.get(i) - n + 1);
        }
//        System.out.println("Solve: " + nm + ", " + n);
        return result;
    }
}
