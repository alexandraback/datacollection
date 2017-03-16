import java.io.*;
import java.util.Scanner;


public class ALarge {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		ALarge main = new ALarge();
		main.answer();
	}
	
	
	public void answer() throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("A-large.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("ALarge.out", "UTF-8");
		for(int cas=1; cas<=T; cas++){
			String[] size = scan.nextLine().split(" ");
			int maxS = Integer.parseInt(size[0]);
			//int maxS = Integer.parseInt(arg0)
			//scan.nextInt();
			String S = size[1];
			int friends =0;
			int pS = friends+S.charAt(0)-'0';
			for(int i=0; i<maxS; i++){
				if(pS>=i+1){
					pS+=S.charAt(i+1)-'0';
				}else{
					friends += i+1-pS;
					pS += S.charAt(i+1)-'0'+i+1-pS;
				}
			}			
			writer.println("Case #"+cas+": "+friends);
			System.out.println("Case #"+cas+": "+friends);
				
		}		
		writer.close();
	}
	
}
