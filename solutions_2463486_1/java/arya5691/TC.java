
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
        memo=new BigInteger[71];
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
	memo[40] = new BigInteger("100220141022001");
	memo[41] = new BigInteger("102012040210201");
	memo[42] = new BigInteger("102234363432201");
	memo[43] = new BigInteger("121000242000121");
	memo[44] = new BigInteger("121242363242121");
	memo[45] = new BigInteger("123212464212321");
	memo[46] = new BigInteger("123456787654321");
	memo[47] = new BigInteger("400000080000004");
	memo[48] = new BigInteger("10000000200000001");
	memo[49] = new BigInteger("10002000300020001");
	memo[50] = new BigInteger("10004000600040001");
	memo[51] = new BigInteger("10020210401202001");
	memo[52] = new BigInteger("10022212521222001");
	memo[53] = new BigInteger("10024214841242001");
	memo[54] = new BigInteger("10201020402010201");
	memo[55] = new BigInteger("10203040504030201");
	memo[56] = new BigInteger("10205060806050201");
	memo[57] = new BigInteger("10221432623412201");
	memo[58] = new BigInteger("10223454745432201");
	memo[59] = new BigInteger("12100002420000121");
	memo[60] = new BigInteger("12102202520220121");
	memo[61] = new BigInteger("12104402820440121");
	memo[62] = new BigInteger("12122232623222121");
	memo[63] = new BigInteger("12124434743442121");
	memo[64] = new BigInteger("12321024642012321");
	memo[65] = new BigInteger("12323244744232321");
	memo[66] = new BigInteger("12343456865434321");
	memo[67] = new BigInteger("12345678987654321");
	memo[68] = new BigInteger("40000000800000004");
	memo[69] = new BigInteger("40004000900040004");
	memo[70] = new BigInteger("1000000002000000001");
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
