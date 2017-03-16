import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class SpeakingInTongues {
	
	public static void main(String[] args) throws IOException {
		File file = new File("c:\\java\\TonguesResults.txt");
		File inFile = new File("c:\\java\\A-small-attempt0.in");
		file.createNewFile();
		PrintStream out = new PrintStream(file);
		Scanner scanIn = new Scanner(inFile);
		
		int cases = scanIn.nextInt();
		StringBuilder sb;
		
		for(int i = 0; i <= cases; i++){
			sb = new StringBuilder(scanIn.nextLine());
			sb = translate(sb);
			if(i == 0) continue;
			out.println("Case #"+(i)+": "+ sb);
		}
		
		out.close();
	}
	
	public static StringBuilder translate(StringBuilder s){
		
		for(int i = 0; i < s.length(); i++){
			if(s.charAt(i) == ' ') continue;
			s.replace(i, i+1, translateChar(s.charAt(i)));
		}
		
		return s;
	}
	
	public static String translateChar(char c){
		if(c == 'a') return "y";
		if(c == 'b') return "h";
		if(c == 'c') return "e";
		if(c == 'd') return "s";
		if(c == 'e') return "o";
		if(c == 'f') return "c";
		if(c == 'g') return "v";
		if(c == 'h') return "x";
		if(c == 'i') return "d";
		if(c == 'j') return "u";
		if(c == 'k') return "i";
		if(c == 'l') return "g";
		if(c == 'm') return "l";
		if(c == 'n') return "b";
		if(c == 'o') return "k";
		if(c == 'p') return "r";
		if(c == 'q') return "z";
		if(c == 'r') return "t";
		if(c == 's') return "n";
		if(c == 't') return "w";
		if(c == 'u') return "j";
		if(c == 'v') return "p";
		if(c == 'w') return "f";
		if(c == 'x') return "m";
		if(c == 'y') return "a";
		if(c == 'z') return "q";
		
		return "1";
	}

}
