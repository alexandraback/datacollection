import java.util.*;

class A {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      int T = scan.nextInt();
      scan.nextLine();
      for (int i = 1; i <= T; i++) {
         System.out.printf("Case #%d: %s\n", i, solve(scan));
      }
   }

   public static Object solve(Scanner scan) {
      return solve(scan.nextLine());
   }

   public static char biggestChar(String s) {
      char c;
      for (c = 'Z'; s.indexOf(c) < 0; c--)
         ;
      return c;
   }

   public static String solve(String s) {
      if (s.length() == 0) return "";

      char c = biggestChar(s);
      StringBuilder out = new StringBuilder();

      for (char i : s.toCharArray()) {
         if (i == c) {
            out.append(c);
         }
      }

      out.append(solve(s.substring(0,s.indexOf(c))));
      for (int i = s.indexOf(c)+1; i < s.length(); i++) {
         if (s.charAt(i) != c) {
            out.append(s.charAt(i));
         }
      }
      return out.toString();
   }
}
