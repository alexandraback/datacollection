
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class TC
{
    static BigInteger[] memo;
    
    static void init()
    {
        memo=new BigInteger[40];
        memo[0] = new BigInteger("1");
	memo[1] = new BigInteger("4");
	memo[2] = new BigInteger("9");
	memo[3] = new BigInteger("121");
	memo[4] = new BigInteger("484");
	memo[5] = new BigInteger("10201");
	memo[6] = new BigInteger("12321");
	memo[7] = new BigInteger("14641");
	memo[8] = new BigInteger("40804");
	memo[9] = new BigInteger("44944");
	memo[10] = new BigInteger("1002001");
	memo[11] = new BigInteger("1234321");
	memo[12] = new BigInteger("4008004");
	memo[13] = new BigInteger("100020001");
	memo[14] = new BigInteger("102030201");
	memo[15] = new BigInteger("104060401");
	memo[16] = new BigInteger("121242121");
	memo[17] = new BigInteger("123454321");
	memo[18] = new BigInteger("125686521");
	memo[19] = new BigInteger("400080004");
	memo[20] = new BigInteger("404090404");
	memo[21] = new BigInteger("10000200001");
	memo[22] = new BigInteger("10221412201");
	memo[23] = new BigInteger("12102420121");
	memo[24] = new BigInteger("12345654321");
	memo[25] = new BigInteger("40000800004");
	memo[26] = new BigInteger("1000002000001");
	memo[27] = new BigInteger("1002003002001");
	memo[28] = new BigInteger("1004006004001");
	memo[29] = new BigInteger("1020304030201");
	memo[30] = new BigInteger("1022325232201");
	memo[31] = new BigInteger("1024348434201");
	memo[32] = new BigInteger("1210024200121");
	memo[33] = new BigInteger("1212225222121");
	memo[34] = new BigInteger("1214428244121");
	memo[35] = new BigInteger("1232346432321");
	memo[36] = new BigInteger("1234567654321");
	memo[37] = new BigInteger("4000008000004");
	memo[38] = new BigInteger("4004009004004");
	memo[39] = new BigInteger("100000020000001");
    }
    
    static String status( long A, long B )
    {
        int cnt=0;
        for( int i=0; i<memo.length; i++ )
        {
            long val=memo[i].longValue();
            if( ( A <= val ) && ( B >= val ) )
                cnt++;
        }
        return Integer.toString(cnt);
    }
    
    public static void main( String[] args ) throws IOException
    {
        BufferedReader br=new BufferedReader( new InputStreamReader( System.in ));
        BufferedWriter out=new BufferedWriter( new OutputStreamWriter( System.out ));
        init();
        int T=Integer.parseInt(br.readLine() );
        for( int t=1; t<=T; t++ )
        {
            String s=br.readLine();
            StringTokenizer tok=new StringTokenizer( s );
            long A=Long.parseLong( tok.nextToken() );
            long B=Long.parseLong( tok.nextToken() );
    
            String res="Case #" +t+": ";
            res=res+status(A,B);
            out.write( res +"\n");
        }
        out.close();
    }
    
    
}
