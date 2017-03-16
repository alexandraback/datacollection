import java.io.*;
import java.util.*;

public class SpeakingInTongues {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static StringTokenizer st;

    public static void main ( String [] args ) throws IOException
    {
	int T = Integer.parseInt(br.readLine());

	for(int i = 0;i < T; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new SpeakingInTongues().cal();
	}
    }

 
    private void cal() throws IOException 
    {
	char [] g = br.readLine().toCharArray();

	for( char c : g )
	    System.out.print(translate(c));
	System.out.println("");
    }

    private char translate(char c) {
	switch(c) {
	case 'a' : return 'y';
	case 'b' : return 'h';
	case 'c' : return 'e';
	case 'd' : return 's';
	case 'e' : return 'o';
	case 'f' : return 'c';
	case 'g' : return 'v';
	case 'h' : return 'x';
	case 'i' : return 'd';
	case 'j' : return 'u';
	case 'k' : return 'i';
	case 'l' : return 'g';
	case 'm' : return 'l';
	case 'n' : return 'b';
	case 'o' : return 'k';
	case 'p' : return 'r';
	case 'q' : return 'z';
	case 'r' : return 't';
	case 's' : return 'n';
	case 't' : return 'w';
	case 'u' : return 'j';
	case 'v' : return 'p';
	case 'w' : return 'f';
	case 'x' : return 'm';
	case 'y' : return 'a';
	case 'z' : return 'q';
	}
	return c;
    }

}
