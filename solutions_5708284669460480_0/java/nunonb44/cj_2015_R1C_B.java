
import java.util.ArrayList;
import java.util.Scanner;

public class cj_2015_R1C_B {
	
	private static ArrayList<String> permutacoes;

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		int n = read.nextInt();
		for (int i = 1; i <= n; i++) {
			int k = read.nextInt();
			int l = read.nextInt();
			int s = read.nextInt();
			read.nextLine();
			String a = read.nextLine();
			String b = read.nextLine();
			if (l > s) {
				System.out.printf("Case #%d: %d\n", i, 0);
			}
			else {
				permutacoes = new ArrayList<String>();
				prePermutacao(a, s);
				//for (String str : permutacoes)
					//System.out.println(s);
				int max = 0;
				double count = 0;
				for (String str : permutacoes) {
					int countMax = 0;
					int j = -1;
					while ((j = str.indexOf(b, j + 1)) != -1) {
						count++;
						countMax++;
					}
					if (countMax > max)
						max = countMax;
				}
				System.out.printf("Case #%d: ", i);
				System.out.println(max - count / permutacoes.size());
			}
		}
		read.close();
	}
	
	private static void prePermutacao(String st, int z) {
		StringBuilder s = new StringBuilder();
		s.append(st);
		StringBuilder f = new StringBuilder();
		permutacao(s, f, z);
	}
	
	private static void permutacao(StringBuilder s, StringBuilder f, int z) {
		int n = s.length();
		if (f.toString().length() == z)
			permutacoes.add(f.toString());
		else
			for (int i = 0; i < n; i++) {
				StringBuilder f1 = new StringBuilder();
				f1.append(f);
				f1.append(s.charAt(i));
				StringBuilder s1 = new StringBuilder();
				s1.append(s);
				permutacao(s1, f1, z);
			}
	}
}
