import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class DancingWithTheGooglers {

	public static void main(String[] args) throws IOException {
		
		String inputName = "B-small-attempt0";
		
		FileReader fr = new FileReader(inputName+".in");
		Scanner sc = new Scanner(fr);
		
		FileWriter fstream = new FileWriter(inputName+".out");
		BufferedWriter out = new BufferedWriter(fstream);
				
		int T = sc.nextInt();
		for(int i = 0; i < T; i++){
			int N = sc.nextInt();
			int S = sc.nextInt();
			int p = sc.nextInt();
			int t[] = new int[N];
			for(int j = 0; j < N; j++){
				t[j] = sc.nextInt();
			}
			int ans = 0;
			//System.out.println(N + " " + S + " " + p);
			for(int j = 0; j < N; j++){
				int leftover = t[j] - p;
				//System.out.println(leftover + " " + leftover/2);
				if(leftover < 0){
					continue;
				}
				if(leftover/2 >= p-1){
					ans++;
				}
				else if(S > 0 && leftover/2 >= p-2){
					ans++;
					S--;
				}
			}
			
			out.write("Case #" + (i+1) + ": " + ans);
			out.newLine();
			System.out.println("Case #" + (i+1) + ": " + ans);
		}

		fr.close();
		out.close();
	}
}
