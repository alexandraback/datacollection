package root;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	
	public static void main(String[] args) throws IOException {
		solveFolder(INPUT);
	}
	
	public static int task1(int r, int c, int w) {
		int res = c/w * r;
		if (c % w != 0)
			res += 1;
		res += (w-1);
		return res;
	}
	
	
	public static final File INPUT = new File("d:/TEST/");

	public static void solveFolder(File folder) throws IOException {
		if(!folder.isDirectory())
			throw new RuntimeException("Input folder dosen't exist");
		for(File file : folder.listFiles(f -> f.getName().endsWith(".in"))) {
			solveFile(file);
		}
	}
	
	public static String getSimpleFileName(String fileName) {
		return fileName.replaceAll("\\.([^\\.]*)$", "");
	}
	
	public static void solveFile(File inputFile) throws IOException {
		File outputFile = new File(getSimpleFileName(inputFile.getAbsolutePath())+".out");
		BufferedReader inputReader = new BufferedReader(new FileReader(inputFile));
		PrintWriter outputWriter = new PrintWriter(outputFile);
		int testNum = Integer.parseInt(inputReader.readLine());
		for (int i=0; i<testNum; i++) {
			String[] rcw = inputReader.readLine().split(" ");
			int r = Integer.parseInt(rcw[0]);
			int c = Integer.parseInt(rcw[1]);
			int w = Integer.parseInt(rcw[2]);
			int answer = task1(r, c ,w);
			outputWriter.format("Case #%d: %d\n", (i+1), answer);
		}
		inputReader.close();
		outputWriter.close();
	}
	
}