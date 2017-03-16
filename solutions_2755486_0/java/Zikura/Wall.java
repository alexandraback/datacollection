import java.util.*;

public class Wall {

    private List<Interval> wall;

    public static void main(String[] args) {
        new Wall().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);

        int numCases = s.nextInt();

        for(int numCase=1;numCase<=numCases;numCase++) {
            int numTribes = s.nextInt();
            wall = new ArrayList<Interval>();

            Tribe[] tribes = new Tribe[numTribes];
            for(int i=0;i<numTribes;i++) {
                tribes[i] = new Tribe(s);
            }

            int numAttacks = simulate(tribes, wall);
            System.out.println(String.format("Case #%d: %d", numCase, numAttacks));
        }
    }

    private int simulate(Tribe[] tribes, List<Interval> wall) {

        int numSuccessfulAttacks = 0;
        for(boolean hasMore = hasMoreAttacks(tribes);hasMore; hasMore = hasMoreAttacks(tribes)) {

            List<Tribe> nextAttackingTribes = getAttackingTribes(tribes);

            for(Tribe tribe : nextAttackingTribes) {
                if(performAttack(tribe, wall))
                    numSuccessfulAttacks++;
            }

            for(Tribe tribe : nextAttackingTribes) {
                raiseWall(wall, tribe.west, tribe.east, tribe.strength);
                tribe.increment();
            }
        }

        return numSuccessfulAttacks;
    }

    private void raiseWall(List<Interval> wall, int west, int east, int strength) {
        wall.add(new Interval(west, east, strength));
    }

    private boolean performAttack(Tribe tribe, List<Interval> wall) {
        Interval attackInterval = new Interval(tribe.west, tribe.east, tribe.strength);

        List<Interval> coveringIntervals = new ArrayList<Interval>();
        for(Interval interval : wall) {
            if(attackInterval.start < interval.end && interval.start < attackInterval.end && attackInterval.strength <= interval.strength)
                coveringIntervals.add(interval);
        }

        return !covers(attackInterval, coveringIntervals);
    }

    private boolean covers(Interval attackInterval, List<Interval> coveringIntervals) {
        if(coveringIntervals.isEmpty())
            return false;

        Collections.sort(coveringIntervals);

        int west = coveringIntervals.get(0).start;
        int east = coveringIntervals.get(0).end;
        for(Interval interval : coveringIntervals) {
            if(interval.start <= east && interval.end >= east) {
                east = interval.end;
            }
        }

        return west <= attackInterval.start && east >= attackInterval.end;
    }

    private List<Tribe> getAttackingTribes(Tribe[] tribes) {
        List<Tribe> aTribes = new ArrayList<Tribe>();

        int nextDay = Integer.MAX_VALUE;

        for(Tribe tribe : tribes) {
            if(!tribe.hasRemainingAttacks())
                continue;

            if(tribe.day < nextDay) {
                aTribes.clear();
                nextDay = tribe.day;
                aTribes.add(tribe);
            } else if (tribe.day == nextDay) {
                aTribes.add(tribe);
            }
        }
        return aTribes;
    }

    private boolean hasMoreAttacks(Tribe[] tribes) {
        for(Tribe tribe : tribes) {
            if(tribe.hasRemainingAttacks())
                return true;
        }
        return false;
    }




    private static class Tribe {

        int day;
        int maxAttacks;
        int west;
        int east;
        int strength;
        int dDays;
        int dDistance;
        int dStrength;

        int numAttacks = 0;

        public Tribe(Scanner s) {
            day = s.nextInt();
            maxAttacks = s.nextInt();
            west = s.nextInt();
            east = s.nextInt();
            strength = s.nextInt();
            dDays = s.nextInt();
            dDistance = s.nextInt();
            dStrength = s.nextInt();
        }

        boolean hasRemainingAttacks() {
            return numAttacks < maxAttacks;
        }

        void increment() {
            numAttacks++;
            day += dDays;
            west += dDistance;
            east += dDistance;
            strength += dStrength;
        }
    }

    private static class Interval implements Comparable<Interval> {
        int start;
        int end;
        int strength;

        public Interval(int start, int end, int strength) {
            this.start = start;
            this.end = end;
            this.strength = strength;
        }

        @Override
        public int compareTo(Interval o) {
            return start-o.start;
        }
    }
}
