import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;


public class MainA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		FileReader ir;
		
		try {
			ir = new FileReader("src/B-small-attempt3 (1).in");
			BufferedReader b = new BufferedReader(ir);
			String s;
			s = b.readLine();
			int num = Integer.valueOf(s);
			
			FileWriter fw = new FileWriter("src/B-answer.txt");
			String answer;
			String tmp;
			for(int gameNum = 1; gameNum <= num;gameNum++){
				s = b.readLine();
				System.out.println(s);
				String sE = s.substring(0,s.indexOf(' '));
				tmp = s.substring(s.indexOf(' ' )+1);
				String sR = tmp.substring(0,tmp.indexOf(' '));
				tmp = tmp.substring(tmp.indexOf(' ')+1);
				String sN = tmp;
				int n = Integer.valueOf(sN);
				tmp = b.readLine();
				ArrayList<Long> v = new ArrayList<Long>();
				ArrayList<Long> vs = new ArrayList<Long>();
				for(int i = 0; i < n; i++){
					if(tmp.indexOf(' ')>=0){
						v.add(Long.valueOf(tmp.substring(0, tmp.indexOf(' '))));
						vs.add(Long.valueOf(tmp.substring(0, tmp.indexOf(' '))));
						tmp = tmp.substring(tmp.indexOf(' ')+1);
					}else{
						v.add(Long.valueOf(tmp));
						vs.add(Long.valueOf(tmp));
					}
				}
				
				Collections.sort(vs);
				System.out.println(v);
//				System.out.println(vs);

				long E = Long.valueOf(sE);
				long R = Long.valueOf(sR);
				long ene = E;
				long val;
				long gain = 0;
				long gainTemp = 0;
				long list[] = new long[n];
				for(int k = 0; k < n; k++){
					list[k] = 0;
				}

				for(int k = 0; k < Math.pow(E+1, n); k++){
					for(int j = 0; j < n-1;j++){
						if(list[j]> E){
							list[j] = 0;
							if(j < n){
								list[j+1]++;
							}
						}						
					}
//					System.out.print("list: ");
//					for(int i = 0; i < n;i++){
//						System.out.print(list[i]+" ");
//					}
//					System.out.print("\n");
					ene = E;
					gainTemp = 0;
					for(int i = 0; i < n; i++){
						ene -= list[i];
						if(ene <0){
							gainTemp = -1;
//							break;
						}
						gainTemp += list[i]*v.get(i);
						ene += R;
						if(ene > E){
							ene = E;
						}
					}
					
					if(gain < gainTemp){
						gain = gainTemp;
					}
					
					list[0]++;

				}
				
//				for(int j = v.size()-1; j >= 0;j--){
//					val = BigInteger.valueOf(v.get(j));
//					gain = gain.add(val.multiply(ene));
//					if(E.compareTo(R)<0){
//						ene = E;
//					}else{
//						ene = R;
//					}
//				}
//				

//
				answer = "Case #"+gameNum+": "+String.valueOf(gain);
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
