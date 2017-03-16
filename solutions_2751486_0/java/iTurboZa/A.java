import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class A {
	
	
	public static int query(String s, int n){
		
		int i, cnt=0, length=s.length();
		for(i=0;i<length;i++){
			if(s.charAt(i)=='c'){
				cnt++;
				if(cnt==n){
					break;
				}
			}
			else
				cnt=0;
		}
		
		if(i==length) return 0;
		
		return s.substring(i).length();
	}
	
	public static int getNValue(String s, int n){
		
		int sum=0;
		for(int i=0;i<s.length();i++){
			sum+=query(s.substring(i),n);
//			System.out.println(s.substring(i)+"..."+s.substring(i).length());
		}
		
		return sum;
	}
	

	private static String convertCV(String s) {
		
		String converted = "";
		s = s.toLowerCase();
		for(int i=0;i<s.length();i++){
			char c = s.charAt(i);
			if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
				converted += "v";
			else
				converted += "c";
		}
			
		return converted;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		
		String name = "A-small-attempt0 (2)";
		Scanner sc = new Scanner(new File(name+".in"));
		PrintStream ps = new PrintStream(new File(name+".out"));
		
		int nCase = sc.nextInt();
		
		for(int x=1;x<=nCase;x++){
			String s = sc.next();
			int n = sc.nextInt();
			
			int result = getNValue(convertCV(s),n);
			System.out.println("Case #"+x+": "+result);
			ps.println("Case #"+x+": "+result);
		}
		
	}


}
