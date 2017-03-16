import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class TaskC {
	
	int A;
	int B;
	int[] valid={1,4,9,121,484};
	int count;
	
	public void parseCase(Scanner input) {
		A=input.nextInt();
		B=input.nextInt();
		count=0;
	}
	
	public void solveCase() {
		for(int i=0;i<valid.length;i++)
			if(A<=valid[i]&&valid[i]<=B)
				count++;
	}

	public String getSolution() {
		return ""+count;
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
			System.out.println("Case #"+i+": "+getSolution());
		}
		
	}

	public static void main(String[] args) {
		new TaskC().runTask(args);

	}

}
