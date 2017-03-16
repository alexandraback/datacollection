import java.util.*;
import java.io.*;
public class A{
public static int min = Integer.MAX_VALUE;
public static int dp[] = new int[1000001];
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int cases = Integer.parseInt(lector.readLine());
Arrays.fill(dp,-1);
for(int c = 1;c<=cases;c++){
long res = 0;
int r = Integer.parseInt(lector.readLine());
min = Integer.MAX_VALUE;
res = jod(r,1);
System.out.println("Case #"+c+": "+res);
}
}
public static int jod(int a,int b){
if(b>min)return min+1;
if(a==1){
min = Math.min(min,b);
return 1;
}
if(dp[a]!=-1)return dp[a];
String aa = ""+a;
String ree = rev(aa);
int rev = Integer.parseInt(ree);
if(rev<a-1 && aa.charAt(aa.length()-1)!='0')
return dp[a]=Math.min(jod(rev,b+1),jod(a-1,b+1))+1;
else
return dp[a]=jod(a-1,b+1)+1;
}
public static String rev(String a){
String b = "";
for(int n = a.length()-1;n>-1;n--)b+=a.charAt(n);
return b;
}
}
