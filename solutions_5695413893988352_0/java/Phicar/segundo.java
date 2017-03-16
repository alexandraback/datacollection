import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class segundo{
public static int resa = -1,resb=-1;
public static int dif = Integer.MAX_VALUE;
public static String ta = "";
public static long mod = 1000000007;
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
//String tmp[] = lector.readLine().split(" ");
int cas = Integer.parseInt(lector.readLine());
for(int cc = 0;cc<cas;cc++){
String res = "";
ta = lector.readLine();
dif = Integer.MAX_VALUE;
hagale(0,"");
int o = ta.indexOf(" ");
String res1 = resa+"";
String res2 = resb+"";
while(res1.length()<o)res1 = "0"+res1;
while(res2.length()<ta.length()-o-1)res2 = "0"+res2;
System.out.println("Case #"+(cc+1)+": "+res1+" "+res2);
}
}
public static void hagale(int a,String b){
if(a==ta.length()){
//System.out.println(b);
String sep[] = b.split(" ");
int sa = Integer.parseInt(sep[0]);
int sb = Integer.parseInt(sep[1]);
int dd = Math.abs(sa-sb);
if(dd<=dif){
if(dd<dif){resa = sa;resb=sb;}
else if(sa<resa || (sa==resa && sb<resb)){resa = sa;resb=sb;}
dif = dd;
}
return;
}	
if(ta.charAt(a)!='?'){
hagale(a+1,b+ta.charAt(a));
return;
}
for(int n = 0;n<10;n++)hagale(a+1,b+n);
}
}
class p implements Comparable{
public int a;
public p(int a){
this.a = a;	
}
public String toString(){
return "";
}
public int compareTo(Object o){
p pp = (p)o;
return (int)Math.signum(a-pp.a);
}
}