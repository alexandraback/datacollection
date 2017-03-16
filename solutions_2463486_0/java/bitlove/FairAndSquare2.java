import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class FairAndSquare2 {
	
	List<List<String>> roots;
	
	public FairAndSquare2(){
		roots = new ArrayList<List<String>>();
		for(int i = 1 ; i <= 51 ; i ++){
			List<String> result = new ArrayList<String>();
			char[] chs = new char[i];
			gen(result , chs , 0 , 0 , i);
			roots.add(result);
		}
	}
	
	private void gen(List<String> result , char[] chs , int sum, int i, int n){
		if(i > (n - 1)/ 2){
			result.add(new String(chs));
			return;
		}
		
		for(char k = '0' ; k <= '3' ; k ++){
			int j = k - '0';
			if((i > 0 || i == 0 && j > 0) && 
			   ((n % 2 == 1 && i == n / 2 && sum + j * j < 10) ||
			   (n % 2 == 1 && i != n / 2 && sum + 2 * j * j < 10) ||
			   (n % 2 == 0 && sum + 2 * j * j < 10))){
				chs[i] = k;
				chs[n - 1 - i] = k;
				if(n % 2 == 1 && i == n / 2)
					gen(result , chs , sum + j * j , i + 1 , n);
				else
					gen(result , chs , sum + 2 * j * j , i + 1 , n);
			}
		}
	}

	public  long count(String A , String B){
		int a = (A.length() + 1) / 2 ;
		int b = (B.length() + 1) / 2;
		int count = 0;
		BigInteger ba = new BigInteger(A);
		BigInteger bb = new BigInteger(B);
		for(int i = a ; i <= b ; i ++){
			
			List<String> root = roots.get(i - 1);
			for(String s : root){
				BigInteger bs = new BigInteger(s);
				BigInteger square = bs.multiply(bs);
				if(square.compareTo(ba) >= 0 && square.compareTo(bb) <= 0){
					count ++;
				}
			}
		}
		return count;
	}
	public static void main(String args[]) throws Exception{
		Scanner in = new Scanner(new FileInputStream("C-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(
				new FileOutputStream("output2.txt"));
		FairAndSquare2 s = new FairAndSquare2();
		
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			String a = in.next();
			String b = in.next();
			long result = s.count(a , b);
			writer.write("Case #" + (i + 1) + ": ");
			writer.println(result);
			System.out.println(result);
		}
		in.close();
		writer.close();
		
	}
}
