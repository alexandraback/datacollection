import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner in = new Scanner(new File("A-large.in"));
		Formatter out = new Formatter(new File("A-large.out"));
		
//		Scanner in = new Scanner(System.in);
//		Formatter out = new Formatter(System.out);

		int t = in.nextInt();
		int caseNum = 1;

		while (caseNum <= t) {
			
			output(caseNum, in.next(), out);
			
			caseNum++;
		}

		out.flush();
		out.close();

	}

	private static void output(int caseNum, String next, Formatter out) {
		
		int n = next.length();
		char[] chars = new char[1000];
		for(int i=0;i<n;++i){
			chars[next.charAt(i)]++;
		}
		
		int[] result = new int[10];
		output(0,result,chars,"ZERO",'Z');
		output(4,result,chars,"FOUR",'U');
		output(5,result,chars,"FIVE",'F');
		output(6,result,chars,"SIX",'X');
		output(7,result,chars,"SEVEN",'S');
		output(3,result,chars,"THREE",'R');
		output(2,result,chars,"TWO",'W');
		output(8,result,chars,"EIGHT",'T');
		output(9,result,chars,"NINE",'I');
		output(1,result,chars,"ONE",'O');
		
		StringBuffer output = new StringBuffer();
		for(int i=0;i<10;++i){
			while(result[i]>0){
				output.append(i);
				result[i]--;
			}
		}
		
		out.format("Case #%d: %s%n",caseNum,output.toString());
		
	}

	private static void output(int digit,int[] result, char[] chars, String string, char c) {		
		int num = chars[c];
		result[digit]+=num;
		
		for(Character ch:string.toCharArray()){
			chars[ch]-=num;
		}		
	}

	
}
