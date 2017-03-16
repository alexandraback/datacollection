package code;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Part1 {

	public static void main (String [] args) throws Exception{
		Scanner fileName = new Scanner(System.in);
		FileReader fileRead = new FileReader(fileName.nextLine());
		PrintWriter fileWrite = new PrintWriter(fileName.nextLine());
		Scanner sc = new Scanner(fileRead);
		
		long P, Q;
		String input;
		
		int testCase = 0;
		int TC = sc.nextInt();
		sc.nextLine();
		while (testCase++ < TC){
			input = sc.nextLine();
			P = Long.parseLong(input.split("\\/")[0]);
			Q = Long.parseLong(input.split("\\/")[1]);
			
			
			long n = P; 
			long d = Q; 

			while (d != 0) { 
				long t = d; 
				d = n % d; 
				n = t; 
			} 

			long gcd = n; 

			P /= gcd; 
			Q /= gcd; 
			
						
			if(!(!isPowerOfTwo(Q) || P > Q)){
				long a = P;
				long b = Q;
				int count = 0;
				while (a < b){
					a = a * 2;
					count ++; 
				}
				fileWrite.print("Case #"+ testCase + ": ");
				fileWrite.print(count);
				fileWrite.println();
				
			} else {
				// impossible
				fileWrite.print("Case #"+ testCase + ": ");
				fileWrite.print("impossible");
				fileWrite.println();
			}
			
			
		}
		
		fileWrite.close();
		return;
	}

	
	//checks whether an int is prime or not.
	public static boolean isPowerOfTwo(long i){
		return (i & (i - 1)) == 0;
	}
	
}


/*
 * 
 * 
 * 
 * 
 * inputs = new String[N];
				indexes = new int[N];
				for (int i=0; i<N; i++){
					inputs[i] = sc.nextLine();
					indexes[i] = 0;
				}
				
				
				String prevChar = " ";
				while (N==0){
					/*
					if (Ac == AS.length && Bc == BS.length){
						break;
					}
					if (Ac == AS.length && Bc != BS.length){
						ans = -10000;
						break;
					}
					if (Ac != AS.length && Bc == BS.length){
						ans = -10000;
						break;
					}
					int Adiff = 0;
					int Bdiff = 0;
					prevChar = AS[Ac];
					if (!AS[Ac].equals(BS[Bc])){
						ans = -10000;
						break;
					}
					while (Ac < AS.length && AS[Ac].equals(prevChar)){
						Adiff++;
						Ac++;
					}
					while (Bc < BS.length && BS[Bc].equals(prevChar)){
						Bdiff++;
						Bc++;
					}
					ans += Math.abs(Adiff-Bdiff);
					*/				
				
				//System.out.println(ans);
