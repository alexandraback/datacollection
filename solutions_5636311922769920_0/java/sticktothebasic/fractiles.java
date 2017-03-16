import java.util.*;
import java.lang.*;
import java.math.*;

public class fractiles
{
	static String indianaJones(int k, int c, long s){
		//Math.ceil(k/c) is # of searches 
		int searchesNeeded = (int)(Math.ceil((double)k/(double)c));
		if (searchesNeeded > s){
			return " IMPOSSIBLE";
		}
		else if (s >= k){
			String ret = "";
			for (int i = 1; i <= s; i++){
				ret += " " + i;
			}
			return ret;
		}
		else {
			String ret = "";
			BigInteger bigK = new BigInteger(Integer.toString(k));
			BigInteger bigC = new BigInteger(Integer.toString(c));
			//Each search will check for c blocks => need Math.ceil(k/c) for-loop
			for (int i = 1; i <= searchesNeeded; i++){
				//This will search 1 .. c, c+1 .. 2c, 2c + 1 .. 3c etc
				BigInteger minSearch = new BigInteger("1");
				BigInteger maxSearch = bigK.pow(c);

				for (int j = (i-1)*c + 1; j <= i*c; j++){
					//This will loop c times
					//We want to divide the [minSearch, maxSearch] into the jth block
					BigInteger blockSize = ((maxSearch.subtract(minSearch)).add(BigInteger.ONE)).divide(bigK);
					BigInteger bigJ = new BigInteger(Integer.toString(j));
					BigInteger bigJm1 = new BigInteger(Integer.toString(j - 1));

					if (j > k){
						minSearch = maxSearch;
						break;
					}

					minSearch = (blockSize.multiply(bigJm1)).add(minSearch); // bs * (j-1) + min
					maxSearch = (minSearch.add(blockSize)).subtract(BigInteger.ONE); //min + block
				}

				//minSearch SHOULD BE maxSearch
				if (minSearch.compareTo(maxSearch) == 0){
					ret += " " + minSearch.toString();
				}
				else {
					ret += " error(" + minSearch.toString() + "," + maxSearch.toString() + ")";
				}
			}

			return ret;
		}
	}

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfTests = in.nextInt();
        for (int i = 0; i < numberOfTests; i++)
        {
        	int k = in.nextInt(); //Length of original tiles
        	int c = in.nextInt(); //Complexity; Starts at 1
        	int s = in.nextInt(); //# of tiles you can check

            System.out.println("Case #" + (i + 1) + ":" + indianaJones(k,c,s));
        }
    }
}