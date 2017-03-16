import java.util.*;
import java.math.BigInteger;

public class CoinJam{
    
    public static void main(String args[]){
        int t,n,j;
        Scanner sc = new Scanner(System.in);
        t=sc.nextInt();
        ArrayList<BigInteger> list = new ArrayList<BigInteger>();
        list.add(new BigInteger("2"));
        for(int i=0;i<100;i++){
            list.add(list.get(i).nextProbablePrime());
        }
        char arr[]= new char[500];
        for(int i=0;i<500;i++){
            arr[i]='0';
        }
        String zeros=String.valueOf(arr);
        int forPrint[] = new int[11];
        for(int i=0;i<t;i++){
            System.out.println("Case #1:");
            n=sc.nextInt();
            j= sc.nextInt();
            
            int count=0;
            BigInteger innerString = new BigInteger("0");
            BigInteger increment = new BigInteger("1");
            while(count<j){
                String str=innerString.toString(2);
                str="1"+zeros.substring(0,n-2-str.length())+str+"1";
            //System.out.println(str);
                boolean isPrime= false;
                for(int k=2;k<=10;k++){
                    BigInteger test = new BigInteger(str,k);
                    isPrime=test.isProbablePrime(10);
                    if(isPrime) break;
                    boolean found = false;
                    int currP = 0;
                    while(!found && !isPrime){
                        if(currP>1000) isPrime=true;
                        if(currP>=list.size())list.add(list.get(list.size()-1).nextProbablePrime());
                        BigInteger rem = test.mod(list.get(currP));
                        if(rem.compareTo(BigInteger.ZERO)==0){
                            found=true;
                            forPrint[k]=list.get(currP).intValue();
                        }
                        currP++;
                    }
                }
                innerString=innerString.add(increment);
                if(isPrime) continue;
                count++;
                System.out.print(str);
                for(int k=2;k<=10;k++){
                    System.out.print(" "+forPrint[k]);
                }
                System.out.println();
            }
        }
    }
}
