import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.io.*;
public class A{
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tmp = Integer.parseInt(lector.readLine());
for(int m = 0;m<tmp;m++){
String a = lector.readLine();
double r = Double.parseDouble(a.substring(0,a.indexOf(" ")));
double p = Double.parseDouble(a.substring(a.indexOf(" ")+1));
/*System.out.println((-1.0*(2.0*r+3)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0);
System.out.println((1.0*(2.0*r+3)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0);
double res1 = Math.floor((-1.0*(2.0*r+3)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0)+1;
double res2 = Math.floor((1.0*(2.0*r+3)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0)+1;
System.out.println("Case #"+(m+1)+": "+(long)Math.min(res1,res2));
*/for(int n = 0;;n++){
double t = (n+1)*(2.0*r+1.0+2.0*n);
if(t>p){System.out.println("Case #"+(m+1)+": "+n);break;}
}
}
}
public static BigDecimal sqrt(BigDecimal a) throws Exception{
//if(a.equals("0"))return "0";
BigDecimal x = a;
BigDecimal p = BigDecimal.ONE;
BigDecimal tmp =new BigDecimal("0.0");
while(p.compareTo(tmp)!=0){
tmp = p;
p = p.subtract(((p.multiply(p)).subtract(x)).divide(p.multiply(new BigDecimal("2.0")),10, BigDecimal.ROUND_HALF_UP));
//System.out.println(p);
}
return p;
}

}
