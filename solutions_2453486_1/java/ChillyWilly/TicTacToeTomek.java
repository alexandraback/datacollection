import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

/**
 * @author Adrian
 */
public class TicTacToeTomek {
	
	public static void main(String args[]) throws FileNotFoundException, IOException {
		Game game = new Game("A-large.in", "output.out");
		game.run();
	}
	
	public static enum State {
		X, O, DRAW, INCOMPLETE;
	}
	
	public static class Game {

		private String inputFile;
		private FileOutputStream outputFile;
		
		public Game(String inputFile, String outputFile) throws FileNotFoundException {
			this.inputFile = inputFile;
			File file = new File(outputFile);
			this.outputFile = new FileOutputStream(file);
		}
		
		public void run() throws FileNotFoundException, IOException {
			BufferedReader reader = openFile(inputFile);
			int tests = getTestCases(reader);
			for (int i=1; i<=tests; i++) {
				State state = getGameState(reader);
				writeResult(i, state);
			}
			outputFile.close();
			reader.close();
		}
		
		private void writeResult(int testCase, State state) throws IOException {
			StringBuilder builder = new StringBuilder("Case #");
			builder.append(testCase);
			builder.append(": ");
			switch(state) {
				case DRAW: builder.append("Draw"); break;
				case INCOMPLETE: builder.append("Game has not completed"); break;
				case O: builder.append("O won"); break;
				case X: builder.append("X won"); break;
			}
			builder.append("\n");
			outputFile.write(builder.toString().getBytes("UTF-8"));
		}
		
		private State getGameState(BufferedReader reader) throws IOException {
			boolean emptyCellFound = false;
			int lines[] = {0, 0, 0, 0};
			int columns[] = {0, 0, 0, 0};
			int diagonals[] = {0, 0};
			char ch;
			for (int i=0; i<4; i++) {
				for (int j=0; j<4; j++) {
					ch = readChar(reader);
					int val = 0;
					switch (ch) {
						case 'X': val =  1; break;
						case 'O': val = -1; break;
						case 'T': val = 10; break;
						case '.': val =  0; emptyCellFound = true; break;
						default:
							throw new IOException("Unexpected character: "+ch);
					}
					lines[i] += val;
					columns[j] += val;
					if (i == j) {
						diagonals[0] += val;
					}
					if (i+j == 3) {
						diagonals[1] += val;
					}
				}
			}
			for (int i=0; i<4; i++) {
				if (lines[i] == 4 || lines[i] == 13 || columns[i] == 4 || columns[i] == 13) {
					return State.X;
				}
				if (lines[i] == -4 || lines[i] == 7 || columns[i] == -4 || columns[i] == 7) {
					return State.O;
				}
			}
			for (int i=0; i<2; i++) {
				if (diagonals[i] == 4 || diagonals[i] == 13) {
					return State.X;
				}
				if (diagonals[i] == -4 || diagonals[i] == 7) {
					return State.O;
				}
			}
			if (emptyCellFound) {
				return State.INCOMPLETE;
			}
			return State.DRAW;
		}
		
		private char readChar(BufferedReader reader) throws IOException {
			char ch;
			do {
				ch = (char)reader.read();
			}
			while (Character.isWhitespace(ch));
			return ch;
		}

		private int getTestCases(BufferedReader reader) throws IOException {
			int tests = Integer.parseInt(reader.readLine().trim());
			return tests;
		}

		private BufferedReader openFile(String fileName) throws FileNotFoundException {
			URL url = TicTacToeTomek.class.getClassLoader().getResource(fileName);
			if (url == null) {
				throw new FileNotFoundException("Cannot find input file");
			}
			File f = new File(url.getPath());
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
			return br;
		}
	}
}