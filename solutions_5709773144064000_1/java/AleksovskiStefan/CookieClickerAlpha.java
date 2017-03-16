import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class CookieClickerAlpha {
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "B-large.in";
        String output = base + "B-large.out";
        
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
		double C, F, X;
		C = scan.nextDouble();	// kolko treba da soberu za da kupu novu farmu
		F = scan.nextDouble();	// za kolko nova farma ke mi zgolemi currentCookieRate
		X = scan.nextDouble();	// kolko treba da soberu
		
		double currentCookiRate = 2.0;
		double currentTime = 0.0;
		
		
		while(true){
			if( X / currentCookiRate > (C / currentCookiRate) + (X / (currentCookiRate + F))){
				currentTime += C / currentCookiRate;
				if(currentTime >= X)
					break;
				currentCookiRate += F;
			} else {
				currentTime += X / currentCookiRate;
				break;
			}
		}
		
		write.printf("%.7f\n", currentTime);
		
	}
}
