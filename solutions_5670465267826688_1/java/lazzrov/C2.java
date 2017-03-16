import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C2 {

  public static void main(String[] args) throws FileNotFoundException {
    
    Scanner in = new Scanner(new File("C-large.in"));
//    PrintWriter out = new PrintWriter(System.out);
     PrintWriter out = new PrintWriter(new File("C-large.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      long L = in.nextLong();
      long X = in.nextLong();
      String s = in.next();
      System.out.println(t);
//      System.out.println("Case " + t + ":  ");
      time = System.currentTimeMillis();
      out.println("Case #" + t + ": " + solve(L, X, s));
    }

    out.close();
  }

  static long time = 0;
  
  private static String solve(long L, long X, String string) {
    System.out.println(string);
    String s = string.replaceAll("i+", "i");
    String s2 = string.replaceAll("j+", "j");
    String s3 = string.replaceAll("k+", "k");
    if (s.equals("i")
        || s2.equals("j")
         || s3.equals("k")) {
      return "NO";
    }
    X--;
    
    int at = 0;
    
    // i
    Quaternion r1 = new Quaternion(1, false, ' ');
    while (((r1.hasLetter && r1.letter != 'i') || !r1.hasLetter)) {
      if (System.currentTimeMillis() - time > 3000) {
        return "NO";
      }
      if (at < string.length()) {
        r1 = multiply(r1, new Quaternion(1, true, string.charAt(at)));
        at++;
      } else if (X > 0){
        X--;
        at = 0;
      } else {
        return "NO";
      }
    }
//    System.out.println(r1);
    
    // j
    Quaternion r2 = new Quaternion(1, false, ' ');
    while (((r2.hasLetter && r2.letter != 'j') || !r2.hasLetter)) {     
      if (System.currentTimeMillis() - time > 3000) {
      return "NO";
    }
      if (at < string.length()) {
        r2 = multiply(r2, new Quaternion(1, true, string.charAt(at)));
        at++;
      } else if (X > 0){
        X--;
        at = 0;
      } else {
        return "NO";
      }
    }
//    System.out.println(r2);
    
    // k
    Quaternion r3 = new Quaternion(1, false, ' ');
    while (at < string.length()) {
      if (System.currentTimeMillis() - time > 3000) {
        return "NO";
      }
      r3 = multiply(r3, new Quaternion(1, true, string.charAt(at)));
      at++;
    }
    
    if (X > 0) {
      Quaternion base = new Quaternion(1, false, ' ');
      for (int i = 0; i < string.length(); i++) {
        base = multiply(base, new Quaternion(1, true, string.charAt(i)));
      }
      
      r3 = multiply(r3, exponent(base, X));
    }
//    System.out.println(r3);
    if (r1.hasLetter && r1.letter == 'i' 
        && r2.hasLetter && r2.letter == 'j' 
        && r3.hasLetter && r3.letter == 'k'
        && r1.sign * r2.sign * r3.sign == 1) {
      return "YES";
    }
    
    return "NO";
  }
  
  public static Quaternion exponent(Quaternion base, long n) {
    
    Quaternion res = new Quaternion(1, false, ' ');
      
    while (n > 0) {
      if (n % 2 == 1) {
        res = multiply(res, base);
      }
      
      n >>= 1;
      base = multiply(base, base);
    }
    return res;
  }
  
  
  static class Quaternion {
    int sign;
    boolean hasLetter;
    char letter;
    
    public Quaternion() {
    }
    
    public Quaternion(int a, boolean b, char c) {
      sign = a;
      hasLetter = b;
      letter = c;
    }
    @Override
    public String toString() {
      return sign + " " + hasLetter + " "+ letter;
    }
  }
  
  public static Quaternion multiply(Quaternion a, Quaternion b){
    Quaternion c = new Quaternion();
    
    c.sign = a.sign * b.sign;
    
    if (a.hasLetter || b.hasLetter) c.hasLetter = true;
    else c.hasLetter = false;
    
    if (a.hasLetter && !b.hasLetter) c.letter = a.letter;
    else if (!a.hasLetter && b.hasLetter) c.letter = b.letter;
    else if (a.hasLetter && b.hasLetter) {
      if (a.letter == b.letter) {
        c.letter = ' ';
        c.hasLetter = false;
        c.sign *= -1;
      } else if (a.letter == 'i' && b.letter == 'j') {
        c.letter = 'k';
      } else if (a.letter == 'i' && b.letter == 'k') {
        c.letter = 'j';
        c.sign *= -1;
      } else if (a.letter == 'j' && b.letter == 'i') {
        c.letter = 'k';
        c.sign *= -1;
      } else if (a.letter == 'j' && b.letter == 'k') {
        c.letter = 'i';
      } else if (a.letter == 'k' && b.letter == 'i') {
        c.letter = 'j';
      } else if (a.letter == 'k' && b.letter == 'j') {
        c.letter = 'i';
        c.sign *= -1;
      }
    }
    
    return c;
  }

}
