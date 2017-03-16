package com.tiennt4;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Created by tiennt4 on 16/04/2016.
 */
public class ArgusArmy {

    public static void main(String[] args) throws IOException {
        String fileName = "resources/B/B-small-attempt0";
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File(fileName + ".out")))) {
            try (BufferedReader br = new BufferedReader(new FileReader(new File(fileName + ".in")))) {
                int numTest = Integer.parseInt(br.readLine());
                for (int i = 1; i <= numTest; i++) {
                    List<List<Integer>> board = new ArrayList<>();
                    int N = Integer.valueOf(br.readLine());
                    for (int j = 0; j < 2*N-1; j++) {
                        List<Integer> r = new ArrayList<>();
                        String[] split = br.readLine().split(" ");
                        for(String h : split) {
                            r.add(Integer.valueOf(h));
                        }
                        board.add(r);
                    }
                    bw.write(String.format("Case #%d: %s\n", i, getLostCol(N,board)));
                }
            }
        }
    }

    public static String getLostCol(int N, List<List<Integer>> data) {
        Map<Integer, Key> count = new HashMap<>();
        data.forEach(l -> {
            l.forEach(v -> {
                if (count.containsKey(v)) {
                    count.get(v).inscreaseValue();
                }else {
                    count.put(v, new Key(v, 1));
                }
            });
        });
        System.out.println("");
        List<Key> collect = count.values().stream().filter(k -> k.count % 2 != 0).collect(Collectors.toList());

        collect.sort(new KeyComparator());

        List<Integer> tmp = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            tmp.add(collect.get(i).v);
        }
        Collections.sort(tmp);
        StringBuilder sb = new StringBuilder(tmp.get(0) + "");
        for (int i = 1; i < N; i++) {
            sb.append(" " + tmp.get(i));
        }

        return sb.toString();
    }

    static class Key {
        int v;
        int count;

        public Key(int v, int c) {
            this.v = v;
            this.count = c;
        }

        public void inscreaseValue() {
            count++;
        }
    }

    static class KeyComparator implements Comparator<Key> {

        @Override
        public int compare(Key o1, Key o2) {
            return (o1.count == o2.count) ? 0 : (o1.count > o2.count ? 1 : -1);
        }
    }
}
