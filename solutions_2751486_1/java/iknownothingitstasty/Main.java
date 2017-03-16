import java.io.*;
import java.util.*;
public class  Main
{
	public static void main(String[] args) throws FileNotFoundException 
	{
	    FileInputStream psi = null;
	    PrintStream pso = null;
	    Scanner sc = null;
	    int num = 0;
	    byte[][] mtx = new byte[4][4];
	    psi = new FileInputStream("D:\\Users\\Rophyll\\Downloads\\A-large.in");
		pso = new PrintStream(new FileOutputStream("D:\\Users\\Rophyll\\Downloads\\out1.out"));
		System.setIn(psi);
		System.setOut(pso);
		sc = new Scanner(System.in);
		
		num = sc.nextInt();
		for(int i = 0; i < num; i++){//each case
			String sample = sc.next();
			int n = sc.nextInt();
			int[][] sub = new int[sample.length()][sample.length()];
					
			System.out.println("Case #"+(i+1)+": " + calc(sub, sample, n));
		}
	}

	private static long calc(int[][] sub, String sample, int n) {
		// TODO Auto-generated method stub
		for(int i = 0; i < sample.length(); i++){
			if(sample.charAt(i) == 'a' || sample.charAt(i) == 'i' || sample.charAt(i) == 'u' || sample.charAt(i) == 'e' || sample.charAt(i) == 'o'){
				sub[i][i] = 0;
			}else{
				sub[i][i] = -1;
			}
		}
		for(int i = 0; i < sample.length(); i++){
			for(int j = 0; j < i; j++){
				if(sub[j][i-1] == 1)
					sub[j][i] = 1;
				else if(sample.charAt(i) == 'a' || sample.charAt(i) == 'i' || sample.charAt(i) == 'u' || sample.charAt(i) == 'e' || sample.charAt(i) == 'o'){
					sub[j][i] = 0;
				}else{
					sub[j][i] = sub[j][i-1]-1;
				}
				if(sub[j][i] <= 0-n)
					sub[j][i] = 1;
			}
			if(sub[i][i] <= 0-n)
				sub[i][i] = 1;
		}
		long count = 0;
		for(int i = 0; i < sample.length(); i++){
			for(int j = 0; j <= i; j++)
				if(sub[j][i] == 1)
					count++;
		}
		return count;
	}
}