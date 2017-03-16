import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class tercero{
public static long mod = 1000000007;
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
//String tmp[] = lector.readLine().split(" ");
int cas = Integer.parseInt(lector.readLine());
for(int cc = 0;cc<cas;cc++){
int res =0;
int a = Integer.parseInt(lector.readLine());
long has[][] = new long[a][2];
for(int n = 0;n<a;n++){
String aa[] = lector.readLine().split(" ");
for(int r = 0;r<2;r++){
long mu=0;
for(int m = 0;m<aa[r].length();m++)
mu = mu*29L+aa[r].charAt(m)-'A';
has[n][r]=mu;
}
}
//for(int n = 0;n<a;n++)System.out.println(has[n][0]+" "+has[n][1]);
if(a<=2){
System.out.println("Case #"+(cc+1)+": 0");
continue;
}
for(int n = 1;n<(1<<a);n++){
HashSet<Long> prim = new HashSet<Long>();	
HashSet<Long> seg = new HashSet<Long>();	
int nn = n,c=0;
while(c<a){
if((nn&1)==1){prim.add(has[c][0]);seg.add(has[c][1]);}
c++;
nn/=2;
}
//System.out.println(a+" "+n+" "+prim+" "+seg);
nn = n;
c=0;
int cant = 0;
while(c<a){
//System.out.println("Viendo "+c+" ");
if((nn&1)==0){
//System.out.println("ver "+c+" "+prim.contains(has[c][0])+" "+seg.contains(has[c][1]));
if(prim.contains(has[c][0]) && seg.contains(has[c][1]))
cant++;
//System.out.println("-->"+c+" "+has[c][0]+" "+has[c][1]);
}
nn/=2;
c++;
}
res = Math.max(cant,res);
}
System.out.println("Case #"+(cc+1)+": "+res);	
}
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