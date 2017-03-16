import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import static java.lang.Math.min;


public class TaskA {
	int A;
	int B;
	double[] p;
	double[] probs;
	double[] best;

	public void parseCase(Scanner input) {
		input.useLocale(Locale.US);
		A=input.nextInt();
		B=input.nextInt();
		input.nextLine();
		p=new double[A];
		for(int i=0;i<A;i++)
			p[i]=input.nextDouble();
		

	}

	public void solveCase() {
		double prob=1.0;
		probs=new double[A+1];
		probs[0]=1.0;
		for(int i=1;i<=A;i++){
			prob*=p[i-1];
			probs[i]=prob;
		}
		
		best=new double[A+1];
		best[0]=B+1;
		for(int i=1;i<=A;i++){
			double ifFinish=probs[i]*(B-i+1)+(1-probs[i])*(B-i+1+B+1);
			double ifBack=best[i-1]+1;
			double ifEnter=B+2;
			best[i]=min(ifFinish,min(ifBack,ifEnter));
		}

	}

	public String getSolution() {
		return Double.toString(best[A]);
	}

	public void runTask(String[] args) {
		if(args.length<1)
		{
			System.out.println("Not enough parameters");
			return;
		}
		try{
			Scanner in=new Scanner(new File(args[0]));
			PrintWriter out=new PrintWriter(new File(args[1]));
			runCases(in,out);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public void runCases(Scanner in, PrintWriter out){
		int numOfCases=in.nextInt();
		in.nextLine();
		for(int i=1;i<=numOfCases;i++){
			parseCase(in);
			solveCase();
			out.println("Case #"+i+": "+getSolution());
			out.flush();
		}
		
	}

	public static void main(String[] args) {
		new TaskA().runTask(args);

	}

}
