import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;



public class TaskA {
	
	int[] S;
	int Smax;
	int friendsNeeded;

	
	public void parseCase(Scanner input) {
		Smax=input.nextInt();
		S=new int[Smax+1];
		input.useDelimiter("");
		input.next();
		for(int i=0;i<=Smax;i++)
			S[i]=Integer.parseInt(input.next());
		input.reset();
	}
	
	
	public void solveCase() {
		friendsNeeded=0;
		int guestsToGo=0;
		int i=0;
		while (i<=Smax)
		{
			if (i<=guestsToGo)
			{
				guestsToGo+=S[i];
				i++;
			}
			else
			{
				friendsNeeded++;
				guestsToGo++;
			}
				
		}
	}

	public String getSolution() {
		return Integer.toString(friendsNeeded);
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
