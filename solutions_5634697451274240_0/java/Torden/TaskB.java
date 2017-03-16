import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskB {

	long result;
	String line;
	
	public void parseCase(Scanner input) {
		line=input.nextLine();
	}
	
	
	public void solveCase() {
		result=0;
		char last='+';
		for(int i=line.length()-1;i>=0;i--)
			if(line.charAt(i)!=last){
				last=line.charAt(i);
				result++;
			}
	}

	public String getSolution() {
		return ""+result;
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
