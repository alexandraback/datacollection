import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	static int a,b;
	static double[] p;
	static double[] pp;
	static Scanner in;
	
	
	public static double calculate(int pos,int back){
		return pp[pos-back]*(2*back+b-a+1)+(1.0-pp[pos-back])*(2*back+2*b+2-a);
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		
		in = new Scanner(new File("C:/Users/JiaKY/Desktop/A-small-attempt1.in"));
		System.setOut(new PrintStream("C:/Users/JiaKY/Desktop/A-small-attempt1.out"));
		int testcase = in.nextInt();
		
		
		for(int ii=1;ii<=testcase;ii++){
			a = in.nextInt();
			b = in.nextInt();
			p = new double[a+1];
			pp = new double[a+1];
			for(int i=1;i<=a;i++){
				p[i] = in.nextDouble();
			}
			pp[0] = 1;
			pp[1] = p[1];
			for(int i=2;i<=a;i++){
				pp[i] = pp[i-1]*p[i];
			}
			double ans = Double.MAX_VALUE;
			for(int i=0;i<=a;i++){
				double tmp = calculate(a,i);
				//System.out.println(i+" -> "+tmp);
				if(ans > tmp)
					ans = tmp;
			}
			
			double re = 2.0+(double)b;
			if(ans > re)
				ans = re;
			
			System.out.printf("Case #%d: %f\n",ii,ans);
			
			
		}
		
		
	}

}
