import java.util.*;

public class B {

	public static void main(String[] args) {
		B b = new B();
		b.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int k = in.nextInt();
			int l = in.nextInt();
			int s = in.nextInt();
			in.nextLine();
			String keys = in.nextLine();
			String word = in.nextLine();
			int[] freq = new int[26];
			for (int i=0; i<k; i++) {
				freq[keys.charAt(i)-'A']++;
			}
			boolean poss = true;
			for (int i=0; i<l; i++) {
				if (freq[word.charAt(i)-'A']==0) {
					poss = false;
					break;
				}
			}
			if (!poss) {
				System.out.println("Case #" + (a+1) + ": 0.0");
			}
			else {
				double prob = 1.0;
				for (int i=0; i<l; i++) {
					prob *= ((double) freq[word.charAt(i)-'A'])/((double) k);
				}
				prob *= ((double)(s-l+1));
				int offset = l;
				for (int i=1; i<l; i++) {
					if (word.substring(i).startsWith(word.substring(0,l-i))) {
						offset = i;
						break;
					}
				}
				int count = 1 + (s-l)/offset;
				double ans = ((double) count) - prob;
				System.out.printf("Case #%d: %.6f\n",(a+1),ans);
			}
		}
	}

	// public void run() {
	// 	Scanner in = new Scanner(System.in);
	// 	int cases = Integer.parseInt(in.nextLine());
	// 	for (int a=0; a<cases; a++) {
	// 		int k = in.nextInt();
	// 		int l = in.nextInt();
	// 		int s = in.nextInt();
	// 		in.nextLine();
	// 		String keys = in.nextLine();
	// 		String word = in.nextLine();
	// 		boolean poss = true;
	// 		for (int i=0; i<l; i++) {
	// 			if (!keys.contains(""+word.charAt(i))) {
	// 				poss=false;
	// 				break;
	// 			}
	// 		}
			// if (!poss) {
			// 	System.out.println("Case #" + (a+1) + ": 0.0");
			// }
			// else {
	// 			int offset = l;
				// for (int i=1; i<l; i++) {
				// 	if (word.substring(i).startsWith(word.substring(0,l-i))) {
				// 		offset = i;
				// 		break;
				// 	}
				// }
	// 			ArrayList<String> possible = new ArrayList<>();
	// 			ArrayList<String> possibleNext = new ArrayList<>();
	// 			possible.add("");
	// 			for (int i=0; i<s; i++) {
	// 				for (String str: possible) {
	// 					for (int j=0; j<k; j++) {
	// 						possibleNext.add(str+keys.charAt(j));
	// 					}
	// 				}
	// 				possible = possibleNext;
	// 				possibleNext = new ArrayList<>();
	// 			}
	// 			int sum = 0;
	// 			int max = 1;
	// 			for (String str: possible) {
	// 				int sub = 0;
	// 				int count = 0;
	// 				int index = str.substring(sub).indexOf(word);
	// 				while (index>=0) {
	// 					count++;
	// 					sub += index + offset;
	// 					if (sub>=str.length()) {
	// 						break;
	// 					}
	// 					index = str.substring(sub).indexOf(word);
	// 				}
	// 				max = Math.max(count,max);
	// 				sum += count;
	// 			}
	// 			double ans = ((double) max) - (((double) sum) / ((double) possible.size()));
	// 			System.out.printf("Case #%d: %.6f\n",(a+1),ans);
	// 		}
	// 	}
	// }

}