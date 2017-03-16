import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
		String[] ia;
		
		int T = Integer.parseInt(is.readLine());
		for(int t = 1;t <= T; ++t){
			ia = is.readLine().split(" ");
			int X = Integer.parseInt(ia[0]);
			int Y = Integer.parseInt(ia[1]);

			StringBuilder sb = new StringBuilder();
			int x = 0, y = 0;
			int dif = 1;
			if(X > 0){
				while(x != X){
					x-=dif;
					++dif;
					sb.append('W');
					x+=dif;
					++dif;
					sb.append('E');
				}
			} else {
				while(x != X){
					x+=dif;
					++dif;
					sb.append('E');
					x-=dif;
					++dif;
					sb.append('W');
				}
			}
			if(Y > 0){
				while(y != Y){
					y-=dif;
					++dif;
					sb.append('S');
					y+=dif;
					++dif;
					sb.append('N');
				}
			} else {
				while(y != Y){
					y+=dif;
					++dif;
					sb.append('N');
					y-=dif;
					++dif;
					sb.append('S');
				}
			}

			System.out.println("Case #" + t + ": " + sb.toString());
		}
	}
}
