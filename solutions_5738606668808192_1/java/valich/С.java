package С;

import java.math.BigInteger;
import java.util.*;

public class С {
    private static List<BigInteger> primes = new ArrayList<>();
    static {
        BigInteger i = BigInteger.ONE;
        for (int j = 0; j < 10000; ++j) {
            i = i.nextProbablePrime();
            primes.add(i);
        }
    }
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            final int T = in.nextInt();
            for (int i = 0; i < T; i++) {
                System.out.printf("Case #%d:\n", i + 1);
                solve(in.nextInt(), in.nextInt());
            }
        }
    }

    private static void solve(int N, int J) {
        List<Answer> result = new ArrayList<>();
        Set<String> processed = new HashSet<>();
        final Random random = new Random();
        while (result.size() < J) {
            String s = "1" + Integer.toBinaryString((1 << (N - 2)) + random.nextInt(1 << (N - 2))).substring(1) + "1";
            assert s.length() == N;

            if (!processed.add(s)) {
                continue;
            }
            
            final С.Answer answerForNumber = getAnswerForNumber(s);
            if (answerForNumber != null) {
                result.add(answerForNumber);
            }
        }
        
        Collections.sort(result, new Comparator<С.Answer>() {
            @Override
            public int compare(С.Answer o1, С.Answer o2) {
                return o1.number.compareTo(o2.number);
            }
        });

        for (С.Answer answer : result) {
            System.out.print(answer.number);
            for (String witness : answer.witnesses) {
                System.out.print(" " + witness);
            }
            System.out.println();
        }
    }

    private static Answer getAnswerForNumber(String s) {
        for (int d = 2; d <= 10; ++d) {
            final BigInteger number = new BigInteger(s, d);
            if (number.isProbablePrime(10)) {
                return null;
            }
        }
        final List<String> witnesses = new ArrayList<>();
        outer: for (int d = 2; d <= 10; ++d) {
            final BigInteger number = new BigInteger(s, d);
            
            for (BigInteger p : primes) {
                if (number.mod(p).signum() == 0) {
                    witnesses.add(p.toString(10));
                    continue outer;
                }
            }
            return null;
        }
        return new Answer(s, witnesses);
    }

    private static class Answer {
        public final String number;
        public final List<String> witnesses;

        public Answer(String number, List<String> witnesses) {
            this.number = number;
            this.witnesses = witnesses;
        }
        
        
    }
}
