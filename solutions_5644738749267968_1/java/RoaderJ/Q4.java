import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Q4 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file = new File("input.txt");  
		File dest = new File("output.txt");  
		BufferedReader reader = new BufferedReader(new FileReader(file));  
		BufferedWriter writer = new BufferedWriter(new FileWriter(dest));  
		String data = reader.readLine();
		int num = Integer.parseInt(data);
		for (int t = 1; t <= num; t++){
			writer.write("Case #"+t+": ");
			data = reader.readLine();
			int block = Integer.parseInt(data);
			double massN[] = new double[block];
			double massK[] = new double[block];
			boolean choseN[] = new boolean[block];
			boolean choseK[] = new boolean[block];
			init(choseN);
			init(choseK);
			data = reader.readLine();
			String value1[] = data.split(" ");
			data = reader.readLine();
			String value2[] = data.split(" ");
			for (int i = 0; i < block; i++) {
				massN[i] = Double.valueOf(value1[i]).doubleValue();
				massK[i] = Double.valueOf(value2[i]).doubleValue();
			}
			sort(massN);
			sort(massK);
			int Nscore = 0;
			int Kscore = 0;
			for (int i = 0; i < block; i++) {
				boolean win = true;
				for (int j = 0; j < block; j++){
					if ((massK[i] < massN[j]) && (!choseN[j])) {
						Nscore++;
						choseN[j] = true;
						win = false;
						break;
					}
				}
				if (win) {
					Kscore++;
					for (int j = 0; j < block; j++){
						if (!choseN[j]) {
							choseN[j] = true;
							break;
						}
					}
				}
			}
			writer.write(Nscore+" ");
			// opt
			init(choseN);
			init(choseK);
			Nscore = 0;
			Kscore = 0;
			for (int i = 0; i < block; i++) {
				boolean win = true;
				for (int j = 0; j < block; j++){
					if ((massK[j] > massN[i]) && (!choseK[j])) {
						Kscore++;
						win = false;
						choseK[j] = true;
						break;
					}
				}
				if (win) {
					Nscore++;
					for (int j = 0; j < block; j++){
						if (!choseK[j]) {
							choseK[j] = true;
							break;
						}
					}
				}
			}
			writer.write(Nscore+"\n");
		}
		reader.close();
		writer.flush();
		writer.close();
	}

	public static void sort(double a[]) {
		double temp = 0;
		for(int i = a.length - 1; i > 0; i--) {
			for(int j = 0; j < i; j++) {
				if(a[j+1] < a[j]) {
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
	}
	
	public static void init(boolean a[]) {
		for (int i = 0; i < a.length; i++)
			a[i] = false;
	}
}
