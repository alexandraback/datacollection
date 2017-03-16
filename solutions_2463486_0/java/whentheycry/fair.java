import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.ArrayList;


public class fair {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		try {
			BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			ArrayList<String> result = new ArrayList<String>();
		
			int cases = Integer.parseInt(br.readLine());
			for (int k = 0; k<cases;k++){
				String se = br.readLine();
				int cn = k+1;
				BigInteger s = new BigInteger(se.split(" ")[0]);
				BigInteger e = new BigInteger(se.split(" ")[1]);
				BigInteger q = s;
				int count = 0;
				while (q.compareTo(e.add(BigInteger.ONE)) == -1){
					System.out.println("q: "+q.toString());
					BigInteger[] sq = sqrt(q);
					if (isfair(q) && isfair(sq[0]))
						count ++;
					if (sq[0].equals(BigInteger.ZERO))
						q = sq[1].pow(2);
					else
						q = q.add(BigInteger.ONE);
				}
				result.add("Case #" +cn +": " + count);
				
			}

			
			for (int i = 0;i<result.size();i++){
				out.write(result.get(i)+"\n");
			}
			br.close();
			out.close();
			}catch (Exception e) {
		        System.err.println("Error:" + e.getMessage());
		        e.printStackTrace();
		    }
	}
	
	static boolean isfair(BigInteger n){
		if (n.equals(BigInteger.ZERO))
			return false;
		String s = String.valueOf(n);
	    String rs = new StringBuffer(s).reverse().toString();
	    if (s.equals(rs))
	    	return true;
	    else
	    	return false;
		
		
	}
	
	static BigInteger[] sqrt(BigInteger n) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		  BigInteger[] res = new BigInteger[2];
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  a = a.subtract(BigInteger.ONE);
		  if (a.pow(2).equals(n)){
			  res[0] = a;
			  res[1] = BigInteger.ZERO;
			  return res;
		  }
		  else{
			  res[0] = BigInteger.ZERO;
			  res[1] = a.add(BigInteger.ONE);
			  return res;
		  }
		}

}
