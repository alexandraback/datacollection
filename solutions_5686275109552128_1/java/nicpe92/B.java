import java.io.BufferedReader;
import java.io.InputStreamReader;


public class B {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int cas = 1; cas <=T; cas++) {
			int D = Integer.parseInt(in.readLine());
			String[] spl = in.readLine().split(" ");
			int[] vals = new int[D];
			for (int i = 0; i < vals.length; i++) {
				vals[i] = Integer.parseInt(spl[i]);
			}
			int min = Integer.MAX_VALUE;
			for (int i = 1; i <=1000; i++) {
				int numT = i;
				for (int j = 0; j < vals.length; j++) {
					int curV = vals[j] - i;
					if(curV <=0) continue;
					numT += curV/i;
					if(curV%i!=0)
						numT++;
				}
				min = Math.min(min, numT);
			}
			System.out.println("Case #"+cas+": "+min);
		}
	}

}
