import java.util.*;
import java.io.*;

public class SpeakingInTongues {
	public static char convert(char c) {
		switch(c) {
			case 'y': return 'a';
			case 'n': return 'b';
			case 'f': return 'c';
			case 'i': return 'd';
			case 'c': return 'e';
			case 'w': return 'f';
			case 'l': return 'g';
			case 'b': return 'h';
			case 'k': return 'i';
			case 'u': return 'j';
			case 'o': return 'k';
			case 'm': return 'l';
			case 'x': return 'm';
			case 's': return 'n';
			case 'e': return 'o';
			case 'v': return 'p';
			case 'z': return 'q';
			case 'p': return 'r';
			case 'd': return 's';
			case 'r': return 't';
			case 'j': return 'u';
			case 'g': return 'v';
			case 't': return 'w';
			case 'h': return 'x';
			case 'a': return 'y';
			case 'q': return 'z';
			default:
				return c;
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		for(int caseNo = 1;caseNo <=T; caseNo++) {
			String s = in.nextLine();
			
			System.out.printf("Case #%d: ", caseNo);
			for(int i=0;i<s.length();i++){
				System.out.print(convert(s.charAt(i)));
			}
			System.out.println();
		}
	}
}
