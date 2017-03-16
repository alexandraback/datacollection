// The code is a mess, deal with it.

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Jelle Prins
 */
public class MinesweeperMaster {

	public static void main(String[] args) {
		String input = "input.txt";
		String output = "output.txt";
		if (args.length >= 1) {
			input = args[0];
			if (args.length >= 2) {
				output = args[1];
			}
		}
		new MinesweeperMaster(input, output);
	}

	private class Case {
		private boolean rotated = false;
		private int height;
		private int width;
		private int mines;

		public Case(String line) {
			String[] split = line.split(" ");
			height = Integer.parseInt(split[0]);
			width = Integer.parseInt(split[1]);
			mines = Integer.parseInt(split[2]);
			if (width > height) {
				int tmp = height;
				height = width;
				width = tmp;
				rotated = true;
			}
		}
	}

	public MinesweeperMaster(String inputString, String outputString) {
		File input = new File(inputString);
		File output = new File(outputString);
		if (!input.isFile()) {
			System.err.println("input file not found");
			System.exit(1);
		}
		if (output.exists()) {
			output.delete();
		}

		try {
			Case[] cases = readInput(input);
			String[] results = executeCases(cases);
			writeOutput(output, results);
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private Case[] readInput(File file) throws Exception {
		Scanner scanner = new Scanner(file);
		int caseCount = scanner.nextInt();
		scanner.nextLine();
		Case[] cases = new Case[caseCount];
		for (int i = 0; i < caseCount; i++) {
			cases[i] = new Case(scanner.nextLine());
		}
		scanner.close();
		return cases;
	}

	private String[] executeCases(Case[] cases) {
		String[] output = new String[cases.length];
		for (int i = 0; i < cases.length; i++) {
			output[i] = executeCase(i + 1, cases[i]);
		}
		return output;
	}

	private void writeOutput(File output, String[] results) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter(output));
		for (int i = 0; i < results.length; i++) {
			if (i != results.length - 1) {
				pw.println(results[i]);
			} else {
				pw.print(results[i]);
			}
		}
		pw.close();
	}

	private String executeCase(int caseID, Case input) {
		int free = getFreeCount(input);

		if (free == 0) {
			return parseOutput(caseID, null);
		} else if (free == 1 || input.mines == 0) {
			return parseOutput(caseID, fillField(input));
		} else if (input.width == 1 || input.height == 1) {
			if (free != 0) {
				return parseOutput(caseID, fillField(input));
			} else {
				return parseOutput(caseID, null);
			}
		} else if (input.width == 2 || input.height == 2) {
			if (free % 2 == 0 && free != 2) {
				if (input.height == 2) {
					int freePerRow = input.width - input.mines / 2;
					return parseOutput(caseID,
							fillField(input, freePerRow, freePerRow));
				} else {
					return parseOutput(caseID, fillField(input));
				}
			} else if (free == 1) {
				return parseOutput(caseID, fillField(input));
			} else {
				return parseOutput(caseID, null);
			}
		} else if (free <= 3) {
			return parseOutput(caseID, null);
		} else if (free == 2 * input.width + 1) {
			return parseOutput(caseID, fillFieldException2(input));
		} else if (free < 2 * input.width) {
			return parseOutput(caseID, fillFieldException1(input));
		} else {
			return parseOutput(caseID, fillField(input));
		}
	}

	private String[] fillFieldException1(Case input) {
		int free = getFreeCount(input);

		if (free < 9 && free % 2 == 1) {
			return null;
		}

		int minesOnTopRows = input.width * 2 - free;
		int minesOnFirstRow = minesOnTopRows / 2;
		int minesOnSecondRow = minesOnTopRows - minesOnFirstRow;
		int minesonThirdRow = input.width;
		if (minesOnTopRows % 2 == 1) {
			minesOnFirstRow += 2;
			minesOnSecondRow += 1;
			minesonThirdRow -= 3;
		}

		return fillField(input, input.width - minesOnFirstRow, input.width
				- minesOnSecondRow, input.width - minesonThirdRow);
	}

	private String[] fillFieldException2(Case input) {
		if (input.width < 4) {
			return null;
		}

		int minesOnFirstRow = 1;
		int minesOnSecondRow = 1;
		int minesonThirdRow = input.width - 3;

		return fillField(input, input.width - minesOnFirstRow, input.width
				- minesOnSecondRow, input.width - minesonThirdRow);
	}

	private String[] fillField(Case input) {
		int free = getFreeCount(input);
		String[] result = new String[input.height];
		int count = 0;

		for (int y = 0; y < input.height; y++) {
			StringBuilder sb = new StringBuilder();
			for (int x = 0; x < input.width; x++) {
				if (count == free && x == 1 && y != 0) {
					StringBuilder s = new StringBuilder();
					for (int i = 0; i < input.width - 1; i++) {
						s.append('.');
					}
					s.append('*');
					count--;
					result[y - 1] = s.toString();
				}
				if (count == 0) {
					sb.append('c');
				} else if (count < free) {
					sb.append('.');
				} else {
					sb.append('*');
				}
				count++;
			}
			result[y] = sb.toString();
		}

		return rotateField(input, result);
	}

	private String[] fillField(Case input, int... freePerRow) {
		String[] result = new String[input.height];
		int count = 0;

		for (int y = 0; y < input.height; y++) {
			int free = 0;
			count = 0;
			if (y < freePerRow.length) {
				free = freePerRow[y];
			}
			StringBuilder sb = new StringBuilder();
			for (int x = 0; x < input.width; x++) {
				if (y == 0 && count == 0) {
					sb.append('c');
				} else if (count < free) {
					sb.append('.');
				} else {
					sb.append('*');
				}
				count++;
			}
			result[y] = sb.toString();
		}

		return rotateField(input, result);
	}

	private String[] rotateField(Case c, String[] field) {
		if (!c.rotated) {
			return field;
		}

		String[] rotated = new String[field[0].length()];
		for (int i = 0; i < rotated.length; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < field.length; j++) {
				sb.append(field[j].charAt(i));
			}
			rotated[i] = sb.toString();
		}
		return rotated;
	}

	private int getFreeCount(Case input) {
		return input.width * input.height - input.mines;
	}

	private String parseOutput(int caseID, String[] field) {
		StringBuilder sb = new StringBuilder();
		sb.append("Case #").append(caseID).append(":\n");
		if (field == null) {
			sb.append("Impossible\n");
		} else {
			for (String s : field) {
				sb.append(s).append("\n");
			}
		}
		sb.deleteCharAt(sb.length() - 1);
		String output = sb.toString();
		System.out.println(output);
		return output;
	}
}
