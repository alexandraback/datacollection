import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class B {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\input.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.txt"));
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 1; t <= T; t++){
			
			System.out.println("Working on case " + t);
			
			int D = Integer.parseInt(in.readLine());
			String[] nextLine = in.readLine().split(" ");
			
			ArrayList<Integer> pancakes = new ArrayList<Integer>();
			
			for (int i = 0; i < nextLine.length; i++){
				
				pancakes.add(Integer.parseInt(nextLine[i]));
				
			}
			
			Collections.sort(pancakes);
			System.out.println(pancakes);
			int min = pancakes.get(pancakes.size() - 1);
			int max = pancakes.get(pancakes.size() - 1);
			
			while (max > 0){
				
				int slices = 0;
				
				for (int i = 0; i < pancakes.size(); i++){
					
					int chunks = (int) Math.ceil(pancakes.get(i) / (double) max);
					slices += chunks - 1;
					
				}
				
				min = Math.min(slices + max, min);
				
				max--;
				
//				min = Math.min(pancakes.get(pancakes.size() - 1) + i, min);
//				
//				int temp = pancakes.get(pancakes.size() - 1);
//				pancakes.remove(pancakes.size() - 1);
//				int half = temp / 2;
//				int other = temp - half;
//				
//				int insertion = Collections.binarySearch(pancakes, half);
//				
//				if (insertion < 0) {
//					
//					insertion = insertion + 1;
//					insertion = -insertion;
//					
//				}
//				
//				pancakes.add(insertion, half);
//				
//				insertion = Collections.binarySearch(pancakes, other);
//				
//				if (insertion < 0) {
//					
//					insertion = insertion + 1;
//					insertion = -insertion;
//					
//				}
//				
//				pancakes.add(insertion, other);
//				
//				i++;
				
			}
			
			out.println("Case #" + t + ": " + min);
			
		}
		
		in.close();
		out.close();
		
		System.exit(0);
		
	}
	
}