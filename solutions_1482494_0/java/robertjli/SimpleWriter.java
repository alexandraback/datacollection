package kingdomrush;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class SimpleWriter {
	private BufferedWriter bw;
	private int line;
	
	public SimpleWriter() {
		String filename = prompt();
		setWriter(filename);
	}
	
	public SimpleWriter(String filename) {
		setWriter(filename);
	}
	
	private String prompt() {
		System.out.println("Output file: ");
		BufferedReader bufr = new BufferedReader(
				new InputStreamReader(System.in));
		String filename = null;
		try {
			filename = bufr.readLine();
		} catch (IOException e) {
			System.err.println("At prompt: " + e.getMessage());
		}
		return filename;
	}
	
	private void setWriter(String filename) {
		try {
			bw = new BufferedWriter(new FileWriter(filename));
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
	
	public void writeLine(String str) {
		try {
			line++;
			bw.write(str + "\n");
		} catch (IOException e) {
			System.err.println("Line " + (line - 1) + ": " + e.getMessage());
		}
	}
	
	public void writeLine(int i) {
		writeLine(i + "");
	}
	
	public void writeLine(int[] arr) {
		String line = "";
		for (int i : arr) {
			line = line + i + " ";
		}
		line = line.trim();
		writeLine(line);
	}
	
	public void flush() {
		try {
			bw.flush();
		} catch (IOException e) {
			System.err.println("At flush: " + e.getMessage());
		}
	}
}
