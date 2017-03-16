package com.meituan.tests.topcoder.jam2013;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

public class FairSquare {

    public boolean isLoop(long n) {
        if (n < 10) {
            return true;
        }
        char[] chars = String.valueOf(n).toCharArray();
        int len = chars.length;
        int a = chars.length / 2;
        len--;
        for (int i = 0; i < a; i++) {
            if (chars[i] != chars[len - i]) {
                return false;
            }
        }
        return true;
    }

    private List<Long> lista=new ArrayList<>();

    public void test() {
        int max = 100000000;
        for (int i = 1; i < max; i++) {
            long n = i * 1L * i;
            if (isLoop(i) && isLoop(n)) {
                System.out.printf("%d\t%d\n", n, i);
                lista.add(n);
            }
        }
    }

    private Map<Integer, List<String>> map1 = new HashMap<>();

    public void gen1() {
        String[] ss = new String[]{"0", "1"};
        List<String> list;
        list = new ArrayList<>(3);
        list.add("0");
        list.add("1");
        list.add("2");
        map1.put(1, list);
        list = new ArrayList<>();
        list.add("00");
        list.add("11");
        map1.put(2, list);
        for (int i = 3; i <= 52; i++) {
            List<String> list1 = map1.get(i - 2);
            list = new ArrayList<>(2 * list1.size());
            for (String s : ss) {
                for (String one : list1) {
                    list.add(s + one + s);
                }
            }
            map1.put(i, list);
        }
    }

    public static void main1(String[] args) throws Exception {
        new FairSquare().test();
        System.out.println("here "+args.length);
    }

    public long test1(final long a, final long b) {
        long t = 0;
        long start=System.currentTimeMillis();
        for (Long n : lista) {
            if(n>=a && n<=b) {
                t++;
            }
        }
        System.out.printf("using %d miilis\n", System.currentTimeMillis() - start);
        return t;
    }

    public static void main(String[] args) throws Exception {
        FairSquare test = new FairSquare();
        test.test();
        File file = new File("/Users/zms/Downloads/C-large-1.in");
        System.out.println(file.exists());
        try (Scanner scanner = new Scanner(new FileReader(file))) {
            File out = new File(file.getParentFile(), "a3.dat");
            try (PrintWriter writer = new PrintWriter(out)) {
                int count = scanner.nextInt();
                for (int i = 0; i < count; i++) {
                    writer.printf("Case #%d: %d\n", i + 1, test.test1(scanner.nextLong(), scanner.nextLong()));
                }
                writer.flush();
            }
        }
    }

}
