import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Energy {
	
	public static String solve(long E, long R, long value[], int N) {
		long before[] = new long[N];
		long after[] = new long[N];
		long work[] = new long[N];
		int order[] = new int[N];
		long total = 0;
		long totalEnergy = 0;
		long temp;
		
		//System.out.println("args : " + E + " " + R + " " + N);
		totalEnergy = E + (N-1)*R;
		System.out.println("total : " +totalEnergy);
		
		long max = 0;
		for (int i = 0; i < N; i++){
			if (max < value[i]){
				max = value[i];
				order[0] = i;
			}
			before[i] = 0;
			after[i] = 0;
			work[i] = 0;
		}
		
		for (int i = 1; i < N; i++){
			max = 0;
			for (int j = 0; j < N; j++){
				if (value[j] > max && value[j] < value[order[i - 1]]){
					max = value[j];
					order[i] = j;
				}
			}
		}
		
		for (int i = 0; i < N; i++){
			//System.out.println("order: "+ order[i]);
		}
		
		for (int i = 0; i < N; i++){
			int pos = order[i];
			int secPos = -1;
			for (int j = 0; j < i; j++){
				if (order[j] < pos && order[j] > secPos){
					secPos = j;
				}
			}
			
			System.out.println("from : " +secPos + "to : " + pos);
			
			if (secPos == -1){
				if (totalEnergy >= E){
					before[pos] = E;
					work[pos] = E;
					after[pos] = 0;
				}
				else{
					before[pos] = totalEnergy;
					work[pos] = totalEnergy;
					after[pos] = 0;
				}
				totalEnergy -= work[pos];
			}
			else if (secPos == pos){
				before[pos] = totalEnergy;
				work[pos] = totalEnergy;
				after[pos] = 0;
				totalEnergy -= work[pos];
			}
			else{
				temp = Math.min((pos - secPos) * R, E);
				if (totalEnergy >= temp){
					before[pos] = temp;
					work[pos] = temp;
					after[pos] = 0;
				}
				else{
					before[pos] = totalEnergy;
					work[pos] = totalEnergy;
					after[pos] = 0;
				}
				totalEnergy -= work[pos];
			}
			System.out.println("E " + totalEnergy);
			
			if (totalEnergy == 0){
				break;
			}
		}
		
		for (int i = 0; i < N; i++){
			System.out.println("Wrok " + work[i]);
			total += work[i] * value[i];
		}
		return total + "";
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		String result = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_E.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			long E;
			long R;
			int N;
			long value[];
			for (int i = 0; i < T; i++) {
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				E = Long.parseLong(tokenizer.nextToken());
				R = Long.parseLong(tokenizer.nextToken());
				N = Integer.parseInt(tokenizer.nextToken());
				value = new long[N];
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				for (int n = 0; n < N; n++){
					value[n] = Long.parseLong(tokenizer.nextToken());
				}
				
				result = solve(E, R, value, N);
				System.out.println(result);
				bw.write(String.format("Case #%d: %s\n", i+1, result));
			}
			
			fileReader.close();
			br.close();
			
			bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
