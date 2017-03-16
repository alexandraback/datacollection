package round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import javax.swing.JFileChooser;

public class RankAndFile {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = chooseInput();
		PrintWriter output = new PrintWriter("Round1A_Part_B_Large.txt");
		process(input, output);
		output.close();
		System.out.println("done");
	}
	
	public static void process(Scanner input, PrintWriter out){
		int numTests = input.nextInt();
		for(int i=1; i<= numTests; i++){
			int[] missing = tally(input);
			out.printf("Case #%d:", i);
			for(int num: missing){
				out.print(" " + num);
			}
			out.println();
		}
	}
	
	public static int[] tally(Scanner input){
		int N = input.nextInt();
		int[] ans = new int[N];
		Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
		for(int i=0; i<(2*N-1)*N; i++){
			int next = input.nextInt();
			if(!counts.containsKey(next)){
				counts.put(next, 0);
			}
			counts.put(next, counts.get(next)+1);
		}
		int index = 0;
		for(int key: counts.keySet()){
			if(counts.get(key)%2 != 0){
				ans[index] = key;
				index++;
			}
		}
		Arrays.sort(ans);
		return ans;
	}
	
	
	
	public static Scanner chooseInput() throws FileNotFoundException{
		JFileChooser fileChooser = new JFileChooser();
		int result = fileChooser.showOpenDialog(fileChooser);
		if(result == JFileChooser.APPROVE_OPTION){
			File selectedFile = fileChooser.getSelectedFile();
			Scanner ret = new Scanner(new FileReader(selectedFile));
			return ret;
		}
		return null;
	}
}
