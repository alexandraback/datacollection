package sg;

import java.io.*;
import java.math.BigDecimal;
import java.util.*;


public class ProblemA {

    static BigDecimal[] calc(int[] marks) {
        int[] sortedMarks = Arrays.copyOf(marks, marks.length);
        Arrays.sort(sortedMarks);
        long sum = 0;
        for (int value : marks) {
            sum += value;
        }
        long sum2 = sum;
        Map<Integer, BigDecimal> accum = new HashMap<Integer, BigDecimal>();
        int cnt = 0;
        for (int i = sortedMarks.length - 1; i >= 0; i--) {
            int value = sortedMarks[i];
            if ((value * (i + 1)) > sum + sum2) {
                sum2 -= value;
                accum.put(value, new BigDecimal(0));
            } else {
                cnt = i+1;
                break;
            }
        }

        BigDecimal sumObj = new BigDecimal(sum);
        BigDecimal avg = new BigDecimal(sum + sum2).divide(new BigDecimal(cnt), 50, BigDecimal.ROUND_HALF_UP );
        BigDecimal[] res = new BigDecimal[marks.length];
        for (int i = 0; i < marks.length; i++) {
            int value = marks[i];
            if (accum.containsKey(value)) {
                res[i] = accum.get(value);
                continue;
            }
            BigDecimal a = avg.subtract(new BigDecimal(value)).multiply(new BigDecimal(100)).divide(sumObj, 5, BigDecimal.ROUND_HALF_UP);
            res[i] = a;
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        final long start = System.currentTimeMillis();

//        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("taskA.out")));
//        BufferedReader reader = new BufferedReader(new FileReader("taskA.in"));

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
        BufferedReader reader = new BufferedReader(new FileReader("A-small-attempt0.in"));

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
            BigDecimal[] res = calc(marks);
            writer.printf("Case #%d: %s\r\n", caseIndex, Arrays.toString(res));
        }

        writer.close();


        final long finish = System.currentTimeMillis();
        final long dur = finish - start;
        System.err.println(dur);
    }
}
