import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class StandingOvation {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("D:\\javaspace\\codjam\\A-large.in"));//B-small-practice.in
		int n = in.nextInt();
		PrintWriter out = new PrintWriter("D:\\javaspace\\codjam\\out.txt");
		for(int i=1;i<=n;i++){
			int S = in.nextInt();
			String str = in.next();
			int res = helper(S,str);
			out.println("Case #"+i+": "+res);
		}
		out.close();
		in.close();
	}
	
	private static int helper(int S, String str){
		if(S<=0){
			return 0;
		}
		int res=0;
		int curNum =0;
		for(int i=0;i<=S;i++){
			if(curNum<i&&str.charAt(i)>'0'){
				res+=i-curNum;
				curNum+=i-curNum;
				curNum+=str.charAt(i)-'0';
			}
			else{
				curNum+=str.charAt(i)-'0';
			}
		}
		return res;
	}

}
