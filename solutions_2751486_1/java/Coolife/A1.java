import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));
		
		int T = in.nextInt();
		in.nextLine();
		for(int i = 1; i <= T; i++) {			
			String nameAndN = in.nextLine();
			String[] s = nameAndN.split(" ");
			int n = Integer.parseInt(s[1]);


			int jj = 0;
			int j = 0;
			int currentN = 0;
			long y = 0;
			while(j<s[0].length()){
				if ((s[0].charAt(j)=='a') ||
						(s[0].charAt(j)=='e') ||
						(s[0].charAt(j)=='i') ||
						(s[0].charAt(j)=='o') ||
						(s[0].charAt(j)=='u') ) {
					
					currentN=0;
					
				} else {
					currentN++;																
				}			
				while(currentN>=n && j-jj+1>=n){
					y = y + s[0].length() - j;
					jj = jj+1;
				}
				j++;
				
			}
			
			//System.out.println("Case" + i +":" + y);
			out.write("Case #" + i + ": " +y);
			out.newLine();
			
		}
		
		
		
		in.close();
		out.close();

	}

}
