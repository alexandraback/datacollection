import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class FairAndSquareLarge {
	public static void main(String[] args){
		long[] valid = {1, 2, 3, 11, 101, 111, 121, 1001, 1111, 10001, 10101, 10201, 11011, 11111, 11211, 100001, 101101, 110011, 111111, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111};
		long[] valid2 = {22, 202, 212, 2002, 20002, 20102, 200002, 2000002, 2001002};
		for(int i = 0; i < valid.length; i++){
			valid[i] = valid[i]*valid[i];
		}
		for(int i = 0; i < valid2.length; i++){
			valid2[i] = valid2[i]*valid2[i];
		}

		
		FileReader input;
		Scanner scanner;
		BufferedReader reader;
		try {
			input = new FileReader("C-large-1.in.txt");
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			reader = new BufferedReader(input);
			int testcase = Integer.parseInt(reader.readLine());
			for(int k = 1; k <= testcase; k++){
				scanner = new Scanner(reader.readLine());
				long low = scanner.nextLong();
				long high = scanner.nextLong();
				int count = 0;
				for(long i : valid){
					if(i >= low && i <= high) count++;
				}
				for(long i : valid2){
					if(i >= low && i <= high) count++;
				}
				out.println("Case #" + k + ": " + count); 
			}
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
