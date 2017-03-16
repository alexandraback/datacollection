import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class SafetyInNumbers {

	static BufferedWriter out;
	
	public static void main(String[] args) throws IOException {
		String inputName = "A-small-attempt1";
		
		FileReader fr = new FileReader(inputName+".in");
		Scanner sc = new Scanner(fr);
		
		FileWriter fstream = new FileWriter(inputName+".out");
		out = new BufferedWriter(fstream);
				
		int T = sc.nextInt();
		for(int t = 0; t < T; t++){
			int N = sc.nextInt();
			if(N == 1){
				print("Case #" + (t+1) + ": " + 0);
				continue;
			}
			int s[] = new int[N];
			int sum = 0;
			for(int n = 0; n < N; n++){
				s[n] = sc.nextInt();
				sum += s[n];
			}
			
			int total = sum*2;
			int m = 0;
			int sum2 = 0;
			for(int n = 0; n < N; n++){
				if(s[n] <= total/N){
					m++;
					sum2 += s[n];
				}
			}
			double need = (double)(sum2+sum)/m;
			//print(m + " " + sum2 + " " + need);
			
			print("Case #" + (t+1) + ":");
			for(int n = 0; n < N; n++){
				if(s[n] > total/N){
					print(" "+0);
				}
				else{
					print(" " +(double)(need-s[n])/sum*100);
				}
			}
			print("\n");
		}

		fr.close();
		out.close();
	}

	public static void print(String s) throws IOException{
		out.write(s);
		//out.newLine();
		System.out.print(s);
	}
}
