package Round1B;

import java.util.Scanner;
import java.util.TreeMap;

public class ProbB {
	//public static TreeMap<Integer,String> diffs = new TreeMap<Integer,String>();
	static long mindist=Long.MAX_VALUE;
	static String minC;
	static String minJ;
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		long t = sc.nextInt();
		for(int curcase=1;curcase<=t;curcase++)
		{
		String C = sc.next();
		String J = sc.next();
		mindist=Long.MAX_VALUE;
		recurse(C.toCharArray(),J.toCharArray(),0,0);
		System.out.println("Case #"+curcase+": "+minC+" "+minJ);		
		}
		
	}
	//bigger >0 means C bigger, bigger = 0 undecided, bigger <0 means J bigger
	public static void recurse(char[] C,char[] J,int earlQ,int bigger)
	{
		if(earlQ == C.length)
		{
			String CC = new String(C);
			String JJ = new String(J);
			long dist = Math.abs(Long.parseLong(CC)-Long.parseLong(JJ));
//			diffs.put(Math.abs(Integer.parseInt(CC)-Integer.parseInt(JJ)), CC+" "+JJ);
			if(dist<mindist)
			{
				mindist = dist;minC = CC;minJ = JJ;
			}
			if((dist==mindist)&&(Long.parseLong(CC)<Long.parseLong(minC)))
			{
				minC = CC;minJ = JJ;
			}
			if((dist==mindist)&&(Long.parseLong(CC)==Long.parseLong(minC))&&(Long.parseLong(JJ)<Long.parseLong(minJ)))
			{
				minC = CC;minJ = JJ;
			}
			return;
		}
		if((C[earlQ]!='?')&&(J[earlQ]!='?'))
		{
			if((bigger==0)&&(C[earlQ]!= J[earlQ]))
			{
				bigger = C[earlQ]-J[earlQ];
			}
			recurse(C,J,earlQ+1,bigger);
			return;
		}
		if((C[earlQ]!='?')&&(J[earlQ]=='?'))
		{
			if( bigger==0){
			if(C[earlQ]>'0')
			{
				J[earlQ] = (char) (C[earlQ]-1);
				recurse(C,J,earlQ+1,1);
			}else
			{
				J[earlQ] = '9';
				recurse(C,J,earlQ+1,-1);
			}
			J[earlQ] = C[earlQ];
			recurse(C,J,earlQ+1,0);
			if(C[earlQ]<'9')
			{
				J[earlQ] = (char) (C[earlQ]+1);
				recurse(C,J,earlQ+1,-1);
			}else{
				J[earlQ] = '0';
				recurse(C,J,earlQ+1,1);
			}
			J[earlQ] ='?';
			}
			if(bigger>0)
			{
				J[earlQ] = '9';
				recurse(C,J,earlQ+1,bigger);
				J[earlQ] ='?';
			}
			if(bigger<0)
			{
				J[earlQ] = '0';
				recurse(C,J,earlQ+1,bigger);
				J[earlQ] ='?';				
			}			

				return;
		}
		if((C[earlQ]=='?')&&(J[earlQ]!='?'))
		{
			if(bigger ==0)
			{
			if(J[earlQ]>'0')
			{
				C[earlQ] = (char) (J[earlQ]-1);
				recurse(C,J,earlQ+1,-1);
			}else
			{
				C[earlQ] ='9';
				recurse(C,J,earlQ+1,1);
			}
			C[earlQ] = J[earlQ];
			recurse(C,J,earlQ+1,bigger);
			if(J[earlQ]<'9')
			{
				C[earlQ] = (char) (J[earlQ]+1);
				recurse(C,J,earlQ+1,1);
			}else{
				C[earlQ] = '0';
				recurse(C,J,earlQ+1,-1);
			}
			
			C[earlQ] ='?';}
		if(bigger>0)
		{
			C[earlQ] = '0';
			recurse(C,J,earlQ+1,bigger);
			C[earlQ] ='?';
		}
		if(bigger<0)
		{
			C[earlQ] = '9';
			recurse(C,J,earlQ+1,bigger);
			C[earlQ] ='?';				
		}			

			return;
		}
		if(bigger==0){
		C[earlQ] = '0';
		J[earlQ] = '0';
		recurse(C,J,earlQ+1,bigger);

		C[earlQ] = '1';
		J[earlQ] = '0';
		recurse(C,J,earlQ+1,1);

		C[earlQ] = '0';
		J[earlQ] = '1';
		recurse(C,J,earlQ+1,-1);
		
		}
		if(bigger<0){
		C[earlQ] = '9';
		J[earlQ] = '0';
		recurse(C,J,earlQ+1,bigger);}
		if(bigger>0){
		C[earlQ] = '0';
		J[earlQ] = '9';
		recurse(C,J,earlQ+1,bigger);}
		C[earlQ] ='?';
		J[earlQ] ='?';
	}

}
