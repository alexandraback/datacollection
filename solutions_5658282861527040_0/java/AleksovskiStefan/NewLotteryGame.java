import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class NewLotteryGame {
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "B-small-attempt0.in";
        String output = base + "B-small-attempt0.out";
        
		try {
			Scanner scan = new Scanner(new FileReader(input));
			PrintWriter write = new PrintWriter(output);
			
			int n = scan.nextInt();
			scan.nextLine();
			
			for (int i = 1; i <= n; i++) {
				write.write("Case #" + i + ": ");
				test(scan, write);
			}
			
			scan.close();
			write.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void test(Scanner scan, PrintWriter write) {
		int A, B, K;
		A = scan.nextInt();
		B = scan.nextInt();
		K = scan.nextInt();
		
		int c = 0;
		
		for(int i=0;i<A;i++){
			for(int j=0;j<B;j++){
				int tmp = i & j;
				if(tmp < K)
					c++;
			}
		}
		
		write.write(Integer.toString(c)+"\n");		
	}
}
