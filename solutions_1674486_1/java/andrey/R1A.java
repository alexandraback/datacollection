import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;


public class R1A {
	public static void solve(BufferedReader reader, BufferedWriter writer) throws IOException {
		int testCount = readIntFromLine(reader);
		
		for (int test = 1; test <= testCount; test++) {
			writer.append("Case #").append(Integer.toString(test)).append(':');
			
			solveTestCase(reader, writer);
			
			writer.newLine();
		}
		writer.flush();
	}

	private static void solveTestCase(BufferedReader reader, BufferedWriter writer) throws IOException {
		int classCount = readIntFromLine(reader);
		
		int[][] classes = new int[classCount+1][];
		
		for (int i=1; i <= classCount; i++) {
			classes[i] = readArrayFromLine(reader);
		}
		
		if (findCycle(classCount, classes)) {
			writer.append(" Yes");
		} else {
			writer.append(" No");
		}
		
	}

	private static boolean findCycle(int classCount, int[][] classes) {
		ArrayList<Integer> queue = new ArrayList<Integer>(classCount);
		boolean[] visited = new boolean[classCount + 1];
		for (int i=1; i <= classCount; i++) {
			Arrays.fill(visited, false);
			queue.add(i);
			visited[i] = true;
			
			while (!queue.isEmpty()) {
				int currentClass = queue.remove(queue.size() - 1);
				
				for (int j=0; j < classes[currentClass].length; j++) {
					int parent = classes[currentClass][j]; 
					if (visited[parent]) {
						return true;
					}
					
					visited[parent] = true;
					queue.add(parent);
				}
			}
		}
		
		return false;
	}
	
	public static void solve(String inputFile, String outputFile) throws IOException {
		File input = new File(inputFile);
		File output = new File(outputFile);
		
		if (!input.exists()) {
			throw new IllegalArgumentException("Input file doesn't exist: " + inputFile);
		}
		
		BufferedReader reader = null;
		BufferedWriter writer = null;
		try {
			reader = new BufferedReader(new FileReader(input));
			writer = new BufferedWriter(new FileWriter(output));
			solve(reader, writer);
		
		} finally {
			if (reader != null)
				reader.close();
			if (writer != null)
				writer.close();
		}
	}
	
	public static int readIntFromLine(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		int testCount = Integer.parseInt(line);
		return testCount;
	}

	public static int[] readArrayFromLine(BufferedReader reader, int itemsCount) throws IOException {
		int[] items = new int[itemsCount];
		
		String line = reader.readLine();
		StringTokenizer tokenizer = new StringTokenizer(line);
		for (int i=0; i < itemsCount; i++) {
			items[i] = Integer.parseInt(tokenizer.nextToken());
		}
		return items;
	}
	
	public static int[] readArrayFromLine(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		StringTokenizer tokenizer = new StringTokenizer(line);
		
		int itemsCount = Integer.parseInt(tokenizer.nextToken());
		int[] items = new int[itemsCount];
		for (int i=0; i < itemsCount; i++) {
			items[i] = Integer.parseInt(tokenizer.nextToken());
		}
		return items;
	}
	
	public static void main(String[] args) throws IOException {
		System.out.println("Start...");
		solve("res/input.txt", "res/output.txt");
		System.out.println("Done!");
	}
}
