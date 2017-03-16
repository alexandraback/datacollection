import java.util.Scanner;
import java.io.BufferedReader;

public class B{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+solve(scanner));
    }
  }

  private static int eat(int[] diner,int minutes){
    int specials=0;
    for(int i=0;i<diner.length;i++)
      specials+=Math.max((diner[i]-1)/minutes,0);
    return specials+minutes;
  }

  private static int solve(Scanner scanner){
    int diners=scanner.nextInt();
    int[] diner=new int[diners];
    int most=0;
    for(int i=0;i<diners;i++){
      diner[i]=scanner.nextInt();
      most=Math.max(most,diner[i]);
    }

    if(most==0)
      return 0;

    int best=most;
    for(int i=1;i<most;i++){
      //System.out.println("  "+i+": "+eat(diner,i));
      best=Math.min(best,eat(diner,i));
    }
    return best;
  }
}
