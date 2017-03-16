import java.io.*;
import java.util.*;

public class ABlong{

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("AB-large (1).in"));
		PrintStream output = new PrintStream(new File("AB2final.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			System.out.println("case"+i);
			long number = console.nextLong();
			output.println("Case #"+i+": " + find(number) );
		}
	}

	public static long find(long n) {
		if(n%10==0){
			return find(n-1)+1;
		}
		long a=n;
		long c=n;
		int index=1;
		while(a>9){
			a=a/10;
			index++;
		}
		long[] lit=new long[index];
		for(int i=0;i<index;i++){
		lit[i]=c%10;
		c=c/10;
		}
		long b=(long)Math.pow(10,index-1);
		for(int i=0;i<index/2;i++){
			b= (long) (b+(long)lit[index-1-i]*Math.pow(10,i));
		}
		long d=b;
		int[] lit2=new int[index];
		for(int i=0;i<index;i++){
			lit2[i]=(int) (d%10);
			d=d/10;
			}
		d=0;
		for(int r=0;r<index;r++){
			d= (long) (d+(long)lit2[index-1-r]*Math.pow(10,r));
		}
		System.out.println(b+"  "+d+"   "+n);
		if(index==1){
			return n;
		}else{
			if(b>=d){
					return find((long)Math.pow(10,index-1))+n-(long)Math.pow(10,index-1);
				}
				return n-d+1+find(b);
		}
}

}