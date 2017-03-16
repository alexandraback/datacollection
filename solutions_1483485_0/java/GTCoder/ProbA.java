import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class ProbA {
	public static char[] buildMap() {
          char[] map = new char[26];
	      String[] s = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	         "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	       "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	      
	      String[] t = {"our language is impossible to understand",
	       "there are twenty six factorial possibilities",
	       "so it is okay if you want to just give up"};
	      for(int i = 0; i<s.length; i++)
	    	  for(int j = 0; j<s[i].length(); j++)
	    	  {
	    		  if(s[i].charAt(j) != ' ')
	    	          map[s[i].charAt(j) - 'a'] = t[i].charAt(j);
	    	  }
	      map['z'-'a'] = 'q';
	      map['q'-'a'] = 'z';
	      /*for(int i = 0; i<26; i++) {
	    	  //System.out.print(i+'a') ;
	    	  System.out.print(map[i]); 
	      }*/
	      return map;

		
	}
	public static String solve(char[] map, char[] input) {
		for(int i = 0; i<input.length; i++) {
			if(input[i] != ' ')
			    input[i] = map[input[i]-'a'];
		}
		return String.valueOf(input);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		char[] map = buildMap();
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for(int i=1; i<=T; i++) {
			line = in.readLine();
			out.print("Case #" + i+ ": ");
			out.println(solve(map, line.toCharArray()));
		}
		
		out.flush();
		in.close();
		out.close();
	}
}
