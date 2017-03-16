import java.io.*;
import java.util.*;

public class AB{

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("A-small-attemptAB.in"));
		PrintStream output = new PrintStream(new File("ABfinal.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			System.out.println("case"+i);
			int number = console.nextInt();
			output.println("Case #"+i+": " + find(number) );
		}
	}

	public static int find(int n) {
		if(n%10==0){
			return find(n-1)+1;
		}
		int a=n;
		int c=n;
		int index=1;
		while(a>9){
			a=a/10;
			index++;
		}
		int[] lit=new int[index];
		for(int i=0;i<index;i++){
		lit[i]=c%10;
		c=c/10;
		}
		int b=(int)Math.pow(10,index-1);
		for(int i=0;i<index/2;i++){
			b= (int) (b+(int)lit[index-1-i]*Math.pow(10,i));
		}
		int d=b;
		int[] lit2=new int[index];
		for(int i=0;i<index;i++){
			lit2[i]=d%10;
			d=d/10;
			}
		d=0;
		for(int i=0;i<index;i++){
			d= (int) (d+(int)lit2[index-1-i]*Math.pow(10,i));
		}
		System.out.println(b+"  "+d+"   "+n);
		if(index==1){
			return n;
		}else{
			if(b>=d){
					return find((int)Math.pow(10,index-1))+n-(int)Math.pow(10,index-1);
				}
				return n-d+1+find(b);
		}
}
}