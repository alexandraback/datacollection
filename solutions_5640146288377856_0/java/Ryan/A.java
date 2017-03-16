import java.util.Scanner;
import java.util.*;
import java.io.BufferedReader;

public class A{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+solve(scanner));
    }
  }

  private static Map<Integer,Integer> cache;

  private static int replay(int c,int guesses,int answers,int ship,int guess,int[] valids){
    int best=-1;
    int nextGuesses=guesses|guess;
    boolean isNoValid=false,isYesValid=false,isYesDone=false;

    for(int i=0;i<valids.length;i++){
      int valid=valids[i];
      if((answers&nextGuesses)==(valid&nextGuesses))
        isNoValid=true;

      if(((answers|guess)&nextGuesses)==(valid&nextGuesses))
        isYesValid=true;

      if((answers|guess)==valid)
        isYesDone=true;
    }

    if(isNoValid)
      best=play(c,nextGuesses,answers,ship,valids);

    if(isYesDone)
      best=Math.max(best,0);
    else if(isYesValid)
      best=Math.max(best,play(c,nextGuesses,answers|guess,ship,valids));

    return best;
  }

  private static int play(int c,int guesses,int answers,int ship,int[] valids){
    int key=(guesses<<c)|answers;
    if(cache.containsKey(key))
      return cache.get(key);

    //System.out.println(c+", "+guesses+","+answers);

    int best=1000;
    for(int i=0;i<c;i++){
      int bit=1<<i;
      if((guesses&bit)!=0)
        continue;
      int score=1+replay(c,guesses,answers,ship,bit,valids);
      best=Math.min(best,score);
    }

    cache.put(key,best);
    return best;
  }

  private static int solve(Scanner scanner){
    cache=new HashMap<Integer,Integer>();
    int r=scanner.nextInt();
    int c=scanner.nextInt();
    int ship=scanner.nextInt();

    int[] valids=new int[c-ship+1];
    int shipMap=(1<<ship)-1;
    for(int i=0;i+ship<=c;i++)
      valids[i]=shipMap<<i;

    return play(c,0,0,ship,valids);
  }
}
