import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.regex.Pattern;


public class Problem1CB2013 {
	private static Pattern p = Pattern.compile(" ");
	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		InputStream is = new FileInputStream("B-small-attempt0 (1).in");
		Scanner sc = new Scanner(is);
		
		OutputStream os = new FileOutputStream("B-answer.txt");
		PrintWriter pw = new PrintWriter(os);	
		
		
		int n = Integer.parseInt(sc.nextLine());
		
		for (int i = 1; i <= n; i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			StringBuilder sb = new StringBuilder();
			if (x > 0){
				while (x > 0){
					sb.append("WE");
					x--;
				}
			} else{
				while (x < 0){
					sb.append("EW");
					x++;
				}
			}
			
			if (y > 0){
				while (y > 0){
					sb.append("SN");
					y--;
				}
			} else{
				while (y < 0){
					sb.append("NS");
					y++;
				}
			}
			
			
			pw.println("Case #" + i + ": " + sb);
			System.out.println("Case #" + i + ": " + sb);
		}
		
		
		pw.close();
		
		sc.close();
		System.out.println("finished");
		
	}
}
