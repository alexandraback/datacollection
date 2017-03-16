import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	
	public void run() {
		int ntst = nextInt();
		int wordsCnt = 521196;
		String[] arr = new String[wordsCnt];
		int[] poses = new int[26];
		Arrays.fill(poses, -1);
		try {
		BufferedReader wr = new BufferedReader(new FileReader(new File("D:\\garbled_email_dictionary.txt")));
		for (int i = 0; i < wordsCnt; ++i) {
			arr[i] = wr.readLine();
			if (poses[(int)(arr[i].charAt(0) - 'a')] == -1) {
				poses[(int)(arr[i].charAt(0) - 'a')] = i;
			}
		}
		}
		catch (IOException e) {
			
		}
		
		for (int tst = 0; tst < ntst; ++tst) {
			char[] s = nextWord().toCharArray();
			int n = s.length;
			int[][] cnt = new int[n+1][6];
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j < 6; ++j) {
					cnt[i][j] = -1;
				}
			}
			cnt[0][0] = 0;
			
			int[] errors = new int[10000];
			int errPos = 0;
			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= 5; ++j) {
					if (cnt[i][j] >= 0) {
						int start = 0;
						int end = wordsCnt;
						
						if (j != 0) {
							start = poses[(int)(s[i] - 'a')];
							if (s[i] != 'z') {
								end = poses[(int)(s[i] - 'a') + 1];
							}
							
							if (start == -1) {
								start = 0;
								end = wordsCnt;
							}
						}
						
						for (int k = start; k < end; ++k) {
							if (i + arr[k].length() > s.length) {
								continue;
							}
							int errCnt = 0;
							errPos = 0;
							boolean ok = true;
							for (int l = 0; l < arr[k].length(); ++l) {
								if (s[i+l] != arr[k].charAt(l)) {
									errors[errPos] = l;
									++errPos;
								}
							}
							errCnt = errPos;
							
							if (errPos != 0 && j != 0 && 5 - errors[0] > j) {
								ok = false;
							}
							
							for (int l = 1; l < errPos; ++l) {
								if (errors[l] - errors[l-1] < 5) {
									ok = false;
									break;
								}
							}
							
							if (ok) {
								int idx = 0;
								if (errPos != 0) {
									idx = arr[k].length() - errors[errPos - 1];
								}
								if (errPos == 0 && j != 0) {
									idx = j + arr[k].length();
								}
								else if (errPos == 0 && j == 0) {
									idx = 0;
								}
								if (idx > 5) {
									idx = 0;
								}
								
								if (cnt[i + arr[k].length()][idx] == -1 ||
										cnt[i + arr[k].length()][idx] > cnt[i][j] + errCnt) {
									cnt[i + arr[k].length()][idx] = cnt[i][j] + errCnt;
								}
							}
						}
					}
				}
			}
			
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i <= 5; ++i) {
				if (cnt[n][i] != -1 && cnt[n][i] < ans) {
					ans = cnt[n][i];
				}
			}
			out.println("Case #"+(tst+1)+": "+ans);
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\C.txt")));
		out = new PrintWriter("D:\\CC.txt");
		(new Thread(new C())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}
