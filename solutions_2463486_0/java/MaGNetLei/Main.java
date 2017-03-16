
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
		int[] f = {1,4,9,121,484};
		int[] fb =new int[1001];
		for (int i = 0; i < f.length; i++) {
			fb[f[i]]=1;
		}
		int a,b,p1 = 0,p2 = 0,k;
		for (int case_n = 1; case_n <= case_num; case_n++) {
			a=sc.nextInt();
			b=sc.nextInt();
			k=0;
			for (int i = a; i <= b; i++) {
				if (fb[i]==1) k++;
			}
			System.out.println("Case #"+case_n+": "+k);
		}
		try{
			out.close();
		}catch(Exception e){}
	}
	

}
