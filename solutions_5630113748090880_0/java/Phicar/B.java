import java.math.*;
import java.util.*;
import java.io.*;
public class B{
public static int map[][];
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int ca = Integer.parseInt(lector.readLine());
for(int c = 0;c<ca;c++){
String res ="";
int a = Integer.parseInt(lector.readLine());
map= new int[2*a-1][a];
int cant[] = new int[2501];
for(int n = 0;n<2*a-1;n++){
String t[]= lector.readLine().split(" ");
for(int m = 0;m<t.length;m++){
map[n][m]=Integer.parseInt(t[m]);
cant[map[n][m]]++;
}
}

/*boolean nada = false;
for(int n = 0;n<a && !nada;n++){
for(int m = 0;m<2*a-1;m++){//la mesima en pos n
boolean pues[] =new boolean[2*a-1];
int last = -1;
for(int r =0;r<a;r++){//
int bus = map[m][r];
boolean pudelocal = false;
for(int k = 0;k<2*a-1 && !pudelocal;k++)
if(!pues[k] && map[k][n]==bus && cumple(last,k)){
pudelocal = true;
last = k;
}
if(!pudelocal)nada = true;
}

}

}*/
Vector<Integer> tal = new Vector<Integer>();
for(int n =0;n< cant.length;n++)
if(cant[n]%2==1)tal.add(n);
Collections.sort(tal);
for(int n = 0;n<a;n++)
res+=tal.get(n)+" ";
System.out.println("Case #"+(c+1)+": "+res.substring(0,res.length()-1));
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
