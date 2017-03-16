import java.io.*;

public class B {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new B().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		for (int n = 1; n <= num; n++) {
			String lines[] = br.readLine().split(" ");
			int h = Integer.parseInt(lines[0]);
			int w = Integer.parseInt(lines[1]);
			int base[][] = new int[h][w];
			for (int i = 0; i < h; i++) {
				lines = br.readLine().split(" ");
				for (int j = 0; j < w; j++) {
					base[i][j] = Integer.parseInt(lines[j]);
				}
			}
			solve(n, h, w, base);
		}
	}

	public void solve(int num, int h, int w, int base[][]) {
		int kijun = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				kijun = base[i][j];
				boolean yokoOk = true;
				for (int k = 0; k < w; k++) {
					if (base[i][k] > kijun) {
						yokoOk = false;
						break;
					}
				}
				boolean tateOk = true;
				for (int k = 0; k < h; k++) {
					if (base[k][j] > kijun) {
						tateOk = false;
						break;
					}
				}
				if (yokoOk || tateOk)
					;
				else {
					System.out.println("Case #" + num + ": NO");
					return;
				}
			}
		}
		System.out.println("Case #" + num + ": YES");
	}
}
