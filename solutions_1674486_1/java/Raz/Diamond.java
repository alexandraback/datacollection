import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;


public class Diamond {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader reader = null;
		BufferedWriter writer = null;
		try {
            
			if (args.length == 0) {             
				System.out.println("Usage Diamond <input_file>");
				System.exit(0);
			}
			
			File inputFile = new File(args[0]);

            if (!inputFile.exists())
            	System.out.println("File " + args[0] +" not found in the current directory");
           
                 
			FileReader fileReader = new FileReader(inputFile.getAbsolutePath());
			reader = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter("Output.txt");
			writer = new BufferedWriter(fileWriter);
			String line = reader.readLine();			
			int numberOfTestCases = Integer.parseInt(line);
			for (int i = 0; i < numberOfTestCases; i++) {
				line = reader.readLine();
				int classCount = Integer.parseInt(line);
				int[][] matrix = new int[classCount][];
				for (int classId = 0; classId < classCount; classId++) {
					line = reader.readLine();
					String[] tokens = line.split(" ");
					int parentCount = Integer.parseInt(tokens[0]);
					int[] parentClasses = new int[parentCount];
					for (int j = 1; j < tokens.length; j++) {
						parentClasses[j - 1] =  Integer.parseInt(tokens[j]) - 1;
					}
					matrix[classId] = parentClasses;
				}
				String output = "Case #" + (i + 1) + ": " + (hasDiamond(matrix)? "Yes":"No");
				System.out.println(output);
				writer.write(output);
				writer.newLine();
			}
						
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
			if (reader!=null) {
				reader.close();
			}
			if (writer!=null) {
				writer.close();
			}
			} catch(Exception e) {}
		}		

	}
	
	private static boolean visitAll(int[][] matrix, int node, Set<Integer> visited) {
		visited.add(node);
		int[] parents = matrix[node];
		boolean hasCycle = false;
		for (int i = 0; i < parents.length; i++) {
			if (visited.contains(parents[i])) {
				return true;
			} else {				
				hasCycle = visitAll(matrix, parents[i], visited);
				if (hasCycle){
					return true;
				}
			}				
		}
		return hasCycle;
	}

	private static boolean hasDiamond(int[][] matrix) {
		for (int classId = 0; classId < matrix.length; classId++) {
			Set<Integer> visited = new HashSet<Integer>(0);
			if (visitAll(matrix, classId, visited)) {
				return true;
			}
		}
		return false;
	}

}
