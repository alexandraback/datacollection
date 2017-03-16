import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class ReorderingTrainCars {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "B-small-attempt1.in";
		StringBuilder answer = new StringBuilder();
		try {
			FileInputStream fis = new FileInputStream(inputFilename);
			Scanner sc = new Scanner(fis);
			int testCases = sc.nextInt();
			for (int i=1; i<=testCases; i++) {
				int N = sc.nextInt();
				String[] trains = new String[N];
				for (int j=0; j<N; j++) {
					String tmp = sc.next();
					if (tmp.length() == 1)
						trains[j] = tmp+tmp;
					else
						trains[j] = tmp;
				}
				String ans = solve(N, trains);
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
			sc.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}

	private static String solve(int N, String[] trains) {
		Set<Character> middleChars = new HashSet<Character>();
		for (int i=0; i<N; i++) {
			char last = trains[i].charAt(0);
			if (trains[i].length() > 2) {
				for (int c=1; c<trains[i].length()-1; c++) {
					char current = trains[i].charAt(c);
					if (current != last) {
						if (!middleChars.add(new Character(current))) {
							return "0";
						}
						last = current;
					}
				}
			}
		}
		for (int i=0; i<N; i++) {
			char first = trains[i].charAt(0);
			if (middleChars.contains(new Character(first)) &&
					first != trains[i].charAt(1)) {
				return "0";
			}
			char lastc = trains[i].charAt(trains[i].length()-1);
			if (middleChars.contains(new Character(lastc)) &&
					lastc != trains[i].charAt(trains[i].length()-2)) {
				return "0";
			}
		}
		if (N==1) {
			return "1";
		}
		String[] newTrains = new String[N];
		for (int i=0; i<N; i++) {
			char first = trains[i].charAt(0);
			char last = trains[i].charAt(trains[i].length()-1);
			newTrains[i] = first + "" + last;
		}
		long validWays = 0;
		int[] indexes = new int[N];
		for (int i=0; i<N; i++) {
			indexes[i]=i;
		}
		do {
			StringBuilder sb = new StringBuilder();
			for (int i=0; i<N; i++) {
				sb.append(newTrains[indexes[i]]);
			}
			if (isLegal(sb.toString())) {
				validWays++;
			}
		} while (permuteLexically(indexes));

		return ""+(validWays%1000000007);
	}
	
	private static boolean isLegal(String string) {
		
		char curr;
		char last = '!';
		Set<Character> been = new HashSet<Character>();
		for (int i=0; i<string.length(); i++) {
			curr = string.charAt(i);
			if (curr != last) {
				if (been.add(curr)) {
					last = curr;
				} else {
					return false;
				}
			}
		}
		return true;
	}

	private static boolean permuteLexically(int[] data) {
	    int k = data.length - 2;
	    while (data[k] >= data[k + 1]) {
	        k--;
	        if (k < 0) {
	            return false;
	        }
	    }
	    int l = data.length - 1;
	    while (data[k] >= data[l]) {
	        l--;
	    }
	    swap(data, k, l);
	    int length = data.length - (k + 1);
	    for (int i = 0; i < length / 2; i++) {
	        swap(data, k + 1 + i, data.length - i - 1);
	    }
	    return true;
	}
	
	private static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}

	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}

}
