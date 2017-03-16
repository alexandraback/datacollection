import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Recycle {
	
	static Set<Integer> chosen ;
	static int a = 0;
	static int b = 0;
	public static PrintWriter pw;
	
	public static void main(String[] args) throws Exception {
		try{
			File f = new File("\\\\filesrv/stufiles$/matt.tough/out.txt");
			f.createNewFile();
			pw = new PrintWriter(f);
		}catch(Exception e){
			
		}
		Scanner in = new Scanner(new File("\\\\filesrv/stufiles$/matt.tough/C-large.in"));
		//Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		int cases = Integer.parseInt(line);
		for (int t=0; t < cases; t++){
			line = in.nextLine();
			Scanner thisLine = new Scanner (line);
			a = thisLine.nextInt();
			b = thisLine.nextInt();
			
			int minDigits = ((int)Math.floor(Math.log10(a)))+1;
			int maxDigits = ((int)Math.floor(Math.log10(b)))+1;
			
			int count = 0;
			chosen = new HashSet<Integer>();
			
			for (int digits = minDigits; digits <= maxDigits; digits++){
				if (digits < 2){
					count += 0;
				}else{
					int minNum =(int) Math.pow(10, digits-1);
					int maxNum =(int) Math.pow(10, digits);
					for (int i = minNum; i < maxNum; i++){
						
						if(i > b){
							
							break;
						}
						
						
						
						if(i>=a){
						String thisNum = i+"";
						count += countPairsAdded(thisNum);
						}
						
					}
					
				}
			}
			
			pw.printf("Case #%d: %d\n", t+1,count);
			
			
			
			
		}
		pw.flush();
	}
	
	public static int countPairsAdded(String s){
		
		
		int count =0;
		int num = Integer.parseInt(s);
		if (chosen.contains(num))
			return 0;
		
		
		for (int shift = 0; shift < s.length() ; shift++){
			String test = shift(s,shift);
			int i = Integer.parseInt(test);
			if(i <= b && i >=a && i != num &&  !chosen.contains(i)){
				//System.out.println(test);
				count++;
				chosen.add(i);
			}
			
		}
		
		//System.out.println(count);
		
		
		
		count *= count+1;
		count /=2;
		
		return count;
	}
	
	public static String shift(String s, int shift){
		return s.substring(shift) + s.substring(0,shift);
		
	}

}
