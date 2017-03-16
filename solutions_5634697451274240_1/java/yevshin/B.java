import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B {

	private static int solve(byte[] s)
	{
		int n = 1;
		for(int i = 1; i < s.length; i++)
			if(s[i] != s[i-1])
				++n;
		return n - (s[0]=='+' ? n % 2 : (n+1)%2);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader( new InputStreamReader(System.in));
		int nt = Integer.parseInt(in.readLine());
		for(int t = 1; t <= nt; t++)
			System.out.println( "Case #" + t + ": " + solve( in.readLine().getBytes() ) );
	}
}
