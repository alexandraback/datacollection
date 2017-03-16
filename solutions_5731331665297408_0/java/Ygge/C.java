import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class C {

    private static final String FILE_NAME = "C-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] split = in.readLine().split(" ");
            int n = Integer.parseInt(split[0]);
            int m = Integer.parseInt(split[1]);
            List<City> cities = new ArrayList<City>();
            for (int i = 0; i < n; ++i) {
                cities.add(new City(in.readLine()));
            }
            for (int i = 0; i < m; ++i) {
                split = in.readLine().split(" ");
                int a = Integer.parseInt(split[0])-1;
                int b = Integer.parseInt(split[1])-1;
                City cityA = cities.get(a);
                City cityB = cities.get(b);
                cityA.neigh.add(cityB);
                cityB.neigh.add(cityA);
            }
            Collections.sort(cities);
            boolean[] used = new boolean[n];
            used[0] = true;
            List<String> zips = new ArrayList<String>();
            zips.add(cities.get(0).zip);
            List<City> fromCities = new ArrayList<City>();
            fromCities.add(cities.get(0));
            calc(cities, used, zips, fromCities);
            out.write(String.format("Case #%d: %s\n", c, concat(zips)));
        }
        out.close();
    }

    private static boolean calc(List<City> cities, boolean[] used, List<String> zips, List<City> fromCities) {
        int index = 0;
        boolean done = true;
        for (City city : cities) {
            if (!used[index]) {
                done = false;
                for (int i = fromCities.size()-1; i >= 0; --i) {
                    City fromCity = fromCities.get(i);
                    if (fromCity.neigh.contains(city)) {
                        used[index] = true;
                        List<String> newZips = new ArrayList<String>();
                        for (String zip : zips) {
                            newZips.add(zip);
                        }
                        newZips.add(city.zip);
                        List<City> newFrom = new ArrayList<City>();
                        for (int j = 0; j <= i; ++j) {
                            newFrom.add(fromCities.get(j));
                        }
                        newFrom.add(city);
                        if (calc(cities, used, newZips, newFrom)) {
                            if (zips.size() != newZips.size()) {
                                zips.clear();
                                for (String newZip : newZips) {
                                    zips.add(newZip);
                                }
                            }
                            return true;
                        }
                        used[index] = false;
                    }
                }
            }
            ++index;
        }
        return done;
    }

    private static String concat(List<String> zips) {
        StringBuilder sb = new StringBuilder();
        for (String zip : zips) {
            sb.append(zip);
        }
        return sb.toString();
    }

    private static class City implements Comparable<City> {
        private final String zip;
        private final List<City> neigh = new ArrayList<City>();

        private City(String zip) {
            this.zip = zip;
        }

        @Override
        public int compareTo(City otherCity) {
            return zip.compareTo(otherCity.zip);
        }
    }
}
