import java.util.*;

public class TheBoredTravelingSalesman {
    static List<String> cities;
    static Set<BidirectionalFlight> flights;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTestCases = sc.nextInt();
        for (int testCase = 1; testCase <= numTestCases; ++testCase) {
            int numCities = sc.nextInt(), numFlights = sc.nextInt();
            cities = new ArrayList<>();
            flights = new HashSet<>();
            for (int i = 0; i < numCities; ++i)
                cities.add(sc.next());
            for (int i = 0; i < numFlights; ++i)
                flights.add(new BidirectionalFlight(cities.get(sc.nextInt() - 1), cities.get(sc.nextInt() - 1)));
            Collections.sort(cities);
            System.out.printf("Case #%d: %s\n", testCase, getSmallestNumber());
        }
    }

    static String getSmallestNumber() {
        Optional<String> min = Optional.empty();
        for (String startingCity : cities) {
            Deque<String> path = new ArrayDeque<>();
            path.add(startingCity);
            Set<String> remainingCities = new HashSet<>(cities);
            remainingCities.remove(startingCity);
            Optional<String> optSolution = getSmallestNumber(path, remainingCities);
            if (optSolution.isPresent()) {
                String n = startingCity + optSolution.get();
                if (min.isPresent())
                    min = Optional.of(min(min.get(), n));
                else
                    min = Optional.of(n);
            }
        }
        return min.get();
    }

    static Optional<String> getSmallestNumber(Deque<String> path, Set<String> remainingCities) {
        if (remainingCities.isEmpty())
            return Optional.of("");

        Optional<String> min = Optional.empty();
        minSearch:
        for (String nextCity : remainingCities) {
            Set<String> newRemCities = new HashSet<>(remainingCities);
            newRemCities.remove(nextCity);
            Deque<String> newPath = new ArrayDeque<>(path);
            while (!newPath.isEmpty()) {
                String from = newPath.getLast();
                if (flights.contains(new BidirectionalFlight(from, nextCity))) {
                    newPath.addLast(nextCity);
                    Optional<String> optSol = getSmallestNumber(newPath, newRemCities);
                    newPath.removeLast();

                    if (optSol.isPresent()) {
                        String n = nextCity + optSol.get();
                        if (min.isPresent())
                            min = Optional.of(min(min.get(), n));
                        else
                            min = Optional.of(n);
                        continue minSearch;
                    }
                }
                newPath.removeLast();
            }
        }
        return min;
    }

    static String min(String a, String b) {
        return a.compareTo(b) < 0 ? a : b;
    }

    static class BidirectionalFlight {
        final String a, b;

        BidirectionalFlight(String a, String b) {
            this.a = a;
            this.b = b;
        }

        public boolean equals(Object o) {
            if (!(o instanceof BidirectionalFlight))
                return false;
            BidirectionalFlight that = (BidirectionalFlight) o;
            return this.a.equals(that.a) && this.b.equals(that.b)
                    || this.a.equals(that.b) && this.b.equals(that.a);
        }

        public int hashCode() {
            return a.hashCode() + b.hashCode();
        }
    }
}
