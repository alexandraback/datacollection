import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;


public class CookieClickerAlpha {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		CookieClickerAlpha me =  new CookieClickerAlpha();
		FileReader fr = new FileReader("B-small-attempt0.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("out");
		BufferedWriter bw = new BufferedWriter(fw);
		String result = null;
		
		int T = Integer.valueOf(br.readLine());
		double C = 0;
		double F = 0;
		double X = 0;
		String[] tokens = null;
		
		for(int i=1;i<=T;i++){
		tokens = br.readLine().split(" +");
		C = Double.valueOf(tokens[0]);
		F = Double.valueOf(tokens[1]);
		X = Double.valueOf(tokens[2]);
		
		bw.write("Case #" + i + ": " + me.getResult(C, F, X));
		bw.write('\n');
			
		}//T loop
		
		
		br.close();
		fr.close();
		bw.close();
		fw.close();
	}

	public String getResult(double C, double F, double X){
		
		double cookie = 2;
		double pre_time = X/cookie ;
		double farm_time = 0;
		
		farm_time += C/cookie;
		cookie  += F;
		double time = X/cookie +  farm_time;
		
		while(time<= pre_time){
			pre_time = time;
			farm_time += C/cookie;
			cookie  += F;
			time = X/cookie +  farm_time;
			
		}
		
		return String.valueOf(pre_time);
	}
	
	
	
	
}
