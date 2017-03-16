import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		in = new Scanner(new File("C-small-attempt0.in"));
		
		int T = in.nextInt();
		for (int i=1; i<=T; i++) {
			int N = in.nextInt();
			in.nextLine();
			List<String> first = new ArrayList<String>();
			List<String> second = new ArrayList<String>();
			for (int j=0; j<N; j++) {
				String[] temp = in.nextLine().split(" ");
				first.add(temp[0]);
				second.add(temp[1]);
			}
			int cnt = 0;
			for (int j=0; j<N; j++) {
				String firstWord = first.remove(0);
				String secondWord = second.remove(0);
				
				if (first.contains(firstWord) && second.contains(secondWord)) {
					cnt++;
				}
				
				first.add(firstWord);
				second.add(secondWord);
			}
			
			System.out.printf("Case #%d: %s\n", i, cnt);
		}
	}
}