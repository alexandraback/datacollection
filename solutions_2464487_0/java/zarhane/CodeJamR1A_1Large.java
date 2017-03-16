import java.io.*;
import java.util.Scanner;

public class CodeJamR1A_1Large {
	public static void main(String[] args) throws IOException {
	  String fileName = "A-small";
		Scanner s = new Scanner(new FileReader(new File(fileName+".in")));
		PrintWriter out = new PrintWriter(new File(fileName+".out"));
		StringBuilder resultat =new StringBuilder("");
		
		int TC = s.nextInt();

    for (int tc = 0; tc < TC; tc++) {
      if(tc!=0)
        resultat.append("\n");
      resultat.append("Case #"+(tc+1)+": ");

			int r = s.nextInt();
			
			int t = s.nextInt();
			
			int R = r;
			
			
			int count = 0;
			
			while(t>0){
			  
			  t -= (R+1)*(R+1)-R*R;
			  if(t>=0)
			    count++;
			  
			  R=R+2;
			}
			
			if(count<1)
			  count = 1;
			
			resultat.append(count);
		}
		
		out.print(resultat);
		out.close();
		s.close();
	}
}
