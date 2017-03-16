import java.util.Scanner;
import java.util.*;
import java.io.BufferedReader;

public class C2{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+solve(scanner));
    }
  }

  private static int[] add(int[] array,int value){
    int[] newArray=new int[array.length+1];
    for(int i=0;i<array.length;i++)
      newArray[i]=array[i];
    newArray[array.length]=value;
    Arrays.sort(newArray);
    return newArray;
  }

  private static int getMinValue(int[] coin,int coinLimit,int most,int use){
    int coinValue=coin[use-1];
    if(use==1){
      if(coinValue!=1)
        return 1;
      return coinLimit+1;
    }
    int smallMinValue=getMinValue(coin,coinLimit,most,use-1);
    if(smallMinValue<coinValue)
      return smallMinValue;
    return (int)Math.min((long)coinValue*coinLimit+smallMinValue,most+1);
  }

  private static int solve(Scanner scanner){
    int coinLimit=scanner.nextInt();
    int coins=scanner.nextInt();
    int most=scanner.nextInt();
    int[] coin=new int[coins];
    for(int i=0;i<coins;i++)
      coin[i]=scanner.nextInt();
    Arrays.sort(coin);
    do{
      int minValue=getMinValue(coin,coinLimit,most,coin.length);
      if(minValue>most)
        break;
      coin=add(coin,minValue);
    }while(true);

    return coin.length-coins;
  }
}
