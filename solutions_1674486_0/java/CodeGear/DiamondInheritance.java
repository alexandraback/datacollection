import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class DiamondInheritance {
	static String[][] s;
	static int[] dest;
	
	static void getDest(int i, int[] dest) {
		int numClass = Integer.parseInt(s[i][0]);
//		System.out.println(numClass);
		for(int j = 0; j < numClass; j++) {
//			System.out.println(i + "," + j);
			dest[Integer.parseInt(s[i][j+1])-1]++;
			getDest(Integer.parseInt(s[i][j+1])-1, dest);
		}
	}
	
	static String isDiamondInheritance(BufferedReader br) throws NumberFormatException, IOException {
		int N = Integer.parseInt(br.readLine());
		s = new String[N][];
		for(int i = 0; i < N; i++) {
			s[i] = br.readLine().split(" ");
//			for(int j = 0; j < s[i].length; j++)
//				System.out.println(s[i][j]);
//			System.out.println();
		}
		for(int i = 0; i < N; i++) {
			int numClass = Integer.parseInt(s[i][0]);
			if(numClass > 1) {
				dest = new int[N];
				getDest(i, dest);
				for(int j = 0; j < N; j++) {
					if(dest[j] > 1) {
						return "Yes";
					}
				}
			}
		}
		return "No";
	}

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/A-small-attempt1.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("src/R1C-A-small.out"));
        int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			bw.write("Case #" + (i+1) + ": " +
					isDiamondInheritance(br));
			bw.newLine();
		}
        bw.flush();
        bw.close();
        br.close();
	}
}
