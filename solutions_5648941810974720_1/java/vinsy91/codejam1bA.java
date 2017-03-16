import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;


public class codejam1bA {
	public static void main(String[] args) {
		int T = in.nextInt();
		for(int t = 0; t < T; t++) {
			String s = in.nextLine();
			HashMap<Character, Integer> map = new HashMap<>();
			for(int i = 0; i < s.length(); i++) {
				if(map.containsKey(s.charAt(i))) {
					int count = map.get(s.charAt(i));
					map.put(s.charAt(i), count+1);
				} else {
					map.put(s.charAt(i), 1);
				}
			}
			StringBuilder zeros = new StringBuilder();
			if(map.containsKey('Z')) {
				int count = map.get('Z');
				for(int i = 0; i < count; i++) zeros.append('0');
				map.put('Z',map.get('Z')-count);
				map.put('E',map.get('E')-count);
				map.put('R',map.get('R')-count);
				map.put('O',map.get('O')-count);
			}
			StringBuilder sixes = new StringBuilder();
			if(map.containsKey('X')) {
				int count = map.get('X');
				for(int i = 0; i < count; i++) sixes.append('6');
				map.put('S',map.get('S')-count);
				map.put('I',map.get('I')-count);
				map.put('X',map.get('X')-count);
			}
			StringBuilder eights = new StringBuilder();
			if(map.containsKey('G')) {
				int count = map.get('G');
				for(int i = 0; i < count; i++) eights.append('8');
				map.put('E',map.get('E')-count);
				map.put('I',map.get('I')-count);
				map.put('G',map.get('G')-count);
				map.put('H',map.get('H')-count);
				map.put('T',map.get('T')-count);
			}
			StringBuilder twos = new StringBuilder();
			if(map.containsKey('W')) {
				int count = map.get('W');
				for(int i = 0; i < count; i++) twos.append('2');
				map.put('T',map.get('T')-count);
				map.put('O',map.get('O')-count);
				map.put('W',map.get('W')-count);
			}
			StringBuilder sevens = new StringBuilder();
			if(map.containsKey('S') && map.get('S') > 0) {
				int count = map.get('S');
				for(int i = 0; i < count; i++) sevens.append('7');
				map.put('S',map.get('S')-count);
				map.put('E',map.get('E')-count);
				map.put('V',map.get('V')-count);
				map.put('E',map.get('E')-count);
				map.put('N',map.get('N')-count);
			}
			StringBuilder fives = new StringBuilder();
			if(map.containsKey('V') && map.get('V') > 0) {
				int count = map.get('V');
				for(int i = 0; i < count; i++) fives.append('5');
				map.put('F',map.get('F')-count);
				map.put('V',map.get('V')-count);
				map.put('I',map.get('I')-count);
				map.put('E',map.get('E')-count);
			}
			StringBuilder fours = new StringBuilder();
			if(map.containsKey('F') && map.get('F') > 0) {
				int count = map.get('F');
				for(int i = 0; i < count; i++) fours.append('4');
				map.put('F',map.get('F')-count);
				map.put('O',map.get('O')-count);
				map.put('U',map.get('U')-count);
				map.put('R',map.get('R')-count);
			}
			StringBuilder threes = new StringBuilder();
			if(map.containsKey('R') && map.get('R') > 0) {
				int count = map.get('R');
				for(int i = 0; i < count; i++) threes.append('3');
				map.put('T',map.get('T')-count);
				map.put('H',map.get('H')-count);
				map.put('R',map.get('R')-count);
				map.put('E',map.get('E')-count);
				map.put('E',map.get('E')-count);
			}
			StringBuilder nines = new StringBuilder();
			if(map.containsKey('I') && map.get('I') > 0) {
				int count = map.get('I');
				for(int i = 0; i < count; i++) nines.append('9');
				map.put('N',map.get('N')-count);
				map.put('I',map.get('I')-count);
				map.put('N',map.get('N')-count);
				map.put('E',map.get('E')-count);
			}
			StringBuilder ones = new StringBuilder();
			if(map.containsKey('N') && map.get('N') > 0) {
				int count = map.get('N');
				for(int i = 0; i < count; i++) ones.append('1');
				map.put('O',map.get('O')-count);
				map.put('N',map.get('N')-count);
				map.put('E',map.get('E')-count);
			}
			String ans = zeros.toString() + ones.toString() + twos.toString() + threes.toString() + fours.toString() + fives.toString() +
					sixes.toString() + sevens.toString() + eights.toString() + nines.toString();
			System.out.println("Case #"+(t+1)+": " + ans);
		}
		
	}

	//------------ fast input/ouput--------//
	
	public static Object returnFirst(Object x, Object y) {
		return x;
	}

	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	public static FastScanner in = new FastScanner();

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	} //--fast i/o ends here----//
	

}
