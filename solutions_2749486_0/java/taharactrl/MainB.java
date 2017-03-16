import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


public class MainB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
	FileReader ir;
		
		try {
			ir = new FileReader("src/B-small-attempt1.in");
			BufferedReader b = new BufferedReader(ir);
			String s;
			s = b.readLine();
			int num = Integer.valueOf(s);
			
			FileWriter fw = new FileWriter("src/B-answer.txt");
			String answer;
			String tmp;
			int MAX_DEPTH = 500;
			for(int gameNum = 1; gameNum <= num;gameNum++){

				s = b.readLine();
				String sX = s.substring(0,s.indexOf(' '));
				String sY = s.substring(s.indexOf(' ')+1);
				int X = Integer.valueOf(sX);
				int Y = Integer.valueOf(sY);
				int[] ansSet = new int[abs(X)*2+abs(Y)*2];
				for(int i = 0; i < ansSet.length/2;i++){
					if(i < abs(X)){
						if(X>0){
							ansSet[2*i] = 2;
							ansSet[2*i+1] = 3;
						}else{
							ansSet[2*i] = 3;
							ansSet[2*i+1] = 2;
						}
					}else{
						if(Y>0){
							ansSet[2*i] = 1;
							ansSet[2*i+1] = 0;
						}else{
							ansSet[2*i] = 0;
							ansSet[2*i+1] = 1;
						}
						
					}
				}
				
				answer = "Case #"+gameNum+": ";
				for(int k = 0; k < ansSet.length; k++){
					if(ansSet[k] == 0){//N
						answer += "N";
					}else if(ansSet[k] == 1){//S
						answer += "S";
					}else if(ansSet[k] == 2){//W
						answer += "W";
					}else if(ansSet[k] == 3){//E
						answer += "E";
					}					
				}
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
