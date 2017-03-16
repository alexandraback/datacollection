import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Train {

	final int mod = 1000000007;

	public static void main( String[] args ) throws IOException{
		(new Train()).train();
	}

	boolean check( String str ){
		int i, j, n;
		n = str.length();
		boolean[] low = new boolean[26];
		for ( i = 0 ; i < n ; i++ ){
			char ch = str.charAt(i);
			if ( low[ch-'a'] )
				return false;
			low[ch-'a'] = true;
			j = i+1;
			while ( j < n && str.charAt(j) == str.charAt(i) )
				j++;
			i = j-1;
		}
		return true;
	}
	
	int factorial( int n ){
		long ans = 1;
		int i;
		for ( i = 1 ; i <= n ; i++ )
			ans = (ans * i)%mod;
		return (int)ans;
	}
	
	String[] strs;
	int n;
	public void train() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			n = sc.nextInt();
			strs = new String[n];
			int i, j;
			bw.write("Case #" + z + ": ");
			for ( i = 0 ; i < n ; i++ )
				strs[i] = sc.next();
			for ( i = 0; i < n ; i++ )
				for ( j = i+1 ; j < n ; j++ )
					if ( 
							strs[i].charAt(0) > strs[j].charAt(0) || 
							(strs[i].charAt(0) == strs[j].charAt(0) && strs[j].charAt(0) == strs[j].charAt(strs[j].length()-1)) 
						){
						String tstr;
						tstr = strs[i]; strs[i] = strs[j]; strs[j] = tstr;
					}
			long ans = 1;
			int[] num = new int[n+1];
			String[] str2 = new String[n+1];
			int k = 0;
			for ( i = 0 ; i < n ; i++ ){
				if ( strs[i].charAt(0) != strs[i].charAt(strs[i].length()-1) ){
					str2[k] = strs[i];
					num[k] = 1;
					k++;
				}
				else {
					j = i+1;
					int tn = 1;
					String str = strs[i];
					while ( j < n && strs[j].charAt(strs[j].length()-1) == strs[i].charAt(0) && strs[j].charAt(0) == strs[i].charAt(0) ){
						tn++;
						str += strs[j];
						j++;
					}
					if ( j < n && strs[j].charAt(0) == strs[i].charAt(0) ){
						str += strs[j];
						j++;
					}
					str2[k] = str;
					num[k] = factorial(tn);
					k++;
					i = j-1;
				}
			}
			int[] num2 = new int[n];
			int k2 = 0;
			String[] str3 = new String[n];
			boolean[] visit = new boolean[n];
			int[] prev = new int[n];
			int[] rear = new int[n];
			boolean flag = true;
			for ( i = 0 ; i < k ; i++ )
				prev[i] = -1;
			for ( i = 0 ; i < k ; i++ ){
				rear[i] = -1;
				for ( j = 0 ; j < k ; j++ )
					if ( i != j ){
						if ( str2[j].charAt(0) == str2[i].charAt(str2[i].length()-1) ){
							if ( rear[i] > -1 || prev[j] > -1 )
								flag = false;
							rear[i] = j;
							prev[j] = i;
						}
					}
			}
			String all = "";
			int finish = 0;
			for ( i = 0 ; i < k ; i++ ){
				if ( visit[i] || prev[i] != -1 )
					continue;
				visit[i] = true;
				finish++;
				j = i;
				k2++;
				long t = num[i];
				all += str2[i];
				while ( rear[j] != -1 ){
					j = rear[j];
					if ( visit[j] ){
						flag = false;
						break;
					}
					all += str2[j];
					visit[j] = true;
					finish++;
					t = (t*num[j])%mod;
				}
				ans = (ans*t)%mod;
			}
			ans = (ans * factorial(k2))%mod;
			
			if ( !flag || finish < k || !check(all) ){
				bw.write("0\n");
				continue;
			}
			bw.write(""+ans+"\n");
		}
		bw.close();
		sc.close();
	}
	
	
	boolean[] visit;
	int ans = 0;
	void bfs( int index, String str ){
		if ( index == n ){
			if (check(str))
				ans++;
			return;
		}
		int i;
		for ( i = 0 ; i < n ; i++ ){
			if ( !visit[i] ){
				visit[i] = true;
				bfs(index+1, str+strs[i]);
				visit[i] = false;
			}
		}
	}
	
	public void bf() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			n = sc.nextInt();
			strs = new String[n];
			visit = new boolean[n];
			int i, j;
			bw.write("Case #" + z + ": ");
			for ( i = 0 ; i < n ; i++ )
				strs[i] = sc.next();
			ans = 0;
			bfs(0,"");
			bw.write(""+ans+"\n");
		}
		bw.close();
		sc.close();
	}
}
