import java.io.*;
import java.util.*;

public class SpeakingInTongue  {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main ( String [] args ) throws IOException
    {
	int N = Integer.parseInt(br.readLine());

	for(int i = 0;i < N; i++) {
	    System.out.print("Case #" + (i+1) + ":");
	    new SpeakingInTongue().cal();

	}
    }



    private void cal() throws IOException 
    {
    	String str = br.readLine();
    	String str2 = " ";
    	for(int i = 0; i < str.length(); i++){
    		str2 += change(str.charAt(i));
    	}
    	
    	System.out.println(str2);
    }
    
    private char change(char ch){
    	switch(ch){
    	case 'a': return 'y';
    	case 'b': return 'h';
    	case 'c': return 'e';
    	case 'd': return 's';
    	case 'e': return 'o';
    	case 'f': return 'c';
    	case 'g': return 'v';
    	case 'h': return 'x';
    	case 'i': return 'd';
    	case 'j': return 'u';
    	case 'k': return 'i';
    	case 'l': return 'g';
    	case 'm': return 'l';
    	case 'n': return 'b';
    	case 'o': return 'k';
    	case 'p': return 'r';
    	case 'q': return 'z';
    	case 'r': return 't';
    	case 's': return 'n';
    	case 't': return 'w';
    	case 'u': return 'j';
    	case 'v': return 'p';
    	case 'w': return 'f';
    	case 'x': return 'm';
    	case 'y': return 'a';
    	case 'z': return 'q';
    	case ' ': return ' ';
    	}
    	return ch;
    	
    	
    	
    }

}


