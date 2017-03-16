import java.util.*;

public class C{
    static Scanner s;
    public static void main(String[] args){
        s = new Scanner(System.in);
        int cases = s.nextInt();
        for(int i = 0; i < cases; i++) {
            long result = solve();
            System.out.printf("Case #%d: %s\n", i+1, result);
            System.err.printf("Case #%d: %s\n", i+1, result);
        }
    }

    public static long solve() {
        int numOfTribes = s.nextInt();
        Tribe[] tribes = new Tribe[numOfTribes];
        for(int i = 0; i < numOfTribes; i++) {
            tribes[i] = new Tribe(s.nextLong(), s.nextLong(), s.nextLong(), s.nextLong(), s.nextLong(), s.nextLong(), s.nextLong(), s.nextLong());
        }
        Map<Long, Set<Attack>> allAttacks = new TreeMap<Long, Set<Attack>>();
        for(int i = 0; i < numOfTribes; i++) {
            Map<Long, Attack> temp = tribes[i].attacks();
            for( Long day  : temp.keySet()) {
                if (!allAttacks.containsKey(day)) {
                    allAttacks.put(day, new HashSet<Attack>());
                }
                allAttacks.get(day).add(temp.get(day));
            }
        }
        long result = 0;

        Map<Long, Integer> wall = new HashMap<Long, Integer>();
        for(Long day : allAttacks.keySet()) {
            Set<Attack> oneday = allAttacks.get(day);
            //System.out.println(day);
            for(Attack a : oneday) {
label:
                for(long i = a.start*2; i <= a.end*2; i++) {
                    if(!wall.containsKey(i) || wall.get(i) < a.height) {
                        //System.out.println("day: " + day + " " + a.height);
                        result++;
                        break label;
                    } else {
                        //System.out.println("At " + i + " Strength: " + a.height + " height: " + wall.get(i));
                    }
                }
            }

            for(Attack a: oneday) {
                for(long i = a.start*2; i <= a.end*2; i++) {
                    if(!wall.containsKey(i)) {
                        wall.put(i, (Integer) 0);
                    }
                    if(wall.get(i) < a.height) {
                        wall.put(i, (Integer)(int)a.height);
                    }
                }
            }
        }


        return result;
    }


    public static class Tribe{
        long d;
        long n;
        long w;
        long e;
        long s;
        long dd;
        long dp;
        long ds;

        public Tribe(long nd, long nn, long nw, long ne, long ns, long ndd, long ndp, long nds) {
            d = nd;
            n = nn;
            w = nw;
            e = ne;
            s = ns;
            dd = ndd;
            dp = ndp;
            ds = nds;
            
        } 

        public Map<Long, Attack> attacks() {
            Map<Long, Attack> result = new HashMap<Long, Attack>();
            for(int i = 0; i < n; i++) {
                result.put(d, new Attack(w, e, s));
                d += dd;
                w += dp;
                e += dp;
                s += ds;
            }
            return result;
        }


    }

    public static class Attack{
        long start;
        long end;
        long height;

        public Attack(long w, long e, long s) {
            start = w;
            end = e;
            height = s;
        }
    }

}
