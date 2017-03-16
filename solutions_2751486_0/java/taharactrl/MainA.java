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
			ir = new FileReader("src/A-small-attempt1 (1).in");
			BufferedReader b = new BufferedReader(ir);
			String s;
			s = b.readLine();
			int num = Integer.valueOf(s);
			
			FileWriter fw = new FileWriter("src/A-answer.txt");
			String answer;
			String tmp;
			for(int gameNum = 1; gameNum <= num;gameNum++){
				s = b.readLine();
				String S = s.substring(0,s.indexOf(' '));
				int L = S.length();
				String sn = s.substring(s.indexOf(' ')+1);
				int n = Integer.valueOf(sn);
				
				long cnt = 0;
				for(int i = 0; i < L - n+1; i++){
					for(int j = L; j > i; j--){
						String sub = S.substring(i,j);
//						System.out.println(sub);
						int cntC = 0;
						for(int k = 0; k < sub.length();k++){
							if(!isVowel(sub.charAt(k))){
								cntC++;
							}else{
								cntC=0;
							}
							
							if(cntC >= n){
								cnt++;
								break;
							}
						}
						
						
					}
//					String sub = S.substring(i, i+n);
//					boolean ok = true;
//					for(int j = 0; j < sub.length();j++){
//						if(isVowel(sub.charAt(j))){
//							ok = false;
//							break;
//						}
//					}
//					
//					if(ok){
//						System.out.println(sub);
//						int cntA = L - (i+n-1);
//						cnt += L - (i+n-1);
//						if(i > 0){
//							if(isVowel(S.charAt(i-1))){
//								
//								for(int i1 = i-1; i1 >= 0; i1--){
//									int cntC=0;
//									for(int k = i1; k >=0 && k >i1 - n; k--){
//										if(!isVowel(S.charAt(k))){
//											cntC++;
//										}
//									}
//									if(cntC < n){
//										cnt += cntA;
//									}
//								}
//							}
//						}
//						
//					}
					
				}
				
				
				answer = "Case #"+gameNum+": "+cnt;
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

	public static boolean isVowel(char x){
		if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
			return true;
		}else{
			return false;
		}
		
	}
	
    public static BigInteger CeilSquare(BigInteger A){
        //square
        BigInteger x = new BigInteger("1");
        BigInteger y = A;
        BigInteger m = x;
        BigInteger ONE = new BigInteger("1");
        BigInteger TWO = new BigInteger("2");
        BigInteger ms;
        while(x.compareTo(y)<=0){
                m = x.add(y);
                m = m.divide(TWO);
//              System.out.println(m.toString());
                ms = m.pow(2);
                if(ms.equals(A)){
                        break;
                }else if(ms.compareTo(A)>0){
                        y = m.subtract(ONE);
                }else{
                        x = m.add(ONE);
                }
        }

        if(m.pow(2).compareTo(A)<0){
                m = m.add(ONE);
        }

        return m;

    }
	
	public static BigInteger FloorSquare(BigInteger A){
		//square
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

	public static int[] generateNumberTree(int depth, int unitWidth, int num){
		int[] x = new int[depth];
		int tmp = num;
		for(int i = 0; i < depth; i++){
			x[i] = tmp%unitWidth;
			tmp = tmp/unitWidth;
		}
		
		return x;
	}
	
    public static long min (long[] x, long MIN){
        long y = MIN;
        for(int i = 0; i < x.length;i++){
        	if(x[i]>MIN){
        		y = x[i];
        	}
        }
        for(int i = 0; i < x.length;i++){
                if(y>x[i] && x[i]>MIN){
                        y = x[i];
                }
        }

        return y;
    }

    public static long max (long[] x,long MIN){
        long y = x[0];
        for(int i = 0; i < x.length;i++){
                if(y<x[i]){
                        y = x[i];
                }
        }

        return (y >= MIN)? y:null;
    }

	public static int abs(int x){
		if(x < 0){
			return -x;
		}else{
			return x;
		}
	}
	
	public static int cmb(int n, int m){
		int p = 1;
		for(int i = n; i > n-m;i-- ){
			p = p*i;
		}
		for(int i = 1; i <=m;i++ ){
			p = p/i;
		}
		return p;
	}
	
}
