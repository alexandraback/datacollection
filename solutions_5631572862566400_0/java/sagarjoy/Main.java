import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author Sagar
 *
 */
public class Main {

	static int maxS = 0;
	static int n;
	static int f[];
	static List af[] ;
	static boolean d[];
	static boolean c[];
	/**
	 * @param args
	 * @throws IOException 
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args){
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();
		for(int i = 1 ; i <= t; i++){
			n = in.nextInt();
			f = new int[n];
			af = new List[n];
			maxS = 0;
			c = new boolean[n];
			d = new boolean[n];
			for(int j= 0; j<n; j++){
				af[j] = new ArrayList<Integer>();
			}
			for(int j= 0; j<n; j++){
				f[j] = in.nextInt() - 1;
				if(af[f[j]] == null)
					af[f[j]] = new ArrayList<Integer>();
				af[f[j]].add(j);
			}
			
			c[0] = true;
			d[0] = true;
			solve(0, 1);
			
			System.out.println("Case #" + i + ": " + (maxS));
		}
		in.close();
		
	}

	private static int solve(int s, int cnt) {
		if(maxS < cnt)
			maxS = cnt;
		if(cnt == n){
			return n;
		} else {
			int a = -1;
			if(!d[f[s]] && !c[f[s]] ){
				d[f[s]] = true;
				c[f[s]] = true;
				a = f[s]; 
			} else {
				for (Object afo : af[s]) {
					Integer afi = (Integer) afo;
					if(!d[afi] && !c[afi] ){
						d[afi] = true;
						c[afi] = true;
						a = afi;
						break;
					}
				}
			}
			if(a != -1){
				solve(a, ++cnt);
				d[a] = false;
			}
			for (Object afo : af[0]) {
				Integer afi = (Integer) afo;
				if(!d[afi] && !c[afi] ){
					d[afi] = true;
					c[afi] = true;
					a = afi;
					solve(a, ++cnt);
					d[a] = false;
				}
			}
			
		}
		return 0;
	}

}
