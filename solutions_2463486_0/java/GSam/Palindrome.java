import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Palindrome {

	public static void main(String[] args){
		Palindrome p = new Palindrome();
		p.find();
	}
	
	public void find(){
		Scanner scan;
		try {
			scan = new Scanner(new File("input.txt"));
			PrintStream p = new PrintStream("output.txt");
			long num = scan.nextInt();
			//while(scan.hasNextLine()){p.prlongln(scan.nextLine());}
			for(long i = 1; i <= num; i++){
				int count = 0;
				long start = scan.nextInt();
				long end = scan.nextInt();
				long sqStart = (long)Math.ceil(Math.pow(start, 0.5));
				long sqEnd = (long)Math.floor(Math.pow(end, 0.5));
				//System.out.println(start + " " + end + " " + sqStart + " " +sqEnd);
				for(long x = sqStart; x <= sqEnd; x++){
					if(isPalindrome(x) && isPalindrome(x*x)){
						count++;
					}
				}
				p.println("Case #" + i +": " + count);
				System.out.println("Case #" + i +": " + count);

			}
			p.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public boolean isPalindrome(long number) {
		long x = number;
		long reverse = 0;
		while (x > 0) {
			long dig = (x % 10);
			reverse = reverse * 10 + dig;
			x /= 10;
		}
		return reverse == number;
	}
}
