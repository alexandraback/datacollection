import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("B.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("B.out"));
		
		int T = in.nextInt();
		for (int i = 1; i<=T; i++) {
			out.write("Case #" + i +": ");
			int x = in.nextInt();
			int y = in.nextInt();
			if (x>0) {
				for(int j = 0; j<x; j++){
					out.write("WE");
				}				
			}
				
			if (x<0) {
				x = -x;
				for(int j = 0; j<x; j++){
					out.write("EW");
				}				
			}
			
			if (y>0) {
				for(int j = 0; j<y; j++){
					out.write("SN");
				}				
			}
			
			if (y<0) {
				y = -y;
				for(int j = 0; j<y; j++){
					out.write("NS");
				}				
			}
			out.newLine();
		}
		

		in.close();
		out.close();
	}

}
