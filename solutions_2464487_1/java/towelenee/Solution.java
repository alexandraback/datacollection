import java.io.*;
import java.util.*;
import java.math.*;

public class Solution
{

BufferedReader in;
PrintWriter out;
StringTokenizer ss;

String _token()throws IOException{while (!ss.hasMoreTokens())ss=new StringTokenizer(in.readLine());return ss.nextToken();}
int _int()throws IOException{return Integer.parseInt(_token());}
long _long()throws IOException{return Long.parseLong(_token());}
double _double()throws IOException{return Double.parseDouble(_token());}

BigInteger val(long x){
  return BigInteger.valueOf(x);
}
void RUN() throws Exception
{
  String name="";
  in = new BufferedReader(new FileReader(name+"in"));
  out = new PrintWriter(new File(name+"out"));
  ss=new StringTokenizer(" ");
  int testN = _int();

  for( int testId = 1; testId <= testN; testId++){
    out.print("Case #" + testId + ": ");
    long a = _long();
    long x = _long();
    long l = 0, r = (long)(1e18);
    while(l != r - 1){
      long m = (l + r) / 2;
      //int m = 1;
      BigInteger f1 = val(1 + 2 * a + 2 * m).multiply(val(m + 1));
      //System.err.println(f1);
      
      if(f1.compareTo(val(x)) <= 0)
        l = m;
      else
        r = m;
    }
    out.println(l + 1);
  }
  out.close(); 
}

public static void main(String [] args) throws Exception
{
new Solution().RUN();
}
}