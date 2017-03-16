import java.util.Scanner;
import java.util.*;
import java.io.BufferedReader;

public class B{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+solve(scanner));
    }
  }

  private static int computeBackstep(String s){
    for(int i=s.length()-1;i>0;i--){
      String last=s.substring(s.length()-i);
      String start=s.substring(0,i);
      if(last.equals(start))
        return i;
    }
    return 0;
  }

  private static int[] computeBacksteps(String s){
    int[] backstep=new int[s.length()+1];
    for(int i=1;i<=s.length();i++)
      backstep[i]=computeBackstep(s.substring(0,i));
    return backstep;
  }

  private static int computeMax(int charactersTyped,String targetWord,Map<Character,Integer> keyProbability,int[] backstep){
    int index=0,bananas=0;

    for(int i=0;i<charactersTyped;i++){
      if(!keyProbability.containsKey(targetWord.charAt(index)))
        return 0;

      index++;
      if(index==targetWord.length()){
        bananas++;
        index=backstep[index];
      }
    }
    return bananas;
  }

  private static int getNextIndex(int index,char next,String word,int[] backstep){
    if(word.charAt(index)==next)
      return index+1;
    if(index==0) return 0;
    return getNextIndex(backstep[index],next,word,backstep);
  }

  private static double computeExpected(int charactersTyped,String targetWord,Map<Character,Integer> keyProbability,int keysCount,int[] backstep){
    double[][] cache=new double[targetWord.length()][charactersTyped+1];

    for(int charactersLeft=1;charactersLeft<=charactersTyped;charactersLeft++)
      for(int spot=0;spot<targetWord.length();spot++){
        double value=0;
        for(Character next:keyProbability.keySet()){
          double prob=(double)keyProbability.get(next)/keysCount;

          if(spot==targetWord.length()-1 && next==targetWord.charAt(spot)){
            int nextIndex=backstep[spot+1];
            value+=prob*(1+cache[nextIndex][charactersLeft-1]);
          }else{
            int nextIndex=getNextIndex(spot,next,targetWord,backstep);
            value+=prob*cache[nextIndex][charactersLeft-1];
          }
        }
        cache[spot][charactersLeft]=value;
      }

    return cache[0][charactersTyped];
  }

  private static double solve(Scanner scanner){
    int keysCount=scanner.nextInt();
    int targetWordLength=scanner.nextInt();
    int typed=scanner.nextInt();
    String keys=scanner.next(); 
    String targetWord=scanner.next(); 
    Map<Character,Integer> keyProbability=new HashMap<Character,Integer>();
    for(int i=0;i<keys.length();i++){
      Character c=keys.charAt(i);
      if(keyProbability.containsKey(c))
        keyProbability.put(c,keyProbability.get(c)+1);
      else
        keyProbability.put(c,1);
    }
    int[] backstep=computeBacksteps(targetWord);
    int bananas=computeMax(typed,targetWord,keyProbability,backstep);
    double expectedBananas=computeExpected(typed,targetWord,keyProbability,keysCount,backstep);

    /*
    for(int i=0;i<backstep.length;i++)
      System.out.print(backstep[i]+",");
    System.out.println("  "+bananas+"  - "+expectedBananas);
    */
    return bananas-expectedBananas;
  }
}
