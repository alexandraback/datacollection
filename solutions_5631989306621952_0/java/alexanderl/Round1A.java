import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;


public class Round1A {
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(System.in);
		PrintWriter out = new PrintWriter("output.txt", "UTF-8");
		
		System.out.println("Input Filename: ");
		String filename = scan.nextLine();
		try {scan = new Scanner(new File(filename));}
		catch(Exception e){
			System.out.println("Invalid File Input");
			return;
		}
		
		int sets = scan.nextInt(); scan.nextLine();
		for(int k = 1; k <= sets; ++k){
			String s = scan.nextLine();
			String output = "";
			for(int j = 0; j < s.length(); ++j){
				char c = s.charAt(j);
				if(output == ""){
					output += c;
				}
				else {
					//System.out.println(c + " " + output.charAt(0) + " "+ (c > output.charAt(j-1)));
					if(c >= output.charAt(0)){
						output = c+output;
					}
					else {
						output += c;
					}
					//System.out.println(output + "\n");
				}
			}
			out.println("Case #" +k +": " + output );
		}
		out.close();
	}
}
