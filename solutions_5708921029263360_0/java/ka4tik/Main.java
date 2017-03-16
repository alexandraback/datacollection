import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.HashMap;
import java.io.InputStreamReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Kartik Singal (ka4tik)
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public ArrayList<TaskC.Trip> checkValidity(PrintWriter out, ArrayList<TaskC.Trip> triplets, int l) {
            Map<TaskC.Pair, Integer> map = new HashMap<TaskC.Pair, Integer>();
            ArrayList<TaskC.Trip> ok = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < triplets.size(); i++) {
                TaskC.Trip trip = triplets.get(i);
                int x = trip.x;
                int y = trip.y;
                int z = trip.z;

                map.putIfAbsent(new TaskC.Pair(x, y, 1), 0);
                map.putIfAbsent(new TaskC.Pair(y, z, 2), 0);
                map.putIfAbsent(new TaskC.Pair(x, z, 3), 0);


                map.put(new TaskC.Pair(x, y, 1), map.get(new TaskC.Pair(x, y, 1)) + 1);
                map.put(new TaskC.Pair(y, z, 2), map.get(new TaskC.Pair(y, z, 2)) + 1);
                map.put(new TaskC.Pair(x, z, 3), map.get(new TaskC.Pair(x, z, 3)) + 1);

                int a = map.get(new TaskC.Pair(x, y, 1));
                int b = map.get(new TaskC.Pair(y, z, 2));
                int c = map.get(new TaskC.Pair(x, z, 3));
//            out.println(a + " "  +  b + "  "+ c);
                if (a > l || b > l || c > l) {
                    break;
                } else
                    ok.add(trip);
            }
            return ok;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");

            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            int l = in.nextInt();

            ArrayList<TaskC.Trip> ans = new ArrayList<TaskC.Trip>();
            ArrayList<TaskC.Trip> trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    for (int k = 0; k < c; k++)
                        trip.add(new TaskC.Trip(i, j, k));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);

            trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < c; j++) {
                    for (int k = 0; k < a; k++)
                        trip.add(new TaskC.Trip(k, i, j));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);

            trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < c; j++) {
                    for (int k = 0; k < b; k++)
                        trip.add(new TaskC.Trip(i, k, j));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);


            trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < a; j++) {
                    for (int k = 0; k < c; k++)
                        trip.add(new TaskC.Trip(j, i, k));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);

            trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < c; j++) {
                    for (int k = 0; k < b; k++)
                        trip.add(new TaskC.Trip(i, k, j));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);


            trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < a; j++) {
                    for (int k = 0; k < b; k++)
                        trip.add(new TaskC.Trip(j, k, i));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);

            trip = new ArrayList<TaskC.Trip>();
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < b; j++) {
                    for (int k = 0; k < a; k++)
                        trip.add(new TaskC.Trip(k, j, i));
                }
            }
            if (checkValidity(out, trip, l).size() > ans.size())
                ans = checkValidity(out, trip, l);

            out.println(ans.size());

            for (TaskC.Trip t : ans) {
                out.println((t.x + 1) + " " + (t.y + 1) + " " + (t.z + 1));

            }


        }

        static class Trip {
            public int x;
            public int y;
            public int z;

            public Trip(int x, int y, int z) {
                this.x = x;
                this.y = y;
                this.z = z;
            }

        }

        static class Pair {
            public int x;
            public int y;
            public int type;

            public Pair(int x, int y, int type) {
                this.x = x;
                this.y = y;
                this.type = type;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                TaskC.Pair pair = (TaskC.Pair) o;

                if (x != pair.x) return false;
                if (y != pair.y) return false;
                return type == pair.type;

            }


            public int hashCode() {
                int result = x;
                result = 31 * result + y;
                result = 31 * result + type;
                return result;
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

