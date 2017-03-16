package cdejam;

import java.io.*;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class szxcvzxvcxzvc {

	public static void main(String args[]) throws Exception {

		BufferedReader bf = new BufferedReader(
				new FileReader("D:\\Tax_Forms\\formsprocessing\\java_project\\src\\cdejam\\input.txt"));

		BufferedWriter bw = new BufferedWriter(
				new FileWriter("D:\\Tax_Forms\\formsprocessing\\java_project\\src\\cdejam\\output.txt"));

		int N = Integer.parseInt(bf.readLine());

		for (int i = 1; i <= N; i++) {
			String input = bf.readLine();
			char[] sortedch = input.toCharArray();
			Arrays.sort(sortedch);
			String sortedip = new String(sortedch);
			StringBuffer inputbfr = new StringBuffer(sortedip);
			ArrayList<Integer> out = new ArrayList<>();
			boolean flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("Z") >= 0) {
					out.add(0);
					flag = true;
					int k = inputbfr.indexOf("Z");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("R");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("O");
					inputbfr.delete(k, k + 1);
				}
				if (inputbfr.indexOf("W") >= 0) {
					out.add(2);
					flag = true;
					int k = inputbfr.indexOf("T");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("W");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("O");
					inputbfr.delete(k, k + 1);
				}
				if (inputbfr.indexOf("X") >= 0) {
					out.add(6);
					flag = true;
					int k = inputbfr.indexOf("S");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("I");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("X");
					inputbfr.delete(k, k + 1);
				}
				if (inputbfr.indexOf("G") >= 0) {
					out.add(8);
					flag = true;
					int k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("I");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("G");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("H");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("T");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("T") >= 0) {
					out.add(3);
					flag = true;
					int k = inputbfr.indexOf("T");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("H");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("R");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("T") >= 0) {
					out.add(3);
					flag = true;
					int k = inputbfr.indexOf("T");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("H");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("R");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("R") >= 0) {
					out.add(4);
					flag = true;
					int k = inputbfr.indexOf("F");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("O");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("U");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("R");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("F") >= 0) {
					out.add(5);
					flag = true;
					int k = inputbfr.indexOf("F");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("I");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("V");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("O") >= 0) {
					out.add(1);
					flag = true;
					int k = inputbfr.indexOf("O");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("N");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("I") >= 0) {
					out.add(9);
					flag = true;
					int k = inputbfr.indexOf("N");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("I");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("N");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
				}

			}
			flag = true;
			while (flag) {
				flag = false;
				if (inputbfr.indexOf("S") >= 0) {
					out.add(7);
					flag = true;
					int k = inputbfr.indexOf("S");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("V");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("E");
					inputbfr.delete(k, k + 1);
					k = inputbfr.indexOf("N");
					inputbfr.delete(k, k + 1);
				}

			}
			Collections.sort(out);
			bw.write("Case #" + i + ": ");//
			for (Integer integer : out) {
				bw.write(integer + "");
			}
		bw.newLine();
		}
		bw.close();

	}

}
