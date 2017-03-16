import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Googlerese {

	public static final char[] DECODE_MAPPINGS = {'y','h','e','s','o',
											'c','v','x','d','u',
											'i','g','l','b','k',
											'r','z','t','n','w',
											'j','p','f','m','a',
											'q' };
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("googlerese.out")));
		
		int numberCases = Integer.parseInt(f.readLine());
		String log;
		StringTokenizer st;
		
		for (int i = 1; i <= numberCases; i++)
		{
			log = "Case #" + i + ": ";
			st = new StringTokenizer(f.readLine());
			
			while (st.hasMoreTokens())
			{
				log += convertWord(st.nextToken()) + " ";
			}
			
			out.println(log);
		}
		
		out.close();
		System.exit(0);
	}

	private static String convertWord(String string) 
	{
		String result = "";
		
		for (int i = 0; i < string.length(); i++)
		{
			result += DECODE_MAPPINGS[string.charAt(i) - 'a'];
		}
		
		return result;
	}

}
