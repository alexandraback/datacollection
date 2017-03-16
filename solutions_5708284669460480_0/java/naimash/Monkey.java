
public class Monkey {

	public static void main(String[] args) {
		FastScanner s = new FastScanner("input.txt");
		
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			int K = s.nextInt();
			int L = s.nextInt();
			int S = s.nextInt();
			char[] key = s.nextToken().toCharArray();
			char[] word = s.nextToken().toCharArray();
			System.out.println("Case #" + t + ": " + calc(K,L,S,key,word));
		}
		
	}
	
	static double calc(int K0,int L0,int S,char[] abc,char[] word){
//		_(K,L,S,key,word);
		
		//abc - множество допустимых символов (алфавит)
		int N = abc.length;//N - размер алфавита
		// S - кол-во элементов в комбинации
		 
		int pow[] = new int[S + 1];//массив для степеней числа N: N^0, N^1, .., N^K   
		pow[0] = 1;
		for (int i = 1; i <= S; i++) {//вычисляем степени числа N
			pow[i] = pow[i - 1] * N;
		}
		 
		int total = 0;
		int max = 0;
		//перебираем все номера комбинаций
		for (int i = 0; i < pow[S]; i++) {
			char arr[] = new char[S];
			//вычисляем элементы комбинации
			for (int j = 0; j < S; j++) {
				//каждый элемент получаем из массива abc по индексу,
				//индекс - это число в системе счисления по основанию N (0..N-1)
				//в соответствующем разряде j (от 0 до K-1 включительно)
				arr[j] = abc[(i / pow[j]) % N];
			}			
//			for(char ch : arr){
//				System.out.print(ch);
//			}
//			System.out.println();
				
			int local = 0;
			for (int j = 0; j <= arr.length - word.length; j++) {
				boolean check = true;
				for (int k = 0; k < word.length; k++) {
					if(arr[j + k] != word[k]){
						check = false;
						break;
					}
				}
				if(check){
					local++;
					
				}	
				max = Math.max(max, local);
			}
			total += local;
			
			
		}
		
//		_(total,max,pow[S]);
		
		return max - 1d * total / pow[S];
	}
	
	static void _(Object... obj) {
		System.out.println(java.util.Arrays.deepToString(obj));
	}
	
	public static class FastScanner {
		java.io.BufferedReader br;
		java.util.StringTokenizer st;

		public FastScanner() {
			init();
		}

		public FastScanner(String name) {
			init(name);
		}

		public FastScanner(boolean isOnlineJudge) {
			if (!isOnlineJudge || System.getProperty("ONLINE_JUDGE") != null) {
				init();
			} else {
				init("input.txt");
			}
		}

		private void init() {
			br = new java.io.BufferedReader(new java.io.InputStreamReader(
					System.in));
		}

		private void init(String name) {
			try {
				br = new java.io.BufferedReader(new java.io.FileReader(name));
			} catch (java.io.FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new java.util.StringTokenizer(br.readLine());
				} catch (java.io.IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}

	}

}
