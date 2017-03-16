import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Speaking {

	/**
	 * @param args
	 */
	
	static int n =0;
	//static ArrayList<ArrayList<String>> table = new ArrayList<ArrayList<String>>();	

		public static void inputF() throws FileNotFoundException{
			
			File inputFile = new File("A-small-attempt0.in");
			Scanner in = new Scanner(inputFile);
			File outputFile = new File("A-small-attempt0.out");
			PrintWriter out = new PrintWriter(outputFile);
			String result="";
			String input ="";
	  
			
			n = in.nextInt();
			//System.out.println(n);
			input = in.nextLine();
			for (int i=1; i<=n; i++) {
				input =in.nextLine();
				//System.out.println("length of the list: "+list.length);
				result = "Case #"+i+ ": "+ spell(input);
				out.println(result);
			}
			in.close();
			out.close();
		}
		
		
		private static String spell(String input) {
			String result="";
			String press="";
			for(int i=0; i<input.length();i++) {
				char cha = input.charAt(i);
				switch(cha) {
				case 'a' : press="y";
						   break;
				case 'b' : press="h";
				   break;
				case 'c' : press="e";
				   break;
				case 'd' : press="s";
				   break;
				case 'e' : press="o";
				   break;
				case 'f' : press="c";
				   break;
				case 'g' : press="v";
				   break;
				case 'h' : press="x";
				   break;
				case 'i' : press="d";
				   break;
				case 'j' : press="u";
				   break;
				case 'k' : press="i";
				   break;
				case 'l' : press="g";
				   break;
				case 'm' : press="l";
				   break;
				case 'n' : press="b";
				   break;
				case 'o' : press="k";
				   break;
				case 'p' : press="r";
				   break;
				case 'q' : press="z";
				   break;
				case 'r' : press="t";
				   break;
				case 's' : press="n";
				   break;
				case 't' : press="w";
				   break;
				case 'u' : press="j";
				   break;
				case 'v' : press="p";
				   break;
				case 'w' : press="f";
				   break;
				case 'x' : press="m";
				   break;
				case 'y' : press="a";
				   break;
				case 'z' : press="q";
				   break;
				case ' ' : press=" ";
				   break;
				}
				result=result+press;
			}
			
			return result;
		}
	
	public static void main(String[] args) throws FileNotFoundException {
		inputF();

	}

}
