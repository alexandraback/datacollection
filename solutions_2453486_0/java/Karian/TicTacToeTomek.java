import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;

public class TicTacToeTomek {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer.readLine(),buffer.readLine(),buffer.readLine(),buffer.readLine()));
			buffer.readLine();
		}
	}

	private static String solve(String line1, String line2, String line3, String line4) {
		boolean full = true;
		switch(line1.charAt(0))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line1.charAt(1) == 'X' || line1.charAt(1) == 'T') && (line1.charAt(2) == 'X' || line1.charAt(2) == 'T') && (line1.charAt(3) == 'X' || line1.charAt(3) == 'T'))
					return new String("X won");
				if((line2.charAt(1) == 'X' || line2.charAt(1) == 'T') && (line3.charAt(2) == 'X' || line3.charAt(2) == 'T') && (line4.charAt(3) == 'X' || line4.charAt(3) == 'T'))
					return new String("X won");
				if((line2.charAt(0) == 'X' || line2.charAt(0) == 'T') && (line3.charAt(0) == 'X' || line3.charAt(0) == 'T') && (line4.charAt(0) == 'X' || line4.charAt(0) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line1.charAt(1) == 'O' || line1.charAt(1) == 'T') && (line1.charAt(2) == 'O' || line1.charAt(2) == 'T') && (line1.charAt(3) == 'O' || line1.charAt(3) == 'T'))
					return new String("O won");
				if((line2.charAt(1) == 'O' || line2.charAt(1) == 'T') && (line3.charAt(2) == 'O' || line3.charAt(2) == 'T') && (line4.charAt(3) == 'O' || line4.charAt(3) == 'T'))
					return new String("O won");
				if((line2.charAt(0) == 'O' || line2.charAt(0) == 'T') && (line3.charAt(0) == 'O' || line3.charAt(0) == 'T') && (line4.charAt(0) == 'O' || line4.charAt(0) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line1.charAt(1) == 'X' && line1.charAt(2) == 'X' && line1.charAt(3) == 'X')
					return new String("X won");
				if(line2.charAt(1) == 'X' && line3.charAt(2) == 'X' && line4.charAt(3) == 'X')
					return new String("X won");
				if(line2.charAt(0) == 'X' && line3.charAt(0) == 'X' && line4.charAt(0) == 'X')
					return new String("X won");
				if(line1.charAt(1) == 'O' && line1.charAt(2) == 'O' && line1.charAt(3) == 'O')
					return new String("O won");
				if(line2.charAt(1) == 'O' && line3.charAt(2) == 'O' && line4.charAt(3) == 'O')
					return new String("O won");
				if(line2.charAt(0) == 'O' && line3.charAt(0) == 'O' && line4.charAt(0) == 'O')
					return new String("O won");
				break;
		}

		switch(line1.charAt(1))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line2.charAt(1) == 'X' || line2.charAt(1) == 'T') && (line3.charAt(1) == 'X' || line3.charAt(1) == 'T') && (line4.charAt(1) == 'X' || line4.charAt(1) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line2.charAt(1) == 'O' || line2.charAt(1) == 'T') && (line3.charAt(1) == 'O' || line3.charAt(1) == 'T') && (line4.charAt(1) == 'O' || line4.charAt(1) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line2.charAt(1) == 'X' && line3.charAt(1) == 'X' && line4.charAt(1) == 'X')
					return new String("X won");
				if(line2.charAt(1) == 'O' && line3.charAt(1) == 'O' && line4.charAt(1) == 'O')
					return new String("O won");
				break;
		}
		
		switch(line1.charAt(2))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line2.charAt(2) == 'X' || line2.charAt(2) == 'T') && (line3.charAt(2) == 'X' || line3.charAt(2) == 'T') && (line4.charAt(2) == 'X' || line4.charAt(2) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line2.charAt(2) == 'O' || line2.charAt(2) == 'T') && (line3.charAt(2) == 'O' || line3.charAt(2) == 'T') && (line4.charAt(2) == 'O' || line4.charAt(2) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line2.charAt(2) == 'X' && line3.charAt(2) == 'X' && line4.charAt(2) == 'X')
					return new String("X won");
				if(line2.charAt(2) == 'O' && line3.charAt(2) == 'O' && line4.charAt(2) == 'O')
					return new String("O won");
				break;
		}
		
		switch(line1.charAt(3))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line2.charAt(3) == 'X' || line2.charAt(3) == 'T') && (line3.charAt(3) == 'X' || line3.charAt(3) == 'T') && (line4.charAt(3) == 'X' || line4.charAt(3) == 'T'))
					return new String("X won");
				if((line2.charAt(2) == 'X' || line2.charAt(2) == 'T') && (line3.charAt(1) == 'X' || line3.charAt(1) == 'T') && (line4.charAt(0) == 'X' || line4.charAt(0) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line2.charAt(3) == 'O' || line2.charAt(3) == 'T') && (line3.charAt(3) == 'O' || line3.charAt(3) == 'T') && (line4.charAt(3) == 'O' || line4.charAt(3) == 'T'))
					return new String("O won");
				if((line2.charAt(2) == 'O' || line2.charAt(2) == 'T') && (line3.charAt(1) == 'O' || line3.charAt(1) == 'T') && (line4.charAt(0) == 'O' || line4.charAt(0) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line2.charAt(3) == 'X' && line3.charAt(3) == 'X' && line4.charAt(3) == 'X')
					return new String("X won");
				if(line2.charAt(2) == 'X' && line3.charAt(1) == 'X' && line4.charAt(0) == 'X')
					return new String("X won");
				if(line2.charAt(3) == 'O' && line3.charAt(3) == 'O' && line4.charAt(3) == 'O')
					return new String("O won");
				if(line2.charAt(2) == 'O' && line3.charAt(1) == 'O' && line4.charAt(0) == 'O')
					return new String("O won");
				break;
		}
		
		switch(line2.charAt(0))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line2.charAt(1) == 'X' || line2.charAt(1) == 'T') && (line2.charAt(2) == 'X' || line2.charAt(2) == 'T') && (line2.charAt(3) == 'X' || line2.charAt(3) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line2.charAt(1) == 'O' || line2.charAt(1) == 'T') && (line2.charAt(2) == 'O' || line2.charAt(2) == 'T') && (line2.charAt(3) == 'O' || line2.charAt(3) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line2.charAt(1) == 'X' && line2.charAt(2) == 'X' && line2.charAt(3) == 'X')
					return new String("X won");
				if(line2.charAt(1) == 'O' && line2.charAt(2) == 'O' && line2.charAt(3) == 'O')
					return new String("O won");
				break;
		}

		switch(line3.charAt(0))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line3.charAt(1) == 'X' || line3.charAt(1) == 'T') && (line3.charAt(2) == 'X' || line3.charAt(2) == 'T') && (line3.charAt(3) == 'X' || line3.charAt(3) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line3.charAt(1) == 'O' || line3.charAt(1) == 'T') && (line3.charAt(2) == 'O' || line3.charAt(2) == 'T') && (line3.charAt(3) == 'O' || line3.charAt(3) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line3.charAt(1) == 'X' && line3.charAt(2) == 'X' && line3.charAt(3) == 'X')
					return new String("X won");
				if(line3.charAt(1) == 'O' && line3.charAt(2) == 'O' && line3.charAt(3) == 'O')
					return new String("O won");
				break;
		}

		switch(line4.charAt(0))
		{
			case '.':
				full = false;
				break;
			case 'X':
				if((line4.charAt(1) == 'X' || line4.charAt(1) == 'T') && (line4.charAt(2) == 'X' || line4.charAt(2) == 'T') && (line4.charAt(3) == 'X' || line4.charAt(3) == 'T'))
					return new String("X won");
				break;
			case 'O':
				if((line4.charAt(1) == 'O' || line4.charAt(1) == 'T') && (line4.charAt(2) == 'O' || line4.charAt(2) == 'T') && (line4.charAt(3) == 'O' || line4.charAt(3) == 'T'))
					return new String("O won");
				break;
			case 'T':
				if(line4.charAt(1) == 'X' && line4.charAt(2) == 'X' && line4.charAt(3) == 'X')
					return new String("X won");
				if(line4.charAt(1) == 'O' && line4.charAt(2) == 'O' && line4.charAt(3) == 'O')
					return new String("O won");
				break;
		}

		if( !full || line2.charAt(1) == '.'  || line2.charAt(2) == '.'  || line2.charAt(3) == '.'
			 			|| line3.charAt(1) == '.'  || line3.charAt(2) == '.'  || line3.charAt(3) == '.'
				 		|| line4.charAt(1) == '.'  || line4.charAt(2) == '.'  || line4.charAt(3) == '.')
			return new String("Game has not completed");
				
		return new String("Draw");
	}

}
