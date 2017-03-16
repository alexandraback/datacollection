import java.math.*;
import java.util.*;
import java.io.*;
public class C{
public static int ciclomax,pedazos,remax;
public static boolean vis[];
public static int ma[],pad[];
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int ca = Integer.parseInt(lector.readLine());
for(int c = 0;c<ca;c++){
int res =0;
int a = Integer.parseInt(lector.readLine());
ma = new int[a];
String t[] = lector.readLine().split(" ");
for(int n = 0;n<a;n++)
ma[n]=Integer.parseInt(t[n])-1;
ciclomax = 0;
pedazos = 0;
for(int n = 0;n<a;n++){
vis = new boolean[a];
dfs(n,n,0);
}
pad =new int[a];
for(int n =0;n<a;n++)
hagale(n,0,1,false);
System.out.println("Case #"+(c+1)+": "+Math.max(ciclomax,pedazos));
}
}
public static void hagale(int a,int b,int c,boolean d){
if(d){
pedazos = Math.max(pedazos,c);
//System.out.println(tal);
}
if(ma[ma[a]]==a){
pedazos = Math.max(pedazos,c+1);
//if(c+1==pedazos)System.out.println(tal+" "+ma[a]);
b|=(1<<ma[a]);
b|=(1<<a);
for(int n = 0;n<ma.length;n++)
if((b&(1<<n))==0){
//System.out.println("pos " +tal+" "+ma[a]+" "+n+"-->"+ma[n]);
if((ma[ma[n]]==n && (b&(1<<ma[n]))==0)||ma[n]==ma[a]){
//System.out.println(tal+" "+ma[a]+" "+n);
if(ma[ma[n]]==n && (b&(1<<ma[n]))==0)
hagale(n,b|(1<<n)|(1<<ma[n])|(1<<ma[a]),c+2,true);
else
hagale(n,b|(1<<n)|(1<<ma[a]),c+2,true);
}
}
return;
}
if((b&(1<<a))!=0)return;
hagale(ma[a],b|(1<<a),c+1,false);
}
public static int find(int a){
return a==pad[a]?a:find(pad[a]);
}
public static void union(int a, int b){
int pa = find(a);
int pb = find(b);
pad[pa]=pb;
}
public static void dfs2(int a,int b){
if(vis[a])return;
if(ma[ma[a]]==a){
remax = Math.max(remax,b);
}
//if(vis[a])return;
vis[a]=true;
dfs2(ma[a],b+1);
}
public static void dfs(int a,int b,int c){
//if(vis[a])return;
if(c>0 && a==b){
ciclomax = Math.max(ciclomax,c);
}
if(vis[a])return;
vis[a]=true;
dfs(ma[a],b,c+1);
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
