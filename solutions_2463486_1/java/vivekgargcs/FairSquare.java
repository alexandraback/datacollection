import java.math.*;
import java.io.*;
class MyBigInteger extends BigInteger {
	public MyBigInteger(String x ) {
		super(x);
	}
	public MyBigInteger getNextPalindrome() {
		String value=this.toString();
		if(this.compareTo(new BigInteger("10")) <= 0 ) {
			return(new MyBigInteger((this.add(BigInteger.ONE).toString())));
 		}
		int length = value.length();
		String firstPortion=((new BigInteger(value.substring(0,(int)Math.ceil(length/2.0)))).add(BigInteger.ONE)).toString();
		StringBuffer newToMake = new StringBuffer(firstPortion);
		for(int i=(length/2)-1;i>=0;i--) {
			newToMake.append(firstPortion.charAt(i));
		}
		return(new MyBigInteger(newToMake.toString()));
		//return(true);
	}
}

class Functions {
	public static boolean isPalindrome(String stringToCheck) {
		int length = stringToCheck.length();
		for(int i=0;i<Math.floor(length/2.0);i++) {
			if(!(stringToCheck.charAt(i) == (stringToCheck.charAt(length-i-1)))) 
				return(false);
		}
	//System.out.println("YYY" + stringToCheck);
	return(true);
	}
}

class FairSquare {

	public static void main(String args[]) {	
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str;
			str = br.readLine();
			str = br.readLine();
			String inputs[];
			int i=1;
			 while (str != null) {
				inputs=str.split(" ");
				//System.out.println(">>" +str  + "<<"  +inputs[0] + " " + inputs[1] );
				str = br.readLine();
				MyBigInteger start=new MyBigInteger(inputs[0]);
				MyBigInteger myStart;
				if(start.compareTo(new BigInteger("10")) < 0) {
					myStart=new MyBigInteger("0");
				} else {
					myStart=new MyBigInteger (((new MyBigInteger("10")).pow(start.toString().length()/2)).add(BigInteger.ONE).toString());
				}
				MyBigInteger end=new MyBigInteger(inputs[1]);
			//	System.out.println("KKK : " + start );
				MyBigInteger square = new MyBigInteger(myStart.pow(2).toString());
				boolean started=false;
				long count=0;
				for(;(square.compareTo(end))<=0;myStart=myStart.getNextPalindrome()) {
			//		System.out.println("YYY : " + myStart );
					square = new MyBigInteger(myStart.pow(2).toString());
					if(started || square.compareTo(start) >= 0) {
						started=true;
					}
					if(started && Functions.isPalindrome(square.toString()) && square.compareTo(end)<=0 ) {
					//	System.out.println("XXX : " + square + " " + myStart + " " + end );
						count++;
					}
				}
				System.out.println("Case #" + i++ + ": " + count );
					
			} 
		} catch(IOException E) {
			System.err.println("ERROR");
		}
	}
}
