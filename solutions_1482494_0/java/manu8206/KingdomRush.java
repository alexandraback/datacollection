package kingdomrush;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils.Comparison;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;

/**
 *
 * @author Emmanuel
 */
public class KingdomRush {
    class Hit {
        int rank;
        int min1;
        int min2;

        public Hit(int rank, int min1, int min2) {
            this.rank = rank;
            this.min1 = min1;
            this.min2 = min2;
        }
        
    }
    
    class HitComp1 implements Comparator<Hit> 
    {
        @Override
        public int compare(Hit o1, Hit o2) {
            int i = Integer.compare(o1.min1, o2.min1);
            if (i == 0) return -Integer.compare(o1.min2, o2.min2);
            return i;
        }
    }

    class HitComp2 implements Comparator<Hit> 
    {
        @Override
        public int compare(Hit o1, Hit o2) {
            int i = Integer.compare(o1.min2, o2.min2);
            if (i == 0) return -Integer.compare(o1.min1, o2.min1);
            return i;
        }
    }

    
    String executeCase(final BufferedReader reader) throws IOException {
        String line = reader.readLine();
        int N = Integer.parseInt(line);
        int target = 2*N;
        int hits[] = new int[N];
        
        LinkedList<Hit> l1 = new LinkedList<Hit>();
        LinkedList<Hit> l2 = new LinkedList<Hit>();
        {
            Hit h1s[] = new Hit[N];
            Hit h2s[] = new Hit[N];
        
            for (int i = 0; i < N; ++i) {
                hits[i] = 0;
                line = reader.readLine();
                String words[] = line.split(" ");
                Hit h = new Hit(i, Integer.parseInt(words[0]), Integer.parseInt(words[1]));
                h1s[i] = h;
                h2s[i] = h;
            }
            Arrays.sort(h1s, new HitComp1());
            Arrays.sort(h2s, new HitComp2());
        
            for (int i = 0; i < N; ++i) {
                l1.add(h1s[i]);
                l2.add(h2s[i]);
            }
        }
                
        int count = 0;
        int number = 0;
        boolean any = false;
        do {
            any = false;
            while (!l2.isEmpty() && l2.get(0).min2 <= count) {
                count += 2 - hits[l2.get(0).rank];
                hits[l2.get(0).rank] = 2;
                ++number;
                l2.remove(0);
                any = true;
            }
            while (!l1.isEmpty() && l1.get(0).min1 <= count) {
                if (hits[l1.get(0).rank] == 0) {
                    hits[l1.get(0).rank] = 1;
                    count += 1;
                    ++number;
                    any = true;
                    break;
                } else
                    l1.remove(0);
            }
        } while (any);
              
        if (count == target) return Integer.toString(number);
        return "Too Bad";
    }

    void execute() {
        try {
            InputStreamReader stream = new InputStreamReader(System.in);
            BufferedReader reader = new BufferedReader(stream);
        
            String line = reader.readLine();
            int cases = Integer.parseInt(line);
            for (int i = 1; i <= cases; ++i) {
                StringBuilder out = new StringBuilder();
                out.append("Case #");
                out.append(i);
                out.append(": ");
                out.append(executeCase(reader));
                System.out.println(out.toString());
            }
        } catch (Exception e) {
            e.printStackTrace(System.err);
        }
    }

    public static void main(String[] args) {
        new KingdomRush().execute();
    }
}

