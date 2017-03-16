import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskA {

	long N;
	long result;
	boolean digits[];
	int seen;
	
	public void parseCase(Scanner input) {
		N=input.nextLong();
		digits=new boolean[10];
		for(int i =0;i<10;i++)
			digits[i]=false;
		seen=0;
	}
	
	
	public void solveCase() {
		if(N==0) return;
		result=N;
		while(seen<10){
			long n=result;
			long digit;
			while(n>0){
				digit=n%10;
				n/=10;
				if(!digits[(int) digit]){
					digits[(int) digit]=true;
					seen++;
				}
			}
			if(seen<10)
				result+=N;
		}
	}

	public String getSolution() {
		if(result==0)
			return "INSOMNIA";
		else
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
		new TaskA().runTask(args);

	}

}
