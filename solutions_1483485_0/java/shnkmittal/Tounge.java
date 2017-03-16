import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class Tounge {

	public static char Googlerese(char data)
	{
		switch(data) {
		case 'a': data = 'y';  break;
		case 'b': data = 'h';  break;
		case 'c': data = 'e';  break;
		case 'd': data = 's';  break;
		case 'e': data = 'o';  break;
		case 'f': data = 'c';  break;
		case 'g': data = 'v';  break;
		case 'h': data = 'x';  break;
		case 'i': data = 'd';  break;
		case 'j': data = 'u';  break;
		case 'k': data = 'i';  break;
		case 'l': data = 'g';  break;
		case 'm': data = 'l';  break;
		case 'n': data = 'b';  break;
		case 'o': data = 'k';  break;
		case 'p': data = 'r';  break;
		case 'q': data = 'z';  break;
		case 'r': data = 't';  break;
		case 's': data = 'n';  break;
		case 't': data = 'w';  break;
		case 'u': data = 'j';  break;
		case 'v': data = 'p';  break;
		case 'w': data = 'f';  break;
		case 'x': data = 'm';  break;
		case 'y': data = 'a';  break;
		case 'z': data = 'q';  break;
		}
		return data;
	}
	
	public static void convertString(String G, int casenum) {
		String S="";
		for(int i=0; i<G.length(); i++)
		{
			char data = Googlerese(G.charAt(i));;
			S = S + data;
		}
		System.out.print("Case #" + casenum + ": "+S +"\n");
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		
			
		File ffile = new File(args[0]);
		Scanner scanner;
		scanner = new Scanner(new FileReader(ffile));
		
		int N = scanner.nextInt();
		String data;
		data = scanner.nextLine();
		for (int i = 0; i<N; i++)
		{
			data = scanner.nextLine();
			convertString(data, i+1);
		
		}
	}

}
