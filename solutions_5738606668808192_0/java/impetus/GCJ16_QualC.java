import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collectors;

public class GCJ16_QualC {
    public static void main(String[] args) throws IOException {
        int MAX_PRIME = 1000;
        boolean[] notPrime = new boolean[MAX_PRIME];
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i < MAX_PRIME; i++) {
            if (!notPrime[i]) {
                primes.add(i);
                for (int j = i * i; j < MAX_PRIME; j += i) {
                    notPrime[j] = true;
                }
            }
        }

        Scanner scanner = new Scanner(new FileReader("input.txt"));
        PrintWriter printWriter = new PrintWriter(new FileWriter("output.txt"));

        scanner.nextInt();
        int n = scanner.nextInt();
        int j = scanner.nextInt();

        printWriter.println("Case #1:");

        next: for (BigInteger current = BigInteger.valueOf(2).pow(n - 1).add(BigInteger.ONE); j > 0; current = current.add(BigInteger.valueOf(2))) {
            String str = current.toString(2);
            ArrayList<Integer> primeDivisors = new ArrayList<>();
            for (int base = 2; base <= 10; base++) {
                BigInteger interp = new BigInteger(str, base);
                boolean primeDivisorFound = false;
                for (int prime : primes) {
                    if (interp.mod(BigInteger.valueOf(prime)).compareTo(BigInteger.ZERO) == 0) {
                        primeDivisorFound = true;
                        primeDivisors.add(prime);
                        break;
                    }
                }
                if (!primeDivisorFound) {
                    continue next;
                }
            }
            j--;
            printWriter.print(new BigInteger(str, 10).toString() + " ");
            printWriter.println(String.join(" ", primeDivisors.stream().map(i -> i.toString()).collect(Collectors.toList())));
        }

        printWriter.close();
    }
}
