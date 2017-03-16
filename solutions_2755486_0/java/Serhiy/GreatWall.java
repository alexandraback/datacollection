package mp.kotter.challenges.gcj.round1c;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NavigableMap;
import java.util.TreeMap;

import mp.kotter.challenges.utils.Solution;

public class GreatWall extends Solution {

    public static void main(final String[] args) throws Exception {
        (new GreatWall()).run(args);
    }

    @Override
    protected void solve() throws Exception {
        final int T = Integer.parseInt(getInput().readLine());

        for(int c=0; c<T; c++) {
            writeCaseResult(c, solveCase());
        }
    }

    private String solveCase() throws IOException {
        final int N = readInts().get(0);
        final List<Tribe> tribes = new ArrayList<>();
        for(int i=0; i<N; i++) {
            final List<Integer> tribeData = readInts();
            final Tribe tribe = new Tribe();
            tribe.d = tribeData.get(0);
            tribe.n = tribeData.get(1);
            tribe.w = tribeData.get(2);
            tribe.e = tribeData.get(3) - 1;
            tribe.s = tribeData.get(4);
            tribe.dd = tribeData.get(5);
            tribe.dp = tribeData.get(6);
            tribe.ds = tribeData.get(7);

            tribes.add(tribe);
        }

        final NavigableMap<Integer, List<Attack>> attacks = createAttacks(tribes);
        final Wall w = new Wall();
        int total = 0;

        for(final int day : attacks.keySet()) {
            total += w.attack(attacks.get(day));
        }

        return "" + total;
    }

    private NavigableMap<Integer, List<Attack>> createAttacks(final List<Tribe> tribes) {
        final NavigableMap<Integer, List<Attack>> result = new TreeMap<Integer, List<Attack>>();

        for(final Tribe t : tribes) {
            for(int i = 0, d = t.d, s = t.s, e = t.e, w = t.w; i < t.n; i++, d += t.dd, s += t.ds, e += t.dp, w += t.dp) {
                if (!result.containsKey(d)) {
                    result.put(d, new ArrayList<Attack>());
                }

                final List<Attack> attacksForDay = result.get(d);
                final Attack attack = new Attack();
                attack.d = d;
                attack.e = e;
                attack.w = w;
                attack.s = s;
                attacksForDay.add(attack);
            }
        }

        return result;
    }

    static class Tribe {
        public int d, n, w, e, s, dd, dp, ds;

        @Override
        public String toString() {
            return "[" + this.d + " " + this.n + " " + this.w + " " + this.e + " " + this.s + " " + this.dd + " " + this.dp + " " + this.ds + "]" ;
        }
    }

    static class Attack{
        public int d, w, e, s;

        @Override
        public String toString() {
            return "[" + this.d + " " + this.w + " " + this.e + " " + this.s + "]" ;
        }
    }

    static class Wall {
        private final Map<Integer, Integer> wall = new HashMap<>();

        int attack(final List<Attack> attacks) {
            int result = 0;
            for(final Attack a : attacks) {
                if (minHeight(a.w, a.e) < a.s) {
                    result += 1;
                }
            }
            for(final Attack a : attacks) {
                growTo(a.w, a.e, a.s);
            }
            return result;
        }

        private void growTo(final int w, final int e, final int s) {
            for(int x=w; x<=e; x++) {
                this.wall.put(x, Math.max(s, height(x)));
            }
        }

        private int minHeight(final int w, final int e) {
            int min = height(e);
            for(int x=w; x<e; x++) {
                if (height(x) < min) {
                    min = height(x);
                }
            }
            return min;
        }

        private int height(final int e) {
            final Integer h = this.wall.get(e);
            return h == null ? 0 : h;
        }
    }
}
