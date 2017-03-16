import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {

	static boolean check(int no, String str) {
		int a = no;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'a' || str.charAt(i) == 'e'
					|| str.charAt(i) == 'u' || str.charAt(i) == 'o'
					|| str.charAt(i) == 'i')
				a = no;
			else 
				a--;
			
			if (a <= 0)
				return true;
		}
			return false;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		// TODO Auto-generated method stub

		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String[] spl = new String[2];

		int t = Integer.parseInt(r.readLine());
		int test = 1;

		while (t-- > 0) {
			spl = r.readLine().split(" ");

			String str = spl[0];
			int no = Integer.parseInt(spl[1]);

			int count = 0;
			for (int i = 0; i < str.length() - no + 1; i++) {
				for (int j = i + no - 1; j < str.length(); j++) {
					String aa = str.substring(i, j + 1);

					if (check(no, aa)) {
						count++;
					}
				}
			}

			System.out.println("Case #" + test++ + ": " + count);
		}
	}

}
