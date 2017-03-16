import java.io.*;
import java.util.*;

public class Main {
  int[] a, b, c;
  boolean[] used;
  int n, ans;
  
  public class Game implements Comparable<Game> {
    int requiredStar, id;
    public Game(int rs, int id) {
      requiredStar = rs;
      this.id = id;
    }
    public int compareTo(Game game) {
      return this.requiredStar - game.requiredStar;
    }
  }
  
  public boolean possible() {
    Game[] game = new Game[n];
    boolean[] uu = new boolean[n];
    uu = new boolean[n];
    Arrays.fill(uu, false);
    for (int i = 0; i < n; i++)
      game[i] = new Game(c[i], i);
    Arrays.sort(game);
    int cnt = 0;
    boolean flag = true;
    for (int i = 0; i < n; i++) {
      int id = game[i].id;
      if (!used[id])
        continue;
      uu[id] = true;
      if (game[i].requiredStar <= cnt) {
        if (id % 2 == 0)
          if (uu[id^1])
            cnt += 0;
          else
            cnt++;
        else
          if (uu[id^1])
            cnt++;
          else
            cnt += 2;
      }
      else {
        flag = false;
        break;
      }
    }
    return flag;
  }
  
  public void bf(int id, int d, int p) {
    if (id == n) {
      if (p == n && possible())
        ans = Math.min(ans, d);
      return;
    }
    used[id] = true;
    if (id % 2 == 0)
      if (used[id^1])
        bf(id + 1, d + 1, p);
      else
        bf(id + 1, d + 1, p + 1);
    else
      if (used[id^1])
        bf(id + 1, d + 1, p + 1);
      else
        bf(id + 1, d + 1, p + 2);
    used[id] = false;
    bf(id + 1, d, p);
  }
  
  public void go() throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      n = Integer.parseInt(br.readLine());
      a = new int[n+1];
      b = new int[n+1];
      
      for (int i = 1; i <= n; i++) {
        String[] ss = br.readLine().split(" ");
        a[i] = Integer.parseInt(ss[0]);
        b[i] = Integer.parseInt(ss[1]);
      }
      
      n <<= 1;
      c = new int[n];
      for (int i = 0; i < n / 2; i++) {
        c[i*2] = a[i+1];
        c[i*2+1] = b[i+1];
      }
      
      used = new boolean[n];
      ans = Integer.MAX_VALUE;
      Arrays.fill(used, false);
      bf(0, 0, 0);
      
      if (ans == Integer.MAX_VALUE)
        System.out.println("Case #" + caseNo + ": Too Bad");
      else
        System.out.println("Case #" + caseNo + ": " + ans);
    }
  }
  
  public static void main(String[] args) throws Exception {
    new Main().go();
  }
}
