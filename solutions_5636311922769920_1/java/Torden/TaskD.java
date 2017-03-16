import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskD {

	long K,C,S;
	boolean possible;
	
	public void parseCase(Scanner input) {
		K=input.nextLong();
		C=input.nextLong();
		S=input.nextLong();
	}
	
	
	public void solveCase() {
		possible=C*S>=K;
	}
	
	long item(long start, long end){
		long max=end;
		long sum=start;
		if(end>K-1) max=K-1;
		for(long j=1;j<C;j++){
			if(start<max) start++;
			sum=sum*K+start;
		}
		return sum+1;
	}

	public String getSolution() {
		StringBuilder sb=new StringBuilder();
		if(!possible)
			return "IMPOSSIBLE";
		else {
			for(long i=0;i<(K-1)/C+1;i++)
				sb.append(item(i*C,(i+1)*C-1)+" ");
		}
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
		new TaskD().runTask(args);

	}

}
