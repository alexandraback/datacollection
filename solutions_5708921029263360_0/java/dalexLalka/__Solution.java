import java.io.*;
import java.util.*; // тут лежат все коллекции, Random

// имя начинается с двух подчеркиваний, чтобы был первым в списке (он сортится по алфавиту)
public class __Solution {

	// определяет, запускается решение "дома" или на CF/timus
	static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

	public static void main(String[] args) {
		new __Solution().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	void init() throws FileNotFoundException {
		// иницилизация потоков вводилок/выводилок
		// System.in/System.out - стандартные потоки ввода/вывода на консоль

		if (ONLINE_JUDGE) {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
//			in = new BufferedReader(new InputStreamReader(System.in));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
		}

		tok = new StringTokenizer("");
	}

	void run() {
		try {
			long timeStart = System.currentTimeMillis();

			init();

			int tests = readInt();
			for (int test = 1; test <= tests; ++test) {
				out.print("Case #" + test + ": ");
				solve();
				
				long timeEnd = System.currentTimeMillis();
				System.err.println("Test = " + test + " " + (timeEnd - timeStart));
			}

			out.close();

			long timeEnd = System.currentTimeMillis();
			System.err.println("Time = " + (timeEnd - timeStart));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	// чтение строки вернет null, если ничего не осталось
	String readLine() throws IOException {
		return in.readLine();
	}

	char[] readCharArray() throws IOException {
		return readLine().toCharArray();
	}

	// содержит символы, являющиеся "разделителями ввода"
	// по умолчанию это пробел (перевод строки автоматом учитывается)
	String delimiter = " ";

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			String nextLine = readLine();
			if (null == nextLine)
				return null;

			tok = new StringTokenizer(nextLine);
		}

		return tok.nextToken(delimiter);
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}
	
	String f(int index) {
		char l = (char)('A' + index);
		return "" + l;
	}
	
	class Outfit {
		int j, p, s;

		public Outfit(int j, int p, int s) {
			super();
			this.j = j;
			this.p = p;
			this.s = s;
		}
		
		
	}
	
	List<Outfit>[][][][] answers = new List[4][4][4][11];

	// тут мы будем писать основное решение
	void solve() throws IOException {
		int J = readInt();
		int P = readInt();
		int S = readInt();
		int k = readInt();
		
		if (answers[J][P][S][k] != null) {
			out.println(answers[J][P][S][k].size());
			for (Outfit o : answers[J][P][S][k]) {
				out.println((o.j + 1) + " " + (o.p + 1) + " " + (o.s + 1));
			}
			return;
		}
		
		ArrayList<Outfit> outfits = new ArrayList<>();
		
		for (int j = 0; j < J; ++j) {
			for (int p = 0; p < P; ++p) {
				for (int s = 0; s < S; ++s) {
					outfits.add(new Outfit(j, p, s));
				}
			}
		}
		
		int[][] jp = new int[J][P];
		int[][] js = new int[J][S];
		int[][] ps = new int[P][S];


		int[] bMs = new int[11];
		int[] bests = new int[11];
		
		int size = outfits.size();
		for (int mask = 0; mask < (1 << size); ++mask) {
			for (int j = 0; j < J; ++j) {
				for (int p = 0; p < P; ++p) {
					jp[j][p] = 0;
				}
			}
			
			for (int j = 0; j < J; ++j) {
				for (int s = 0; s < S; ++s) {
					js[j][s] = 0;
				}
			}
			
			for (int p = 0; p < P; ++p) {
				for (int s = 0; s < S; ++s) {
					ps[p][s] = 0;
				}
			}
			
			int days = 0;
			for (int i = 0; i < size; ++i) {
				if (checkBit(mask, i)) {
					Outfit o = outfits.get(i);
					jp[o.j][o.p]++;
					js[o.j][o.s]++;
					ps[o.p][o.s]++;
					
					++days;
				}
			}
			
			boolean[] flags = new boolean[11];
			Arrays.fill(flags, true);
			
			for (int j = 0; j < J; ++j) {
				for (int p = 0; p < P; ++p) {
					for (int lim = 0; lim < 11; ++lim) {
						if (jp[j][p] > lim) flags[lim] = false;
					}
				}
			}
			
			for (int j = 0; j < J; ++j) {
				for (int s = 0; s < S; ++s) {
					for (int lim = 0; lim < 11; ++lim) {
						if (js[j][s] > lim) flags[lim] = false;
					}
				}
			}
			
			for (int p = 0; p < P; ++p) {
				for (int s = 0; s < S; ++s) {
					for (int lim = 0; lim < 11; ++lim) {
						if (ps[p][s] > lim) flags[lim] = false;
					}
				}
			}
			
			for (int lim = 0; lim < 11; ++lim) {
				if (flags[lim]) {
					if (days > bests[lim]) {
						bests[lim] = days;
						bMs[lim] = mask;
					}	
				}
			}
		}
		
		for (int lim = 1; lim < 11; ++lim) {
			List<Outfit> os = new ArrayList<>();
			for (int i = 0; i < size; ++i) {
				if (checkBit(bMs[lim], i)) {
					Outfit o = outfits.get(i);
					os.add(o);
				}
			}
			
			answers[J][P][S][lim] = os;
		}
		
		out.println(answers[J][P][S][k].size());
		for (Outfit o : answers[J][P][S][k]) {
			out.println((o.j + 1) + " " + (o.p + 1) + " " + (o.s + 1));
		}
		return;
	}
	
	boolean checkBit(int mask, int bit) {
		return (mask & (1 << bit)) != 0;
	}
}