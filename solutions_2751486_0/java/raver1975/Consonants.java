import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

public class Consonants {
	static FileWriter fstream;
	static BufferedWriter out;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("consonants.txt"));
		fstream = new FileWriter("out.txt");
		out = new BufferedWriter(fstream);
		int T = sc.nextInt();
		sc.nextLine();
		top: for (int t = 0; t < T; t++) {
			String s = sc.nextLine();
			String[] s1 = s.split(" ");
			int n = Integer.parseInt(s1[1]);
			String name = s1[0];

			HashSet<String> hs = new HashSet<String>();
			int count = 0;
			for (int i = n; i < name.length()+1; i++) {
				for (int j = 0; j <=name.length() - i; j++) {
					// System.out.println(i+" "+j);
					String g = name.substring(j, j + i);
//					System.out.println(g + "\t"
//							+check(g));
					if (check(g) >= n) {
						count++;
						
						hs.add(g);
					}
				}
			}
			print(t,Integer.toString(count));
		}

		out.close();
		fstream.close();
	}

	private static int check(String substring) {
		int count = 0;
		int maxcount = 0;
		for (int i = 0; i < substring.length(); i++) {
			char c = substring.charAt(i);
			if (count > maxcount) {
				maxcount = count;
			}
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				count = 0;
			} else {
				count++;
			}
		}
		if (count > maxcount) {
			maxcount = count;
		}
		// System.out.println(substring+" "+count);
		return maxcount;

	}

	public static void print(int cas, String s) {
		s = "Case #" + (cas + 1) + ": " + s;
		System.out.println(s);
		try {
			out.write(s + "\n");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
