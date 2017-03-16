import java.text.NumberFormat;
import java.text.ParsePosition;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	
	public static boolean isNumeric(String str)
	{
	  NumberFormat formatter = NumberFormat.getInstance();
	  ParsePosition pos = new ParsePosition(0);
	  formatter.parse(str, pos);
	  return str.length() == pos.getIndex();
	}
	
	public static int countGeneration(int P, int Q)	{
		//if(((Q - 1) & Q) != 0)
		
		while(P%2==0 && Q%2 ==0 && P!=1 && Q!=1)	{
			P/=2;
			Q/=2;
		}
		
		int factor = 3;
		while(factor <= P&& P!=1 && Q!=1){
			while(P%factor == 0 && Q%factor == 0&& P!=1 && Q!=1)	{
				P/=factor;
				Q/=factor;
			}
			factor+=2;
		}
		if(((Q - 1) & Q) != 0) return -1;
		long p = (long)P;
		long q = (long)Q;
		int generation = 0;
		while(p < q)	{
			p*=2;
			generation++;
			if(generation > 40) return -1;
		}
		
		return generation;
	}
	
	
	public static void main(String[] args){
		Scanner scanner = new Scanner( System.in );
		int T  = Integer.parseInt(scanner.nextLine());
		int line  = 0;
		/*ArrayList<Integer> num = new ArrayList<Integer>();
		ArrayList<String> input = new ArrayList<String>();
		ArrayList<Integer> ans = new ArrayList<Integer>();*/
		int[] P = new int[T];
		int[] Q = new int[T];
		while (scanner.hasNextLine())	{
			String Line = scanner.nextLine();
			String[] Lines = Line.split("/");
			P[line] = Integer.parseInt(Lines[0]);
			Q[line] = Integer.parseInt(Lines[1]);
			line++;
		}
		//for ( int i = 0;  i < P.length; i++)
			//System.out.println(P[i] + "/" + Q[i]);
		for ( int i = 0; i < P.length; i++)	{
			int caseid = i+1;
			System.out.print("Case #"+caseid+": ");
			int g = countGeneration(P[i],Q[i]);
			if (g == -1) System.out.println("impossible");
			else System.out.println(g);
			
		}
	}
	
}
