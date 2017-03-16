import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class lawn {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		int t = 0;
		Scanner sc = new Scanner(new File("input2.in"));
		t = sc.nextInt();
		for(int i = 0; i < t; i++){
			List<List<Integer>> lawn = new ArrayList<List<Integer>>();
			int n = sc.nextInt();
			int m = sc.nextInt();
			List<Integer> line;
			for(int j = 0; j < n; j++){
				line = new ArrayList<Integer>();
				for(int k = 0; k < m; k++)
					line.add(sc.nextInt());
				lawn.add(line);
			}
			System.out.println("Case #" + (i+1) + ": " + solve(n, m, lawn));
		}
	}
	private static String solve(int n, int m, List<List<Integer>> lawn ){
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
			{
				//check line
				int ok1 = 1;
				int ok2 = 1;
				for(int c = 0; c < m; c++)
					if(lawn.get(i).get(j) < lawn.get(i).get(c)) { ok1 = 0; break; }
				//check column
				for(int l = 0; l < n; l++)
					if(lawn.get(i).get(j) < lawn.get(l).get(j)) {ok2 = 0; break; }
				if(ok1 == 0 && ok2 == 0) return "NO";
			}
		}
		
		return "YES";
	}
}
