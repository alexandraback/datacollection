package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class TrainCars {
    public static final long MOD = 1000000007;

    public static void main(String[] args) throws IOException {

        String fileName;

        fileName = "test.in";
        fileName = "B-small-attempt1.in";
//        fileName = "A-large.in";


        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")));) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            s.nextLine();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int n = s.nextInt();
                s.nextLine();
                String str = s.nextLine();
                String[] split = str.split("\\s+");

                w.write("Case #" + (i + 1) + ": " + calc(split) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(String[] s) {
        // check that internal letters do not repeat
        // reduce to 1 or 2 letters strings

        for (int i = 0; i < s.length; i++) {
            String s1 = s[i];
            boolean[] charsUsed = charsUsed(s, i);
            boolean[] charsUsed2 = Arrays.copyOf(charsUsed, charsUsed.length);


            StringBuilder strip = new StringBuilder();
            strip.append(s1);
            while(strip.length() >1) {
                if(strip.charAt(0) == strip.charAt(1)) {
                    strip.delete(0, 1);
                } else{
                    break;
                }
            }

            while(strip.length() >1) {
                if(strip.charAt(strip.length()-1) == strip.charAt(strip.length()-2)) {
                    strip.delete(strip.length()-2, strip.length()-1);
                } else{
                    break;
                }
            }


            char prev = '\0';
            for (int j = 1; j < strip.length() - 1; j++) {
                char c = strip.charAt(j);
                if(charsUsed2[c - 'a'] && c!= prev )  {
                    return "" + 0;
                }
                charsUsed2[c - 'a'] |= true;
                prev = c;
            }
        }

        List<String> singleChar = new ArrayList<>();
        List<String> doubleChar = new ArrayList<>();
        for (int i = 0; i < s.length; i++) {
            String str = s[i];
            if (single(str)) {
                singleChar.add(str);
            } else {
                doubleChar.add(str);
            }
        }


        Node[] graph = new Node[doubleChar.size()];

        for (int i = 0; i < doubleChar.size(); i++) {
            graph[i] = new Node(i, doubleChar.get(i));
        }

        for (int i = 0; i < doubleChar.size(); i++) {
            Node node = graph[i];
            for (int j = 0; j < doubleChar.size(); j++) {

                if (i == j) {
                    continue;
                } else {
                    if (node.getLast() == graph[j].getFirst()) {
                        node.addEdge(graph[j]);
                    }
                }
            }
        }

        boolean[] used = new boolean[graph.length];

        List<Comp> blocks = new ArrayList<>();

        for (int i = 0; i < graph.length; i++) {
            Node node = graph[i];
            if (!used[i] && node.getInEdge().isEmpty()) {
                int index = i;
                Comp component = new Comp();

                while (true) {
                    component.add(node);
                    used[index] = true;

                    if (node.getOutEdge().size() == 0) {
                        blocks.add(component);
                        break;
                    } else if (node.getOutEdge().size() > 1) {
                        return "" + 0;
                    } else {
                        node = node.getOutEdge().get(0);
                        index = node.id;
                        if (used[index]) {
                            return "" + 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < used.length; i++) {
            if (!used[i]) {
                return "" + 0;
            }
        }

        long result = 0;


        Map<Character, Long> count = new HashMap<>();

        for (int i = 0; i < singleChar.size(); i++) {
            String str = singleChar.get(i);
            char c = str.charAt(0);
            Long aLong = count.get(c);
            if (aLong == null) {
                aLong = 1L;
                count.put(c, aLong);
            } else {
                aLong += 1;
                count.put(c, aLong);
            }
        }

        Map<Character, Long> unused = new HashMap<>();

        for (Character c : count.keySet()) {
            long cnt = count.get(c);

            boolean usedC = false;
            for (int i = 0; i < blocks.size(); i++) {
                Comp comp = blocks.get(i);
                if (comp.contains(c)) {
                    updateCount(comp, cnt);
                    usedC = true;
                }
            }
            if (!usedC) {
                unused.put(c, cnt);
            }
        }

        List<Long> comps = new ArrayList<>();
        for (Long integer : unused.values()) {
            comps.add(integer);
        }
        for (Comp block : blocks) {
            comps.add(block.count);
        }
        long res = 1;

        for (int i = 0; i < comps.size(); i++) {
            long cnt = comps.get(i);
            //factorial
            res = (res * (i + 1)) % MOD;
            while (cnt > 0) {
                res = (res * cnt) % MOD;
                cnt--;
            }
        }

        return "" + res;

    }

    private static void updateCount(Comp comp, long cnt) {
        while (cnt > 0) {
            comp.count = (comp.count * cnt) % MOD;
            cnt--;
        }
    }

    private static boolean single(String str) {
        char c = str.charAt(0);
        for (int i = 0; i < str.length(); i++) {
            if (c != str.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    private static boolean haveInternalEqual(String s1, String s2) {
        for (int i = 1; i < s1.length() - 1; i++) {
            for (int j = 1; j < s2.length() - 1; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean[] charsUsed(String[] s, int exclude) {
        boolean[] charsUsed = new boolean[100];

        for (int i = 0; i < s.length; i++) {
            if (i == exclude) {
                continue;
            }
            for (int j = 0; j < s[i].length(); j++) {
                char c = s[i].charAt(j);
                charsUsed[c - 'a'] |= true;
            }
        }
        return charsUsed;
    }

    static class Node {
        int id;
        String str;
        List<Node> outEdge = new ArrayList<>();
        List<Node> inEdge = new ArrayList<>();


        Node(int id, String str) {
            this.id = id;
            this.str = str;
        }

        public void addEdge(Node node) {
            outEdge.add(node);
        }

        public void addInEdge(Node node) {
            inEdge.add(node);
        }

        public char getFirst() {
            return str.charAt(0);
        }

        public char getLast() {
            return str.charAt(str.length() - 1);
        }

        List<Node> getOutEdge() {
            return outEdge;
        }

        List<Node> getInEdge() {
            return inEdge;
        }
    }

    static class Comp {
        List<Node> nodes = new ArrayList<>();
        long count = 1;

        public void add(Node node) {
            nodes.add(node);
        }

        public boolean contains(Character c) {
            for (Node node : nodes) {
                if (node.getFirst() == c || node.getLast() == c) {
                    return true;
                }
            }
            return false;
        }
    }
}


