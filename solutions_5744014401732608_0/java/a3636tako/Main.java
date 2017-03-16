import java.io.*;
import java.util.*;

public class Main{
	int[][] mat;
	int[] memo;
	int B;
	long M;
	public void solve(){
		int T = nextInt();
		for(int cnt = 1; cnt <= T; cnt++){
			B = nextInt();
			M = nextLong();
			mat = new int[B][B];
			memo = new int[B];
			if(createMat(0, 1)){
				out.printf("Case #%d: POSSIBLE\n", cnt);
				for(int i = 0; i < B; i++){
					for(int j = 0; j < B; j++){
						out.print(mat[i][j]);
					}
					out.println();
				}
			}else{
				out.printf("Case #%d: IMPOSSIBLE\n", cnt);
				
			}
			
		}
	}
	
	public boolean createMat(int i, int j){
		if(j >= B){
			if(i >= B){
				Arrays.fill(memo, -1);
				if(count(0) == M){
					return true;
				}
			}else{
				if(createMat(i + 1, i + 2)){
					return true;
				}
			}
		}else{
			if(createMat(i, j + 1)) return true;
			mat[i][j] = 1;
			if(createMat(i, j + 1)) return true;
			mat[i][j] = 0;
		}
		return false;
	}
	public int count(int pos){
		if(memo[pos] != -1) return memo[pos];
		if(pos == B - 1){
			return 1;
		}
		
		int ans = 0;
		for(int i = 0; i < B; i++){
			if(mat[pos][i] == 1){
				ans += count(i);
			}
		}
		return memo[pos] = ans;
	}
	
	private static PrintWriter out;
	public static void main(String[] args){
		out = new PrintWriter(System.out);
		new Main().solve();
		out.flush();
	}
	
	
	
	public static int nextInt(){
		int num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if(str.charAt(0) == '-'){
			minus = true;
			i++;
		}
		int len = str.length();
		for(;i < len; i++){
			char c = str.charAt(i);
			if(!('0' <= c && c <= '9')) throw new RuntimeException();
			num = num * 10 + (c - '0');
		}
		return minus ? -num : num;
	}
	
	public static long nextLong(){
		long num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if(str.charAt(0) == '-'){
			minus = true;
			i++;
		}
		int len = str.length();
		for(;i < len; i++){
			char c = str.charAt(i);
			if(!('0' <= c && c <= '9')) throw new RuntimeException();
			num = num * 10l + (c - '0');
		}
		return minus ? -num : num;
	}
	public static String next(){
		int c;
		while(!isAlNum(c = read())){}
		StringBuilder build = new StringBuilder();
		build.append((char)c);
		while(isAlNum(c = read())){
			build.append((char)c);
		}
		return build.toString();
	}
	
	
	private static byte[] inputBuffer = new byte[1024];
	private static int bufferLength = 0;
	private static int bufferIndex = 0;
	private static int read(){
		if(bufferLength < 0) throw new RuntimeException();
		if(bufferIndex >= bufferLength){
			try{
				bufferLength = System.in.read(inputBuffer);
				bufferIndex = 0;
			}catch(IOException e){
				throw new RuntimeException(e);
			}
			if(bufferLength <= 0) return (bufferLength = -1);
		}
		return inputBuffer[bufferIndex++];
	}
	
	private static boolean isAlNum(int c){
		return '!' <= c && c <= '~';
	}
}