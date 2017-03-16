import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;


public class Main5 {
	public static final String fileName = "A-small-attempt0.in";
	

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		PrintWriter pw = new PrintWriter(new File("out.txt"));
		int num = Integer.valueOf(br.readLine());
		for (int i = 0; i < num; i++) {
			String inline = br.readLine();
			String[] tmps = inline.split(" ");
			int n = Integer.valueOf(tmps[0]);
			int total = 0;
			float[] scores = new float[n];
			for(int j = 0; j < n; j++){
				scores[j] = Float.valueOf(tmps[j+1]);
				total += scores[j];
			}
			String result = "";
			float aver = total*2/n;
			float total2 = total*2;
			int n2 = 0;
			
			for(int j = 0; j < n; j++){
				if(aver < scores[j]){
					total2 -= scores[j];
					n2 ++;
				}
			}
			
			for(int j = 0; j < n; j++){
				if(aver < scores[j]){
					result += " " + String.valueOf(0);
				}else{
					float t = (total2/(n - n2) - scores[j])*100/total;
					result += " " + String.valueOf(t);
				}
			}
			
			pw.println("Case #" + (i + 1) + ":" + result);
		}
		pw.close();
	}
}
