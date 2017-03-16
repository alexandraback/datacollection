import java.util.*;
import java.io.*;
public class c{
public static PrintWriter out = new PrintWriter(System.out);//HACER FLUSHHHH
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tmp =Integer.parseInt(lector.readLine());
for(int c = 1;c<=tmp;c++){
int pa = 0,pb=0;
int a = Integer.parseInt(lector.readLine());
double na[] = new double[a];
double ke[] = new double[a];
String t[] = lector.readLine().split(" ");
for(int n = 0;n<na.length;n++)
na[n]=Double.parseDouble(t[n]);
t = lector.readLine().split(" ");
for(int n = 0;n<na.length;n++)
ke[n]=Double.parseDouble(t[n]);
Arrays.sort(na);
Arrays.sort(ke);
int nap[] = {0,a-1};
int kap[] = {0,a-1};
boolean us[] = new boolean[a];
for(int p = 0;p<a;p++){
if(na[nap[1]]>=ke[kap[1]]){
pa++;
nap[1]--;
kap[1]--;
}else{
nap[0]++;
kap[1]--;
}
boolean encontro = false;
for(int m = 0;m<a && !encontro;m++){
if(ke[m]>=na[p] && !us[m]){
encontro = true;
us[m]=true;
}
}
if(!encontro)pb++;
}

System.out.println("Case #"+c+": "+pa+" "+pb);
}

}

}
