import java.io.*;
import java.util.*;
import java.math.BigInteger;

/*
Problem A. The Last Word
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE
 */

public class r1aa {
	
	
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		// For STDIN, put two stars below.
		// For File In, put one star below.
		/*/
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		/*/
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/sample.in"))));
		/**/
		int n,i,j,k;
		n=sc.nextInt();
		String tt=sc.nextLine();
		for(i=1;i<=n;i++){
			if(i!=1)
				System.out.println();
			System.out.print("Case #"+i+": ");
			String s;
			s=sc.nextLine();

			String ans="";
			ans = ans + s.substring(0,1);
			for(j=1;j<s.length();j++){
				if((int)s.charAt(j)<(int)ans.charAt(0)){
					ans = ans + s.substring(j,j+1);
				}
				else
					ans = s.substring(j,j+1) + ans;
			}
			System.out.print(ans);;
		}
		
	}

}
