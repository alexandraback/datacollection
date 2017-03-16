package year2016.r1a.b;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Small {
  static boolean IS_DEBUG = false;
  public static void main(String[] args) throws Exception{
//    int[][] aii = new int[][]{
//        {1,2,3},
//        {2,3,5},
//        {3,5,6},
//        {2,3,4},
//        {1,2,3}
//    };
//    solve(aii);
    //// GCJ共通 ここから
    String filename = "src/year2016/r1a/b/B-small-attempt0";
    //String filename = "src/year2016/r1a/b/B-large";
    try(PrintWriter out = new PrintWriter(new File(filename + ".out")); Scanner scan = new Scanner(new File(filename + ".in"))){
      
      final int T = scan.nextInt();
      StringBuilder ret = new StringBuilder();
      for (int i = 0; i < T; i++) {
        ret.append("Case #"+(i+1)+": ");
        //// 問題文を読んでsolve()に渡す ここから
        int N = scan.nextInt();
        int[][] aai = new int[2*N-1][N];
        for(int j=0; j<2*N-1; j++) {
          int[] ai = new int[N];
          for(int k=0; k<N; k++) ai[k] = scan.nextInt();
          aai[j] = ai;
        }
        String ans = solve(aai);
        if( IS_DEBUG ) System.out.println(ans);
        ret.append(ans);
        //// 問題文を読んでsolve()に渡す ここまで
        ret.append("\n");
      }
      out.write(ret.substring(0, ret.length()-1));
      out.flush();
    }
    //// GCJ共通 ここまで
  }
  
  static String solve(int[][] aii) {
    // 奇数回しか登場しない数値がN個あるはず
    Map<Integer, Integer> m = new HashMap<>();
    for(int[] ai: aii) for(int i: ai) {
      m.computeIfPresent(i, (k,v) -> v+1);
      m.putIfAbsent(i, 1);
    }
    List<Integer> l = new ArrayList<>();
    for(Map.Entry<Integer, Integer> e : m.entrySet()) {
      if(e.getValue()%2==1) {
        l.add(e.getKey());
      }
    }
    Collections.sort(l);
    StringBuilder ret = new StringBuilder();
    for(Integer i : l){
      ret.append(i.toString());
      ret.append(' ');
    }
    if(IS_DEBUG) System.out.println(ret.substring(0, ret.length()-1));
    return ret.substring(0, ret.length()-1);
  }
}
