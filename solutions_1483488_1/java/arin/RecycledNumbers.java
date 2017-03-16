package qual;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class RecycledPair
{
	int a; 
	int b;
	
	public RecycledPair(int a, int b) {
		super();
		this.a = a;
		this.b = b;
	}

	@Override
	public int hashCode() {
		final int PRIME = 31;
		int result = 1;
		result = PRIME * result + (a + b);
		result = PRIME * result + (a + b);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		final RecycledPair other = (RecycledPair) obj;
		if (a == other.a && b==other.b)
			return true;
		if (a == other.b && b==other.a)
		    return true;
		return false;
	}
	
	
	
}
public class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();

		in.nextLine();

		for (int t = 0; t < T; t++) {
			String s = in.nextLine();
			String[] limit = s.split(" ");
			int A = Integer.parseInt(limit[0]);
			int B = Integer.parseInt(limit[1]);

			Set<RecycledPair> recycledPairsEncountered = new HashSet<RecycledPair>();

			int count = 0;
			for (int i = A; i <= B; i++) 
			{
				char[] num = String.valueOf(i).toCharArray();

				for (int k = num.length - 1; k >= 1; k--) 
				{
					String recycledNumber = "";
					if (num[k] != '0') 
					{
						int indx = k;
						while (indx < num.length)
							recycledNumber += num[indx++];
						indx = 0;
						while (indx < k)
							recycledNumber += num[indx++];
					}

					if (!recycledNumber.equals("")) 
					{
						int recycledNum = Integer.parseInt(recycledNumber);

						if (recycledNum != i
								&& recycledNum <= B
								&& recycledNum >= A)
						{
						     RecycledPair r = new RecycledPair(i, recycledNum);	
						     if(recycledPairsEncountered.contains(r)==false)
						     {
						    	 recycledPairsEncountered.add(r);
						     	 count++;
						     }
						}
					}
				}
			}

			System.out.println("Case #" + (t + 1) + ":" + " " + count);
		}
	}

}
