import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    String orig = "abcdefghijklmnopqrstuvwxyz ";
    String conv = "ynficwlbkuomxsevzpdrjgthaq ";

    Scanner cin = new Scanner(System.in);
    int n = Integer.parseInt(cin.nextLine());

    for(int i=0; i<n; ++i) {

      String s = cin.nextLine();
      int m = s.length();

      String ret = "";

      for(int j=0; j<m; ++j) {
        char c = s.charAt(j);
        int index = conv.indexOf(c);
        ret += orig.charAt(index);
      }

      System.out.println("Case #" + (i + 1) + ": " + ret);

    }

  }

}
