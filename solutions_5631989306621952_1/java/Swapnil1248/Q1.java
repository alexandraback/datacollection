import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int T = Integer.parseInt(br.readLine());
			for (int i = 1; i <= T; i++) {
				String N = (br.readLine());
				System.out.println("Case #" + i + ": " + solve(N));
			}
		} catch (IOException e) {
		}
	}

	private static String solve(String n) {
		char[] arr = n.toCharArray();
		StringBuffer sb = new StringBuffer();
		sb.append(arr[0]);
		int len = arr.length;
		int head = 0;
		for (int i = 1; i < len; i++) {
			if (arr[head] > arr[i]) {
				String s = sb.toString() + arr[i];
				sb = new StringBuffer(s);
			} else {
				head = i;
				String s = arr[i] + sb.toString();
				sb = new StringBuffer(s);
			}
		}
		return sb.toString();
	}

}
