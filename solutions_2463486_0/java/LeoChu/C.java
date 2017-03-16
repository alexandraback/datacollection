import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class C {
	Scanner scanner = new Scanner(System.in);
		
	List<BigInteger> fairAndSquareList = new ArrayList<BigInteger>();
	
	//row, column
	BigInteger A;
	BigInteger B;
	int line = 1;
	boolean debug = false;
	
	String from = null;
	String to = null;
	
	void read() {
		A = new BigInteger(scanner.next());
		B = new BigInteger(scanner.next());
		debugln("A:"+A+", B:"+B+", line="+line);
		line+=1;	
	}
	
	void solve() {
		int inTheRange = 0;
		for(BigInteger fairAndSquareNumber:fairAndSquareList){
			if(fairAndSquareNumber.compareTo(A)>=0 && fairAndSquareNumber.compareTo(B)<=0){
				inTheRange += 1;
			}
		}
		System.out.print(inTheRange);
	}
	
	void generateFairAndSquareList(){
		BigInteger i = new BigInteger(from);
		BigInteger square = new BigInteger(from);
		while(square.compareTo(new BigInteger(to)) <0){
			if(isPalindromes(i)){
				square = i.multiply(i);			
				if(isPalindromes(square)){
					fairAndSquareList.add(square);
					debugln(square.toString());
				}	
			}
			i = i.add(new BigInteger("1"));			
		}
	}
	
	public boolean isPalindromes(BigInteger number){
		
		String numberString = number.toString();
		int numberLength = numberString.length();
		int halfLength = numberLength/2;
		for(int i=0; i<halfLength;i++){			
			if(numberString.charAt(i) != numberString.charAt(numberLength-1-i)){
				return false;
			}
		}
		
		return true;
	}
	
	void run() {
		long stime = System.currentTimeMillis();
		generateFairAndSquareList();
		int caseN = scanner.nextInt();		
		for (int caseID = 1; caseID <= caseN; caseID++) {			
			System.out.printf("Case #%d: ", caseID);
			read();
			solve();
			System.out.println();
			debugln("==================================");
			System.out.flush();
		}
		long ctime = System.currentTimeMillis();
		debugln(String.format("--- Done: "+from+"->"+to+"(10pow"+(to.length()-1)+") %3.0fs",(ctime-stime)*0.001));
	}
	
	@SuppressWarnings("unused")
	private void debug(String message){
		if(debug){
			System.out.print(message);
		}
	}
	
	private void debugln(String message){
		if(debug){
			System.out.println(message);
		}
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream("C-small-attempt0.in")));			
		} catch (Exception e) {
			e.printStackTrace();
		}
		int digits = 5;
		BigInteger to = new BigInteger("10").pow(digits);
		C c =new C();
		c.from = "1";		
		c.to =to.toString();		
		c.run();
	}
}
