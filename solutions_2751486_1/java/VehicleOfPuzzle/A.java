import java.util.*;

class A {
  static boolean isCons(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
  }

  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (int tc = 1, tcc = sc.nextInt(); tc <= tcc; ++tc) {
      String name = sc.next();
      int n = sc.nextInt();
      int[] cons = new int[name.length()];
      for (int i = 0; i < name.length(); ++i) {
        cons[i] = isCons(name.charAt(i)) ? 1 + (i == 0 ? 0: cons[i-1]): 0;
      }
      System.err.println(Arrays.toString(cons));
      List<Integer> ends = new ArrayList<Integer>();
      for (int i = 0; i < name.length(); ++i) {
        if (cons[i] >= n) {
          ends.add(i);
        }
      }
      System.err.println(ends);
      long ans = 0;
      for (int i = 0; i < ends.size(); ++i) {
        long minEnd = ends.get(i);
        long maxStart = minEnd - n + 1;
        long minStart = 0;
        long maxEnd = (i == (ends.size() - 1) ? name.length() : ends.get(i + 1)) - 1;
        System.err.printf("%d-%d through %d-%d%n", minStart, maxStart, minEnd, maxEnd);
        long cur = (maxEnd - minEnd + 1) * (maxStart - minStart + 1);
        System.err.println("That's " + cur + " options");
        ans += cur;
      }
      System.out.printf("Case #%d: %d%n", tc, ans);
    }
  }
}
