import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by sjtudesigner on 5/11/14.
 */
public class TrainSmall {

    public final static int MODULE = 1000000007;
    public static long mod_fact(int n)
    {
        if (n == 0) return 1;
        else return (n * mod_fact(n - 1)) % MODULE;
    }

    public static class Bundle
    {
        public String s;
        public long weight;

        public Bundle(String s)
        {
            this.s = s;
            weight = 1;
        }

        public Bundle(String s, long weight)
        {
            this.s = s;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        int cases = sc.nextInt();
        sc.nextLine();
        OUT:for (int times = 1;times <= cases;times++)
        {
            out.printf("Case #%d: ", times);

            int trains = sc.nextInt();
            ArrayList<Bundle> p = new ArrayList<Bundle>();
            long result = 1;

            for (int i = 0;i < trains;i++)
            {
                p.add(i, new Bundle(sc.next()));
            }

            for (char c = 'a';c <= 'z';c++)
            {
                ArrayList<Bundle> left_slot = new ArrayList<Bundle>();
                ArrayList<Bundle> right_slot = new ArrayList<Bundle>();
                ArrayList<Bundle> left_right = new ArrayList<Bundle>();
                ArrayList<Bundle> inner_slot = new ArrayList<Bundle>();

                for (Bundle s: p)
                {
                    boolean INNER = false;
                    boolean NO_MORE = false;
                    for (int i = 0;i < s.s.length();i++)
                    {
                        if (INNER && s.s.charAt(i) != c) { INNER = false; NO_MORE = true; }
                        else if (!NO_MORE && s.s.charAt(i) == c) { INNER = true; }
                        else if (NO_MORE && s.s.charAt(i) == c) { out.println(0); continue OUT; }
                    }
                    if (NO_MORE && s.s.charAt(0) == c) left_slot.add(s);
                    else if (!NO_MORE && s.s.charAt(0) == c) left_right.add(s);
                    else if (!NO_MORE && s.s.charAt(s.s.length() - 1) == c) right_slot.add(s);
                    else if (NO_MORE) { inner_slot.add(s); }
                }
                if (left_slot.size() > 1 || right_slot.size() > 1) { out.println(0); continue OUT; }
                if (inner_slot.size() > 0 && (left_slot.size() + right_slot.size() + left_right.size() != 0)) { out.println(0); continue OUT; }
                if (left_slot.size() == 1 && right_slot.size() == 1)
                {
                    Bundle extra = new Bundle(right_slot.get(0).s + left_slot.get(0).s, (left_slot.get(0).weight * right_slot.get(0).weight) % MODULE);
                    p.set(p.indexOf(right_slot.get(0)), extra);
                    right_slot.set(0, extra);
                    p.remove(left_slot.get(0));
                }
                if (left_right.size() != 0)
                {
                    long weight = mod_fact(left_right.size());
                    for (int i = 0;i < left_right.size();i++)
                    {
                        p.remove(left_right.get(i));
                    }
                    if (right_slot.size() != 0) { right_slot.get(0).weight *= weight; right_slot.get(0).weight %= MODULE; }
                    else if (left_slot.size() != 0) { left_slot.get(0).weight *= weight; left_slot.get(0).weight %= MODULE; }
                    else
                    {
                        Bundle extra = new Bundle(String.valueOf(c), weight);
                        p.add(extra);
                    }
                }

            }

            for (Bundle b: p)
            {
                result *= b.weight;
                result %= MODULE;
            }
            result *= mod_fact(p.size());
            result %= MODULE;

            out.println(result);
        }
        out.close();
    }
}
