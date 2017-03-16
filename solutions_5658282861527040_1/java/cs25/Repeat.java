import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Map;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
 
public class Repeat {
 
	public static void main(String[] args) {
 
		BufferedReader br = null;
		BufferedWriter bw = null;

		try {
 
			String sCurrentLine;
				
			File file = new File("out.txt");
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			bw = new BufferedWriter(fw);
 
			br = new BufferedReader(new FileReader("input.txt"));
 
			int T = Integer.valueOf(br.readLine());
			
			for(int t=1;t<=T;t++){
				String line[] = br.readLine().split(" ");
				long A = Integer.valueOf(line[0]);
				long B = Integer.valueOf(line[1]);
				long K = Integer.valueOf(line[2]);
				
				long min = Math.min(A,B);
				
				if(min<=K){
					bw.write("Case #"+t+": "+A*B+"\n");
				}
				else{
					long count=0;
					for(long i=K;i<A;i++){
						for(long j=K;j<B;j++){
							if((i&j)<K)
								count++;
						}
					}
					count+=A*K+K*B-K*K;
					bw.write("Case #"+t+": "+count+"\n");
				}
			}
		
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
				bw.close();
			} catch (Exception ex) {
				ex.printStackTrace();
			}
		}
		
	}
}