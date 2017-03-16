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
      int X = Integer.parseInt(st.nextToken()), R = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken());
      boolean ans = false;
      int min = Math.min(R, C), sum = R * C;
      switch (X) {
        case 1:
          ans = true;
          break;
        case 2:
          ans = sum % 2 == 0;
          break;
        case 3:
          ans = sum % 3 == 0 && min >= 2;
          break;
        case 4:
          ans = sum % 4 == 0 && min >= 3;
          break;
        case 5:
          ans = sum % 5 == 0 && min >= 4;
          break;
        case 6:
          ans = sum % 6 == 0 && min >= 4;
          break;
        default:
          ans = false;
          break;
      }
      if (ans) {
        System.out.println(String.format("Case #%d: GABRIEL", t));
      } else {
        System.out.println(String.format("Case #%d: RICHARD", t));
      }
    }
  } 
}