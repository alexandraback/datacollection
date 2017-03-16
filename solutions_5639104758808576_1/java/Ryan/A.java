import java.util.Scanner;
import java.io.BufferedReader;

public class A{
  private static final int MULTIPLE=-1,NONE=-2,ROWS=4,COLUMNS=4;

  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+solve(scanner));
    }
  }

  private static int solve(Scanner scanner){
    scanner.nextInt();
    String audience=scanner.next();
    int standing=0,invited=0;
    for(int i=0;i<audience.length();i++){
      int current=audience.charAt(i)-'0';
      int invite=Math.max(i-standing,0);
      invited+=invite;
      standing+=invite;
      standing+=current;
    }
    return invited;
  }
}
