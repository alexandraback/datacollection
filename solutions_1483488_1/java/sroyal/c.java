import java.util.*;
import java.io.*;
public class c{
	public static void main(String[] args)throws IOException{
		Scanner br = new Scanner(new File("c.in"));
		PrintWriter out = new PrintWriter(new File("c.out"));
		int cases = br.nextInt();
		for(int i = 0;i<cases;i++){
			int a = br.nextInt();
			int b = br.nextInt();
			
			int count = 0;
			for(int j = a;j<=b;j++){
				String cur = Integer.toString(j);
				HashSet<String> seen = new HashSet<String>();
				for(int k = 1;k<cur.length();k++){
					String temp = cur.substring(k, cur.length())+cur.substring(0, k);
					if(!seen.contains(temp)){
						seen.add(temp);
						int num = Integer.parseInt(temp);
						if(num <= j || num < a || num > b){
							continue;
						
						}
						count++;
					}
				}
			}
			out.println("Case #"+(i+1)+": "+count);
		}
		out.close();
	}

}
