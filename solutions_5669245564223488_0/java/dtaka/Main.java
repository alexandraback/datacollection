import java.io.*;
import java.util.*;

public class Main{
  static final String ANSWER = "Case #%d: %d\n";
  static final int MOD = 1000000007;
  
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      int N = Integer.parseInt(line);
      line = stdin.readLine();
      String[] cars = line.split(" ");
      
      ArrayList<String> arr = new ArrayList<String>();
      
      int[] ssc = new int[26];
      for (int i = 0; i < N; i++) {
        int il = cars[i].length();
        if (il == 0) continue;
        
        char ih = cars[i].charAt(0);
        char it = cars[i].charAt(il-1);
        StringBuffer buf = new StringBuffer(cars[i]);
        cars[i] = "";
        for (int j = i+1; j < N; j++) {
          int jl = cars[j].length();
          if (jl == 0) continue;
          
          char jh = cars[j].charAt(0);
          char jt = cars[j].charAt(jl-1);
          if (it == jh && ih == it && jh == jt) {
            ssc[ih-'a']++;
            buf.append(cars[j]);
            cars[j] = "";
          }
        }
        cars[i] = buf.toString();
      }
      
      //cars = arr.toArray(new String[0]);
      //N = cars.length;
      //arr = new ArrayList<String>();
      for (int i = 0; i < N; i++) {
        
        int il = cars[i].length();
        if (il == 0) continue;
        
        char ih = cars[i].charAt(0);
        char it = cars[i].charAt(il-1);
        
        StringBuffer buf = new StringBuffer(cars[i]);
        cars[i] = "";
        if (ih == it) {
          for (int j = 0; j < N; j++) {
            int jl = cars[j].length();
            if (jl == 0) continue;
            
            char jh = cars[j].charAt(0);
            char jt = cars[j].charAt(jl-1);
            
            if (it == jh) {
              buf.append(cars[j]);
              it = jt;
              il += jl;
              cars[j] = "";
              break;
            } else if (ih == jt) {
              StringBuffer buf2 = new StringBuffer(cars[j]);
              buf2.append(buf);
              ih = jh;
              il += jl;
              cars[j] = "";
              buf = buf2;
              break;
            }
            
          }
        }
        cars[i] = buf.toString();
      }
      
      
      //cars = arr.toArray(new String[0]);
      //N = cars.length;
      arr = new ArrayList<String>();
      for (int i = 0; i < N; i++) {
        
        int il = cars[i].length();
        if (il == 0) continue;
        
        char ih = cars[i].charAt(0);
        char it = cars[i].charAt(il-1);
        StringBuffer buf = new StringBuffer(cars[i]);
        cars[i] = "";
        for (int j = 0; j < N; j++) {
          int jl = cars[j].length();
          if (jl == 0) continue;
          
          char jh = cars[j].charAt(0);
          char jt = cars[j].charAt(jl-1);
          
          if (it == jh) {
            buf.append(cars[j]);
            it = jt;
            il += jl;
            cars[j] = "";
            j = -1;
          } else if (ih == jt) {
            StringBuffer buf2 = new StringBuffer(cars[j]);
            buf2.append(buf);
            ih = jh;
            il += jl;
            cars[j] = "";
            buf = buf2;
            j = -1;
          }
          
        }
        
        arr.add(buf.toString());
        
      }
      
      boolean valid = true;
      boolean[] exist = new boolean[26];
      for (String s : arr) {
        //System.out.println(s);
        int l = s.length();
        boolean[] f = new boolean[26];
        for (int i = 0; i < l; i++) {
          char ch = s.charAt(i);
          if (exist[ch-'a']) {
            valid = false;
            break;
          }
          f[ch-'a'] = true;
        }
        if (!valid) break;
        for (int i = 0; i < 26; i++) {
          exist[i] |= f[i];
        }
      }
      
      int ans = 0;
      if (valid) {
        ans = 1;
        int cnt = arr.size();
        ans = calc(ans, cnt);
        for (int i = 0; i < 26; i++) {
          //System.out.print(ssc[i]+" ");
          if (ssc[i] > 0) ans = calc(ans, ssc[i]+1);
        }
        //System.out.println();
      }
      System.out.printf(ANSWER, t, ans);
    }
  }
  static int calc(int ans, int cnt) {
    for (int i = 2; i <= cnt; i++) {
      ans =  (ans * i) % MOD;
    }
    return ans;
  }
}
