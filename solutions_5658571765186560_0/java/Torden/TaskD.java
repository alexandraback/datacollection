import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskD {

	int X,R,C;
	String result;
	final String GABRIEL="GABRIEL";
	final String RICHARD="RICHARD";
	
	public void parseCase(Scanner input) {
		X=input.nextInt();
		R=input.nextInt();
		C=input.nextInt();
	}
	
	
	public void solveCase() {
		result="";
		switch(X){
		case 1: result="GABRIEL";break;
		case 2: if((R*C)%2==0)
					result=GABRIEL;
				else
					result=RICHARD;
				break;
		case 3: if (R<3&&C<3) { result=RICHARD; break;}
				if (R==1||C==1) { result=RICHARD; break;}
				if ((R*C)%3==0)
					result=GABRIEL;
				else
					result=RICHARD;
				break;
		case 4: if(R<4&&C<4)  { result=RICHARD; break;}
				if (R<=2||C<=2) { result=RICHARD; break;}
				if ((R*C)%4==0)
					result=GABRIEL;
				else
					result=RICHARD;
				break;
				
		}
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
		new TaskD().runTask(args);

	}

}
