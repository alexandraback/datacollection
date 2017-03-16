
package urtbest;


import java.awt.Point;
import java.io.*;
import java.io.ObjectInputStream.GetField;
import java.sql.Array;
import java.util.*;
import java.util.jar.Attributes.Name;
import java.util.logging.Level;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
import javax.swing.text.MaskFormatter;
 
 
 
 
 
 
 
 class TestClass {
 
static long mod ;
static long[] A;
static ArrayList<Integer>[] maps; 
static boolean[][] dp;
static int z;
static int[][] V;
static int[] P;
static boolean[] pos;
static int nextnode;
static int max;
static boolean important;
 
 
 
public static boolean is_path(int s, int t , int n){
    
     int[] X = new int[n];
     Stack<Integer> Q = new Stack<>();
     Q.add(s);
     X[s]=1;
     P[s]=-1;
     while(!Q.isEmpty()){
         
         
          int x = Q.pop();
          
          for(int i=0;i<n;i++){
             // System.out.println(V[x][i]+" "+X[i]);
              if(V[x][i]>0 && X[i]!=1){
                  P[i]=x;
                  X[i]=1;
                  Q.add(i);
              }
          }
          
     }
   
     return X[t]==1;
}
 
 
public static int max_flow(int s , int t, int n){
    
      int flow =0;
      
      P = new int[n];
      while(is_path(s, n/2+t, n)){
          
            int x = t;
            int f = Integer.MAX_VALUE;
            
            while(P[x]!=-1){
              
                f = Math.min(f,V[P[x]][x]);
                x = P[x];
                
            }
          
             x = t;
               
            while(P[x]!=-1){
                
               V[P[x]][x]-=f;
               V[x][P[x]]+=f;
                x = P[x];
                
                
            }
            flow+=f;
            
            
          
      }
      
      
      return flow;
    
    
    
}
 
public static int search (String S){
    
    
    if(S.toLowerCase().equals("is") || S.toLowerCase().equals("est") || S.toLowerCase().equals("ist") || S.toLowerCase().equals("es"))
        important = true;
    
    if(S.toLowerCase().equals("is") || S.toLowerCase().equals("in") || 
         S.toLowerCase().equals("the")|| S.toLowerCase().equals("to") || S.toLowerCase().equals("she")||S.toLowerCase().equals("he"))
        return 0;
    
     if(S.toLowerCase().equals("est") || S.toLowerCase().equals("dans") || 
         S.toLowerCase().equals("la")|| S.toLowerCase().equals("Ã�ï¿½Ã¯Â¿Â½Ã�Â¯Ã�Â¿Ã�Â½ ") || S.toLowerCase().equals("elle")||S.toLowerCase().equals("il"))
         return 1;
         
     
      if(S.toLowerCase().equals("ist") || S.toLowerCase().equals("im") || 
         S.toLowerCase().equals("das")|| S.toLowerCase().equals("nach") || S.toLowerCase().equals("sie")||S.toLowerCase().equals("er"))
         return 2;
      
       if(S.toLowerCase().equals("es") || S.toLowerCase().equals("en") || 
         S.toLowerCase().equals("el") || S.toLowerCase().equals("ella")||S.toLowerCase().equals("Ã�ï¿½Ã¯Â¿Â½Ã�Â¯Ã�Â¿Ã�Â½Ã�ï¿½Ã¯Â¿Â½Ã�ï¿½Ã�Â©l"))
         return 3;
       
       return 4;
    
    
}
 
 
public static void generate_me(int curr , int n , int k, String S, String temp, int c){
    
      if(k<0) return ;
      
      
          boolean found = false;
          for(int i=1;i<10 && !found;i++){
              
              for(int j=0;j<temp.length() &&j+2*i<temp.length();j++){
                if(temp.charAt(j)==temp.charAt(j+i)&& temp.charAt(j)==temp.charAt(j+i+i)) found = true;
              }
              
          }
          if(found) return ;
      
      
      
      if(curr==n){
        
          
          z++;
          return ;
      }
      
      for(int i=0;i<c;i++){
          int x = S.charAt(curr);
          int y = 'a'+i;
         
          if(x!=y && x<='c') 
          {  
             
              generate_me(curr+1, n, k-1, S, temp+(char)('a'+i),c);
          
          }
          else generate_me(curr+1, n, k, S,temp+(char)('a'+i),c);
      }
}


public static double super_pow(double A , long B){
    
      double o=1;
      
      while(B>0){
          
          if((B&1)!=0) o*=A;
          
          A*=A;
          B/=2;
          o%=mod;
          A%=mod;
        
      }
    
      return o%mod;
}

 
public static void main(String args[] ) throws java.lang.Exception {
 
 
 
//InputStream inputStream = System.in;
//InputReader in = new InputReader(inputStream);
 
//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\Sompathak\\Desktop\\yes.txt"));
Scanner in = new Scanner(new FileReader("C:\\Users\\Sompathak\\Desktop\\yes.java"));
 PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\sompathak\\Desktop\\output.txt"));
//InputStream inputStream = System.in;
//InputReader in = new InputReader(inputStream);
//Scanner in = new Scanner(new InputStreamReader(System.in));
// Scanner in = new Scanner(new FileReader("C:\\Users\\sompatha\\Desktop\\yes.txt"));
//we can we will ??? !!!!!! SOM RISES
//long startTime = System.currentTimeMillis();
//long startTime = System.currentTimeMillis();
 
//float endTime   = System.currentTimeMillis();
//float totalTime = (endTime - startTime)/(float)1000;
//System.out.println(totalTime+" sec....."); 
 
// {is, in ,the ,to ,he ,she}
mod=1000000007;
int t = in.nextInt();
int cases =0;
while(t>0){
  t--;
  cases++;
  pw.print("Case #"+cases+": ");
  int n = in.nextInt();
  int[] F = new int[2501];
  int[][] pos = new int[2501][n];
  for(int i=1;i<2*n;i++){
    
    for(int j=0;j<n;j++){
      
      int x = in.nextInt();
      F[x]++;
      
      
    }
  }
  ArrayList<Integer> ans =new ArrayList<Integer>();
    for(int j=0;j<2501;j++){
      if(F[j]%2==0)continue;
       ans.add(j);
      
    }
    Collections.sort(ans);
    for(int i:ans)
      pw.print(i+" ");
  pw.println();
  pw.flush();
}
 pw.flush();


 
}public static class InputReader
{
private InputStream stream;
private byte[] buf = new byte[1024];
private int curChar;
private int numChars;
private SpaceCharFilter filter;
 
public InputReader(InputStream stream)
{
this.stream = stream;
}
 
public int read()
{
if (numChars == -1)
throw new InputMismatchException();
if (curChar >= numChars)
{
curChar = 0;
try
{
numChars = stream.read(buf);
} catch (IOException e)
{
throw new InputMismatchException();
}
if (numChars <= 0)
return -1;
}
return buf[curChar++];
}
 
public int nextInt()
{
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-')
{
sgn = -1;
c = read();
}
int res = 0;
do
{
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
 
public String readString()
{
int c = read();
while (isSpaceChar(c))
c = read();
StringBuilder res = new StringBuilder();
do
{
res.appendCodePoint(c);
c = read();
} while (!isSpaceChar(c));
return res.toString();
}
public double readDouble() {
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
double res = 0;
while (!isSpaceChar(c) && c != '.') {
if (c == 'e' || c == 'E')
return res * Math.pow(10, nextInt());
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
}
if (c == '.') {
c = read();
double m = 1;
while (!isSpaceChar(c)) {
if (c == 'e' || c == 'E')
return res * Math.pow(10, nextInt());
if (c < '0' || c > '9')
throw new InputMismatchException();
m /= 10;
res += (c - '0') * m;
c = read();
}
}
return res * sgn;
}
public long readLong() {
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
long res = 0;
do {
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
public boolean isSpaceChar(int c)
{
if (filter != null)
return filter.isSpaceChar(c);
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
public String next()
{
return readString();
}
 
public interface SpaceCharFilter
{
public boolean isSpaceChar(int ch);
}
}
}                        