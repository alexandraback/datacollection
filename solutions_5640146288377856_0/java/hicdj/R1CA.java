import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;


public class R1CA {

	public static int solve(String s){
		
		String[] str = s.trim().split("\\s+");
		int R = Integer.parseInt(str[0]);
		int C = Integer.parseInt(str[1]);
		int W = Integer.parseInt(str[2]);
		
		if(W==1) return R*C;
		if(W==C) return W;
		else if(W<C){			
			return R*getMin(1,C,W);
		}
		
		return 0;
	}
	
	public static int getMin(int s, int e, int w){
		int len = e-s+1;
		if(len==w) return w;
		else if(len<(2*w)) return w+1;
		
		int index = s+w;
		
		int miss = 1 + getMin(index, e, w);
		int hit = 1 + Math.min(w-1,getMin(s+1, s+w-1, w-1));
		
		return Math.max(miss, hit);
	}
	
	public static void main(String[] args) {
		
//		System.err.println(getMin(1, 8, 2));
		
		try {

			FileWriter fw = new FileWriter("data/R1C/A-small-attempt0.out");
			String out = "";

			BufferedReader br = new BufferedReader(new FileReader(
					"data/R1C/A-small-attempt0.in"));
			int count = Integer.parseInt(br.readLine());

			int caseno = 1;
			String str = null;
			while ((str = br.readLine()) != null && caseno <= count) {
				int res = solve(str);
				String output = "Case #" + caseno + ": " + res;
				caseno++;
				System.out.println(output);

				out += output + "\n";
			}

			fw.flush();
			fw.write(out);
			fw.flush();
			fw.close();

			br.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}
