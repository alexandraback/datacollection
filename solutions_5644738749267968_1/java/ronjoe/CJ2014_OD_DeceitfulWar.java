package org.rtc.codeJam;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CJ2014_OD_DeceitfulWar {

	public CJ2014_OD_DeceitfulWar(String inFile, String outFile) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			int numCases = getInt(br);
			for (int i = 0; i < numCases; i++) {
				int numBlocks = getInt(br);
				List<Double> blocksN = getList(br);
				List<Double> blocksK = getList(br);
				Collections.sort(blocksN);
				Collections.sort(blocksK);

				List<Double> blocksND = copy(blocksN);
				List<Double> blocksKD = copy(blocksK);

				int wN = 0;
				for (int j = 0; j < numBlocks; j++) {
					double bN = blocksN.remove(0);
					Double bK = null;
					for (int k = 0; k < blocksK.size(); k++) {
						if (blocksK.get(k) > bN) {
							bK = blocksK.remove(k);
							break;
						}
					}
					if (bK == null) {
						bK = blocksK.remove(0);
					}
					if (bN > bK) {
						wN++;
					}
				}

				int dwN = 0;
				for (int j = 0; j < numBlocks; j++) {
					if (blocksND.get(0) > blocksKD.get(0)) {
						dwN++;
						blocksND.remove(0);
						blocksKD.remove(0);
					} else {
						blocksND.remove(0);
						blocksKD.remove(blocksKD.size() - 1);
					}
				}

				String outStr = "Case #" + (i + 1) + ": " + dwN + " " + wN;
				put(bw, outStr);
			}
			br.close();
			bw.close();

		} catch (Exception e) {
			System.err.println(e);
		}
	}

	public static void main(String[] args) {
		// String fileName = args[0];
		// String fileName = "inDeceitWar.txt";
		// String fileName = "D-small-attempt0.in";
		String fileName = "D-large.in";
		new CJ2014_OD_DeceitfulWar(fileName, "out.txt");
	}

	private char[][] createBoard(int cols, int rows, char ch) {
		char[][] board = new char[rows][cols];
		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < cols; y++) {
				board[x][y] = ch;
			}
		}
		return board;
	}

	private void put(BufferedWriter bw, String s) throws IOException {
		System.out.println(s);
		bw.write(s, 0, s.length());
		bw.newLine();
	}

	private int getInt(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Integer.parseInt(line);
	}

	private double getDouble(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Double.parseDouble(line);
	}

	private List<Double> getList(BufferedReader br) throws IOException {
		String nums = br.readLine();
		String[] strs = nums.split(" +");
		List<Double> list = new ArrayList<>();
		for (int i = 0; i < strs.length; i++) {
			list.add(Double.parseDouble(strs[i]));
		}
		return list;
	}

	private List<Double> copy(List<Double> list) {
		List<Double> copy = new ArrayList<>();
		copy.addAll(list);
		return copy;
	}
}
