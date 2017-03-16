import java.util.*;
import java.io.*;
import java.util.Arrays;
import java.math.BigInteger;

class Cons {

	static long maxEnergy=0 , regainEnergy=0;
	public static boolean isVowel(char x) {
		return(x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
	}
	public static boolean isCons(char x) {
		return(!isVowel(x));
	}

	public static boolean hasRequired(String line ,int minSize ) {
		int ct=0;
		for(int i=0;i<line.length();i++) {
			if(isCons(line.charAt(i))) {
				ct++;	
			} else {
				ct=0;
			}
			if(ct==minSize) {
				myTrace("KKK " + line + " " + minSize);
				return(true);
				
			}
		}
		return(false);
	}
	public static long getPossible(String line ,int minSize ) {
		if(line.length() < minSize ) {
			return(0);
		} else if(line.length() == minSize) {
			if(hasRequired(line,minSize)) {
				return(1);
			} else {
				return(0);
			}
		} else if(line.length() > minSize) {
			int ct=0,eleBefore=0;
			int counter=0;
			for(int i=0;i<line.length();i++) {
				
				eleBefore++;
				if(isCons(line.charAt(i))) {
					ct++;	
				} else {
					ct=0;
				}
				if(ct==minSize) {
					int a=1,b=1;
					if(eleBefore > minSize) {
						a=2+(eleBefore-1-minSize);
					}
					if(line.length()  > (i+1)) {
						b=2+(line.length()-2-i);
					}
					counter+=a*b;
					myTrace(counter + "" );
					ct--;
					eleBefore=minSize-1;
				}
			}
			return(counter);
			/*if(hasRequired(line,minSize)) {
				xx=1;
			}
			myTrace(xx+" " + line.substring(0,line.length()-1) + " " + line.substring(1,line.length()));
			//myTrace( " TTT : " + xx+" " + getPossible(line.substring(0,line.length()-1),minSize) + " " + getPossible(line.substring(1,line.length()),minSize));
			return(xx+getPossible(line.substring(0,line.length()-1),minSize) + getPossible(line.substring(1,line.length()),minSize)-getPossible(line.substring(1,line.length()-1),minSize));*/
		}
		return(0);
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
				String inputLine    =inputs[0];
				//long size =Long.parseLong(inputs[1]);
				int size =Integer.parseInt(inputs[1]);

				//long getPossible(inputLine,size);

				myPrint("Case #" + caseCount++ + ": " + getPossible(inputLine,size) );
				str = br.readLine();
			}
		} catch(IOException E) {
			System.out.println("ERROR");
			
		}
	}
}
