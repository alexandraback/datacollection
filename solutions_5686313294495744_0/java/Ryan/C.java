import java.util.*;

public class C{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      System.out.println("Case #"+c+": "+solve(read(scanner)));
    }
  }

  private static int solve(int[][] topics){
    int best=0;
    for(int set=0;set<(1<<topics.length);set++)
      if(isValid(set,topics))
        best=Math.max(best,count(set));
    return best;
  }

  private static boolean isValid(int set,int[][] topics){
    HashSet<Integer> realFirst=new HashSet<Integer>();
    HashSet<Integer> realSecond=new HashSet<Integer>();
    for(int i=0;i<topics.length;i++)
      if((set & (1<<i))==0){
        realFirst.add(topics[i][0]);
        realSecond.add(topics[i][1]);
      }

    for(int i=0;i<topics.length;i++)
      if((set & (1<<i))!=0){
        if(!realFirst.contains(topics[i][0]))
          return false;
        if(!realSecond.contains(topics[i][1]))
          return false;
      }
    return true;
  }

  private static int count(int n){
    int ret=0;
    while(n>0){
      if(n%2!=0)
        ret++;
      n/=2;
    }
    return ret;
  }

  private static int[][] read(Scanner scanner){
    int n=scanner.nextInt();
    int[][] ret=new int[n][2];
    HashMap<String,Integer> map=new HashMap<String,Integer>();
    for(int i=0;i<n;i++){
      ret[i][0]=add(scanner.next(),map);
      ret[i][1]=add(scanner.next(),map);
    }
    return ret;
  }

  private static int add(String word,HashMap<String,Integer> map){
    if(map.containsKey(word))
      return map.get(word);
    map.put(word,map.size());
    return map.get(word);
  }
}
