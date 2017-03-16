import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class TicTacToeTomek {

	public static void main(String[] args) throws IOException {

		String name = "A-large";
		String path = "C:\\Users\\dbu\\Downloads\\";
		
		String text = TextReader.read(path + name + ".in");
		
		PrintStream out = new PrintStream(new File(path + name + ".out"));
		
		StringTokenizer tokenizer = new StringTokenizer(text);
		int n = Integer.parseInt(tokenizer.nextToken());
		System.out.println(n);
		System.out.println();
		for (int i = 0; i < n; i += 1) {
			String[] lines = new String[10];
			for (int j = 0; j < 4; j += 1) {
				lines[j] = tokenizer.nextToken();
				System.out.println(lines[j]);
			}
			System.out.println();
			
			for (int j = 0; j < 4; j += 1) {
				lines[4 + j] = "";
				for (int k = 0; k < 4; k+=1) {
					lines[4 + j] += lines[k].charAt(j);
				}
			}
			
			lines[8] = "";
			for (int k = 0; k < 4; k+=1) {
				lines[8] += lines[k].charAt(k);
			}
			
			lines[9] = "";
			for (int k = 0; k < 4; k+=1) {
				lines[9] += lines[k].charAt(3-k);
			}
			
			if (won('X', lines)) {
				out.println("Case #"+(i+1)+": X won");
				System.out.println("Case #"+(i+1)+": X won");
			} else if (won('O', lines)) {
				out.println("Case #"+(i+1)+": O won");
				System.out.println("Case #"+(i+1)+": O won");
			} else if (anyBlank(lines)) {
				out.println("Case #"+(i+1)+": Game has not completed");
				System.out.println("Case #"+(i+1)+": Game has not completed");
			} else {
				out.println("Case #"+(i+1)+": Draw");
				System.out.println("Case #"+(i+1)+": Draw");
			}
			
			System.out.println();
			System.out.println("-------");
		}
		
		out.close();
	}
	
	static boolean won(char player, String[] lines) {
		boolean won = false;
		for (int i = 0; i < 10; i += 1) {
			boolean all = true;
			for (int k = 0; k < 4; k+=1) {
				char c = lines[i].charAt(k);
				all = all && ((c == 'T') || (c == player));
			}
			won = won || all;
		}
		return won;
	}

	static boolean anyBlank(String[] lines) {
		boolean blank = false;
		for (int i = 0; i < 10; i += 1) {
			for (int k = 0; k < 4; k+=1) {
				char c = lines[i].charAt(k);
				blank = blank || (c == '.');
			}
		}
		return blank;
	}
	
}
