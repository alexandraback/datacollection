import java.util.*;

public class D{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      int patternSize=scanner.nextInt();
      int levels=scanner.nextInt();
      int spots=scanner.nextInt();

      if(levels*spots<patternSize){
        System.out.println("Case #"+c+": IMPOSSIBLE");
        continue;
      }

      System.out.print("Case #"+c+":");
      long[] solvedSpots=solve(patternSize,levels);
      for(int i=0;i<solvedSpots.length;i++)
        System.out.print(" "+solvedSpots[i]);
      System.out.println();
    }
  }

  private static long generate(int start,int levels,int patternSize){
    long ret=0,digits=1;
    for(int i=0;i<levels;i++)
    {
      int digit=start+i;
      if(digit>=patternSize)
        digit=0;

      ret=ret*patternSize+digit*digits;
      digit*=patternSize;
    }
    return ret+1;
  }

  private static long[] solve(int patternSize,int levels){
    long[] ret=new long[(patternSize+levels-1)/levels];
    int start=0;
    for(int i=0;i<ret.length;i++){
      for(int j=0;j<levels;j++)
        ret[i]=generate(start,levels,patternSize);
      start+=levels;
    }
    return ret;
  }
}
