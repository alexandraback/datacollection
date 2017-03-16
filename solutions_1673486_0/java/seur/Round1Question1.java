import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Round1Question1 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("./r1q1.in")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0;i < T;i++) {
			String l1 = br.readLine();String l2 = br.readLine();
			doCase(i + 1, l1, l2);
		}
	}
	
	static void doCase(int caseNum, String s1, String s2) {
		String[] ss1 = s1.split(" ");
		String[] ss2 = s2.split(" ");
		int currentC = Integer.parseInt(ss1[0]);
		int maxC = Integer.parseInt(ss1[1]);
		float[] vals = new float[currentC];
		for (int i = 0;i < vals.length;i++) {
			vals[i] = i > 0 ? (vals[i - 1] * Float.parseFloat(ss2[i])) : (Float.parseFloat(ss2[i]));
		}
		float ret = findBest(vals, maxC);
		System.out.println("Case #" + caseNum + ": " + ret);
	}
	
	static float findBest(float[] vals, int total) {
		int keysLeft = total - vals.length;
		int backspace = 0;
		float min = total * 3;
		for (int i = vals.length - 1;i >= 0;i--) { // For each number of backspaces, find the expected!
			float expectedSuccess = vals[i] * (keysLeft + 1);
			float expectedFail = (keysLeft + total + 2) * (1 -vals[i]);
			float totalExp = expectedSuccess + expectedFail + backspace;
			if (totalExp < min)
				min = totalExp;
			backspace = backspace + 2;
		}
		if (total + 2 < min)
			return total + 2;
		else
			return min;
	}
}
