import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;


public class Solution {
	String[] names ;
	int[] n ;
	int T ;	
	static ArrayList<Character> vowels = new ArrayList<Character>(5) ;
	
	public Solution() throws IOException {
		Scanner sc = null;

		PrintWriter out = new PrintWriter(new FileWriter("result.txt")) ;
		try {
			sc = new Scanner(new FileReader("A-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		T = Integer.parseInt(sc.nextLine()) ;
		names = new String[T]  ;
		n = new int[T] ;
		String[] line ;
		int  count = 0 ;
		for(int i = 0 ; i < T ; i ++) {
			count = 0 ;
			line = sc.nextLine().split(" ") ;
			names[i] = line[0] ;
			n[i] = Integer.parseInt(line[1])  ;
			for(int j = 0 ; j < names[i].length() ; j ++) {
				for(int k = (j+1) ; k <= names[i].length() ; k ++) {
					if(isCorrect(names[i].substring(j, k),n[i])) {
						count ++ ;
					}
				}
			}
			out.println("Case #"+(i+1)+": "+count) ;
		}
		out.flush();
		out.close() ;
		sc.close() ;	
	}

	public boolean isCorrect(String s, int n) {
		int count = 0, maxCount = 0 ;
		for(int i = 0 ; i < s.length() ; i++) {
			if(vowels.contains(s.charAt(i))) {
				if(count > maxCount) {
					maxCount = count ;
				}
				count = 0 ;
			}
			else {
				count ++ ;
			}
		}
		if(count > maxCount) {
			maxCount = count ;
		}
		return(maxCount >= n ) ;
	}
	
	public static void main(String[] args){
		vowels.add('e') ;
		vowels.add('a') ;
		vowels.add('i') ;
		vowels.add('o') ;
		vowels.add('u') ;
		try {
			Solution s = new Solution() ;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
