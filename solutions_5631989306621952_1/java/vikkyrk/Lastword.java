import java.util.Scanner;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class Lastword {
  public static String solve(Scanner scn) {
    String s = scn.next();
    char[] ch = s.toCharArray();
    String res = "" + ch[0];
    for(int i = 1; i < ch.length; i++) {
      if(ch[i] >= res.charAt(0))
        res = ch[i] + res;
      else
        res = res + ch[i];
    }

    return res;
  }

  public static void main(String[] args) throws Exception {
    Scanner scn;
    PrintStream out;
    if(args.length != 1) {
      scn = new Scanner(System.in);
      out = System.out;
    } else {
      String fileName = args[0];
      int pos = fileName.lastIndexOf(".");
      String outFileName = fileName.substring(0, pos) + ".out";
      scn = new Scanner(new File(args[0]));
      out = new PrintStream(new FileOutputStream(outFileName, false));
    }

    int T = scn.nextInt();

    for(int i = 0; i < T; i++) {
      out.println("Case #" + (i+1) + ": " + solve(scn));
    }

    scn.close();
    out.close();
  }
}