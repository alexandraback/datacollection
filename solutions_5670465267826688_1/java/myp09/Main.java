import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
    Map<String, String> map = new HashMap<String, String>();
    map.put("11", "1");map.put("1i", "i");map.put("1j", "j");map.put("1k", "k");
    map.put("i1", "i");map.put("ii", "-1");map.put("ij", "k");map.put("ik", "-j");
    map.put("j1", "j");map.put("ji", "-k");map.put("jj", "-1");map.put("jk", "i");
    map.put("k1", "k");map.put("ki", "j");map.put("kj", "-i");map.put("kk", "-1");
    int T = Integer.parseInt(br.readLine());
    for (int t = 1; t <= T; t++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int L = Integer.parseInt(st.nextToken());
      long X = Long.parseLong(st.nextToken());
      if (X > 16) {
        X = 16 + ((X - 16) % 16);
      }
      String line = br.readLine();
      int loc = 0;
      X--;
      String cur = "1";
      boolean sign = true, ans = true;
      for (int k = 0; k < 3; k++) {
        boolean find = false;
        while (loc < L) {
          char ch = line.charAt(loc);
          loc++;
          if (loc == L && X > 0) {
            X--;
            loc = 0;
          }
          cur = map.get(cur + ch);
          if (cur.length() == 2) {
            cur = cur.substring(1);
            sign = !sign;
          }
          if (valid(cur, sign, k, loc == L)) {
            find = true;
            break;
          }
        }
        if (!find) {
          ans = false;
          break;
        }
      }
      if (ans) {
        System.out.println(String.format("Case #%d: YES", t)); 
      } else {
        System.out.println(String.format("Case #%d: NO", t));
      }
    }
  }

  private static boolean valid(String cur, boolean sign, int k, boolean flag) {  
    boolean ret = false;
    if (k == 0) {
      ret = cur.equals("i") && sign;
    } else if (k == 1) {
      ret = cur.equals("k") && sign;
    } else {
      ret = cur.equals("1") && !sign && flag;
    }
    return ret;
  }
}