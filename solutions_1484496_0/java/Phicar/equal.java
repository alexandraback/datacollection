import java.util.*;
import java.io.*;
public class equal{
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tod = Integer.parseInt(lector.readLine());
//HashMap<Long,Vector<Integer>> tal = new HashMap<Long,Vector<Integer>>();
for(int i = 0;i<tod;i++){
HashMap<Long,Vector<Integer>> tal = new HashMap<Long,Vector<Integer>>();
System.out.println("Case #"+(i+1)+":");
String jod = lector.readLine();
String tmp[] = jod.split(" ");
//System.out.println(jod);
boolean sicas = false;
for(int n = 1;n<(1<<(tmp.length-1));n++){
long sum = 0;
Vector<Integer> tm = new Vector<Integer>();
for(int m = 0;m<(tmp.length-1);m++){
if(((n>>m)&1)==1){
tm.add(Integer.parseInt(tmp[m+1]));
sum+=Long.parseLong(tmp[m+1]);
}
}
//System.out.println(tm);
if(sum>0 && tal.get(sum)!=null){
imprimir(tal.get(sum));
imprimir(tm);
sicas = true;
break;
}else
tal.put(sum,tm);
}
if(!sicas)System.out.println("Impossible");
}
}
public static void imprimir(Vector<Integer> a){
Collections.sort(a);
for(int n = 0;n<a.size();n++)
System.out.print(a.get(n)+((n==a.size()-1)?"":" "));
System.out.println();
} 
}
