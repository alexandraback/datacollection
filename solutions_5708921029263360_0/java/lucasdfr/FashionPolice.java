import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.stream.Stream;


public class FashionPolice {
	static ArrayList<String> path;
	static void solve(int J, int P, int S, int K){
		int[][] JP = new int[J][P];
		int[][] PS = new int[P][S];
		int[][] JS = new int[J][S];
		path = new ArrayList<String>();
		while(true){
			int min = 100000000;
			int jm = -1, pm = -1, sm = -1;
			for (int j = 0; j < J; j++) {
				for (int p = 0; p < P; p++) {
					for (int s = 0; s < S; s++) {
						String str = ((j+1)+ " "+(p+1)+ " "+(s+1));
						if(!path.contains(str)){
							if(JP[j][p] < K && PS[p][s] < K && JS[j][s] < K ){
								int sum = JP[j][p] + PS[p][s] + JS[j][s];
								if(sum < min) {
									min = sum;
									jm = j;
									pm = p;
									sm = s;
								}
							}
						}
					}
				}
			}
			if (jm == -1 ) break;
			JP[jm][pm] ++;
			PS[pm][sm] ++;
			JS[jm][sm] ++;
			path.add((jm+1)+ " "+(pm+1)+ " "+(sm+1));
		}
	}
	
	public static void main(String[] args) {
		Path pathInput = Paths.get( "src", "input.txt");
		try {
			PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
			Stream<String> input = Files.lines(pathInput, StandardCharsets.UTF_8);
			Iterator<String> it = input.iterator();
			int T = Integer.parseInt(it.next());
			int J, P, S, K;
			for (int i = 1; i < T+1; i++) {
				String[] s = it.next().split(" ");
				J = Integer.parseInt(s[0]);
				P = Integer.parseInt(s[1]);
				S = Integer.parseInt(s[2]);
				K = Integer.parseInt(s[3]);
				solve(J, P, S, K);
				writer.print("Case #"+i+": ");
				writer.println(path.size() + "");
				for (int l = 0; l < path.size(); l++) {
					writer.println(path.get(l));
				}
				
			}
			input.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
