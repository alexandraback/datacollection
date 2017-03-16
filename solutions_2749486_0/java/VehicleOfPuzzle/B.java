import java.util.*;

class B {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (int tc = 1, tcc = sc.nextInt(); tc <= tcc; ++tc) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      String xs = x < 0 ? "EW" : "WE"; x = Math.abs(x);
      String ys = y < 0 ? "NS" : "SN"; y = Math.abs(y);
      System.out.printf("Case #%d: ", tc);
      while (x-->0) System.out.print(xs);
      while (y-->0) System.out.print(ys);
      System.out.println();
    }
  }
}
