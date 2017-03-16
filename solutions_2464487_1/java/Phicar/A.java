import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.io.*;
public class A{
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tmp = Integer.parseInt(lector.readLine());
BigDecimal m1 = new BigDecimal("-1.0");
BigDecimal dos = new BigDecimal("2.0");
BigDecimal tr = new BigDecimal("3.0");
BigDecimal cu = new BigDecimal("4.0");
BigDecimal och = new BigDecimal("8.0");
for(int m = 0;m<tmp;m++){
String a = lector.readLine();
double r = Double.parseDouble(a.substring(0,a.indexOf(" ")));
//BigDecimal r = BigDecimal(a.substring(0,a.indexOf(" ")));
//BigDecimal p = BigDecimal(a.substring(a.indexOf(" ")+1));
double p = Double.parseDouble(a.substring(a.indexOf(" ")+1));
//System.out.println((-1.0*(2.0*r+3)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0);
//System.out.println((1.0*(2.0*r+3)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0);
//BigDecimal res1 = ((m1.multiply(dos.multiply(r)).add(tr)).add(sqrt((cu.multiply(r.multiply(r))).
//subtract(cu.multiply(r)).add(BigDecimal.ONE).add(och.multiply(p))))).divide(cu,10,BigDecimal.ROUND_HALF_UP);
double res1 = Math.floor((1.0*(2.0*r+3.0)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0)+1;
//BigDecimal res2 = ((m1.multiply(dos.multiply(r)).add(tr)).add(sqrt((cu.multiply(r.multiply(r))).
//subtract(cu.multiply(r)).add(BigDecimal.ONE).add(och.multiply(p))))).divide(cu,10,BigDecimal.ROUND_HALF_UP);
double res2 = Math.floor((-1.0*(2.0*r+3.0)+Math.sqrt(4.0*r*r-4.0*r+1.0+8.0*(p)))/4.0)+1;
if(res1<0.0)res1 = Double.MAX_VALUE;
if(res2<0.0)res2 = Double.MAX_VALUE;
boolean si = true;
for(int n = 0;n<1000;n++){
double t = (n+1)*(2.0*r+1.0+2.0*n);
if(t>p){System.out.println("Case #"+(m+1)+": "+n);si=false;break;}
}
if(si)
System.out.println("Case #"+(m+1)+": "+(long)Math.min(res1,res2));
/*
for(int n = 0;;n++){
double t = (n+1)*(2.0*r+1.0+2.0*n);
if(t>p){System.out.println("Case #"+(m+1)+": "+n);break;}
}*/
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
