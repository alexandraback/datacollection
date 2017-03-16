package c;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		
		int nbr = 1;
		while (t-- > 0) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int score = 0;
			
			Set<Integer> set = new HashSet<Integer>();
			
			while (a < b) {
				if (!set.contains(a)){
					String s = a+"";
					Set<Integer> temp = new HashSet<Integer>();
					for (int i = 0; i < s.length(); i++) {
						if (s.charAt(0) != '0'){
							int asdf = Integer.parseInt(s);
							if (a <= asdf && asdf <= b){
								temp.add(asdf);
							}
						}
						s = s.substring(1, s.length()) + s.charAt(0);
					}
					set.addAll(temp);
					int n = temp.size();
					while (n > 1){
						score += --n;
					}
				}
				a++;
			}

			System.out.printf("Case #%d: %d\n", nbr++, score);
		}
	}
}
