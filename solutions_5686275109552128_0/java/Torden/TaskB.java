import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;



public class TaskB {
	
	int D;
	int[] P;
	int minutes;
	
	public void parseCase(Scanner input) {
		D=input.nextInt();
		P=new int[1000];
		for(int i=0;i<D;i++)
			P[i]=input.nextInt();
	}
	
	int maxPos(){
		int max=0;
		int pos=-1;
		for (int i=0;i<D;i++)
			if(P[i]>max)
			{
				max=P[i];
				pos=i;
			}
		return pos;
	}
	
	public void solveCase() {
		minutes=P[maxPos()];
		while(true)
		{
			int pos=maxPos();
			int val=P[pos];
			P[pos]=(val+1)/2;
			if(P[maxPos()]+1<val)
			{
				D++;
				P[D-1]=val-P[pos];
				minutes=minutes-P[D-1]+1;
			}
			else
				break;
		}
	}

	public String getSolution() {
		return Integer.toString(minutes);
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
