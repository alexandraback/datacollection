import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class D {


	
	/**
	 * @param args
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException, IOException {
		try (Scanner scan = new Scanner(System.in);
				FileOutputStream os = new FileOutputStream("d.txt")) {
			PrintStream ps = new PrintStream(os);
			//ps = System.out;
			int T = scan.nextInt();
			for (int t=0; t<T; t++) {
				int X = scan.nextInt();
				int R = scan.nextInt();
				int C = scan.nextInt();
				int Large = Math.max(R, C);
				int Small = Math.min(R, C);
				boolean richard = false;
				if (X > Large)
					richard = true;
				else if ( (R*C) % X != 0)
					richard = true;
				else switch (X) {
				case 1:
					richard = false;
					break;
				case 2:
					richard = false;
					break;
				case 3:
					if (Small >= 2)
						richard = false;
					else
						richard = true;
					break;
				case 4:
					if (Small >= 3)
						richard = false;
					else
						richard = true;
					break;
				case 5:
					if (Small >= 3)
						richard = false;
					else
						richard = true;
					break;
				case 6:
					if (Small >= 4)
						richard = false;
					else
						richard = true;
					break;
				default:
					richard = true;
				}
				if (richard)
					ps.format("Case #%d: RICHARD\n",t+1);
				else
					ps.format("Case #%d: GABRIEL\n",t+1);
			}
		}
	}

}
