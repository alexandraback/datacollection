package contest.codejam.codejam2016r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.UncheckedIOException;
import java.io.Writer;
import java.util.stream.IntStream;

/**
 * @author julian
 */
public class A {

	public static final void main(String[] args) throws IOException {
		(new A()).run();
	}

	private String className = getClass().getSimpleName();
	private String inputFile = this.className + ".in";
	private String outputFile = this.className + ".out";

	String s;

	public A() {
	}

	public void run() throws IOException {
		Reader input = new FileReader(this.inputFile);
		Writer output = new FileWriter(this.outputFile);
		execute(input, output);
		input.close();
		output.close();
	}

	public void execute(Reader input0, Writer output0) throws IOException {
		BufferedReader input = new BufferedReader(input0);
		BufferedWriter output = new BufferedWriter(output0);
		int t = Integer.parseInt(input.readLine());
		precompute();
		IntStream.range(0, t).forEach(index -> {
			reset();
			read(input);
			write(output, index, solve());
		});
		output.flush();
	}

	public void precompute() {
	}

	public void reset() {
	}

	public void read(BufferedReader in) {
		try {
			this.s = in.readLine();
		} catch (IOException e) {
			throw new UncheckedIOException(e);
		}
	}

	public void write(BufferedWriter out, int index, String solution) {
		try {
			out.write("Case #" + (index + 1) + ": " + solution + "\n");
		} catch (IOException e) {
			throw new UncheckedIOException(e);
		}
	}

	public String solve() {
		StringBuilder ret = new StringBuilder();
		s.chars().forEach(ch -> {
			if (ret.toString().compareTo("" + ((char) ch) + ret.toString()) > 0) {
				ret.append((char) ch);
			} else {
				ret.insert(0, (char) ch);
			}
		});
		return ret.toString();
	}

}
