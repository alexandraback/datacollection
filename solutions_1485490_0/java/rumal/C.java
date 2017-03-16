package Round_1C_2012;

import java.util.*;
import java.io.*;
import java.math.*;
import java.text.DecimalFormat;

public class C {

    static int N, M;
    static LinkedList<Y> box = new LinkedList<Y>(), toy = new LinkedList<Y>();

    public static void main(String[] args) throws Exception {
        String file = ".\\Files\\A-";
        if (true) {
            file += "small";
        } else {
            file += "large";
        }
        //file += "-attempt";
        //BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(file + ".in")));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(file + ".out")));
        StringTokenizer st;
        DecimalFormat twoDForm = new DecimalFormat("0.000000");
        int T = Integer.parseInt(in.readLine());
        for (int tt = 1; tt < T + 1; tt++) {
            String testans = "";
            st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            box.clear();
            toy.clear();

            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < N; i++) {
                long n = Long.parseLong(st.nextToken());
                long type = Long.parseLong(st.nextToken());
                box.add(new Y(n, type));
            }

            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < M; i++) {
                long n = Long.parseLong(st.nextToken());
                long type = Long.parseLong(st.nextToken());
                toy.add(new Y(n, type));
            }
//            System.out.println(box);
//            System.out.println(toy);
//            System.out.println();
            long count = counts(box, toy);

            count += totalPossible(box, toy);
//
//            System.out.println(box);
//            System.out.println(toy);
            testans = count + "";
            out.append("\nCase #" + (tt) + ": " + testans);

            System.out.println("Case #" + (tt) + ": " + testans);
        }
        out.close();
    }

    private static long totalPossible(LinkedList<Y> box, LinkedList<Y> toy) {
        long count = 0;
        if (box.isEmpty() || toy.isEmpty()) {
            return 0;
        }
        LinkedList<Y> ttoy = new LinkedList<Y>();
        LinkedList<Y> tbox = new LinkedList<Y>();
        for (Y y : toy) {
            if (y != null) {
                ttoy.add(new Y(y.q, y.t));
            }
        }
        for (Y y : box) {
            if (y != null) {
                tbox.add(new Y(y.q, y.t));
            }
        }
        Y curToy = ttoy.peek();
        Y curBox = tbox.poll();
        if (curBox == null || curToy == null) {
            count = 0;
        } else {
            while (curToy.t != curBox.t) {
                curBox = tbox.poll();
                if (curBox == null) {
                    break;
                }
            }
            tbox.push(curBox);
            count = counts(tbox, ttoy);
            count += totalPossible(tbox, ttoy);
        }

        ttoy.clear();
        tbox.clear();
        for (Y y : toy) {
            if (y != null) {
                ttoy.add(new Y(y.q, y.t));
            }
        }
        for (Y y : box) {
            if (y != null) {
                tbox.add(new Y(y.q, y.t));
            }
        }
        curToy = ttoy.poll();
        curBox = tbox.peek();
        if (curBox == null || curToy == null) {
        } else {
            while (curToy.t != curBox.t) {
                curToy = ttoy.poll();
                if (curToy == null) {
                    break;
                }
            }
            ttoy.push(curToy);
            long y = counts(tbox, ttoy);
            y += totalPossible(tbox, ttoy);
            count = Math.max(y, count);
        }
        return count;

    }

    private static long counts(LinkedList<Y> box, LinkedList<Y> toy) {
//        LinkedList<Y> box = (LinkedList<Y>) tbox.clone();
//        LinkedList<Y> toy = (LinkedList<Y>) ttoy.clone();
//        System.out.println("count");
//        System.out.println(box);
//        System.out.println(toy);
        long count = 0;
        boolean changed = true;
        while (changed) {
            changed = false;
            Y b = box.peek();
            Y t = toy.peek();
            if (b == null || t == null) {
                break;
            }else{
            changed  = true;
            }
//            b = new Y(b.q, b.t);
//            t = new Y(t.q, t.t);
            if (b.t != t.t) {
                break;
            } else {
                changed = true;
            }
            if (b.q > t.q) {
                count += t.q;
                b.q -= t.q;
                toy.poll();
//                ttoy.poll();
            } else if (b.q < t.q) {
                count += b.q;
                t.q -= b.q;
                box.poll();
//                tbox.poll();
            } else {
                count += b.q;
                box.poll();
                toy.poll();
//                ttoy.poll();
//                tbox.poll();
                changed = true;
            }
        }
      ///  System.out.println(count);
        return count;
    }
}

class Y {

    long t;
    long q;

    public Y(long q, long t) {
        this.t = t;
        this.q = q;
    }

    @Override
    public String toString() {
        return t + "-" + q;
    }
}