import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class Tongues {
	static char[] letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
		'v','w','x','y','z'};
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new File("tongue.in"));
		System.setOut(new PrintStream(new File("tongue.out")));
		int numCases = Integer.parseInt(sc.nextLine().trim());
		for(int i=1; i<=numCases; i++){
			String b = new String(sc.nextLine().trim());
			for(char c: letters)
				b = b.replaceAll(c+"",swap(c)+"");
			System.out.println("Case #"+i+": "+b.toLowerCase());
		}
	}
	static char swap(char c){
		switch(c){
		case 'y': return 'A';
		case 'n': return 'B';
		case 'f': return 'C';
		case 'i': return 'D';
		case 'c': return 'E';
		case 'w': return 'F';
		case 'l': return 'G';
		case 'b': return 'H';
		case 'k': return 'I';
		case 'u': return 'J';
		case 'o': return 'K';
		case 'm': return 'L';
		case 'x': return 'M';
		case 's': return 'N';
		case 'e': return 'O';
		case 'v': return 'P';
		case 'z': return 'Q';
		case 'p': return 'R';
		case 'd': return 'S';
		case 'r': return 'T';
		case 'j': return 'U';
		case 'g': return 'V';
		case 't': return 'W';
		case 'h': return 'X';
		case 'a': return 'Y';
		case 'q': return 'Z';
		}
		return ' ';
	}

}
