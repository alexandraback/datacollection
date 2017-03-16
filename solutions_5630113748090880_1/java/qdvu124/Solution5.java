import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.Map.Entry;
import java.util.Scanner;

public class Solution5 {
	public static String convert(int array[]){
		StringBuilder sb = new StringBuilder();
		for(int i: array)
			sb.append(i + " ");
		return sb.toString();
	}
	public static void main (String []args) throws IOException{
		File inputFile = new File("C:/Users/dinhq/OneDrive/Documents/Study/College/Sophomore Year/Spring/COSC 290L/Twitter/B-large.in");
		File outputFile = new File("C:/Users/dinhq/OneDrive/Documents/Study/College/Sophomore Year/Spring/COSC 290L/Twitter/Output.txt");
		FileWriter output = new FileWriter(outputFile);
		Scanner input = new Scanner(inputFile);
		int test, n, scan;
		test = input.nextInt();
		input.nextLine();
		for(int i = 1; i <= test; i++){
			n = input.nextInt();
			input.nextLine();
			scan = 2*n-1;
			String data;
			int index = 0;
			int[] missing = new int[n];
			Hashtable <Integer,Integer> soldiers = new Hashtable<Integer,Integer>();
			for(int j = 0; j < scan; j++){
				data = input.nextLine();
				String[] dataArray = data.split(" ");
				for(int k = 0; k < n; k++){
					int current = Integer.parseInt(dataArray[k]);
					if(soldiers.containsKey(current))
						soldiers.put(current, soldiers.get(current)+1);
					else
						soldiers.put(current, 1);
				}
			}
			for(Entry <Integer,Integer> e: soldiers.entrySet()){
				if(e.getValue()%2==1){
					missing[index] = e.getKey();
					index++;
				}
			}
			Arrays.sort(missing);
			output.write("Case #" + i + ": " + convert(missing)+ "\n");
		}
		input.close();
		output.close();
	}
}
