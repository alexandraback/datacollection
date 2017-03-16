package contest.codejam.codejam2016r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.UncheckedIOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.stream.IntStream;

/**
 * @author julian
 */
public class B {

	public static final void main(String[] args) throws IOException {
		(new B()).run();
	}

	private String className = getClass().getSimpleName();
	private String inputFile = this.className + ".in";
	private String outputFile = this.className + ".out";

	int n;
	List<List<Integer>> lists = new ArrayList<>();

	public B() {
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
		lists.clear();
	}

	public void read(BufferedReader in) {
		try {
			StringTokenizer stok = new StringTokenizer(in.readLine());
			this.n = Integer.parseInt(stok.nextToken());
			IntStream.range(0, (2 * this.n) - 1).forEach(x -> {
				try {

					String line = in.readLine();
					StringTokenizer st = new StringTokenizer(line);
					List<Integer> list = new ArrayList<>();
					IntStream.range(0, this.n).forEach(y -> {
						list.add(Integer.parseInt(st.nextToken()));
					});
					this.lists.add(list);
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			});
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
		List<Integer> elements = new ArrayList<>();
		this.lists.forEach(list -> {
			list.forEach(elem -> elements.add(elem));
		});
		Map<Integer, Integer> count = new HashMap<>();
		elements.forEach(elem -> count.put(elem, 0));
		elements.forEach(elem -> {
			int newValue = count.get(elem) + 1;
			count.put(elem, newValue);
		});
		Set<Integer> result = new TreeSet<>();
		elements.forEach(elem -> {
			if (count.get(elem) % 2 != 0) {
				result.add(elem);
			}
		});
		StringBuilder sb = new StringBuilder();
		result.forEach(elem -> sb.append(elem + " "));
		return sb.toString().trim();
	}

}
