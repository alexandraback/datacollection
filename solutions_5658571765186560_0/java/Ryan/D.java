import java.util.Scanner;
import java.io.BufferedReader;

public class D{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+(solve(scanner)?"GABRIEL":"RICHARD"));
    }
  }

  private static boolean solve(Scanner scanner){
    int omino=scanner.nextInt();
    int r=scanner.nextInt();
    int c=scanner.nextInt();

    int squares=r*c;
    if(squares%omino!=0)
      return false;

    if(omino==1 || omino==2) return true;
    if(omino==4) return r==4 && c==4;

    if(r==3) return c!=1;
    if(c==3) return r!=1;

    return false;
  }
}
