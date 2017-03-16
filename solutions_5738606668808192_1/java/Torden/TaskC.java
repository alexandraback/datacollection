import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;
import java.math.BigInteger;



public class TaskC {

	long N,J;
	BigInteger pow[][];
	BigInteger jamcoins[];
	BigInteger divisors[][];

	BigInteger getDivisor(BigInteger x){
		BigInteger y=BigInteger.valueOf(11);
		BigInteger max=y.add(BigInteger.valueOf(100));
		for(;y.compareTo(max)<0;y=y.add(BigInteger.valueOf(1)))
			if(x.divideAndRemainder(y)[1].equals(BigInteger.valueOf(0))) return y;
		return x;
	}
	
	BigInteger evaluate(BigInteger x, int base){
		BigInteger result=BigInteger.valueOf(0);
		BigInteger digit;
		for(int i=0;i<32;i++){
			digit=x.divideAndRemainder(BigInteger.valueOf(2))[1];
			if(digit.equals(BigInteger.valueOf(1))) result=result.add(pow[base][i]);
			x=x.divide(BigInteger.valueOf(2));
		}
		return result;
	}
	
	public void parseCase(Scanner input) {
		N=input.nextLong();
		J=input.nextLong();
		jamcoins=new BigInteger[(int) J];
		divisors=new BigInteger[(int) J][11];
		{
			pow=new BigInteger[11][32];
			for(int i=2;i<=10;i++){
				pow[i][0]=BigInteger.valueOf(1);
				for(int j=1;j<=31;j++)
					pow[i][j]=pow[i][j-1].multiply(BigInteger.valueOf(i));
			}
		}
	}
	
	
	public void solveCase() {
		int index=0;
		BigInteger n=pow[2][31].add(BigInteger.valueOf(1));
		boolean found;
		while (index<J){
			found=true;
			for(int base=2;base<=10;base++){
				BigInteger x=evaluate(n,base);
				BigInteger divisor=getDivisor(x);
				if(divisor.equals(x)){
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
			n=n.add(BigInteger.valueOf(2));
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
