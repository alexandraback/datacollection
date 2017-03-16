import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


public class MainA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		FileReader ir;
		
		try {
			ir = new FileReader("src/A-large (2).in");
			BufferedReader b = new BufferedReader(ir);
			String s;
			s = b.readLine();
			int num = Integer.valueOf(s);
			
			FileWriter fw = new FileWriter("src/A-answer.txt");
			String answer;
			for(int gameNum = 1; gameNum <= num;gameNum++){
				s = b.readLine();
				String sR = s.substring(0,s.indexOf(' '));
				String sT = s.substring(s.indexOf(' ')+1,s.length());
//				System.out.println(sR);
//				System.out.println(sT);
				BigInteger R = new BigInteger(sR);
				BigInteger T = new BigInteger(sT);
				BigInteger ONE = new BigInteger("1");
				BigInteger TWO = new BigInteger("2");
				BigInteger FOUR = new BigInteger("4");
				BigInteger EIGHT = new BigInteger("8");
				BigInteger nONE = new BigInteger("-1");
				BigInteger N = ONE;
				
				N = (((R.multiply(TWO).subtract(ONE)).multiply(nONE)).
						add(SmallerSquare((R.multiply(TWO).subtract(ONE).pow(2)).add(T.multiply(EIGHT))))).divide(FOUR);
				
				answer = "Case #"+gameNum+": "+N.toString();
				System.out.println(answer);
				fw.write(answer+"\r\n");
				
								
			}

			fw.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static BigInteger SmallerSquare(BigInteger A){
		//square
		boolean isSquareTMP = false;
		BigInteger x = new BigInteger("1");
		BigInteger y = A;
		BigInteger m = x;
		BigInteger ONE = new BigInteger("1");
		BigInteger TWO = new BigInteger("2");
		BigInteger ms;
		while(x.compareTo(y)<=0){
			m = x.add(y);
			m = m.divide(TWO);
			ms = m.pow(2);
			if(ms.equals(A)){
				break;
			}else if(ms.compareTo(A)>0){
				y = m.subtract(ONE);
			}else{
				x = m.add(ONE);
			}
		}
		
		if(m.pow(2).compareTo(A)>0){
			m = m.subtract(ONE);
		}
		
		return m;

	}

}
