import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class B{
	
	static int t,k,l,s;
	static double eps = 1e-6d;
	static double a = 0d;
	static String line,key, ch,str;
	static String[] row;
	static boolean debug = false;
	static int max = 0;
	static int c = 0;
	static long tc = 0;
	static long pow = 1;
	
	public static void main(String [ ] args) throws IOException{
		int i;
		
		
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
	    try {
	    	File file = new File("bbb.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 100.

			
	        for(i = 0; i < t; i++){
				
				line = br.readLine();
				row = line.split("\\s");
				k = Integer.valueOf(row[0]);
				l = Integer.valueOf(row[1]);
				s = Integer.valueOf(row[2]);
				
				line = br.readLine();
				key = new String (line);
				
				line = br.readLine();
				ch = new String (line);
				
	        	//1 <= n <= 10^6.
				debug = true;
				a=0d;
				
				
				
				
				if(checkKeyboard(key,ch)){//check letters
					str = "";
					max = c = 0;
					tc = 0;
					pow = 1;
					for(int jj = 0; jj<s;jj++){ pow*=k;}
					
					back(0);
					
					if(max==0) {
				    	a = 0d;
				    } else {

				    	//if(debug) System.out.println("--------------C");
				    	//if(debug) System.out.println("pow:"+pow+" tc "+tc+" max "+max);
				    	a = max - (double) tc/ pow;

				    	//if(debug) System.out.println("1:"+(double) tc/ pow);
				    	//if(debug) System.out.println("2:"+a);
				    }
					
				} //else a=0d, no letters available
				
				//if(debug) System.out.println("-------");
    			bw.write("Case #"+(i+1)+": "+a+"\n");
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
	
	private static boolean checkKeyboard(String k, String w){
		boolean goon=true;
		int i = 0;
		while(goon && i < w.length()){
			if(k.indexOf(w.charAt(i)) ==-1) goon=false;
			else i++;
		}
		return goon; 
	}
	
	private static int matchCount(String s1, String s2){
		int a;
		a = 0;

		Pattern p = Pattern.compile(s1);
		Matcher m = p.matcher(s2);
	    while (m.find()){
	    	a++;
	    }
	    return a;
	}
	
	private static int matchCount2(String s1, String s2){
		int a=0;

		Pattern p = Pattern.compile(s1);
		Matcher m = p.matcher(s2);
		boolean found = m.find();
	    while (found){
	    	a++;
	    	found = m.find(m.start() + 1);
	    }
	    return a;
	}
	
	private static void back(int j){
	    int jj;
		if(j == s){
			c = matchCount2(ch,str);
		    
		    if(max<c) max = c;
		    tc+=c;
		    //if(debug) System.out.println("------F");
	    	//if(debug) System.out.println(str +":"+c+" total "+tc+" max "+max);
		} else {
			for(jj = 0; jj<k;jj++){
		    	str = str + key.charAt(jj);
		    	back(j+1);
		    	str = str.substring(0, str.length()-1);
	    	 }
		}
	}
}
