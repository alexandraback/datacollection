import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;


public class R1CP3 {

	public static void main(String[] args) throws Exception {
		String file = "C-small-attempt2";
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader(file + ".in"));
		PrintStream ps = new PrintStream(new FileOutputStream(file + ".out"));
		int testcases = Integer.parseInt(br.readLine());
		for(int t = 0; t < testcases; t++){
			String[] ln = br.readLine().split(" ");
			int c = Integer.parseInt(ln[0]);
			int d = Integer.parseInt(ln[1]);
			int v = Integer.parseInt(ln[2]);
			
			String[] udn = br.readLine().split(" ");
			ArrayList<Integer> dn = new ArrayList<Integer>();
			for(int i = 0; i < udn.length; i++){
				dn.add(Integer.parseInt(udn[i]));
			}
			
			ArrayList<Integer> remainders = new ArrayList<Integer>();
			for(int i = 1; i <= v; i++){
				found = false;
				minRemain = Integer.MAX_VALUE;
				remain(dn, i, new ArrayList<Integer>());
				if(minRemain != 0 && !remainders.contains(minRemain))
					remainders.add(minRemain);
			}
			
			for(int k = 0; k < remainders.size(); k++){
				lbl:
				for(int i = 0; i < k; i++){
					for(int j = 0; j < k; j++){
						if(remainders.get(i) + remainders.get(j) == remainders.get(k) && i != j){
							remainders.remove(k);
							k--;
							break lbl;
						}
					}
				}
			}
			
			System.out.println(remainders.toString());
			ps.println("Case #" + (t + 1) + ": " + remainders.size());

		}

	}
	public static boolean found = false;
	public static int minRemain = Integer.MAX_VALUE;
	public static void remain(ArrayList<Integer> dn, int n, ArrayList<Integer> used){
		
		if(n < minRemain)
				minRemain = n;
		if(n == 0){
			found = true;
			minRemain = 0;
			return;
		}

		for(int i : dn){
			if(i <= n && !used.contains(i)){
				used.add(i);
				remain(dn, n - i, (ArrayList<Integer>) used.clone());
			}
			
		}
	}

}
