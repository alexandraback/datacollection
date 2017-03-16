import java.util.*;
import java.io.*;
public class BC{
public static PrintWriter out = new PrintWriter(System.out);//HACER FLUSHHHH
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int tmp =Integer.parseInt(lector.readLine());
for(int a = 1;a<=tmp;a++){
int res = 0;
String t[] = lector.readLine().split(" ");
int c = Integer.parseInt(t[2]);
for(int n = 0;n<Integer.parseInt(t[0]);n++)
for(int m = 0;m<Integer.parseInt(t[1]);m++)
if((n&m)<c)res++;
System.out.println("Case #"+a+": "+res);
}
}

}
