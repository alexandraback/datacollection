
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	static Boolean DEBUG = true;
	static PrintStream out;
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		if (DEBUG){
			BufferedInputStream in = new BufferedInputStream(new FileInputStream("std.in"));   
			System.setIn(in);
			out = new PrintStream(new FileOutputStream("std.dout"));   
			System.setOut(out);
		}
		Scanner sc = new Scanner(System.in);
		int case_num = sc.nextInt();
		double[] f = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,
				102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001.,
				10221412201.,12102420121.,12345654321.,40000800004.,1000002000001.,1002003002001.,
				1004006004001.,1020304030201.,1022325232201.,1024348434201.,1210024200121.,1212225222121.,
				1214428244121.,1232346432321.,1234567654321.,4000008000004.,4004009004004.,};
		int p1 = 0,p2 = 0,k;
		double a,b;
		for (int case_n = 1; case_n <= case_num; case_n++) {
			a=sc.nextDouble();
			b=sc.nextDouble();
			k=0;
			for (int i = 0; i < f.length; i++) {
				if (a>f[i]) p1=i+1;
				else if (a==f[i]) p1=i;
				if (b>=f[i]) p2=i;
			}
			System.out.println("Case #"+case_n+": "+(p2-p1+1));
		}
		try{
			out.close();
		}catch(Exception e){}
	}
	

}
