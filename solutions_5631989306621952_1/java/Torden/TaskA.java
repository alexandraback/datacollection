import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskA {

	String line;
	String result;
	
	public void parseCase(Scanner input) {
		line=input.nextLine();
	}
	
	
	public void solveCase() {
		result="";
		for(int i=0;i<line.length();i++)
			if(result.isEmpty()||Integer.valueOf(line.charAt(i))>=Integer.valueOf(result.charAt(0)))
				result=line.charAt(i)+result;
			else
				result=result+line.charAt(i);
	}

	public String getSolution() {
		return result;
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
		new TaskA().runTask(args);

	}

}
