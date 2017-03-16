package gcj;

import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.util.*;

/**
 * Created by song on 4/8/16.
 */
public class R1C {
    final static String PATH = "/Users/eatstreet/Downloads/";

    public static void main(String[] args) throws IOException {
        new R1C().solve();
    }

    private void solve() throws IOException {
//        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "C.in"));
        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "C-small-attempt2.in"));
//        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "C-large.in"));
        PrintWriter writer = new PrintWriter(PATH + "C.out", "UTF-8");
        int t = Integer.parseInt(lines.get(0));
        for (int ca=1; ca<=t; ca++) {
            int n = Integer.parseInt(lines.get(ca * 2 - 1));
            final String[] split = lines.get(ca * 2).split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++) {
                a[i] = Integer.parseInt(split[i]) - 1;
            }
            System.out.println("Case:" + ca);
            writer.println(String.format("Case #%d: %s", ca, findBest(a)));
        }
        writer.close();
    }

    private int findBest(int[] a) {
        int n = a.length;
        boolean[] inLoop = new boolean[n];
        boolean[] found = new boolean[n];
        int[] loopLength = new int[n];
        int[] loopGroup = new int[n];
        int[] number = new int[n];
        int loopIndex = 1;
        for (int i=0; i<n; i++) {
            if (!found[i]) {
                int idx = 1;
                number[i] = idx;
                int t = i;
                boolean newLoop = false;
                int newLoopLength = 0;
                while (true) {
                    t = a[t];
                    idx++;
                    if (found[t]) {
                        int t2 = i;
                        while (t2 != t) {
                            inLoop[t2] = false;
                            found[t2] = true;
                            loopGroup[t2] = loopGroup[t];
                            loopLength[t2] = loopLength[t];
                            t2 = a[t2];
                        }
                        break;
                    }
                    if (number[t] > 0) {
                        newLoopLength = idx - number[t];
                        newLoop = true;
                        break;
                    }
                    number[t] = idx;
                }
                if (newLoop) {
                    int start = t;
                    while (true) {
                        found[t] = true;
                        loopLength[t] = newLoopLength;
                        inLoop[t] = true;
                        loopGroup[t] = loopIndex;
                        t = a[t];
                        if (t == start) {
                            break;
                        }
                    }
                    if (!found[i]) {
                        t = i;
                        while (true) {
                            found[t] = true;
                            inLoop[t] = false;
                            loopLength[t] = newLoopLength;
                            loopGroup[t] = loopIndex;
                            t = a[t];
                            if (t == start) {
                                break;
                            }
                        }
                    }
                    loopIndex ++;
                }
            }
        }

        for (int i=0; i<n; i++) {
            System.out.println(i + "->" + a[i] + " " + loopGroup[i] + " " + inLoop[i] + " " + loopLength[i]);
        }

        int pairs = 0;
        int maxDepths = 0;
        int max = 0;
        int pairSum = 0;
        int maxLoop = 0;
        for (int j = 1; j < loopIndex; j++) {
            ArrayList<Integer> roots = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (loopGroup[i] == j) {
                    if (inLoop[i]) {
                        roots.add(i);
                    }
                }
            }
            if (roots.size() > 2) {
                maxLoop = Math.max(maxLoop, roots.size());
            } else {
                pairs++;
                int max1 = 0;
                int max2 = 0;
                for (int i = 0; i < n; i++) {
                    if (loopGroup[i] == j && !inLoop[i]) {
                        int counts = 0;
                        int t = i;
                        while (!inLoop[t]) {
                            t = a[t];
                            counts++;
                        }
                        if (t == roots.get(0)) {
                            max1 = Math.max(max1, counts);
                        } else {
                            max2 = Math.max(max2, counts);
                        }
                    }
                }
                // maxDepths = Math.max(maxDepths, max1 + max2);
                pairSum += 2 + max1 + max2;
            }
        }
        max = Math.max(maxLoop, pairSum);
        System.out.println(max + " " + pairs + " " + pairSum + " " + maxLoop);
        return max;
    }

//    private int calc(int start, List<Integer>[] v) {
//        Map<Integer, Integer> results = new HashMap<>();
//        if (v[start].size() == 2) {
//            results.put(start, 0);
//            int t = v[start].get(0);
//            results.put(t, 1);
//            int last = start;
//            int idx = 2;
//            while (true) {
//                if (v[t].size() != 2) {
//                    return -1;
//                }
//                int next = -1;
//                if (v[t].get(0) == last) {
//                    next = v[t].get(1);
//                } else if (v[t].get(1) == last) {
//                    next = v[t].get(0);
//                } else {
//                    System.out.println("Wrong " + v[t].get(0) + " " + v[t].get(1) + " " + last);
//                    return -1;
//                }
//                if (results.containsKey(next)) {
//                    // System.out.println(idx - results.get(next) + " " + start);
//                    return idx - results.get(next);
//                }
//                last = t;
//                t = next;
//                results.put(next, idx);
//                idx++;
//            }
//        }
//        return -1;
//    }
}
