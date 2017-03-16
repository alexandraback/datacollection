import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Asmall {

	int cases_;
	int[] rowMask_ = new int[4];
	int[] colMask_ = new int[4];
	int[] diagMask_ = new int[2];
	int allMask_;

	private enum State {
		X, O, DRAW, UNFINISHED;
	}


	public Asmall(String input, String output) throws IOException {
		allMask_ = 0xFFFF;
		rowMask_[0] = 0xF;
		rowMask_[1] = 0xF0;
		rowMask_[2] = 0xF00;
		rowMask_[3] = 0xF000;
		colMask_[0] = 0x1111;
		colMask_[1] = 0x2222;
		colMask_[2] = 0x4444;
		colMask_[3] = 0x8888;
		diagMask_[0] = 0x1248;
		diagMask_[1] = 0x8421;
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		cases_ = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < cases_; i++) {
			int[] boards = readLines(4, sc);
			int boardX = boards[0];
			int boardO = boards[1];
			if (sc.hasNextLine())
				sc.nextLine();
			System.out.print("Case #" + (i + 1) + ": ");
			bw.write("Case #" + (i + 1) + ": ");
			switch (getState(boardX, boardO)) {
			case X:
				System.out.println("X won");
				bw.write("X won");
				break;
			case O:
				System.out.println("O won");
				bw.write("O won");
				break;
			case DRAW:
				System.out.println("Draw");
				bw.write("Draw");
				break;
			case UNFINISHED:
				System.out.println("Game has not completed");
				bw.write("Game has not completed");
			}
			if (i != cases_ - 1)
				bw.newLine();
		}
		sc.close();
		bw.close();
	}

	// get state of board
	private State getState(int boardX, int boardO) {
		for (int i = 0; i < 4; i++) {
			if ((boardX & rowMask_[i]) == rowMask_[i]) {
				return State.X;
			}
			if ((boardX & colMask_[i]) == colMask_[i]) {
				return State.X;
			}
			if ((boardO & rowMask_[i]) == rowMask_[i]) {
				return State.O;
			}
			if ((boardO & colMask_[i]) == colMask_[i]) {
				return State.O;
			}
		}
		for (int i = 0; i < 2; i++) {
			if ((boardX & diagMask_[i]) == diagMask_[i]) {
				return State.X;
			}
			if ((boardO & diagMask_[i]) == diagMask_[i]) {
				return State.O;
			}
		}
		if ((boardX | boardO) == allMask_) {
			return State.DRAW;
		}
		return State.UNFINISHED;
	}


	// return BigInteger bitmap array with X's and O's
	private int[] readLines(int size, Scanner sc) {
		int boardX = 0;
		int boardO = 0;
		for (int i = 0; i < size; i++) {
			String line = sc.nextLine();
			for (int j = 0; j < size; j++) {
				if (line.charAt(j) == 'X') {
					boardX |= 1 << (i * size + j);
				} else if (line.charAt(j) == 'O') {
					boardO |= 1 << (i * size + j);
				} else if (line.charAt(j) == 'T') {
					boardX |= 1 << (i * size + j);
					boardO |= 1 << (i * size + j);
				}
			}
		}
		return new int[] { boardX, boardO };
	}


	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		Asmall t = new Asmall("A-large.in", "output-large.txt");

	}

}
