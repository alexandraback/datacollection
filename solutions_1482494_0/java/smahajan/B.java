import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;


public class B {

	public static void main(String[] args) throws NumberFormatException, IOException {
		File file = new File(args[0]);
		BufferedReader reader = new BufferedReader(new FileReader(file));
		PrintStream printer = new PrintStream(new File("B-small.txt"));

		int T = Integer.parseInt(reader.readLine());
		
		for (int t = 1; t <= T; t++) {
			int n = Integer.valueOf(reader.readLine());
			int[] s1 = new int[n];
			int[] s2 = new int[n];
			for (int i = 0 ; i < n; i++) {
				String line = reader.readLine();
				String numStrArr[] = line.split(" ");
				s1[i] = Integer.parseInt(numStrArr[0]);
				s2[i] = Integer.parseInt(numStrArr[1]);
			}
			int[] l = new int[n];
			int ns = 0;
			int cnt = 0;
			while (true) {
				int mins2 = 10000, mins2pos = n +1;
				int mins1 = 10000, mins1pos = n +1;
				
				for (int i = 0 ; i < n; i++) {
					if (l[i] < 2 && mins2 > s2[i]) {
						mins2 = s2[i];
						mins2pos = i;
					}
					if (l[i] < 1 && mins1 > s1[i]) {
						mins1 = s1[i];
						mins1pos = i;
					}
				}
				
				//System.out.println(mins1 + " !! " + mins1pos);
				//System.out.println(mins2 + " !! " + mins2pos);
				
				if (mins2 <= ns && mins2pos < n) {
					ns+=2-l[mins2pos];
					l[mins2pos] = 2;
					cnt++;
				}
				else if (mins1 <= ns && mins1pos < n) {
					ns+=1-l[mins1pos];
					l[mins1pos] = 1;
					cnt++;
				}
				else {
					cnt=-1;
					break;
				}
				
				boolean solved = true;
				for (int i = 0 ; i < n && solved; i++) {
					if (l[i] < 2) solved = false;
				}
				if (solved)	break;
			}
			printer.println("Case #" + t + ": " + (cnt == -1 ? "Too Bad" : cnt));
		}
	}
	
}
