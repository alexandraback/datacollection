import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskB {

	int heights[];
	int N;
	
	public void parseCase(Scanner input) {
		heights=new int[2500];
		N=input.nextInt();
		for(int i=0;i<N*(2*N-1);i++){
			int h=input.nextInt();
			heights[h-1]++;
		}
	}
	
	StringBuilder sb;
	
	public void solveCase() {
		sb=new StringBuilder();
		for(int i=0;i<2500;i++)
			if(heights[i]%2==1)
				sb.append((i+1)+" ");
	}

	public String getSolution() {
		return sb.toString().trim();
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
