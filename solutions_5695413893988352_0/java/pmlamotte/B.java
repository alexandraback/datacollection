import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;
import java.util.stream.Collectors;

public class B {
    public static void main(String[] args) {

        try {
            System.setOut(new PrintStream(new FileOutputStream("B.out")));
            Scanner scan = new Scanner(new FileInputStream("B.in"));
            int cases = scan.nextInt();

            allNums = new ArrayList<Integer>();
            for (int i = 0; i < 1000; i++) {
                allNums.add(i);
            }

            for (int c = 0; c < cases; c++) {
                results = new HashMap<>();
                String one = scan.next();
                String two = scan.next();

                String res = "";
                if (all(one, '?') && all(two, '?')) {
                    res = one.replaceAll("\\?", "0");
                    res = res + " " + res;
                } else {
                    List<Integer> poss1 = find(one, idxs(one));
                    List<Integer> poss2 = find(two, idxs(two));

                    TreeMap<Integer, List<Integer[]>> minDiffs = new TreeMap<>();
                    for (int i = 0; i < poss1.size(); i++) {
                        for (int j = 0; j < poss2.size(); j++) {
                            int diff = Math.abs(poss1.get(i) - poss2.get(j));
                            if (!minDiffs.containsKey(diff)) {
                                minDiffs.put(diff, new ArrayList<Integer[]>());
                            }
                            List<Integer[]> lst = minDiffs.get(diff);
                            lst.add(new Integer[]{poss1.get(i), poss2.get(j)});
                        }
                    }
                        List<Integer[]> results = minDiffs.firstEntry().getValue();

                        int minCoder = Integer.MAX_VALUE;
                        int minJammer = Integer.MAX_VALUE;
                        for (Integer[] result : results) {
                            minCoder = Math.min(minCoder, result[0]);
                            minJammer = Math.min(minJammer, result[1]);
                        }

                        final int minc = minCoder;
                        final int minj = minJammer;
                        results = results.stream().filter(result -> result[0] == minc).collect(Collectors.toList());

                        Integer[] finalRes = results.get(0);
                        for (Integer[] result : results) {
                            if (result[1] < finalRes[1]) {
                                finalRes = result;
                            }
                        }

                        res = leftPad(one.length(), finalRes[0]) + " " + leftPad(two.length(), finalRes[1]);
                }

                System.out.printf("Case #%d: %s%n", c+1, res);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String leftPad(int len, int num) {
        String res = num + "";
        while (res.length() != len) {
            res = "0" + res;
        }
        return res;
    }

    public static List<Integer> allNums;
    public static HashMap<Integer, String> results;

    public static List<Integer> find(String val, boolean[] idxs) {
        return allNums.stream().filter(num -> {
            //System.out.println(num);
            if ((num + "").length() > val.length()) {
                return false;
            }
            int modifier = 1;
            for (int i = idxs.length - 1; i >= 0; i--) {
                if (idxs[i]) {
                    int x = Integer.parseInt(val.charAt(i) + "");
                    if (((num / modifier) % 10) != x) {
                        return false;
                    }
                }
                modifier *= 10;
            }
            return true;

        }).collect(Collectors.toList());
    }

    public static int mask(String x) {
        int mask = 0;
        for (int i = x.length() - 1; i >= 0; i--) {
            if (x.charAt(i) != '?') {
                mask |= (1 << i);
            }
        }
        System.out.println(Integer.toBinaryString(mask));
        return mask;
    }

    public static boolean[] idxs(String x) {
        boolean[] arr = new boolean[x.length()];
        char[] carr = x.toCharArray();
        for (int i = 0; i < carr.length; i++) {
            arr[i] = carr[i] != '?';
        }

        return arr;
    }

    public static boolean all(String x, char cmp) {
        for (char c : x.toCharArray()) {
            if (c != cmp) {
                return false;
            }
        }
        return true;
    }
}
