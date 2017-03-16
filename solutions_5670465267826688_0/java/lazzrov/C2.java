import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C2 {

  public static void main(String[] args) throws FileNotFoundException {
    
    Scanner in = new Scanner(new File("C-small-attempt1.in"));
//    PrintWriter out = new PrintWriter(System.out);
     PrintWriter out = new PrintWriter(new File("C-small-attempt1.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      long L = in.nextLong();
      long X = in.nextLong();
      String s = in.next();

//      System.out.println("Case " + t + ":  ");
      out.println("Case #" + t + ": " + solve(L, X, s));
    }

    out.close();
  }

  private static String solve(long L, long X, String s) {
    
    String string = "";
    for (int i = 0; i < X; i++) {
      string += s;
    }
    
    int at = 0;
    
    // i
    Quaternion r1 = new Quaternion(1, false, ' ');
    while (((r1.hasLetter && r1.letter != 'i') || !r1.hasLetter) && at < string.length()) {
      r1 = multiply(r1, new Quaternion(1, true, string.charAt(at)));
      at++;
    }
//    System.out.println(r1);
    
    // j
    Quaternion r2 = new Quaternion(1, false, ' ');
    while (((r2.hasLetter && r2.letter != 'j') || !r2.hasLetter)  && at < string.length()) {
      r2 = multiply(r2, new Quaternion(1, true, string.charAt(at)));
      at++;
    }
//    System.out.println(r2);
    
    // k
    Quaternion r3 = new Quaternion(1, false, ' ');
    while (at < string.length()) {
      r3 = multiply(r3, new Quaternion(1, true, string.charAt(at)));
      at++;
    }
//    System.out.println(r3);
//    System.out.println(r1 + r2 + r3);
//    System.out.println();
    
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
