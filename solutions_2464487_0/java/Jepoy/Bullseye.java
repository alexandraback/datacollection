import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Bullseye{
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		Scanner sc = new Scanner(in);
		// int t = Integer.valueOf(br.readLine());
		int t = sc.nextInt();
		for(int tt=0; tt<t; tt++){
			int rad = sc.nextInt();
			int cap = sc.nextInt();
			int ctr = 0;
			int r = rad;
			while(true){
				int area = ((r+1)*(r+1)-r*r);
				if((cap-area)>=0){
					cap-=area;
					ctr++;
					r += 2;
				}else{
					break;
				}
			}
			out.printf("Case #%d: %d\n", tt+1, ctr);
		}
		bw.flush();
	}
}
