import java.io.*;

public class SpeakinginTongues {
	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("A.in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("A.out"));
			int numCase = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCase; i++) {
				ofStream.println("Case #"+i+": "+speakinginTongues(ifStream.readLine()));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static String speakinginTongues(String input) {
		String result = "";
		char ch;

		for (int i=0; i<input.length(); i++) {
			ch = input.charAt(i);
			switch (ch) {
				case 'a': ch = 'y'; break;
				case 'b': ch = 'h'; break;
				case 'c': ch = 'e'; break;
				case 'd': ch = 's'; break;
				case 'e': ch = 'o'; break;
				case 'f': ch = 'c'; break;
				case 'g': ch = 'v'; break;
				case 'h': ch = 'x'; break;
				case 'i': ch = 'd'; break;
				case 'j': ch = 'u'; break;
				case 'k': ch = 'i'; break;
				case 'l': ch = 'g'; break;
				case 'm': ch = 'l'; break;
				case 'n': ch = 'b'; break;
				case 'o': ch = 'k'; break;
				case 'p': ch = 'r'; break;
				case 'q': ch = 'z'; break;
				case 'r': ch = 't'; break;
				case 's': ch = 'n'; break;
				case 't': ch = 'w'; break;
				case 'u': ch = 'j'; break;
				case 'v': ch = 'p'; break;
				case 'w': ch = 'f'; break;
				case 'x': ch = 'm'; break;
				case 'y': ch = 'a'; break;
				case 'z': ch = 'q'; break;
				case ' ': break;
				default:
					System.out.println("Wrong Input.");
					System.exit(1);
			}
			result += ch;
		}

		return result;
	}
}
