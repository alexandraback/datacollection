import java.util.*;
import java.io.*;

public class C {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2016/io/C-small-attempt0.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2016/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] s = input.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int J = Integer.parseInt(s[1]);
			String[] strs = new String[J];
			int index = 0;
			
			int start = 1;
			while(start < Math.pow(2, N)){
				String str = Integer.toBinaryString(start);
				if(str.length() == N && str.charAt(0) == '1' && str.charAt(str.length() - 1) == '1'){
					boolean isok = true;
					long[] nums = new long[9];
					for(int j = 2 ; j <= 10 ;j++){
						long n = Long.parseLong(str, j);
						long primen = isPrime(n);
						if(primen == -1){
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
						System.out.println(strs[index]);
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
	
	public static long isPrime(long n){

		if(n % 2 == 0 || n == 1){
			return 2;
		}else{
			for(int i = 3 ; i <= Math.sqrt(n) ; i += 2){
				if(n % i == 0){
					return i;
				}
			}
		}
		return -1;
	}
}
