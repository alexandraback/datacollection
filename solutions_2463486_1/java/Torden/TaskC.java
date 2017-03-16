import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class TaskC {
	
	long A;
	long B;
	long count;
	
	public void parseCase(Scanner input) {
		A=input.nextLong();
		B=input.nextLong();
		count=0;
	}
	
	public void solveCase() {
		long low=(long) Math.sqrt(A);
		if(low*low<A) low++;
		long high=(long) Math.sqrt(B);
		for(long i=low;i<=high;i++)
			if(isPalyndrome(i)&&isPalyndrome(i*i))
			{
				count++;
			}
	}
	
	boolean isPalyndrome(long num)
	{
		long copy=num;
		long temp=0;
		while(num!=0)
		{
			temp=temp*10+num%10;
			num/=10;
		}
		return temp==copy;
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
