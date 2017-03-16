import java.util.*;
import java.io.*;
public class B{
public static int max =  0,e = 0,r= 0;
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tmp = Integer.parseInt(lector.readLine());
for(int m = 0;m<tmp;m++){
String a[] = lector.readLine().split(" ");
max = 0;
int jo[] = new int[Integer.parseInt(a[2])];
e= Integer.parseInt(a[0]);
r = Integer.parseInt(a[1]);
String b[] = lector.readLine().split(" ");
for(int n = 0;n<jo.length;n++)jo[n]=Integer.parseInt(b[n]);
hagale(Integer.parseInt(a[0]),0,jo,0);
System.out.println("Case #"+(m+1)+": "+max);
}
}
public static void hagale(int a,int b,int c[],int v){
if(a<=0 || b==c.length){
if(a>-1)
max = Math.max(v,max);
return;
}
if(a>e)return;
for(int n = 0;n<=a;n++)
hagale(a-n+r,b+1,c,v+c[b]*n);
}
}
