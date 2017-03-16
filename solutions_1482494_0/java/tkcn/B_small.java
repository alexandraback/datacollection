import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B_small {

    class Level {
        int star;
        int index;
        int order;
        public Level(int s, int i, int t) {
            star = s;
            index = i;
            order = t;
        }
        public String toString() {
            return star+" "+index+" "+ order;
        }
    }

    public B_small() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            int n = in.nextInt();
            List<Level> aList = new ArrayList<Level>();
            LinkedList<Level> bList = new LinkedList<Level>();
            for (int i=0; i<n; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                aList.add(new Level(a, i, -b));
                bList.add(new Level(b, i, b));
            }
            Comparator<Level> comp = new Comparator<Level>() {
                public int compare(Level a, Level b) {
                    return a.order-b.order;
                }
            };
            Collections.sort(aList, comp);
            Collections.sort(bList, comp);


            boolean[] doneA = new boolean[n];
            boolean[] doneB = new boolean[n];

            int p = 0;
            int ans = 0;
            while (true) {
                int c = p;
                while (!bList.isEmpty()) {
                    if (bList.getFirst().star>c) break;
                    Level l = bList.removeFirst();
                    doneB[l.index] = true;
                    c += doneA[l.index]?1:2;
                    ans++;
                }

                if (p==c) {
                    for (int i=0; i<aList.size(); i++) {
                        Level l = aList.get(i);
                        if (l.star>c) continue;
                        aList.remove(i);
                        if (doneB[l.index]) continue;
                        doneA[l.index] = true;
                        c += 1;
                        ans++;
                        break;
                    }
                }

                if (p==c) break;
                p = c;
            }

            if (p!=2*n) {
                out.println("Too Bad");
            } else {
                out.println(ans);
            }

        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new B_small();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    } 
    // }}}
}
