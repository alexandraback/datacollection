import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;

public class Dancing {

	static PrintStream O = System.out;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			PrintWriter out = new PrintWriter(new FileWriter("b.out"));
			BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
			int cases = Integer.parseInt(in.readLine());
			for (int kase = 0; kase < cases; kase++){
				String input = in.readLine();
				String[] arr = input.split(" ");
				int N = Integer.parseInt(arr[0]);
				int S = Integer.parseInt(arr[1]);
				int p = Integer.parseInt(arr[2]);
				int[] t = new int [arr.length - 3];
				for (int i = 0; i < t.length; i++){
					t[i] = Integer.parseInt(arr[i + 3]);
				}
				
				int pastMax = 0;
				for (int i = 0; i < t.length; i++){
					if (findMax(t[i]) >= p){
						pastMax++;
					}else if (S > 0 && findSMax(t[i]) >= p){
						pastMax++;
						S--;
					}
				}
				out.println("Case #" + (kase + 1) + ": " + pastMax);
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static int findMax (int sum){
		if (sum == 0){
			return 0;
		}else if (sum == 1){
			return 1;
		}else if (sum == 2){
			return 1;
		}else if (sum == 3){
			return 1;
		}else if (sum == 4){
			return 2;
		}
		return (sum + 2) / 3;
	}
	
	static int findSMax (int sum){
		if (sum == 0){
			return 0;
		}else if (sum == 1){
			return 1;
		}else if (sum == 2){
			return 2;
		}else if (sum == 3){
			return 2;
		}else if (sum == 4){
			return 2;
		}else if (sum == 5){
			return 3;
		}
		return (sum + 4) / 3;
	}

}
