
import java.util.*;

public class Consonants {

//	public static void go(String n ) {
//		
//	}
	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args){
		int N = Integer.parseInt(in.nextLine());
		
		for(int caze = 1; caze<=N ; caze++) {
			String[] line = in.nextLine().split(" ") ;
			
			System.out.printf("Case #%d: %d\n",caze,nvalue(line[0],Integer.parseInt(line[1])));
//			if(caze<N && in.hasNextLine()) 
//				in.nextLine();
		} 
	}
	
	public static boolean check(String s, int i, int j, int n) {
		int curr = 0 ; 
		for(int k=i ; k<=j ; k++) {
			//a, e, i, o, and u
			if(s.charAt(k)!='a' && 
					s.charAt(k)!='e' && 
					s.charAt(k)!='i' &&
					s.charAt(k)!='o' &&
					s.charAt(k)!='u') {
				curr++ ;
//				System.out.printf(" -> counted %s\n",s.charAt(k));
			}
			else {
				curr = 0 ; //vowel
//				System.out.println(" -> reset!");
			}				
			
			if(curr>=n)
				return true ;
		}
		return false ;
	}
	
	public static int nvalue(String s, int n) {
		int nvalue = 0 ;
		
		for(int i=0 ; i<s.length() ; i++) {
			for(int j=i ; j<s.length() ; j++) {
				boolean check = check(s, i, j, n) ; 
				if(check) nvalue++ ;

//				System.out.printf("check %s=%s nvalue=%d\n",s.substring(i, j+1),check,nvalue);
			}
		}
		
		return nvalue;
	}
}

