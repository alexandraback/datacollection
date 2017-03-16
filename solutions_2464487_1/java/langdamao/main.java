import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
public class main {
     public static void main (String[] args)throws IOException{
    	 Scanner in=new Scanner (new File("A-large.in"));
    	 File file =new File("A-large.out");
    	 FileWriter out = new FileWriter(file);
    	 int tt = in.nextInt();//System.out.printf("%d\n",tt);
    	 for (int ca=1;ca<=tt;ca++){
    		 BigInteger r = new BigInteger ("0");
    		 BigInteger t = new BigInteger ("0");
    		 r=in.nextBigInteger();
    		 t=in.nextBigInteger();
    		 BigInteger head=new BigInteger ("0");
    		 BigInteger tail=new BigInteger ("2000000000");
    		 boolean got = false;
    		 BigInteger ans = new BigInteger("0");
    		 while (head.compareTo(tail)<=0){
    		   BigInteger mid = new BigInteger("0");
    		   BigInteger er=new BigInteger("2");
    		   mid = head.add(tail).divide(er);
    		   BigInteger temp = er.multiply(mid).multiply(r);
    		   temp=temp.add(mid.multiply(er).multiply(mid).subtract(mid));
    		   //System.out.print(head.toString()+" "+tail.toString()+" "+temp.toString()+"\n");
    		   if (temp.compareTo(t)<0) head = mid.add(new BigInteger("1"));
    		   if (temp.compareTo(t)>0) tail=mid.subtract(new BigInteger("1"));
    		   if (temp.compareTo(t)==0) {got=true; ans=mid;break;}
    		 }
    		 if (!got) ans=tail;
    		 out.write("Case #"+ca+": "+ans.toString()+"\r\n");
    	 }
		 out.close();
     }
}
