import java.util.*;
import java.io.*;
public class d{
public static boolean mat[][],mat2[][],vis[][];
public static boolean si = false;
public static int nn=0,mm=0,ceros=0,ceros1=0;
public static PrintWriter out = new PrintWriter(System.out);//HACER FLUSHHHH
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tt =Integer.parseInt(lector.readLine());
for(int cc =1;cc<tt+1;cc++){
System.out.println("Case #"+cc+":");
String p[] = lector.readLine().split(" ");
int a = Integer.parseInt(p[0]);
int b = Integer.parseInt(p[1]);
int c = a*b-Integer.parseInt(p[2]);
mat = new boolean[a][b];
si = false;
for(int n = 0;n<a && !si;n++)
for(int m = 0;m<b && !si;m++)
hagale(nn=n,mm=m,c);
if(!si)System.out.println("Impossible");
else{
for(int n = 0;n<a;n++,System.out.println())
for(int m =0;m<b;m++)
System.out.print((n==nn && m==mm?"c":(mat[n][m]?".":"*")));
}
}
}
public static void hagale(int a,int b,int c){
if(c==0){
ceros=0;
//System.out.println("llegue");
mat2 = new boolean[mat.length][mat[0].length];
si = true;
for(int n = -1;n<2 && si;n++)
for(int m = -1;m<2 && si;m++)
if(nn+n<mat.length && nn+n>-1 && mm+m<mat[nn].length && mm+m>-1 && !mat[nn+n][mm+m])
si = false;
for(int na = 0;na<mat.length;na++)
for(int ma = 0;ma<mat[na].length;ma++)
if(mat[na][ma]){
boolean ninguno = true;
boolean esCero = true;
for(int n = -1;n<2;n++)
for(int m = -1;m<2;m++){
if(na+n<mat.length && na+n>-1 && ma+m<mat[na].length && ma+m>-1){
if(mat[na+n][ma+m]){
boolean esChevere = true;
for(int nb = -1;nb<2 && esChevere;nb++)
for(int mb = -1;mb<2 && esChevere;mb++)
if(nb+n+na<mat.length && nb+n+na>-1 && mb+m+ma<mat[nb+na+n].length && mb+m+ma>-1 && !mat[nb+na+n][mb+ma+m])
esChevere =false;
if(esChevere)ninguno =false;
}else
esCero = false;
}
}
if(ninguno)si = false;
if(esCero){
mat2[na][ma]=true;
ceros++;
}
}
if(si){
vis = new boolean[mat2.length][mat2[0].length];
ceros1=0;
dfs(nn,mm);
//System.out.println(ceros+" "+ceros1);
//for(int n = 0;n<mat.length;n++,System.out.println())
//for(int m =0;m<mat[n].length;m++)
//System.out.print((n==nn && m==mm?"c":(mat[n][m]?".":"*")));
//for(int n = 0;n<mat.length;n++,System.out.println())
//for(int m =0;m<mat[n].length;m++)
//System.out.print(((mat2[n][m]?"0":"1")));
if(ceros!=ceros1)si=false;
}
return;
}
for(int n = -1;n<2 && !si;n++)
for(int m = -1;m<2 && !si;m++)
if(a+n<mat.length && a+n>-1 && b+m<mat[a].length && b+m>-1 && !mat[a+n][b+m]){
mat[a+n][b+m]=true;
hagale(a+n,b+m,c-1);
if(!si)
mat[a+n][b+m]=false;
}
}
public static void dfs(int a,int b){
//	if(vis[a][b])return;
ceros1++;
vis[a][b]=true;
for(int n = -1;n<2;n++)
for(int m = -1;m<2;m++)
if(a+n<mat.length && a+n>-1 && b+m<mat[a].length && b+m>-1 && mat2[n+a][m+b] && !vis[n+a][m+b])
dfs(n+a,m+b);
}
}
