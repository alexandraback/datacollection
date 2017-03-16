import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("a.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("a.out"));
		int T = s.nextInt();
		s.nextLine();
		for (int i = 1; i <= T; i++) {
			out.write("Case #"+i+": ");
			String str = s.nextLine();
			String ans = "";
			for(int j=0; j<str.length(); j++){
				char ch = str.charAt(j);
				if(ans.length()==0 || ch>=ans.charAt(0)){
					ans = ch+ans;
				}else{
					ans = ans+ch;
				}
			}
			out.write(ans+"\n");
		}
		out.close();	
	}

}
