package passwordproblem;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class SimpleReader {

	private BufferedReader br;
	private int line = 0;
	
	public SimpleReader() {
		String filename = prompt();
		setReader(filename);
	}
	
	public SimpleReader(String filename) {
		setReader(filename);
	}
	
	private String prompt() {
		System.out.println("Input file: ");
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
	
	private void setReader(String filename) {
		try {
			br = new BufferedReader(new FileReader(filename));
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
	
	public String readLine() {
		try {
			line++;
			return br.readLine();
		} catch (IOException e) {
			System.err.println("Line " + (line - 1) + ": " + e.getMessage());
			return null;
		}
	}
	
	public int readInt() {
		return Integer.parseInt(readLine());
	}
	
	public int[] readIntArray() {
		String[] tokens = readLine().split(" ");
		int[] ret = new int[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			ret[i] = Integer.parseInt(tokens[i]);
		}
		return ret;
	}
	
	public String[] readStringArray() {
		return readLine().split(" ");
	}

    public double[] readDoubleArray() {
        String[] tokens = readLine().split(" ");
        double[] ret = new double[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            ret[i] = Double.parseDouble(tokens[i]);
        }
        return ret;
    }
}
