import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
		String[] ia;

		int T = Integer.parseInt(is.readLine());
		for(int t = 1;t <= T; ++t){
			ia = is.readLine().split(" ");
			char[] name = ia[0].toCharArray();
			int least = Integer.parseInt(ia[1]);
			int ans = 0;
			for(int i = 0;i < name.length; ++i){
				for(int j = i;j < name.length; ++j){
					int c = 0;
					int m = 0;
					for(int k = i;k <= j; ++k){
						switch(name[k]){
							case 'a':
							case 'i':
							case 'u':
							case 'e':
							case 'o':
								if(m < c){
									m = c;
								}
								c=0;
								break;
							default:
								++c;
								break;
						}
					}
					if(least <= Math.max(m,c)){
						++ans;
					}
				}
			}
			System.out.println("Case #" + t + ": " + ans);
		}
	}

}
