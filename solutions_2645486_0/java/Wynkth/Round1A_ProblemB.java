import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Google Code Jam 2013
 * Round 1A: Problem B. Manage Your Energy 
 * @author Jose Toro (@Wynkth)
 */

public class Round1A_ProblemB {
	public static void main (String[] args) throws IOException {	
		FileReader fr = new FileReader("in.txt");
		Scanner sc = new Scanner(fr);
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
		int cases = Integer.parseInt(sc.nextLine());
		
		for(int i = 1; i<=cases; i++) {
			System.out.println("Processing Case #" + i);
			StringTokenizer st = new StringTokenizer(sc.nextLine());
			int max = Integer.valueOf(st.nextToken());
			int regain = Integer.valueOf(st.nextToken());
			int n = Integer.valueOf(st.nextToken());
			List<Integer> tareas = new ArrayList<Integer>();
			st = new StringTokenizer(sc.nextLine());
			for (int k = 0; k < n; k++) {
				tareas.add(Integer.parseInt(st.nextToken()));
			}
			if(max == regain) {
				int kk = 0;
				int gain = 0;
				while(kk<tareas.size()) {
					gain+=tareas.get(kk)*regain;
					kk++;
				}
				bw.write("Case #" + i + ": " + gain + "\n");
			}
			else {
				bw.write("Case #" + i + ": " + solve(max,max,0,regain,tareas) + "\n");
			}
			
		}
		
		sc.close();
		fr.close();
		bw.close();
	}
	
	public static int solve(int max, int power, int i, int regain, List<Integer> tareas) {
		if(i == tareas.size()) return 0;
		
		int tar = tareas.get(i);
		List<Integer> res = new ArrayList<Integer>();
		for(int k = 0; k<=power; k++) {
			res.add(k*tar + solve(max,Math.min(max,power-k+regain),i+1,regain,tareas));
		}
		//Math.max(power*tar + solve(max,regain,i+1,regain,tareas),
		//		regain*tar + solve(max,power-regain,i+1,regain,tareas));
		return Collections.max(res);	
	}
}