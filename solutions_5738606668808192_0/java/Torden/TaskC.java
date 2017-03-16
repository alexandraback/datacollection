import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;
import java.lang.Math;



public class TaskC {

	long N,J;
	long pow[][];
	long jamcoins[];
	long divisors[][];

	{
		pow=new long[11][16];
		for(int i=2;i<=10;i++){
			pow[i][0]=1;
			for(int j=1;j<=15;j++)
				pow[i][j]=pow[i][j-1]*i;
		}
	}
	
	long getDivisor(long x){
		for(long y=2;y<(long)Math.sqrt(x);y++)
			if(x%y==0) return y;
		return x;
	}
	
	long evaluate(long x, int base){
		long result=0;
		int digit;
		for(int i=0;i<16;i++){
			digit=(int)(x%2);
			if(digit==1) result+=pow[base][i];
			x/=2;
		}
		return result;
	}
	
	public void parseCase(Scanner input) {
		N=input.nextLong();
		J=input.nextLong();
		jamcoins=new long[(int) J];
		divisors=new long[(int) J][11];
	}
	
	
	public void solveCase() {
		int index=0;
		long n=32769;
		boolean found;
		while (index<J){
			found=true;
			for(int base=2;base<=10;base++){
				long x=evaluate(n,base);
				long divisor=getDivisor(x);
				if(divisor==x){
					found=false;
					break;
				} else {
					divisors[index][base]=divisor;
				}
			}
			if(found){
				jamcoins[index]=n;
				index++;
			} 
			n+=2;
		}
	}

	public String getSolution() {
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<J;i++){
			sb.append("\n");
			sb.append(evaluate(jamcoins[i],10));
			for(int j=2;j<=10;j++)
				sb.append(" "+divisors[i][j]);
		}
		return sb.toString();
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
		new TaskC().runTask(args);

	}

}
