import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.util.Scanner;


public class A {

  static char[] m = new char[256];
  static {
    m['a'] = 'y';
    m['b'] = 'h';
    m['c'] = 'e';
    m['d'] = 's';
    m['e'] = 'o';
    m['f'] = 'c';
    m['g'] = 'v';
    m['h'] = 'x';
    m['i'] = 'd';
    m['j'] = 'u';
    m['k'] = 'i';
    m['l'] = 'g';
    m['m'] = 'l';
    m['n'] = 'b';
    m['o'] = 'k';
    m['p'] = 'r';
    m['q'] = 'z';
    m['r'] = 't';
    m['s'] = 'n';
    m['t'] = 'w';
    m['u'] = 'j';
    m['v'] = 'p';
    m['w'] = 'f';
    m['x'] = 'm';
    m['y'] = 'a';
    m['z'] = 'q';
  }
  public static String gao(String s) {
    String ret = "";
    for (char c : s.toCharArray()) {
      if (c == ' ') {
        ret += ' ';
      } else {
        ret+=  m[c];
      }
      
    }
    return ret;
    /*
    
    Input
    3
    ejp mysljylc kd kxveddknmc re jsicpdrysi
    rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
    de kr kd eoya kw aej tysr re ujdr lkgc jv


    Output
    our language is impossible to understand
    there are twenty six factorial possibilities
    so it is okay if you want to just give up
    
*/
  }
  public static void main(String[] args) throws Exception {
    
    
    //InputStream in = System.in;
    InputStream in = new FileInputStream("c:\\A-small-attempt0.in");
    
    //Scanner scanner = new Scanner(in);
    BufferedReader r = new BufferedReader(new InputStreamReader(in));
    /*
    for (;;) {
      String l = r.readLine();
      if (l == null) {
        break;
      }
    }
    */
    
    int n = Integer.parseInt( r.readLine());
    for (int i = 1; i <= n; ++i) {
      String s = r.readLine();
      System.out.println("Case #" + i + ": " + gao(s));
    }
    
    
  }

}
