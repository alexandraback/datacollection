import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("D.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("D.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			double[] massNaomi = new double[N];
			double[] massKen = new double[N];
			String[] str = br.readLine().split(" ");
			for (int j = 0; j < N; j++) massNaomi[j] = Double.parseDouble(str[j]); 
			str = br.readLine().split(" ");
			for (int j = 0; j < N; j++) massKen[j] = Double.parseDouble(str[j]); 
			pw.println("Case #"+(i+1)+": "+analyze(N, massNaomi, massKen));
		}

		pw.close();
		br.close();
	}
	
	private static String analyze(int N, double[] massNaomi, double[] massKen) {

		Arrays.sort(massNaomi);
		Arrays.sort(massKen);
		
		int naomiMin = 0, naomiMax = N-1, kenMin = 0, kenMax = N-1;
		int score1 = 0;
		if (massKen[kenMax] == 1.0) { naomiMin++; kenMax--; }
		while (naomiMin <= naomiMax) {
			if (massNaomi[naomiMin] > massKen[kenMin]) { naomiMin++; kenMin++; score1++; }
			else { naomiMin++; kenMax--; }
		}
		
		int naomiPos = 0, kenPos = 0;
		while (kenPos < N) {
			while (kenPos < N && massNaomi[naomiPos] > massKen[kenPos]) kenPos++;
			if (kenPos < N) { naomiPos++; kenPos++; }
		}
		int score2 = kenPos - naomiPos;
		return ""+score1+" "+score2;
		
	}
}
