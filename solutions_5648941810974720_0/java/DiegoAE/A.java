import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class A {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens()) {
				String cad = br.readLine();
				if (cad == null)
					return null;
				tk=new StringTokenizer(cad);
			}
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	
	static String[] array = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	
	
	static void first_round(int[] m) {
		char[] K = {'Z', 0, 'W', 0, 'U', 0, 'X', 0, 'G', 0};
		for(int i = 0; i < K.length; i++) {
			if (K[i] == 0) continue;
			while (m[K[i] - 'A'] > 0) {
				l.add(i);
				char[] word = array[i].toCharArray();
				for(int j = 0; j < word.length; j++) {
					m[word[j] - 'A']--;
				}
			}
		}
	}
	
	
	static void second_round(int[] m) {
		char[] K = {0, 'O', 0, 'H', 0, 'F', 0, 'S', 0,  'N'};
		for(int i = 0; i < K.length; i++) {
			if (K[i] == 0) continue;
			while (m[K[i] - 'A'] > 0) {
				l.add(i);
				char[] word = array[i].toCharArray();
				for(int j = 0; j < word.length; j++) {
					m[word[j] - 'A']--;
				}
			}
		}
	}
	
	static LinkedList<Integer> l;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++) {
			l = new LinkedList<Integer>();
			char[] letters = sc.next().toCharArray();
			int[] map = new int[30];
			for(int i = 0; i < letters.length; i++)
				map[letters[i] - 'A']++;
			first_round(map);
			second_round(map);
			Collections.sort(l);
			System.out.print("Case #" + c +": ");
			for(int i: l)
				System.out.print(i);
			System.out.println();
			
		}
	}

}
