package codeJam.util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class IOStream {

	public static BufferedReader bufferedReader;
	public static BufferedWriter bufferedWriter;
	public static String fileName;

	public IOStream(String filename) {
		fileName = filename;
	}
	public static void setInput() throws IOException {
		bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(new File(
				fileName + ".in"))));
	}

	public static void setOutput() throws IOException {
		bufferedWriter = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(
				fileName + ".out"))));
	}

	public static int[] convertString2Int(String... split) {
		int[] numList = new int[split.length];
		int i = 0;
		for (String num : split) {
			numList[i] = Integer.parseInt(num);
			i++;
		}
		return numList;
	}

	protected static void close() throws IOException {
//		System.out.println("closing...");
		if (bufferedWriter != null) {
			bufferedWriter.flush();
			bufferedWriter.close();
		}

		if (bufferedReader != null) {
			bufferedReader.close();
		}
	}

}
