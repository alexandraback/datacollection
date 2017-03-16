import java.util.*;
import java.math.*;

public class A {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = Integer.parseInt(scanner.nextLine());
	boolean[] list = new boolean[100000];
	for (int nc = 1; nc <= nCase; nc++) {
		String name = scanner.next();
		int nameLen = name.length();
		int n = scanner.nextInt();
		int len = 0;
		Arrays.fill(list,false);
		for (int i = 0; i < nameLen; i++)
			switch(name.charAt(i)) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					list[i] = true;
					len++;
					break;
			}
		long ans = 0;
		for (int i = 0; i < nameLen; i++)
		for (int j = i+n-1; j < nameLen; j++) {
			int maxLen = 0;
			int curLen = 0;
			for (int k = i; k <= j; k++) {
				if (list[k]) {
					maxLen = Math.max(maxLen, curLen);
					curLen = 0;
				} else {
					curLen++;
				}
			}
			maxLen = Math.max(maxLen, curLen);
			if (maxLen >= n)
				ans++;
		}
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}