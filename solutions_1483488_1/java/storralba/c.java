import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class c {
	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int numOfLines = new Integer(in.nextLine());
		for (int i= 1; i<=numOfLines; i++)
		{
			int res =0;
			String [] lineValues = in.nextLine().split(" ");
			int n = new Integer(lineValues[0]);
			int m = new Integer(lineValues[1]);
			
			for (Integer j = n; j<m; j++)
			{
				String nS=j.toString();
				if (nS.length()<2) continue;
				List<Integer> parellesBones = new ArrayList<Integer>();
				for (int k = nS.length();k>=1;k--)
				{
					String endPart=nS.substring(k);
					String beginPart=nS.substring(0,k);
					Integer recycled = new Integer(endPart+beginPart);
					
					if (recycled >m) continue;
					if (recycled <j) continue;
					if (recycled == j)continue;
					if (parellesBones.indexOf(recycled)!=-1 )continue;
					if (recycled >j) 
					{
						parellesBones.add(recycled);
						res++;
					}
				}
								
			}
			
			System.out.format("Case #%d: %d\n", i, res);
		}
		return;
	}
}