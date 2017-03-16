import java.io.*;
import java.util.*;

class Main {
  static String[] train;
  public static void main(String[] args) {
    Scanner read = new Scanner(System.in);
    int cases = read.nextInt();
    read.nextLine();
    MAIN:for(int i=1; i<=cases; i++) {
      System.out.printf("Case #%d: ", i);
      int N = read.nextInt();
      train = new String[N];
      for(int j=0; j<N; j++) {
        train[j] = read.next();
      }
      read.nextLine();
      System.out.println(calc(N, new boolean[N], ""));
    }  
  }
  public static int calc(int n, boolean[] flag, String tmp) {
    if(n == 0) {
      return check(tmp)? 1 :0;
    }
    int tmpc = 0;
    for(int i=0; i<flag.length; i++) {
      if(!flag[i]) {
        flag[i] = true;
        tmpc += calc(n-1, flag, tmp+train[i]);
        flag[i] = false;
      }
    }
    return tmpc;
  }
  public static boolean check(String s) {
    boolean[] flags = new boolean[26];
    char[] target = s.toCharArray();
    char tmp = target[0];
    flags[target[0] - 'a'] = true;
    for(int i=1; i<target.length; i++) {
      if(tmp != target[i]) {
        tmp = target[i];
        if(flags[tmp-'a']) {
          return false;
        } else {
          flags[tmp-'a'] = true;
        }
      }
    }
    return true;
  }
}