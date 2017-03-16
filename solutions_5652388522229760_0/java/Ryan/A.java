import java.util.*;

public class A{
  private static final int INSOMNIA=0;
  private static final int ALL=(1<<10)-1;

  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      int s=solve(scanner.nextInt());
      if(s==INSOMNIA)
        System.out.println("Case #"+c+": INSOMNIA");
      else
        System.out.println("Case #"+c+": "+s);
    }
  }

  private static int findDigits(int n){
    int seen=0;
    while(n>0){
      seen|=1<<(n%10);
      n/=10;
    }
    return seen;
  }

  private static int solve(int start){
    if(start==0)
      return INSOMNIA;
    int m=0,seen=0;
    while(seen!=ALL){
      m++;
      int next=findDigits(m*start);
      seen|=next;
    }
    return m*start;
  }
}
