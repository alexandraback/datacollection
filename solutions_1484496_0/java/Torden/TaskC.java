import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class TaskC {
	
	int N;
	long[] numbers;
	String zeros500="00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	String zeros20="00000000000000000000";
	String oldValue;
	StringBuilder newValue;
	Map<Long,String> subs;

	public void parseCase(Scanner input) {
		N=input.nextInt();
		numbers=new long[N];
		for(int i=0;i<N;i++)
			numbers[i]=input.nextLong();

	}

	public void solveCase() {
		subs=new HashMap<Long,String>();

		if(N==20)
			newValue=new StringBuilder(zeros20);
		else
			newValue=new StringBuilder(zeros500);

		for(int i=1;i<N;i++)
		{
			iterate(0,i,0);
			if(oldValue!=null)
				return;
		}
			
	}

	private void iterate(int startPos, int itemsLeft, long sum) {
		if(itemsLeft==0)
		{
			oldValue=subs.put(sum, newValue.toString());
		}
		else
		{
			for(int i=startPos;i<=N-itemsLeft;i++)
			{
				newValue.setCharAt(i, '1');
				iterate(i+1,itemsLeft-1,sum+numbers[i]);
				if(oldValue!=null)
					return;
				else
					newValue.setCharAt(i,'0');
			}
		}
	}

	public String getSolution() {
		if(oldValue==null)
			return "\nImpossible";
		else
		{
			StringBuilder sb=new StringBuilder("\n");
			String nv=newValue.toString();
			for(int i=0;i<N;i++)
				if(oldValue.charAt(i)=='1')
					sb.append(numbers[i]+" ");
			sb.append("\n");
			for(int i=0;i<N;i++)
				if(nv.charAt(i)=='1')
					sb.append(numbers[i]+" ");
			return sb.toString();
		}
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
		new TaskC().runTask(args);

	}

}
