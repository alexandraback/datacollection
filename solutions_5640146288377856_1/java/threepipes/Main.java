import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
//	public static int[][][] dp;
	public static void main(String[] args) throws NumberFormatException,
	IOException {
		ContestScanner in = new ContestScanner("in.dat");
//		ContestScanner in = new ContestScanner();
		ContestWriter out = new ContestWriter("out.dat");
		int t = in.nextInt();
		for(int test = 0; test < t; test++){
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			int firstHit = r*(c/w);
			out.println("Case #"+(test+1)+": "+(firstHit+w-(c%w==0?1:0))+"");
		}
		out.close();
	}
	
}

class Node{
	int id;
	HashSet<Node> edge = new HashSet<Node>();
	public Node(int id) {
		this.id = id;
	}
	public void createEdge(Node node) {
		edge.add(node);
	}
}

class MyComp implements Comparator<int[]> {
	final int idx;
	public MyComp(int idx){
		this.idx = idx;
	}
	public int compare(int[] a, int[] b) {
		return a[idx] - b[idx];
	}
}

class Reverse implements Comparator<Integer> {
	public int compare(Integer arg0, Integer arg1) {
		return arg1 - arg0;
	}
}


class ContestWriter {
	private PrintWriter out;

	public ContestWriter(String filename) throws IOException {
		out = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
	}

	public ContestWriter() throws IOException {
		out = new PrintWriter(System.out);
	}

	public void println(String str) {
		out.println(str);
	}

	public void print(String str) {
		out.print(str);
	}

	public void close() {
		out.close();
	}
}

class ContestScanner {
	private BufferedReader reader;
	private String[] line;
	private int idx;

	public ContestScanner() throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(System.in));
	}

	public ContestScanner(String filename) throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				filename)));
	}

	public String nextToken() throws IOException {
		if (line == null || line.length <= idx) {
			line = reader.readLine().trim().split(" ");
			idx = 0;
		}
		return line[idx++];
	}
	
	public String readLine() throws IOException{
		return reader.readLine();
	}

	public long nextLong() throws IOException, NumberFormatException {
		return Long.parseLong(nextToken());
	}

	public int nextInt() throws NumberFormatException, IOException {
		return (int) nextLong();
	}

	public double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}
}