import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	static double EPS = 1e-9;
	public static void main(String[] args) throws Exception{
		Scanner sc =new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			double rad = sc.nextDouble();
			double paint = sc.nextDouble()*Math.PI;
			long many = 0;
			double white = rad;
			double black = rad+1;
			while(true){
				double whiteC = Math.PI*white*white;
				double blackC = Math.PI*black*black;
				double newC = blackC-whiteC;
				if(newC<paint+EPS){
					many++;
					paint-=newC;
				}
				else break;
				white+=2;
				black+=2;
			}
			System.out.printf("Case #%d: %d%n",t,many);
			out.printf("Case #%d: %d%n",t,many);

		}
		out.close();
	}
}
