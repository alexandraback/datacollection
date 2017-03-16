
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


/**
 *
 * @author ABDULRAHUMAN
 */
public class CoinJam {
    
    static int j,n,count=0;
    static PrintWriter out;
    
    static public void permutation(int length,String str){
        if(count>=j)
            return;
        if(length==n-1){
            boolean flag=true;
            BigInteger divisor[]=new BigInteger[11];
            str+="1";

            
            BigInteger bi;
            BigInteger one=new BigInteger("1");
                BigInteger zero=new BigInteger("0");
                out:for(int i=2;i<=10;i++){
                bi=new BigInteger(str,i);
                BigInteger temp=new BigInteger("2");
                BigInteger end;
                if(str.length()>12)
                end=new BigInteger("999999");
                else
                    end=new BigInteger(str.substring(0,str.length()/2));
               
                if(bi.isProbablePrime(100))
                {
                    flag=false;
                    break;
                }
                for(;temp.compareTo(end)<0;temp=temp.add(one)){
                    
                    if((bi.mod(temp)).equals(zero)){
                        divisor[i]=new BigInteger("0");
                        divisor[i]=temp;
                        continue out;
                    }
                }
                flag=false;
                break;
            }
                if(flag){
                    System.out.print(str+" ");
                    out.print(str+" ");
                    for(int i=2;i<=10;i++){
                        System.out.print(divisor[i]+" ");
                        out.print(divisor[i]+" ");
                    }
                    System.out.println();
                    out.println();
                    count++;
                }
            
        }
        else{
            permutation(length+1,str+'0');
            permutation(length+1,str+'1');
        }
    }
    
    public static void main(String args[]) throws FileNotFoundException, IOException{
        Scanner in=new Scanner(new FileReader("E:\\c.in"));
        out=new PrintWriter(new FileWriter("E:\\c.out"));
        int t=in.nextInt();
        n=in.nextInt();
        j=in.nextInt();
        System.out.println("Case #1:");
        out.println("Case #1:");
        String str="1";
        permutation(1,str);
        System.out.println(count);
        out.close();
       

    } 
}
