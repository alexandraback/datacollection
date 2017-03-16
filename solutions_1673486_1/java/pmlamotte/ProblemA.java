import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/**
 * @author Paul LaMotte
 *
 */
public class ProblemA {

	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File("A-large.in"));
			System.setOut(new PrintStream(new FileOutputStream(new File("probA.out"))));
			
			int num = Integer.parseInt(scan.nextLine());
			
			for (int l = 0; l < num; l++) {
				String line = scan.nextLine();
				Scanner s = new Scanner(line);
				int numTyped = s.nextInt();
				int passLen = s.nextInt();
				int toType = passLen - numTyped;
				
				line = scan.nextLine();
				s = new Scanner(line);
				double[] prob = new double[passLen];
				
				double retype = 0;
				for (int i = 0; i < numTyped; i++) {
					prob[i] = s.nextDouble();
					if (i == 0) {
						retype = prob[i];
					} else {
						retype *= prob[i];
					}
				}
				
				// finish retype
				retype = (retype * (toType + 1)) + ((1 - retype) * (toType + 2 + passLen));
			
				double[] backs = new double[numTyped];
				
				for (int i = numTyped-1; i >= 0; i--) {
					double allCorr = 1;
					int backspaces = numTyped - i;
					for (int j = 0; j < i; j++) {
							allCorr *= prob[j];
					}
					
					backs[i] = (allCorr * (backspaces * 2 + 1 + toType)) + ((1 - allCorr) * (backspaces * 2 + toType + 2 + passLen));
				}
				
				double enter = passLen + 2;
				
				double ret = Math.min(retype, enter);
				for (int i = 0; i < backs.length; i++) {
					ret = Math.min(ret, backs[i]);
				}
				
				System.out.printf("Case #%d: %f\n", l + 1, ret);
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
	
	public static void backspace(int num) {
		
	}
}
