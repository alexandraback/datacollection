import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class HouseofPancakes {

	
	public static int NextRec (ArrayList<Integer> numPancakes, int miniute) {
		
		if (numPancakes.size() == 0 || numPancakes.get(0) == 0) return miniute;
		if (numPancakes.get(0) == 1) return miniute + 1;
		ArrayList<Integer> wait = new ArrayList<Integer>(numPancakes);
		for (int i = 0; i < wait.size(); ++i) {
			int cur =wait.get(i);
			wait.set(i, cur - 1);
		}
		wait.removeAll(Arrays.asList(0));
		int minForWait = NextRec(wait, miniute + 1);
		
		ArrayList<Integer> call = new ArrayList<Integer>(numPancakes);
		int max = call.remove(0);
		call.add(max / 2);
		if (max % 2 == 0) call.add(max / 2);
		else call.add(max / 2 + 1);
		Collections.sort(call, Collections.reverseOrder());
		int minForCall = NextRec(call, miniute + 1);
		return Integer.min(minForCall, minForWait);
	}
	
	public static void solution(String inputFile, String outputFile) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File(inputFile)));
		PrintWriter pw = new PrintWriter(new FileWriter(new File(outputFile)));
		String line = br.readLine();
		int N = Integer.parseInt(line);
		int id = 1;
		for (int i = 0; i < N; ++i) {
			int D = Integer.parseInt(br.readLine());
			String[] lineSplit = br.readLine().split(" ");
			ArrayList<Integer> numCakes = new ArrayList<Integer>();
			for (int j = 0; j < D; ++j) {
				numCakes.add(Integer.parseInt(lineSplit[j]));
			}
			Collections.sort(numCakes, Collections.reverseOrder());
			numCakes.removeAll(Arrays.asList(0));
			// int minMiniutes = NextRec(numCakes, 0);
			int minMiniutes = check2(numCakes);
			pw.println("Case #"+id+": "+minMiniutes);
			id++;
		}
		br.close();
		pw.close();
	}
	
	
	public static int check2(ArrayList<Integer> numPancakes) {
		int max = numPancakes.get(0);
		if (max <= 1) return  max;
		int minTime = max;
		for (int eatTime = 1; eatTime < max; ++eatTime) {
			int totalTime = eatTime;
			for (int num : numPancakes) {
				if (num <= eatTime) continue;
				if (num % eatTime == 0) totalTime += (num / eatTime) - 1;
				else totalTime += (num / eatTime);
			}
			minTime = Integer.min(minTime, totalTime);
		}
		return minTime;
		
	}
	public static void main(String[] args) throws IOException {
		String inputFile = "src/HouseofPancakes.in";
		String outputFile = "src/HouseofPancakes.out";
		HouseofPancakes.solution(inputFile, outputFile);
	}
}
