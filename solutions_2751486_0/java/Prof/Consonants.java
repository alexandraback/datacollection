import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Consonants {

  public static void main(String[] args) throws IOException {
     BufferedReader br = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
    // BufferedReader br = new BufferedReader(new FileReader(new
    // File("test.txt")));
//    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String line = br.readLine();
    int t = Integer.parseInt(line);
    for (int i = 0; i < t; i++) {
      line = br.readLine();
      String[] arr = line.split(" ");
      int res = 0;
      String name = arr[0];
      int n = Integer.parseInt(arr[1]);
      char[] charArray = name.toCharArray();

      List<Integer> regionStartPoints = new ArrayList<>();
      List<Integer> regionEndPoints = new ArrayList<>();

      int idx = 0;
      int regionStartIdx = -1;

      for (char c : charArray) {
        boolean cons = isConsonant(c);
        if (!cons) {
          if (regionStartIdx != -1) {
            if (idx - regionStartIdx >= n) {
              regionStartPoints.add(regionStartIdx);
              regionEndPoints.add(idx);
            }
            regionStartIdx = -1;
          }
        }
        else {
          if (regionStartIdx == -1) {
            regionStartIdx = idx;
          }
        }
        idx++;
      }

      if (regionStartIdx != -1) {
        if (idx - regionStartIdx >= n) {
          regionStartPoints.add(regionStartIdx);
          regionEndPoints.add(idx);
        }
      }

//      System.out.println(regionStartPoints);
//      System.out.println(regionEndPoints);

      for (int j = 0; j < regionStartPoints.size(); j++) {
        Integer end = regionEndPoints.get(j);
        Integer start = regionStartPoints.get(j);
        int regionSize = end-start;
        int biggerThanN = regionSize-n+1;
        int tail = charArray.length-end;
        int subs = tail*biggerThanN + biggerThanN*(biggerThanN+1)/2;
        res+=subs;
          int head = j==0 ? start : (start-(regionEndPoints.get(j-1)-(n-1)));
          int subs2 = head*(tail+(biggerThanN));
          res+=subs2;
      }

      System.out.println("Case #" + (i + 1) + ": " + res);
    }

  }

  private static boolean isConsonant(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
  }

}
