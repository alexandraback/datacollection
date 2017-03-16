import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;


public class ReorderingTrainCars {
	
	static int n;
	static String[] s;
	static int c=0;
	public static String gen(boolean[] v, String sol, int pos)
	{
		if (pos == n)
		{
//			System.out.println(isValid(sol)+ " "+sol);
			if(isValid(sol))
				c++;
			return sol;
		}
		for (int i = 0; i < n; i++)
			if (!v[i])
			{
				v[i] = true;
				gen(v, sol+s[i], pos + 1);
				v[i] = false;
			}
		return "";
	}
	
	public static boolean isValid(String str) {
		boolean[] arr=new boolean[27];
		
		arr[str.charAt(0)-'a']=true;
		for(int i=1;i<str.length();i++){
			if(str.charAt(i)!=str.charAt(i-1)){
				if(arr[str.charAt(i)-'a']==true)
					return false;
				else
					arr[str.charAt(i)-'a']=true;
			}
		}
		return true;

	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int nn = Integer.parseInt(br.readLine());
		int t=1;
		while (nn-- > 0) {	
			n = Integer.parseInt(br.readLine());
			c=0;
			s=br.readLine().split(" ");
			
			boolean[] b=new boolean[n];
			gen(b, "", 0);
			

			System.out.println("Case #"+(t++)+": "+c);
			
		}
		
	}


}
