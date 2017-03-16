import java.io.*;

public class Test2 {

	final static String INPUT_FILE_NAME = "input2";

	int T = 0;
	int q = 0;

	public static void main(String args[]) {
		try {
			Test2 tst = new Test2();
			tst.getInput();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void getInput() throws Exception {
		File file = new File(INPUT_FILE_NAME);
		FileReader fis = new FileReader(file);
		BufferedReader br = new BufferedReader(fis);
		String strT = br.readLine();
		T = getInt(strT);

		for (int i=0; i<T; i++) {
			String strHead = br.readLine();
			int N = getInt(strHead);

			int[] a = new int[N];
			int[] b = new int[N];
			for (int j=0; j<N; j++) {
				String str = br.readLine();
				String[] strHairetsu = str.split(" ");
				a[j] = getInt(strHairetsu[0]);
				b[j] = getInt(strHairetsu[1]);
			}

			//list kakunou
			execuse(i, N, a, b);
		}
	}

	private void execuse(int num, int N, int[] a, int[] b) {

		boolean[] aTrue = new boolean[N];
		boolean[] bTrue = new boolean[N];
		for (int i=0;i<N;i++) {
			aTrue[i]=false;
			bTrue[i]=false;
		}
		int stars = 0;
		int count = 0;

		boolean endFlgA = true;
		boolean endFlgB = true;


		while (endFlgA || endFlgB) {
			endFlgA = true;
			endFlgB = true;

			int bMinNumber = getMinNumber(b, stars);
			if (bMinNumber < 10000) {
				bTrue[bMinNumber] = true;
				b[bMinNumber] = 10000;
				count++;
				if (aTrue[bMinNumber]) {
					stars += 1;
				} else {
					stars += 2;
				}
				if (checkTrue(bTrue)) {
					System.out.println("Case #"+(num+1)+": "+count);
					return;
				}
			} else {
				endFlgB = false;
				int aMinNumber = getMinNumber(a, stars);
				if (aMinNumber < 10000) {
					aTrue[aMinNumber] = true;
					a[aMinNumber] = 10000;
					count++;
					if (!bTrue[aMinNumber]) {
						stars += 1;
					} else {
						count--;
					}
				} else {
					endFlgA = false;
				}
			}
		}

		System.out.println("Case #"+(num+1)+": Too Bad");
		//System.out.println("Hello WorldI");
	}

	private boolean checkTrue(boolean[] bTrue) {
		for (int i=0;i<bTrue.length;i++) {
			if (!bTrue[i]) {
				return false;
			}
		}
		return true;
	}

	private int getMinNumber(int[] b, int stars) {
		int min =10000;
		int count = 10000;

		for (int i=0;i<b.length;i++) {
			if (min > b[i]) {
				min = b[i];
				count = i;
				if (stars >= min) {
					break;
				}
			}
		}

		if (count >= 10000) {
			return 10000;
		}

		if (b[count] > stars) {
			return 10000;
		}

		return count;
	}


	private int getInt(String a) {
		return Integer.parseInt(a, 10);
	}

	private int getIntx(String a) {
		if (a.equals(".")) {
			return 0;
		}
		return 1;
	}

}
