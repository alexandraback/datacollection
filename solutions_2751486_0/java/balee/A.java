import java.io.FileInputStream;
import java.util.Scanner;
import java.util.TreeSet;

public class A {

	private static String process(Scanner in) {
		TreeSet<String> used = new TreeSet<String>();  
		byte[] L = in.next("[^0-9 ]*").getBytes();
		int N = in.nextInt();
		boolean[] start = new boolean[L.length];
		long res = 0;
		for(int i = 0; i < L.length - N + 1; i++) {
			//System.out.println(L.length +  " " + i);
			boolean ok = true;
			for(int j = i; j < i + N; j++) {
				if ( L[j] == 'a' || L[j] == 'e' || L[j] == 'i' || L[j] == 'o' || L[j] == 'u' ) {
					ok = false;
					break;
				}
			}
			if ( ok ) {
				start[i] = true;
				//System.out.println(new String(L, i, N));
				for(int j = 0; j <= i; j++) {
					for(int k = i + N - 1; k < L.length; k++) {
						String key = j + "-" + k;
						//System.out.println(key);
						if ( ! used.contains(key) ) {
							used.add(key);
							res++;
						}
					}
				}
			}
		}
		//System.out.println(L + " - " + N);
		return Long.toString(res);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
