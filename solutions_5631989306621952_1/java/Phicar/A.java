import java.math.*;
import java.util.*;
import java.io.*;
public class A{
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int ca = Integer.parseInt(lector.readLine());
for(int c = 0;c<ca;c++){
String res ="";
String a =lector.readLine();
for(int n = 0;n<a.length();n++)
if(res.length()>0 && res.charAt(0)<=a.charAt(n))
res = a.charAt(n)+""+res;
else
res+=a.charAt(n);
System.out.println("Case #"+(c+1)+": "+res);
}
}
}
class p implements Comparable{
int a,b;
public p(int a,int b){
this.a = a;
this.b = b;
}
public String toString(){return a+" "+b;}
public int compareTo(Object o){
p pp = (p)o;
return (int)Math.signum(a-pp.a);
}
}
