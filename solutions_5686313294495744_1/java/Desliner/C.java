package codejam.y2016.round1.subroundB;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class C {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/C-large.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            in.nextLine();
            String[] s = new String[N];
            for (int i = 0; i < N; i++) {
                s[i] = in.nextLine();
            }
            /*{
                int a = solveBF(s);
                String answ = "Case #" + t + ": " + a;
                out.println(answ);
                System.out.println(answ);
            }*/
            {
                int a = solve(s);
                String answ = "Case #" + t + ": " + a;
                out.println(answ);
                System.out.println(answ);
            }
            System.out.println();
        }
    }

    private static int solveBF(String[] s) {
        return bf(new boolean[s.length], s, 0);
    }

    static int bf(boolean[] fake, String[] s, int idx) {
        if (idx == s.length) {
            Set<String> first = new HashSet<>();
            Set<String> second = new HashSet<>();
            for (int i = 0; i < s.length; i++) {
                if (!fake[i]) {
                    String[] parts = s[i].split(" ");
                    first.add(parts[0]);
                    second.add(parts[1]);
                }
            }
            for (int i = 0; i < s.length; i++) {
                if (fake[i]) {
                    String[] parts = s[i].split(" ");
                    if (!first.contains(parts[0])) {
                        return Integer.MIN_VALUE;
                    }
                    if (!second.contains(parts[1])) {
                        return Integer.MIN_VALUE;
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < s.length; i++) {
                if (fake[i]) {
                    count++;
                }
            }
            return count;
        }

        fake[idx] = true;
        int res1 = bf(fake, s, idx + 1);

        fake[idx] = false;
        int res2 = bf(fake, s, idx + 1);

        return Math.max(res1, res2);
    }

    static class T implements Comparable<T> {
        String s;
        int car;

        public T(String s, int car) {
            this.s = s;
            this.car = car;
        }

        @Override
        public int compareTo(T o) {
            return car - o.car;
        }
    }

    private static int solve(String[] s) {
        Map<String, Integer> first = new HashMap<>();
        Map<String, Integer> second = new HashMap<>();
        for (String s1 : s) {
            String[] parts = s1.split(" ");

            Integer c1 = first.get(parts[0]);
            if (c1 == null) {
                c1 = 0;
            }
            c1++;
            first.put(parts[0], c1);

            Integer c2 = second.get(parts[1]);
            if (c2 == null) {
                c2 = 0;
            }
            c2++;
            second.put(parts[1], c2);
        }

        List<String> allSorted = new ArrayList<>();
        for (String s1 : s) {
            allSorted.add(s1);
        }
        Collections.sort(allSorted, new Comparator<String>() {

            int score(String q) {
                String[] parts = q.split(" ");
                return first.get(parts[0]) + second.get(parts[1]);
            }

            @Override
            public int compare(String o1, String o2) {
                return score(o1) - score(o2);
            }
        });
/*
        List<T> firstList = new ArrayList<>();
        for (Map.Entry<String, Integer> e : first.entrySet()) {
            firstList.add(new T(e.getKey(), e.getValue()));
        }
        List<T> secondList = new ArrayList<>();
        for (Map.Entry<String, Integer> e : second.entrySet()) {
            secondList.add(new T(e.getKey(), e.getValue()));
        }

        Collections.sort(firstList);
        Collections.sort(secondList);*/

        Set<String> availFirst = new HashSet<>();
        Set<String> availSecond = new HashSet<>();
        Set<String> all = new HashSet<>();
        for (String s1 : s) {
            all.add(s1);
        }

        int addedOrig = 0;
        int totalFaked = 0;
        for (int i = 0; i < allSorted.size(); i++) {
            addedOrig = i;
            String cand = allSorted.get(i);
            String[] parts = cand.split(" ");
            availFirst.add(parts[0]);
            availSecond.add(parts[1]);
            all.remove(cand);
            int faked = 0;
            Set<String> newAll = new HashSet<>();
            for (String o : all) {
                String[] p2 = o.split(" ");
                if (availFirst.contains(p2[0]) && availSecond.contains(p2[1])) {
                    faked++;
                } else {
                    newAll.add(o);
                }
            }
            totalFaked += faked;/*
            if (i > 1 && faked == 0) {
                break;
            }*/
            all = newAll;
        }

        return totalFaked;
    }

    static int[][] convert(String[] s) {
//        int id = 0;
//        Map<String, Integer> map = new HashMap<>();
//        int[][] res = new int[s.length][2];
//        for (int i = 0; i < s.length; i++) {
//            String[] parts = s[i].split(" ");
//            Integer x = map.get(parts[0]);
//            if (x == null) {
//                map.put()
//            }
//        }
        return null;
    }
}
