package cj.y2015.r1b;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.*;

/**
 * Created by admin on 4/6/2015.
 */
public class A {

    private Scanner scanner;
    private Writer writer;
    private Map<Integer, Integer> imap = new HashMap<Integer, Integer>();
    private Deque<Tuple> list = new LinkedList<Tuple>();
    private Set<Integer> set = new HashSet<Integer>();

    public static void main(String[] args) throws IOException {
        A a = new A();
        a.meat();
    }

    private void meat() throws IOException {
        scanner = new Scanner(new FileInputStream("src/cj/y2015/r1b/A-small-attempt1.in"));
        writer = new FileWriter("src/cj/y2015/r1b/A-small-attempt1.out", false);
        int t = scanner.nextInt();
        for (int i=0; i<t; i++) {
            list.clear();
//            imap.clear();
            set.clear();
            int n = scanner.nextInt();
            if (imap.containsKey(n)) {
                writer.write("Case #" + (i + 1) + ": " + imap.get(n) + "\n");
                System.out.println("Case #" + (i + 1) + ": " + imap.get(n));
                continue;
            }
            int tar = 0;
            int count = 0;
            Tuple tp = new Tuple(tar, count);
            if (imap.get(tar)==null)
                imapPut(tar, count);
            list.add(tp);
            while (list.peekFirst().key!=n) {
                Tuple tmp = list.peekFirst();
                int k = tmp.key;
                if (set.contains(k)) {
                    list.removeFirst();
                    continue;
                } else {
                    set.add(k);
                }
//                System.out.println("peek:k="+tmp.key+", v="+tmp.value);
                int n1 = k+1;
                if (imap.containsKey(n1)) {
                    int oldVal = imap.get(n1);
                    if (tmp.value+1<oldVal) {
                        imapPut(n1, tmp.value + 1);
                    }
                } else {
                    imapPut(n1, tmp.value + 1);
                }

                int n2 = flip(k);
                if (imap.containsKey(n2)) {
                    int oldVal = imap.get(n2);
                    if (tmp.value+1<oldVal) {
                        imapPut(n2, tmp.value + 1);
                    }
                } else {
                    imapPut(n2, tmp.value + 1);
                }

                list.add(new Tuple(n1, imap.get(n1)));
                if (n1!=n2)
                    list.add(new Tuple(n2, imap.get(n2)));

                list.removeFirst();
            }

            writer.write("Case #" + (i + 1) + ": " + list.peekFirst().value + "\n");
            System.out.println("Case #" + (i + 1) + ": " + list.peekFirst().value);
        }
        scanner.close();
        writer.close();
    }

    private int flip(int n) {
        String s = String.valueOf(n);
        StringBuilder sb = new StringBuilder();
        for (int i=s.length()-1; i>-1; i--) {
            sb.append(s.charAt(i));
        }
        String k = sb.toString();
        return Integer.parseInt(k);
    }

    private static class Tuple {
        private int key;
        private int value;
        public Tuple(int k, int v) {
            key = k;
            value = v;
        }
    }

    private void imapPut(int k, int v) {
        imap.put(k, v);
//        System.out.println("putting k="+k+", v="+v);
    }
}
