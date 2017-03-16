import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Dsmall {
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int cas = 1; cas <=T; cas++) {
			String[] spl = in.readLine().split(" ");
			int X = Integer.parseInt(spl[0]);
			int R = Integer.parseInt(spl[1]);
			int C = Integer.parseInt(spl[2]);
			String ans = "";
			if(X==1)
			{
				ans = "GABRIEL";
			}
			else if(X==2)
			{
				if((R*C)%2==0)
					ans = "GABRIEL";
				else ans = "RICHARD";
			}
			else if(X==3)
			{
				if(R%3!=0 && C%3!=0)
					ans ="RICHARD";
				else if(R<2 || C <2)
					ans = "RICHARD";
				else ans = "GABRIEL";
			}
			else if(X==4)
			{
				if((R*C)%4!=0)
					ans = "RICHARD";
				else if(R<3 || C <3)
					ans = "RICHARD";
				else ans = "GABRIEL";
			}
			System.out.println("Case #"+cas+": "+ans);
		}
	}
}
