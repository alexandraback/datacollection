import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.HashSet;

public class Contest {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("test.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

		DecimalFormat df = new DecimalFormat();
		df.setMaximumFractionDigits(6);
		df.setMinimumFractionDigits(6);
		String line = "";
		line = br.readLine();
		int number = Integer.valueOf(line);
		for(int i = 1; i<= number; i++){
			line = br.readLine();
			String[] tokens = line.split(" ");
			int a = Integer.valueOf(tokens[0]);
			int sum = 0;
			int[] b = new int[a];
			double[] result = new double[a];
			for(int n = 1; n<=a; n++){
				b[n-1] = Integer.valueOf(tokens[n]);
				sum += b[n-1];
			}
			int total = 2*sum;
			int flag = 1;
			while(flag == 1){
				flag = 0;
				int ai = 0;
				for(int n =0; n<a; n++){
					if(b[n]>= 0)
						ai++;
				}
				System.out.println(ai);
				for(int n = 0; n< a; n++){
					double temp =(double) total/ai-b[n];

					System.out.println(n+":"+temp);
					if(temp <= 0){
						flag = 1;
						total-=b[n];
						b[n] = -1;
						temp = 0;
					}
					if(b[n] != -1)
						result[n] = (double) 100*temp/sum;					
				}
			}
			
			bw.append("Case #"+i+": ");
			for(int n = 0; n <a; n++){
				bw.append(df.format(result[n])+" ");
			}
			bw.newLine();
		}
		br.close();
		bw.close();

		System.out.println("finished");
	}
}
