import java.util.*;
import java.io.*;
import java.util.Arrays;
import java.math.BigInteger;

class Pogo {

	static long maxEnergy=0 , regainEnergy=0;
	public static boolean isEven(long x) {
		return((Math.abs(x))%2 == 0 );
	}
	public static boolean isOdd(long x) {
		return(!isEven(x));
	}

	public static String getPossible(long x , long y,long step ) {
		boolean isStepEven=isEven(step);
		if(x==0 && y==0) {
			return("");
		} else {
			myTrace(" " + x + " , " + y);
			char dir=' ';
			if(x!=0 && ((isEven(x) && isStepEven ) || (isOdd(x) && !isStepEven ) )) {
				if(x>=step) {
					dir='E';
					x-=step;
				} else {
					dir='W';
					x+=step;
				}
			} else if(y!=0 && ((isEven(y) && isStepEven ) || (isOdd(y) && !isStepEven ) )) {
				if(y>=step) {
					dir='N';
					y-=step; 
				} else {
					dir='S';
					y+=step; 
				}
			} else if(x!=0) {
				if(x>=step) {
					dir='E';
					x-=step;
				} else {
					dir='W';
					x+=step;
				}
			} else {
				if(y>=step) {
					dir='N';
					y-=step; 
				} else {
					dir='S';
					y+=step; 
				}
			}
			myTrace( " " + x + " , " + y + " ," + step);
			return(dir + getPossible(x,y,step+1));
		}
		//return("");
	}

	public static void myTrace(String s) {
		//System.err.println("TRACE : " + s);
	}
	public static void myPrint(String s) {
		System.out.println(s);
	}
	public static void main(String args[]) {
		
		int caseCount = 1 ;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str;
			str = br.readLine();
			str = br.readLine();
			String inputs[];
			while (str != null) {
				//long workDone=0;
				//BigInteger workDone=new BigInteger(0+"");
				//LinkedList workList = new LinkedList();
				//LinkedList subList = new LinkedList();
				
				inputs=str.split(" ");
				long x =Long.parseLong(inputs[0]);
				long y =Long.parseLong(inputs[1]);
				//int size =Integer.parseInt(inputs[1]);

				//long getPossible(inputLine,size);

				myPrint("Case #" + caseCount++ + ": " + getPossible(x,y,1) );
				str = br.readLine();
			}
		} catch(IOException E) {
			System.out.println("ERROR");
			
		}
	}
}
