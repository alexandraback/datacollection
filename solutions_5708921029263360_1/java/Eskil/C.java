import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Random;
import java.util.TreeMap;


public class C {
	
	private static HashMap<Integer,Integer> JP;
	private static HashMap<Integer,Integer> PS;
	private static HashMap<Integer,Integer> JS;
	private static int K;
	
	private static int makeInt(int f, int s) {
		int res = 0;
		res = 10*(f % 10) + (s % 10);
		return res;
	}
	
	private static boolean check(HashMap<Integer,Integer> curr, int cu) {
		if (!curr.containsKey(cu)) {
			curr.put(cu, 0);
		}
		if (curr.get(cu) >= K) {
			return false;
		} else {
			return true;
		}		
	}
	
	private static void add(HashMap<Integer,Integer> curr, int cu) {
		curr.put(cu, curr.get(cu) + 1);		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String s = r.readLine();
		int T = Integer.parseInt(s);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < T; i++) {
			sb.append("Case #" + (i+1) + ": ");
			s = r.readLine();
			StringBuilder sc = new StringBuilder();
			String[] parts = s.split(" ");
			JP = new HashMap<>();
			JS = new HashMap<>();
			PS = new HashMap<>();
			int J, P, S;
			J = Integer.parseInt(parts[0]); P = Integer.parseInt(parts[1]);
			S = Integer.parseInt(parts[2]); K = Integer.parseInt(parts[3]);
			int count = 0;
			for (int j = 1; j <= J; j++) {
				int jp = makeInt(j, j);
				int js = makeInt(j, j);
				int ps = makeInt(j, j);
				count++;
				sc.append(j + " " + j + " " + j + "\n");
				check(JP,jp); check(JS,js); check(PS,ps);
				add(JP,jp); add(JS,js); add(PS,ps);
			}
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int sh = 1; sh <= S; sh++) {
						int jp = makeInt(j, p);
						int js = makeInt(j, sh);
						int ps = makeInt(p, sh);
						if(j == p && j == sh) {
							continue;
						}
						if (check(JP,jp) && check(JS,js) && check(PS,ps)) {
							count++;
							sc.append(j + " " + p + " " + sh + "\n");
							add(JP,jp); add(JS,js); add(PS,ps);
						}						
					}
				}
			}
			StringBuilder sd = new StringBuilder();
			int max = count;
			count = 0;
			JP = new HashMap<>();
			JS = new HashMap<>();
			PS = new HashMap<>();
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int sh = 1; sh <= S; sh++) {
						int jp = makeInt(j, p);
						int js = makeInt(j, sh);
						int ps = makeInt(p, sh);
						if (check(JP,jp) && check(JS,js) && check(PS,ps)) {
							count++;
							sd.append(j + " " + p + " " + sh + "\n");
							add(JP,jp); add(JS,js); add(PS,ps);
						}						
					}
				}
			}
			if (count > max) {
				max = count;
				sc = sd;
			}
			sd = new StringBuilder();
			count = 0;
			JP = new HashMap<>();
			JS = new HashMap<>();
			PS = new HashMap<>();
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int sh = 1; sh <= S; sh++) {
						if (j == p && sh == p) {
							continue;
						}
						int jp = makeInt(j, p);
						int js = makeInt(j, sh);
						int ps = makeInt(p, sh);
						if (check(JP,jp) && check(JS,js) && check(PS,ps)) {
							count++;
							sd.append(j + " " + p + " " + sh + "\n");
							add(JP,jp); add(JS,js); add(PS,ps);
						}						
					}
				}
			}
			if (count > max) {
				max = count;
				sc = sd;
			}
			sd = new StringBuilder();
			count = 0;
			JP = new HashMap<>();
			JS = new HashMap<>();
			PS = new HashMap<>();
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int sh = 1; sh <= S; sh++) {
						if (j == p || sh == p) {
							continue;
						}
						int jp = makeInt(j, p);
						int js = makeInt(j, sh);
						int ps = makeInt(p, sh);
						if (check(JP,jp) && check(JS,js) && check(PS,ps)) {
							count++;
							sd.append(j + " " + p + " " + sh + "\n");
							add(JP,jp); add(JS,js); add(PS,ps);
						}						
					}
				}
			}
			if (count > max) {
				max = count;
				sc = sd;
			}
			sb.append(max + "\n");
			sb.append(sc.toString());
		}
		System.out.println(sb.toString());
		PrintWriter writer = new PrintWriter("Qual1C.CCC.txt", "UTF-8");
		writer.println(sb.toString());
		writer.close();

	}


}
