import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Types;


public class Recycled {

	/**
	 * @param args
	 * @throws IOException 
	 */
	
	public static  int calc(int a,int b) {
		int result = 0;
		int[] numbers = new int[b-a+1];
		int ncircle = 0;
		int type=1;
		for (int i = a; i <= b; i++) {
			ncircle = 0;
			
			if(numbers[i-a]==0)
			{
				numbers[i-a]=type;
				ncircle = 1;
				int tmp=1;
				int n=0;
				while (i/tmp!=0) {
					tmp*=10;
					++n;
				}
				--n;
				tmp /= 10;
				int cur =i;
				for (int j = n; j >0; --j) {
					int up = cur/10;
					int down = cur%10;
					cur = down * tmp + up;
					if(down!=0)
					{
						int shifted = cur;
						if((shifted>=a) && (shifted <=b))
						{
							if(numbers[shifted-a]==0)
							{
								
								numbers[shifted-a]=type;
								++ncircle;
							}
							
						}
					}
				}
				
				result += (ncircle)*(ncircle-1)/2;
				++type;
			}else {
				
			}
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bReader  = new BufferedReader(new InputStreamReader(System.in));
		String number = bReader.readLine();
		int num = Integer.parseInt(number);
		for (int i = 0; i < num; i++) {			
			String s = bReader.readLine();
			String[] strs = s.split(" ");
			int A = Integer.parseInt(strs[0]);
			int B = Integer.parseInt(strs[1]);
			System.out.println("Case #"+(i+1)+": "+calc(A, B));
		}

	}

}
