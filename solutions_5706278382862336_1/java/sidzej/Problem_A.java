import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem_A {
   private PrintWriter writer;
   private Scanner sc;
   private static long[] powerOf2s;

   public static void main(String[] args) throws IOException {
      Problem_A problem = new Problem_A();

      powerOf2s = new long[41];
      powerOf2s[0] = 1;
      for (int i = 1; i <= 40; i++) {
         powerOf2s[i] = powerOf2s[i - 1] * 2;
         System.out.println(powerOf2s[i]);
      }

      //problem.solve("src/test.in");
      //problem.solve("src/A-small-attempt3.in");
      problem.solve("src/A-large.in");
   }

   private long nwd(long p, long q) {
      long c;
      while (p != 0) {
         c = q % p;
         q = p;
         p = c;
      }
      return q;
   }

   private void solve(String inputFilePath) throws IOException {
      sc = new Scanner(new File(inputFilePath));
      writer = new PrintWriter(new File(inputFilePath.replaceAll(".in", ".out")));
      long T = sc.nextLong();
      String line = sc.nextLine();
      for (long i = 1; i <= T; i++) {
         line = sc.nextLine();
         String[] lines = line.split("/");
         long P = Long.parseLong(lines[0]);
         long Q = Long.parseLong(lines[1]);
         writeSolution(i, P, Q);
      }
      writer.close();
   }

   private void writeSolution(long i, long P, long Q) throws IOException {
      long nwd = nwd(P, Q);
      Q = Q / nwd;
      P = P / nwd;
      String solution = "Case #" + i + ": impossible";
      for (int j = 1; j <= 40; j++) {
         if (powerOf2s[j] == Q) {
            int level = 1;
            while (true) {
               if (P * 2l >= Q) {
                  break;
               }
               level++;
               P = P * 2;
            }
            solution = "Case #" + i + ": " + level;
         }
      }
      System.out.println(solution);
      writer.println(solution);
   }

}
