import java.io.File;
import java.util.Scanner;

public class code {
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(new File("C-small-attempt0.in"));// "Asample.in"));
    int input_size = scan.nextInt();
    for (int n = 0; n < input_size; n++) {
      int string_size = scan.nextInt();
      int rep = scan.nextInt();
      String s = scan.next();
      String result = solve(s,rep)?"YES":"NO";
      System.out.println("Case #" + (n + 1) + ": " + result);
    }
  }
  private static boolean solve(String s, int rep) {
    if(s.length() == 1){
      return false;
    }
    int[] a = new int[s.length()];

    for(int i = 0;i < s.length();i++){
      a[i] = toNum(s.charAt(i));
      //System.out.println(a[i]);
    }
    int mul = 1;
    for(int i = 0; i < s.length() * rep; i++){
      mul = multiply(mul,a[i%s.length()]);
    }
    if(mul != -1){
      return false;
    }
    return solve(a, rep, 0, 2);
  }

  private static boolean solve(int[] a, int rep, int start, int target){
      if(target == 5){
        if(start == a.length * rep){
          return true;
        }else{
          return false;
        }
      }
      int result = 1;
      for(int i = start; i < a.length * rep; i++){
        int temp = result;
        result = multiply(result,a[i%a.length]);
        //System.out.println(i + ":"+a[i%a.length]);
        //System.out.println(temp+"*"+ a[i%a.length]+ "="+result);
        if(result == target && solve(a, rep, i + 1, target+1)){
          //System.out.println(i + "t" + target);
          return true;
        }
      }
      return false;
  }

  private static int toNum(char c){
    if(c == 'i'){
      return 2;
    }else if(c == 'j'){
      return 3;
    }else{
      return 4;
    }
  }

  private static int multiply(int a, int b){
    int isNegative = a * b > 0? 1:-1;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    if (a == 1 || b == 1){
      return a * b * isNegative;
    }
    if(a == b){
      return -1 * isNegative;
    }
    if(a == 2){
      if(b == 3){
        return 4 * isNegative;
      }
      if(b == 4){
        return -3 * isNegative;
      }
    }
    if(a == 3){
      if(b == 2){
        return -4 * isNegative;
      }
      if(b == 4){
        return 2 * isNegative;
      }
    }
    if(a == 4){
      if(b == 2){
        return 3 * isNegative;
      }
      if(b == 3){
        return -2 * isNegative;
      }
    }
    return 0;
  }
}
