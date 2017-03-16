package sg;

import java.io.*;
import java.util.*;


public class ProblemC {

//    static double calc(int[] marks) {
//
//    }

    static List[] calculate(int[] valuesSet) {
        Arrays.sort(valuesSet);
        Map<Integer, List<Integer>> knownSums = new HashMap<Integer, List<Integer>>();
        for (int value : valuesSet) {
            Map<Integer, List<Integer>> nextKnownSums = new HashMap<Integer, List<Integer>>();
            nextKnownSums.put(value, Arrays.asList(value));
            for (Integer sum : knownSums.keySet()) {
                if (nextKnownSums.containsKey(sum)) {
                    List<Integer> list1 = knownSums.get(sum);
                    List<Integer> list2 = nextKnownSums.get(sum);
                    return new List[]{list1, list2};
                } else {
                    List<Integer> currentList = knownSums.get(sum);
                    nextKnownSums.put(sum, currentList);
                    int nextSum = sum + value;
                    List<Integer> nextList = new ArrayList<Integer>(currentList);
                    nextList.add(value);
                    nextKnownSums.put(nextSum, nextList);
                }
            }
            knownSums = nextKnownSums;
        }
        return null;
    }

    static int sum(List<Integer> list) {
        int sum = 0;
        for (Integer value : list) {
            sum += value;
        }
        return sum;
    }


    public static void main(String[] args) throws IOException {
        final long start = System.currentTimeMillis();

//        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("taskC.out")));
//        BufferedReader reader = new BufferedReader(new FileReader("taskC.in"));

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("C-small-attempt3.out")));
        BufferedReader reader = new BufferedReader(new FileReader("C-small-attempt3.in"));

        String inLine;
        int caseIndex = 0;
        inLine = reader.readLine();
        while (null != (inLine = reader.readLine())) {
            StringTokenizer st = new StringTokenizer(inLine);
            final int n = Integer.parseInt(st.nextToken());
            int[] marks = new int[n];
            for (int i = 0; i < n; i++)
                marks[i] = Integer.parseInt(st.nextToken());
            caseIndex++;
            writer.printf("Case #%d:\r\n", caseIndex);
            List[] res = calculate(marks);
            if (res == null) {
                writer.println("Impossible");
            } else {

                int s1 = sum(res[0]);
                int s2 = sum(res[1]);
//                if(s1 != s2) {
                {
                    System.err.println(s1);
                    System.err.println(Arrays.toString(res[0].toArray()));
                    System.err.println(s2);
                    System.err.println(Arrays.toString(res[1].toArray()));
                }

                writer.println(Arrays.toString(res[0].toArray()));
                writer.println(Arrays.toString(res[1].toArray()));
            }
//            writer.printf("Case #%d: %d\r\n", caseIndex, cnt);
        }

        writer.close();


        final long finish = System.currentTimeMillis();
        final long dur = finish - start;
        System.err.println();
        System.err.println("-----------------");
        System.err.println();
        System.err.println(dur);
    }
}
