import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Bullseye {

	static int T;
	static BigInteger TWO = new BigInteger("2");
	static BigInteger ONE = new BigInteger("1");
	static BigInteger FOUR = new BigInteger("4");
	static BigInteger EIGHT = new BigInteger("8");
	static BigInteger ONE_NEG = new BigInteger("-1");
	static BigInteger term, term2, bigR, bigT;
	static long r, t;
	
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new FileReader("A.in"));
		T = Integer.parseInt(reader.readLine());
		StringTokenizer st;
		StringBuffer buf = new StringBuffer();
		for (int i = 1; i <= T; i++) {
			st = new StringTokenizer(reader.readLine());
			r = Long.parseLong(st.nextToken());
			t = Long.parseLong(st.nextToken());
			buf.append("Case #"+i+": "+solve()+"\n");
		}
		System.setOut(new PrintStream("A.out"));
		System.out.print(buf);
	}
	
	static String solve(){
		bigR = new BigInteger(r+"");
		bigT = new BigInteger(t+"");
		term = bigR.multiply(TWO).subtract(ONE).pow(2);
		term = term.add(EIGHT.multiply(bigT));
		term = bigsqrt(term.toString());
		term2 = term.subtract(bigR.multiply(TWO).subtract(ONE)).divide(FOUR);
		return term2.toString();
	}
	
	static BigInteger bigsqrt(String n){
        BigInteger root = BigInteger.ZERO;
        BigInteger res = BigInteger.ZERO;
        BigInteger HUNDRED = new BigInteger("100");
        BigInteger TEN = new BigInteger("10");
        BigInteger []DIGITS = new BigInteger[10];
        for (int i = 0; i < DIGITS.length; i++) 
            DIGITS[i]= new BigInteger(""+i);
        ArrayList<String> parts= new ArrayList<String>();
        for (int i = n.length(); i >0; i-=2) 
            parts.add(n.substring(Math.max(i-2,0),i));        
        for (int i = parts.size()-1; i >= 0; i--) {
            res=res.multiply(HUNDRED).add(new BigInteger(parts.get(i)));
            for (int j = 9; j>=0 ; j--) {
                BigInteger temp=root.multiply(DIGITS[2]).multiply(TEN).add(DIGITS[j]).multiply(DIGITS[j]);
                if(temp.compareTo(res)>0) continue;
                root=root.multiply(TEN).add(DIGITS[j]);
                res=res.subtract(temp);
                break;
            }
        }
        return root;
    }
}
