import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class B {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int tests = Integer.parseInt(line);
		for(int i = 1; i <= tests; i++){
			line = br.readLine();
			String[] split = line.split("\\s+");
			double C = Double.parseDouble(split[0]);
			double F = Double.parseDouble(split[1]);
			double X = Double.parseDouble(split[2]);
			double currentProduction = 2.;
			double timePassed = 0.;
			double ans = Double.MAX_VALUE;
			double prevAns = Double.MAX_VALUE;
			while(ans <= prevAns){
				prevAns = ans;
				ans = timePassed + X/currentProduction;
				timePassed += C/currentProduction;
				currentProduction += F;
			}
			ans = prevAns;
			System.out.println("Case #" + i + ": " + ans);
		}
	}
}
