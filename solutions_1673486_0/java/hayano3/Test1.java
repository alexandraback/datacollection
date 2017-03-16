import java.io.*;

public class Test1 {

	final static String INPUT_FILE_NAME = "input1";

	int T = 0;
	char[] beforeString;
	char[] afterString;

	public static void main(String args[]) {
		try {
			Test1 tst = new Test1();
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
			beforeString = new char[105];
			afterString = new char[105];
			String str = br.readLine();
			String[] sepStr = str.split(" ");
			int A = getInt(sepStr[0]);
			int B = getInt(sepStr[1]);

			str = br.readLine();
			String[] sepP = str.split(" ");
			double[] P = new double[sepP.length];
			for (int j=0; j<sepP.length; j++) {
				P[j] = getDouble(sepP[j]);
			}

			double result = execute(A, B, P);

			System.out.println("Case #"+(i+1)+": "+result);
		}
	}

	private double execute(int A, int B, double[] P) {
		double result = 1000000;
		//d = getEnterRightAway();
		double d = B+2;
		if (d < result) {
			result = d;
		}

		d =getKeepTyping(A, B, P, result);
		if (d < result) {
			result = d;
		}

		d = getBackSpace(A, B, P, result);
		if (d < result) {
			result = d;
		}
		return result;
	}

	private double getKeepTyping(int A, int B, double[] P, double min) {
		double trueCollect = 1;
		double d = 1000000;
		for (int i=0; i<P.length; i++) {
			trueCollect = trueCollect * P[i];
			d =  (B-A+1) * trueCollect + (B-A+1+B+1) * (1-trueCollect);
			if (d > min) {
				return 1000000;
			}
		}
		return d;
	}

	private double getBackSpace(int A, int B, double[] P, double min) {
		double trueCollect = 1;
		int backCount = A;
		double backMin = backCount+B+1;
		for (int i=0; i<P.length; i++) {
			trueCollect = trueCollect * P[i];
			backCount--;
			double d = (backCount+B+1-(i+1))*trueCollect + (backCount+B+1-(i+1)+B+1) * (1-trueCollect);
			if (d >backMin) {
				break;
			} else {
				backMin = d;
			}
		}

		return backMin;
	}

	private int getInt(String a) {
		return Integer.parseInt(a, 10);
	}

	private double getDouble(String a) {
		return Double.parseDouble(a);
	}

	private int getIntx(String a) {
		if (a.equals(".")) {
			return 0;
		}
		return 1;
	}

}
