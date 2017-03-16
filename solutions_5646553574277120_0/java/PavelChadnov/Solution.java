import java.io.*;
import java.util.*;


public class Solution {
  BufferedReader reader;

  int nextInt() throws IOException {
    tokenizer.nextToken();
    return (int) tokenizer.nval;
  }

  String next() throws IOException {
    tokenizer.nextToken();
    return tokenizer.sval;
  }

  StreamTokenizer tokenizer;
  Scanner in;

  void run() throws Exception {
//    in = new Scanner(System.in);
//    PrintWriter out = new PrintWriter(System.out);
    in = new Scanner(new File("input.txt"));
    PrintWriter out = new PrintWriter(new File("output.txt"));
    reader = new BufferedReader(new InputStreamReader(System.in));
    tokenizer = new StreamTokenizer(reader);
    solve();


    in.close();
    reader.close();
    out.close();
  }

  boolean check(int []coins) {
    int n = coins.length;
    Set<Integer> amounts = new HashSet<>();
    for(int m=1;m<(1<<n);m++) {
      int amount = 0;
      for(int i=0;i<n;i++) {
        if ((m&(1<<i))!=0) {
          amount += coins[i];
        }
      }
      if (amount<=v) {
        amounts.add(amount);
      }
    }
    return amounts.size()==v;
  }

  void rec(int mask, int pos, int cnt) {
    if (cnt>=res)return;
    int []coins = new int[d+cnt];
    for(int i=0;i<d;i++)coins[i]=this.coins[i];
    int idx=d;
    for(int i=0;i<30;i++) {
      if ((mask&(1<<i))!=0) {
        coins[idx++]=i+1;
      }
    }
    if (check(coins)) {
      res = cnt;
    }
    if (cnt==5)return;
    if (pos==30)return;
    rec(mask | (1<<pos), pos+1, cnt+1);
    rec(mask, pos+1, cnt);
  }

  int c, d, v, res;
  int []coins;

  int solve1() {
    c = in.nextInt();
    d = in.nextInt();
    v = in.nextInt();
    coins=new int[d];
    for(int i=0;i<d;i++)coins[i]=in.nextInt();
    res = 1000;
    rec(0, 0, 0);
    return res;
  }

  void solve() throws IOException, Exception {
    int tcs = in.nextInt();
    for (int tc = 1; tc <= tcs; tc++) {
     int x = solve1();
      System.out.println("Case #"+tc+": "+x);
    }
  }

  public static void main(String[] args) throws Exception {
    new Solution().run();
  }
}

