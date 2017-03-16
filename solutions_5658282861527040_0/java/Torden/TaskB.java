import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class TaskB {
	int A,B,K;
	int result;
	
	public void parseCase(Scanner input) {
		A=input.nextInt();
		B=input.nextInt();
		K=input.nextInt();
	}
	
	public void solveCase() {
		result=0;
		for(int i=0;i<A;i++)
			for(int j=0;j<B;j++)
				if((i&j)<K)
					result++;
		
	}

	public String getSolution() {
		return Integer.toString(result);
	}
	

	public void runTask(String[] args) {
		if(args.length<1)
		{
			System.out.println("Not enough parameters");
			return;
		}
		try{
			Scanner in=new Scanner(new File(args[0]));
			in.useLocale(Locale.ENGLISH);
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
			System.out.println("Case #"+i+": "+getSolution());
		}
		
	}

	public static void main(String[] args) {
		new TaskB().runTask(args);

	}

}
