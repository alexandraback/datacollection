import java.util.*; 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
//SRM525
public class ImportantSequence {
	public static String change(String a){
		int max = a.length();
		String ans = "";
		for(int i = 0; i < max; i++){
			if(a.charAt(i) == 'a')
				ans = ans + "y";
			if(a.charAt(i) == 'b')
				ans = ans + "h";
			if(a.charAt(i) == 'c')
				ans = ans + "e";
			if(a.charAt(i) == 'd')
				ans = ans + "s";
			if(a.charAt(i) == 'e')
				ans = ans + "o";
			if(a.charAt(i) == 'f')
				ans = ans + "c";
			if(a.charAt(i) == 'g')
				ans = ans + "v";
			if(a.charAt(i) == 'h')
				ans = ans + "x";
			if(a.charAt(i) == 'i')
				ans = ans + "d";
			if(a.charAt(i) == 'j')
				ans = ans + "u";
			if(a.charAt(i) == 'k')
				ans = ans + "i";
			if(a.charAt(i) == 'l')
				ans = ans + "g";
			if(a.charAt(i) == 'm')
				ans = ans + "l";
			if(a.charAt(i) == 'n')
				ans = ans + "b";
			if(a.charAt(i) == 'o')
				ans = ans + "k";
			if(a.charAt(i) == 'p')
				ans = ans + "r";
			if(a.charAt(i) == 'q')
				ans = ans + "z";
			if(a.charAt(i) == 'r')
				ans = ans + "t";
			if(a.charAt(i) == 's')
				ans = ans + "n";
			if(a.charAt(i) == 't')
				ans = ans + "w";
			if(a.charAt(i) == 'u')
				ans = ans + "j";
			if(a.charAt(i) == 'v')
				ans = ans + "p";
			if(a.charAt(i) == 'w')
				ans = ans + "f";
			if(a.charAt(i) == 'x')
				ans = ans + "m";
			if(a.charAt(i) == 'y')
				ans = ans + "a";
			if(a.charAt(i) == 'z')
				ans = ans + "q";
			if(a.charAt(i) == ' ')
				ans = ans + " ";
		}
		return ans;
	}
	public static void main(String[] args) throws FileNotFoundException { 
		Scanner scan = new Scanner(System.in);
		//Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		scan.useDelimiter("\\r\\n");
		int t = scan.nextInt();
		for(int i = 1; i <= t; i++){
			String n = scan.next();
			String a = change(n);
			System.out.print("Case #" + i + ": " + a);
			System.out.println();
		}
	} 
	
}
