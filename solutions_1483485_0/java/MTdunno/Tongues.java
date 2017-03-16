import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Tongues {
	
	public static Map <Character,Character> trans = new HashMap<Character, Character>();

	public static PrintWriter pw;
	
	public static void main(String[] args) throws FileNotFoundException {
		try{
			File f = new File("\\\\filesrv/stufiles$/matt.tough/out.txt");
			f.createNewFile();
			pw = new PrintWriter(f);
		}catch(Exception e){
			
		}
		
		trans.put('a', 'y');
		trans.put('b', 'h');
		trans.put('c', 'e');
		trans.put('d', 's');
		trans.put('e', 'o');
		trans.put('f', 'c');
		trans.put('g', 'v');
		trans.put('h', 'x');
		trans.put('i', 'd');
		trans.put('j', 'u');
		trans.put('k', 'i');
		trans.put('l', 'g');
		trans.put('m', 'l');
		trans.put('n', 'b');
		trans.put('o', 'k');
		trans.put('p', 'r');
		trans.put('q', 'z');
		trans.put('r', 't');
		trans.put('s', 'n');
		trans.put('t', 'w');
		trans.put('u', 'j');
		trans.put('v', 'p');
		trans.put('w', 'f');
		trans.put('x', 'm');
		trans.put('y', 'a');
		trans.put('z', 'q');
		trans.put(' ', ' ');
		System.out.println("");
		Scanner s = new Scanner(new File("\\\\filesrv/stufiles$/matt.tough/A-small-attempt3.in"));
		String line = s.nextLine();
		System.out.println(line);
		int itt = 0x0A;
		char c = (char)itt;
		//s.useDelimiter(c+"");
		int num = 30;
		for (int i=0; i< num; i++){
			System.out.println(i);
			line = s.nextLine();
			pw.printf("Case #%d: %s\n", i+1, translate(line));
		}
		pw.flush();
		
	}
	
	public static String translate(String s){
		
		String ret = "";
		for( char c: s.toCharArray()){
			
			ret += trans.get(c);
			
		}
		
		return ret;
	}
	
}
