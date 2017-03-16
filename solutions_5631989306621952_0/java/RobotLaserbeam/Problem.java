import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Problem {
	public static void main(String args[])throws IOException{
		Scanner scan = new Scanner(new File("Problem.txt"));
		PrintWriter pw = new PrintWriter("Problem.out");
		int cases = scan.nextInt();
		for(int i = 0; i < cases; i++){
			String cur = scan.next();
			String val = "";
			for(int l = 0; l < cur.length(); l++){
				if(l==0){
					val+=cur.charAt(l);
				}
				else{
					if(cur.charAt(l)>=val.charAt(0)){
						val = cur.charAt(l)+val;
					}
					else{
						val+=cur.charAt(l);
					}
				}
			}
			pw.println("Case #"+(i+1)+": "+val);
		}
		pw.close();
	}
}
