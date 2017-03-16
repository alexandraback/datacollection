import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class C {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2016/io/input.txt"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2016/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] s = input.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int J = Integer.parseInt(s[1]);
			String[] strs = new String[J];
			int index = 0;
			
			long start = (long)Math.pow(2, N - 1);
			while(start < Math.pow(2, N)){
				String str = Long.toBinaryString(start);
				if(str.length() == N && str.charAt(0) == '1' && str.charAt(str.length() - 1) == '1'){
					boolean isok = true;
					BigInteger[] nums = new BigInteger[9];
					for(int j = 2 ; j <= 10 ;j++){
						BigInteger b = parsing(str, j);
						BigInteger primen = isPrime(b);
						if(primen.equals(new BigInteger("-1"))){
							isok = false;
							break;
						}
						nums[j - 2] = primen;
					}
					if(isok){
						String las = str+" ";
						for(int j = 0 ; j < 9 ; j++){
							if(j != 8){
								las += nums[j]+" ";
							}else{
								las += nums[j];
							}
						}
						strs[index] = las;
						index++;
					}
				}
				if(index == J)break;
				start++;
			}
			
			pw.println("Case #"+(i+1)+":");
			for(int j = 0 ; j < J ; j++){
				pw.println(strs[j]);
			}
		}
		pw.flush();
		input.close();
		pw.close();
	}
	
	public static BigInteger isPrime(BigInteger n){
		if(n.mod(new BigInteger("2")).equals(new BigInteger("0")) || n.equals(new BigInteger("1"))){
			return new BigInteger("2");
		}else{
			BigInteger count = new BigInteger("3");
			while(count.compareTo(new BigInteger("10000000")) <= 0){
				if(n.mod(count).equals(new BigInteger("0")))return count;
				count = count.add(new BigInteger("2"));
			}
		}
		return new BigInteger("-1");
	}
	
	public static BigInteger parsing(String s, int radix){
		BigInteger b = new BigInteger("0");
		if(radix == 10)return new BigInteger(s);
		for(int i = 0 ; i < s.length() ; i++){
			if(s.charAt(i) == '1')b = b.add(new BigInteger(radix+"").pow(s.length() - i - 1));
		}
		return b;
	}

}
