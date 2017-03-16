import java.util.*;

public class C{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      System.out.println("Case #"+c+":");
      solve(scanner.nextInt(),scanner.nextInt());
    }
  }

  private static HashSet<Long> USED=new HashSet<Long>();

  private static int random(){
    return Math.abs(new Random().nextInt())%2;
  }

  private static long generate(int digits){
    long ret=1;
    int total=2;
    for(int i=1;i+1<digits;i++){
      ret*=2;
      int r=random();
      int left=digits-1-i;
      int need=(6-total%6)%6;
      if(left<=6){
        //System.out.println(" "+left+", "+need+" : "+total);
        if(need==left)
          r=1;
        else if(need==0)
          r=0;
      }
      if(r!=0)
        ret+=1;

      total+=r;
    }
    long coin=2*ret+1;
    if(total%6!=0){
      System.out.println(print(coin));
      System.out.println("CRAAAAAAAAAAP");
      System.exit(0);
    }
    return coin;
  }

  private static boolean isFactor(long coin,int base,int factor){
    int sum=0,digit=1;
    while(coin>0){
      if(coin%2==1){
        sum=(sum+digit)%factor;
      }
      digit=(digit*base)%factor;
      coin/=2;
    }
    return sum==0;
  }

  private static int factorize(long coin,int base){
    for(int i=2;i<1000;i++){
      if(isFactor(coin,base,i))
        return i;
    }
    return 0;
  }

  private static long[] produceJamcoin(int digits){
    while(true){
      long[] jamcoin=new long[11];
      long coin=generate(digits);
      if(USED.contains(coin))
        continue;
      USED.add(coin);
      boolean good=true;
      jamcoin[0]=coin;
      for(int i=3;i<jamcoin.length;i+=2)
        jamcoin[i]=2;
      for(int i=4;i<jamcoin.length;i+=3)
        jamcoin[i]=3;
      for(int base=2;base<jamcoin.length;base++){
        if(jamcoin[base]!=0){
          if(!isFactor(coin,base,(int)jamcoin[base]))
            System.out.println("CRAP!!!!");
          continue;
        }
        int factor=factorize(coin,base);
        if(factor==0){
          good=false;
          break;
        }
        jamcoin[base]=factor;
      }
      if(good)
        return jamcoin;
    }
  }

  private static String print(long coin){
    String s="";
    while(coin>0){
      s=(coin%2==0?"0":"1")+s;
      coin/=2;
    }
    return s;
  }

  private static void solve(int digits,int count){
    for(int i=0;i<count;i++){
      long[] jamcoin=produceJamcoin(digits);
      System.out.print(print(jamcoin[0]));
      for(int j=2;j<jamcoin.length;j++)
        System.out.print(" "+jamcoin[j]);
      System.out.println();
    }
  }
}
