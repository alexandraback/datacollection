import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class ManageYourEnergy{
	static int E, R, n;
	static int[] activity;
	static int backtrack(int energy, int index){
		if(index==n)	return 0;
		int tmp = 0;
		for(int i=0; i<=energy; i++){
			tmp = max(tmp, i*activity[index]+backtrack(min(E, energy-i+R), index+1));
		}
		// out.printf("index = %d\n", index);
		// out.printf("tmp = %d\n", tmp);
		return tmp;
	}
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		Scanner sc = new Scanner(in);
		int t = sc.nextInt();
		for(int tt=0; tt<t; tt++){
			E = sc.nextInt();
			R = sc.nextInt();
			n = sc.nextInt();
			activity = new int[n];
			for(int i=0; i<n; i++)	activity[i] = sc.nextInt();
			out.printf("Case #%d: %d\n", tt+1, backtrack(E, 0));
		}
		bw.flush();
	}
}
