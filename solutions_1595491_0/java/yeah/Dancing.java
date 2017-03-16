import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Dancing {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bReader  = new BufferedReader(new InputStreamReader(System.in));
		String number = bReader.readLine();
		int num = Integer.parseInt(number);
		for (int i = 0; i < num; i++) {			
			String s = bReader.readLine();
			String[] strs = s.split(" ");
			int N = Integer.parseInt(strs[0]);
			int S = Integer.parseInt(strs[1]);
			int P = Integer.parseInt(strs[2]);
			int s1 = P + 2*Math.max(0, P-1);
			int s2 = P + 2*Math.max(0, P-2);
			int result = 0;
			for (int j = 0; j < N; j++) {
				int tmp = Integer.parseInt(strs[3+j]);
				if(tmp>=s1)
				{
					++result;
				}else if(tmp>=s2 && S>0)
				{
					--S;
					++result;
				}
			}
			System.out.println("Case #"+(i+1)+": "+result);
		}
	}

}
