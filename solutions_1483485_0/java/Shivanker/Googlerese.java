import java.util.Scanner;


public class Googlerese {

	private static char map(char c)	{
		switch(c)	{
			case 'a': return 'y';
			case 'b': return 'h';
			case 'c': return 'e';
			case 'd': return 's';
			case 'e': return 'o';
			case 'f': return 'c';
			case 'g': return 'v';
			case 'h': return 'x';
			case 'i': return 'd';
			case 'j': return 'u';
			case 'k': return 'i';
			case 'l': return 'g';
			case 'm': return 'l';
			case 'n': return 'b';
			case 'o': return 'k';
			case 'p': return 'r';
			case 'q': return 'z';
			case 'r': return 't';
			case 's': return 'n';
			case 't': return 'w';
			case 'u': return 'j';
			case 'v': return 'p';
			case 'w': return 'f';
			case 'x': return 'm';
			case 'y': return 'a';
			case 'z': return 'q';
		}
		return '!';
	}
	
	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		c.nextLine();
		for(int i=1; i<=t; ++i)	{
			System.out.print("Case #"+i+":");
			String line = c.nextLine();
			Scanner c2 = new Scanner(line);
			while(c2.hasNext())	{
				System.out.print(" ");
				String w = c2.next();
				for(int j=0; j<w.length(); ++j)
					System.out.print(map(w.charAt(j)));
			}
			System.out.println();
		}
	}

}
