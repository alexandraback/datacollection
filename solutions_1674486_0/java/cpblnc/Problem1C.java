import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Problem1C {

	public static void main(String[] args){
		List<String> res = new ArrayList<String>();
		try {
			FileInputStream fstream = new FileInputStream("A-small-attempt0 (1).in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			int cases = Integer.valueOf(br.readLine());
			for(int i = 0; i < cases; i++) {
				String line = br.readLine();
				int size = Integer.valueOf(line);
				List<List<Integer>> graph = new ArrayList<List<Integer>>();
				for(int j = 0; j < size; j++){
					line = br.readLine();
					String[] tokens = line.split(" ");
					graph.add(new ArrayList<Integer>());
					for(int k = 1; k < tokens.length; k++)
						graph.get(j).add(Integer.valueOf(tokens[k])-1);
				}
				res.add(solve(graph));
			}
			in.close();
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
		
		try {
			// Create file
			File fout = new File("out.txt");
			FileWriter fstream = new FileWriter(fout);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < res.size(); i++){
				out.write("Case #" + (i+1) + ": " + res.get(i));
				out.newLine();
			}
			// Close the output stream
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	private static String solve(List<List<Integer>> graph) {
		int[] marked = new int[graph.size()];
		for(int i = 0; i < marked.length; i++){
			if(marked[i] == 0){
				int[] tmp = new int[marked.length];
				if(dfs(graph, i, tmp, marked)){
					return "Yes";
				}
			}
		}
		return "No";
	}
	
	private static boolean dfs(List<List<Integer>> graph, int i, int[] tmp, int[] marked){
		for(Integer parent : graph.get(i)){
			if(tmp[parent] == 1)
				return true;
			else {
				tmp[parent] = 1;
				marked[parent] = 1;
				if(dfs(graph, parent, tmp, marked))
					return true;
			}
		}
		return false;
	}
	
}
