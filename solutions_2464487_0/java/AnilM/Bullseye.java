import java.util.*;
import java.lang.*;
public class Bullseye{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		for(int c=1;c<=T;c++)
		{
			long r=in.nextLong(),t=in.nextLong();
			long t1=2*r-1;
			double t2=(Math.sqrt(t1*t1+8*t)-t1)/4;
			long ans=(int)t2;
			System.out.println("Case #"+c+": "+ans);
		}
	}
}
