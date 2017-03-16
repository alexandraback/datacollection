package googleJamR1C;

import java.util.*;
import java.io.*;

public class PartElf {
	private static Scanner reader = new Scanner(System.in);
	private static String inputFolder;

	public static void main(String[] args) throws Exception {
		inputFolder = reader.nextLine();

		
		BufferedReader br = new BufferedReader(new FileReader(inputFolder
				+ "\\input.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(inputFolder
				+ "\\output.txt"));
		
		int howManyRounds = Integer.parseInt(br.readLine());
		String currLine;
		long P,Q,p,q,gcd;
		String a,b,k;
		String[] helper;
		int result = 0;

		for (int i = 1; i <= howManyRounds; i++) {
			currLine = br.readLine();
			helper = currLine.split("/");
			P = Long.parseLong(helper[0]);
			Q = Long.parseLong(helper[1]);
			gcd = gcd(P,Q);
			p=P/gcd;
			q=Q/gcd;
			
			if (is2i(q)){
				bw.write("Case #"+i+": "+res(p,q)+"\n");
			}
			else{
				bw.write("Case #"+i+": impossible\n");
			}
			
		}
		
		
		br.close();
		bw.close();
	}
	
	public static long gcd(long x, long y){
		if (y==0)
			return x;
		return gcd(y,x%y);
	}
	
	public static boolean is2i(long x ){
		if (x%2 == 0)
			return is2i(x/2);
		else if (x==1)
			return true;
		else
			return false;
	}
	
	public static String res(long p, long q){
		if (q - Math.pow(2, 40) != 0)
			return res(p*2,q*2);
		
		return res2(p);
		
	}
	
	public static String res2(long p){
		int i = 1;
		while (Math.pow(2, i+1) <= p)
			i++;
		
		return ((Integer) (40-i)).toString();
	}
}
