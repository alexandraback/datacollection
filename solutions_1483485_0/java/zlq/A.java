import java.util.*;
import java.io.*;

public class A{
	String map = "yhesocvxduiglbkrztnwjpfmaq";
	void solve() throws FileNotFoundException{
		File fin = new File("data.in");
		File fout = new File("data.out");
		Scanner cin = new Scanner(fin);
		PrintWriter cout = new PrintWriter(fout);
		
		int T;
		String line, str;
		StringTokenizer st;
		T = cin.nextInt();
		line = cin.nextLine();
		for(int k = 0; k < T; k++){
			line = cin.nextLine();
//			System.out.println(line);
			st = new StringTokenizer(line);
			cout.print("Case #"+(k+1)+":");
			while(st.hasMoreTokens()){
				str = st.nextToken();
				cout.print(' ');
				for(int i = 0; i < str.length(); i++){
					int index = str.charAt(i)-'a';
					cout.print(map.charAt(index));
				}
			}
			cout.print('\n');
		}
		cout.flush();
	}
	public static void main(String [] args) throws Exception{
		A test = new A();
		test.solve();
	}
}












