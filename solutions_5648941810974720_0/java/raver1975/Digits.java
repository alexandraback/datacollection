import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Digits {
	static PrintWriter writer;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		String[] digits = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
		String te="";
		for (String s:digits)te+=s;
		for (int i = 0; i < digits.length; i++) {
			for (int j = 0; j < digits[i].length(); j++) {
				char b = digits[i].charAt(j);
				int counter = counter(te,b);
				if (counter==1)System.out.println(i+":"+b+"="+counter);
				
			}
		}
		
		
		Scanner sc = new Scanner(new File("in.txt"));
		writer = new PrintWriter("out.txt", "UTF-8");
		int n = sc.nextInt();
		sc.nextLine();
		ArrayList<Integer> dig = new ArrayList<>();
		for (int t = 0; t < n; t++) {
			dig.clear();
			String s = sc.nextLine();
			String sorig=s;

			// scan
			
			boolean flag=true;
			while(flag){
				flag=false;
				if (s.contains("Z")){
					dig.add(0);
					s=remove(s,"ZERO");
					flag=true;
				}
				
				if (s.contains("W")){
					dig.add(2);
					s=remove(s,"TWO");
					flag=true;
				}
				
				if (s.contains("U")){
					dig.add(4);
					s=remove(s,"FOUR");
					flag=true;
				}
				
				if (s.contains("X")){
					dig.add(6);
					s=remove(s,"SIX");
					flag=true;
				}
				
				if (s.contains("G")){
					dig.add(8);
					s=remove(s,"EIGHT");
					flag=true;
				}
			}
			while (s.length() > 0) {
				top: for (int i = 0; i < digits.length; i++) {
					String temp = s;
					
					for (int j = 0; j < digits[i].length(); j++) {
						char b = digits[i].charAt(j);
						if (!temp.contains(b + ""))
							continue top;
						temp = temp.replaceFirst(b + "", "");
					}
					dig.add(i);
					s = temp;
					//System.out.println(s);
				}
			}
			Collections.sort(dig);
//			//check
//			String check=sorig;
//			for (int i:dig){
//				check=remove(check, digits[i]);
//			}
//			if (!check.isEmpty()){}
//			System.out.println("BROKEN:"+check+":");
//			System.exit(0);
//			
			
			String o = "";
			for (int h : dig)
				o += h;
			out(t + 1, o);
		}
		writer.close();
	}

	private static void out(int i, String j) {
		String s = "Case #" + i + ": " + j;
		writer.println(s);
		System.out.println(s);

	}
	static int counter(String s,char b){
		int counter = 0;
		for( int i=0; i<s.length(); i++ ) {
		    if( s.charAt(i) == b ) {
		        counter++;
		    } 
		}
		return counter;
	}
	
	static String remove(String in,String rem){
		//System.out.println("remin"+"\t"+in);
				for (int i=0;i<rem.length();i++){
					in=in.replaceFirst(rem.charAt(i)+"","");
				}
				//System.out.println("remou"+"\t"+in);
				return in;
	}
}
