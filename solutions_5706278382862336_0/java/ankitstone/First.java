package round_1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class First {
static String s;
static long A,B;
static int a[][];
	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
BufferedReader br=new BufferedReader(new FileReader("C://Users/Austin/Downloads/A-small-attempt0.in"));
	//	BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pr=new PrintWriter("E://OO.txt");
		StringBuilder sb=new StringBuilder();
		int t=Integer.parseInt(br.readLine());
		for(int i=1;i<=t;i++){
			s=br.readLine();
			String x[]=s.split("/");
			 A=Long.parseLong(x[0]);
			 B=Long.parseLong(x[1]);
			 factorize();
			 if(!findPower1(B)){
				 sb.append("Case #"+i+": "+"impossible").append("\n");
				 continue;
			 }
			 int X=small();
			 sb.append("Case #"+i+": "+X).append("\n");
		}


//System.out.println(sb);
pr.print(sb.toString());
pr.flush();
pr.close();
br.close();
	}
public static int small(){
	int a=findPower(A);
	int b=findPower(B);
	return Math.abs(b-a);
}
public static void large(){
	
}
public static void factorize(){
	while(true){
		long get=GCD(A, B);
		if(get==1)
			break;
		A/=get;B/=get;
		}
}
public static boolean isPrime(long A){
	if(A%2==0)
		return false;
	if(A==1)
		return false;
	int sqrt=(int) Math.sqrt(A);
	for(int i=3;i<=sqrt;i+=2){
		if(A%i==0)
			return false;
	}
	return true;
}
public static long GCD(long A,long B){
	if(B==0)
		return A;
	return GCD(B,A%B);
}
public static int findPower(long A){
	int i=0;
	for(;Math.pow(2,i)<=A;i++);
		if(Math.pow(2, i)==A)
			return i;
		else return i-1;
}
public static boolean findPower1(long A){
	int i=0;
	for(;Math.pow(2,i)<=A;i++);
		if(Math.pow(2, i)==A || Math.pow(2, i-1)==A)
			return true;
		else return false;
}

}
