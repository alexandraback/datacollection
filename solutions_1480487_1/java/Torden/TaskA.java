import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class TaskA {
	
	int N;
	int[] J;
	double[] Y;
	double X;

	public void parseCase(Scanner input) {
		N=input.nextInt();
		J=new int[N];
		X=0.0;
		for(int i=0;i<N;i++){
			J[i]=input.nextInt();
			X+=(double)J[i];
		}
	}

	public void solveCase() {
		Y=new double[N];
		int newN=N;
		double sum=X;
		for(int i=0;i<N;i++)
		{
			if(J[i]>2*X/N)
			{
				newN--;
				sum-=J[i];
			}
		}
		for(int i=0;i<N;i++)
		{
			if(J[i]>=2*X/N)
				Y[i]=0.0;
			else
				Y[i]=((X+sum)/newN-J[i])/X;
		}
	}

	public String getSolution() {
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<N;i++)
			sb.append(Y[i]*100+" ");
		return sb.toString();
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
