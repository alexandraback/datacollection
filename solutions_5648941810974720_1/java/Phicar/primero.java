import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class primero{
public static long mod = 1000000007;
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
//String tmp[] = lector.readLine().split(" ");
int cas = Integer.parseInt(lector.readLine());
for(int cc = 0;cc<cas;cc++){
int res[] = new int[10];
String a = lector.readLine().toLowerCase();
int tal[] = new int[26];
for(int n = 0;n<a.length();n++)tal[a.charAt(n)-'a']++;
String orden="0246857913";
String nom[] = {"zero","two","thrE","four","six","eight","sEvn","five","Nie","one"};
for(int n =0;n<orden.length();n++){
int min = Integer.MAX_VALUE;
for(int m = 0;m<nom[orden.charAt(n)-'0'].length();m++){
int y = nom[orden.charAt(n)-'0'].charAt(m)<'a'?2:1;
char yy = nom[orden.charAt(n)-'0'].charAt(m)<'a'?(char)(nom[orden.charAt(n)-'0'].charAt(m)-'A'+'a'):nom[orden.charAt(n)-'0'].charAt(m);
min = Math.min(tal[yy-'a']/y,min);
}
res[orden.charAt(n)-'0']+=min;
//for(int r = 0;r<min;r++)res+=orden.charAt(n);
for(int m = 0;m<nom[orden.charAt(n)-'0'].length();m++){
int y = nom[orden.charAt(n)-'0'].charAt(m)<'a'?2:1;
char yy = nom[orden.charAt(n)-'0'].charAt(m)<'a'?(char)(nom[orden.charAt(n)-'0'].charAt(m)-'A'+'a'):nom[orden.charAt(n)-'0'].charAt(m);
tal[yy-'a']-=min*y;
}
}
String ress = "";
for(int n = 0;n<10;n++)
	for(int m = 0;m<res[n];m++)ress+=n;
System.out.println("Case #"+(cc+1)+": "+ress);	
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