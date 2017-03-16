import java.util.Scanner;
import java.io.BufferedReader;

public class C1{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+solve(scanner));
    }
  }

  private static int count(int n){
    int ret=0;
    while(n>0){
      if(n%2==1)
        ret++;
      n/=2;
    }
    return ret;
  }

  private static boolean valid(int n,int set,int[] coin){
    if((set&(1<<n))!=0)
      return true;
    for(int i=0;i<coin.length;i++)
      if(n==coin[i])
        return true;
    return false;
  }

  private static boolean works(int set,int[] coin,int coinLimit,int most){
    boolean[] canMake=new boolean[most+1];
    canMake[0]=true;

    for(int i=1;i<=most;i++){
      if(!valid(i,set,coin))
        continue;

      for(int j=0;j<coinLimit;j++){
        boolean[] nextCanMake=new boolean[most+1];
        for(int n=0;n<=most;n++){
          nextCanMake[n]=canMake[n];
          if(n>=i && canMake[n-i])
            nextCanMake[n]=true;
        }
        canMake=nextCanMake;
      }
    }


    for(int i=0;i<canMake.length;i++)
      if(!canMake[i])
        return false;
    return true;
  }

  private static int solve(Scanner scanner){
    int coinLimit=scanner.nextInt();
    int coins=scanner.nextInt();
    int most=scanner.nextInt();
    int[] coin=new int[coins];
    for(int i=0;i<coins;i++)
      coin[i]=scanner.nextInt();

    int best=1000;
    for(int i=0;i<(1<<16);i++)
      if(works(i,coin,coinLimit,most))
        best=Math.min(count(i),best);
    return best;
  }
}
