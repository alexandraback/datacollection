
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Stream;


// 10^6 ~ 2 sec
public class Main {

    private static final String IN_FILENAME = "/Users/kyesipau/dev/personal/src/C-small-attempt6.in";
    private static final String OUT_FILENAME = "/Users/kyesipau/dev/personal/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(IN_FILENAME));
        PrintWriter writer = new PrintWriter(OUT_FILENAME, "UTF-8");

        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            String[] jpsk = reader.readLine().trim().split(" ");
            int j = Integer.parseInt(jpsk[0]);
            int p = Integer.parseInt(jpsk[1]);
            int s = Integer.parseInt(jpsk[2]);
            int k = Integer.parseInt(jpsk[3]);
            int caseNumber = (i + 1);
            List<String> resultList = solve(j, p, s, k);


            int res = resultList.size();
            writer.println("Case #" + caseNumber + ": " + res);
            for (String line : resultList) {
                writer.println(line);
            }
        }

        reader.close();
        writer.close();
    }

    private static List<String> solve(int j, int p, int s, int k) {
        List<Fit> fitList = new ArrayList<>(j * p * s);
        for (int fst = 1; fst <= j; fst++) {
            for (int snd = 1; snd <= p; snd++) {
                for (int trd = 1; trd <= s; trd++) {
                    fitList.add(new Fit(fst, snd, trd));
                }
            }
        }

        List<String> resultList = new LinkedList<>();
        int magic = 20000;

        for (int i = 0; i < magic; i++) {
            Collections.shuffle(fitList);

            Map<String, Integer> firstSecond = new HashMap<>(10000);
            Map<String, Integer> firstThird = new HashMap<>(10000);
            Map<String, Integer> secondThird = new HashMap<>(10000);
            List<String> tempList = new LinkedList<>();

            for (Fit fit : fitList) {
                if (canAdd(fit.getFirst(), fit.getSecond(), fit.getThird(), k, firstSecond, firstThird, secondThird)) {
                    add(fit.getFirst(), fit.getSecond(), fit.getThird(), firstSecond, firstThird, secondThird);
                    String resKey = Integer.toString(fit.getFirst()) + " " + Integer.toString(fit.getSecond()) + " " +
                         Integer.toString(fit.getThird());
                    tempList.add(resKey);
                }
            }

            if (tempList.size() > resultList.size()) {
                resultList = tempList;
            }
        }


        return resultList;
    }

    public static class Fit {

        private int first;
        private int second;
        private int third;

        public Fit(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public int getFirst() {
            return first;
        }

        public void setFirst(int first) {
            this.first = first;
        }

        public int getSecond() {
            return second;
        }

        public void setSecond(int second) {
            this.second = second;
        }

        public int getThird() {
            return third;
        }

        public void setThird(int third) {
            this.third = third;
        }
    }


    private static boolean canAdd(int fst, int snd, int trd, int k, Map<String, Integer> firstSecond,
        Map<String, Integer> firstThird, Map<String, Integer> secondThird) {
        String fsKey = (fst + "") + (snd + "");
        String ftKey = (fst + "") + (trd + "");
        String stKey = (snd + "") + (trd + "");

        Integer fsVal = firstSecond.get(fsKey);
        Integer ftVal = firstThird.get(ftKey);
        Integer stVal = secondThird.get(stKey);

        if (fsVal != null && fsVal >= k) {
            return false;
        }
        if (ftVal != null && ftVal >= k) {
            return false;
        }
        if (stVal != null && stVal >= k) {
            return false;
        }

        return true;
    }

    private static void add(int fst, int snd, int trd, Map<String, Integer> firstSecond,
        Map<String, Integer> firstThird, Map<String, Integer> secondThird) {
        String fsKey = (fst + "") + (snd + "");
        String ftKey = (fst + "") + (trd + "");
        String stKey = (snd + "") + (trd + "");

        add(firstSecond, fsKey);
        add(firstThird, ftKey);
        add(secondThird, stKey);
    }

    private static void add(Map<String, Integer> map, String key) {
        Integer val = map.get(key);
        if (val == null) {
            map.put(key, 1);
        } else {
            map.put(key, val + 1);
        }
    }
}
