import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CoinJam {
	
	
	public static void main(String[] args) throws FileNotFoundException{
//		permutate(0, 6, 0, new ArrayList<String>());
//		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File("src/A-large.in")))));
//	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
//	    int n = in.nextInt();
//	    int j = in.nextInt();
//		List<StringBuffer> res = generateCoinJam(j, n);
		List<StringBuffer> res = generateCoinJam(500, 32);
		StringBuffer out_str = new StringBuffer();
		for (StringBuffer re: res){
//			System.out.println(re);
			out_str.append(re);
			out_str.append("\n");
		}
		System.out.println(out_str);
		
	}
	
	public static List<StringBuffer> generateCoinJam(int j, int n){
		List<StringBuffer> res = new ArrayList<StringBuffer>();
		int count = 0;
		List<String> perm = new ArrayList<>();
		permutate(0, n/2 - 2, 0, perm);
		for (int i = 0; i < j; i ++){
			StringBuffer one_res = new StringBuffer(perm.get(i));
			one_res.insert(0, "1");
			one_res.append("1");
			one_res.append(new StringBuffer(one_res));
			res.add(one_res);
			count ++;
		}
		long[] divisor = new long[9];
		for (int i = 2; i <= 10; i ++){
			divisor[i - 2] =  ((long)Math.pow(i, n / 2) + 1);
		}
		for (StringBuffer re : res){
			for (long div: divisor){
				re.append(" ");
				re.append(div);
				
			}
		}
		return res;
		
	}
	public static void permutate(int start, int end, int cur, List<String> res){
		if (start == end){
			StringBuffer sb = new StringBuffer(Integer.toBinaryString(cur));
			StringBuffer zeroString = null;
			if (sb.length() < end){
				int zeros = end - sb.length();
				zeroString = new StringBuffer();
				for (int i = 0; i < zeros; i++){
					zeroString.append("0");
				}
				sb.insert(0, zeroString);
			}
			res.add(sb.toString());
		} else {
			permutate(start + 1, end, cur, res);
			permutate(start + 1, end, cur | (1 << start), res);
		}
	}
}
