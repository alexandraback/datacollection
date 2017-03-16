import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class main {

	public static void write(PrintWriter file, int idx, String str){
		file.println("Case #"+idx+": "+str);
	}
	public static void write(PrintWriter file, int idx, int ans){
		file.println("Case #"+idx+": "+ans);
	}
	
	public static void main(String[] args) throws IOException {
		String epreuve="D-large.in";
		File entry = new File(epreuve);
		Scanner scin= new Scanner(entry);
		File out = new File("Output"+epreuve);
		out.createNewFile();
		PrintWriter scout= new PrintWriter(out);	
		// Set up of the problem
		int T = scin.nextInt();
		String ans;
		for (int i=1; i<= T; i++){
			int X=scin.nextInt(); int R=scin.nextInt(); int C=scin.nextInt();
			ans="GABRIEL";
			if (R<X && C<X)
				ans="RICHARD";
			else if (R+C-1<X)
				ans="RICHARD";
			else if (2*R+1<=X ||2*C+1<=X)
				ans="RICHARD";
			else if ((R*C)%(X)!=0)
				ans="RICHARD";
			else if (X>=4 && (R<=2 ||C<=2))
				ans="RICHARD";
			else if (X>=5&&  (R<=3 ||C<=3))
				ans="RICHARD";
			else if (X>=6 && (R<=4 ||C<=4))
				ans="RICHARD";
			else if (X>=7)
				ans="RICHARD";
			write(scout, i, ans);
		}
		scin.close();
		scout.close();
	}

}
