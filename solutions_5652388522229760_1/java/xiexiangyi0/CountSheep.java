import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;


public class CountSheep {

	public static String count(long n){
		HashSet<Character> hset1 = new HashSet<Character>();
		HashSet<String> hset2 = new HashSet<String>();
	    Long i=(long) 1, tmp_int=(long) -1;
		boolean find = false;
		
		while(!find){
			tmp_int = n * i;
			String tmp_str = String.valueOf(tmp_int);
			if(hset2.contains(tmp_str)){
				return "INSOMNIA";	
			}else{
				hset2.add(tmp_str);
			}
			
			for(int j=0; j<tmp_str.length(); ++j){
				Character c = tmp_str.charAt(j);
				if(!hset1.contains(c)){
					hset1.add(c);
				}
				if(hset1.size()==10){
					find = true;
					break;
				}
			}
			++i;
		}
		if(find){
			return ("" + tmp_int);
		}
		return "INSOMNIA";	
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			//A-small-attempt0.in
		    Scanner scanner = new Scanner(new File("/Users/xiangyixie/Documents/eclipse_workspace/2016Codejam/input/A-large.in"));
		    FileWriter writer = new FileWriter(new File("/Users/xiangyixie/Documents/eclipse_workspace/2016Codejam/input/output_large.txt"), false);
		    int T = scanner.nextInt();
		    for (int i=0; i<T; ++i) {
		    	int N = scanner.nextInt();
		    	String o = count(N);
		    	System.out.println("Case #" + (i+1) + ": " + o);
		    	writer.write("Case #" + (i+1) + ": " + o + "\n");
		    }
		    
		    scanner.close();
		    writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}
		
		System.out.println("done");

	}

}
