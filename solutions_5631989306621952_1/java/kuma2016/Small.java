package year2016.r1a.a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Small {
  static boolean IS_DEBUG = false;
  public static void main(String[] args) throws Exception{
    /*solve("CAB");
    solve("JAM");
    solve("CODE");
    solve("ABAAB");
    solve("CABCBBABC");
    solve("ABCABCABC");
    solve("ZXCASDQWE");*/
    //// GCJ共通 ここから
    //String filename = "src/year2016/r1a/a/A-small-attempt0";
    String filename = "src/year2016/r1a/a/A-large";
    try(PrintWriter out = new PrintWriter(new File(filename + ".out")); Scanner scan = new Scanner(new File(filename + ".in"))){
      
      final int T = scan.nextInt();
      StringBuilder ret = new StringBuilder();
      for (int i = 0; i < T; i++) {
        ret.append("Case #"+(i+1)+": ");
        //// 問題文を読んでsolve()に渡す ここから
        String ans = solve(scan.next());
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
  
  static String solve(String s) {
    StringBuilder sb = new StringBuilder();
    sb.append(s.charAt(0));
    for(int i=1; i<s.length(); i++) {
      if(s.charAt(i) >= sb.charAt(0)){
        sb.insert(0, s.charAt(i));
      } else {
        sb.append(s.charAt(i));
      }
    }
    if(IS_DEBUG) System.out.println(sb.toString());
    return sb.toString();
  }
}
