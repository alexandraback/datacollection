import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {

	static Map<Character, Character> dic = new HashMap<Character, Character>();
	public static void init(){
		String[] in = {
				"ejp mysljylc kd kxveddknmc re jsicpdrysi"
				,"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
				,"de kr kd eoya kw aej tysr re ujdr lkgc jv"
		};
		String[] to = {
				"our language is impossible to understand"
				,"there are twenty six factorial possibilities"
				,"so it is okay if you want to just give up"
		};
		
		for(int k=0;k<in.length;k++){
			String[] words = in[k].split(" ");
			String[] trans = to[k].split(" ");
			for(int i=0;i<words.length;i++){
				for(int j=0;j<words[i].length();j++){
					dic.put(words[i].charAt(j), trans[i].charAt(j));
				}
			}
		}
		
		System.out.println(dic);
	}
	public static String translate(String s){
		StringBuilder builder = new StringBuilder();
		for(int i=0;i<s.length();i++){
			if(dic.containsKey(s.charAt(i)))
				builder.append(dic.get(s.charAt(i)));
			else{
				if(s.charAt(i) == 'q')
					builder.append('z');
				else
					builder.append('q');
			}
		}
		
		return builder.toString();
	}
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter("C:\\Users\\JiaKY\\Desktop\\out.txt");
		init();
		
		int n = Integer.valueOf(in.nextLine());
		for(int i=0;i<n;i++){
			String line = in.nextLine();
			String[] words = line.split(" ");
			out.print("Case #"+(i+1)+": ");
			for(int j=0;j<words.length;j++){
				out.print(translate(words[j])+" ");
			}
			out.println();
			out.flush();
		}
	}

}
