import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
 static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

public static BigInteger sqrt(BigInteger n) {
    BigInteger a = BigInteger.ONE;
    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
    while(b.compareTo(a) >= 0) {
      BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
      else a = mid.add(BigInteger.ONE);
    }
    return a.subtract(BigInteger.ONE);
  }

 public static void main(String args[])throws Exception
 {
	 int t;
  	 String s=br.readLine();
 	 t=Integer.parseInt(s);
 	 int x=1;
 	 while(t!=0)
  	 {
		int i=0,lim;
		BigInteger arr[]=new BigInteger[10];
 	 	s=br.readLine();
  		StringTokenizer st=new StringTokenizer(s," ");
  		while(st.hasMoreTokens())
 	 	  arr[i++]=BigInteger.valueOf(Long.parseLong(st.nextToken()));

		//System.out.println(i);
		BigInteger one=new BigInteger("1");
		BigInteger two=new BigInteger("2");
		BigInteger four=new BigInteger("4");
		BigInteger eight=new BigInteger("8");
		BigInteger d = four.multiply(arr[0]).multiply(arr[0]);
		d = d.subtract((four.multiply(arr[0])));
		d = d.add(one);
		d = d.add((eight.multiply(arr[1])));
		//System.out.println(d);
		d = sqrt(d);
		//System.out.println(d);

		BigInteger ans = new BigInteger("1");
		ans=ans.add(d);
		ans=ans.subtract((two.multiply(arr[0])));
		ans=ans.divide(four);

		System.out.print("Case #"+x+": "+ans);
		if(t!=1) System.out.println();
		x++;
		t--;
	 }
 }
}