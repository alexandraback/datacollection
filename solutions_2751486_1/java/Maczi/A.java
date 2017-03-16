
/************************
 * Maczko Istvan        *
 * Google Code Jam 2013 *
 * Online Round 1C      *
 * 13/05/12             *
 ************************/

import java.io.*;
import java.util.*;

class A
{
  public static String input = "A-large.in";
  public static String output = "A-large.out";

  // belso osztaly, valtozok..
  
  public static int T;
  
  
  
  public static String name;
  public static int n;
  public static long eredmeny;
  
  public static ArrayList<Integer> kezd;
  public static ArrayList<Integer> veg;
  
  
  
  public static BufferedReader be;
  public static BufferedWriter ki;
  public static String sor;
  public static StringTokenizer token;
  
  public static int nextInt() throws IOException
  {
    if(!token.hasMoreTokens()) { token = new StringTokenizer(be.readLine()); } // if nincs tobb..
    return Integer.parseInt(token.nextToken());
  } // nextInt()
  
  public static String nextString() throws IOException
  {
    if(!token.hasMoreTokens()) { token = new StringTokenizer(be.readLine()); } // if nincs tobb..
    return token.nextToken();
  } // nextString()
  
  
  
  public static boolean vovel(char c)
  {
    if('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c )
    {
      return true;
    }
    return false;
  }

  
  public static void main(String[] args) throws IOException, FileNotFoundException
  {
    
    int i, j, k;
    
    token = new StringTokenizer("");
    
    be = new BufferedReader(new FileReader(input));
    ki = new BufferedWriter(new FileWriter(output));
    
    
    T = nextInt();
    
    for(i = 1; i <= T; i ++) {
      
      name = nextString();
      n = nextInt();
      
      kezd = new ArrayList<Integer>();
      veg = new ArrayList<Integer>();
      
      j = 0;
      k = j;
      while(j <= (name.length() - n))
      {
        if( (k == (j + n - 1)) && (k < name.length()) && !vovel(name.charAt(k)) && !vovel(name.charAt(j)))
        {
          kezd.add(j);
          veg.add(k);
          //System.out.println("i[" + i + "]: jo: [" + j + "," + k + "]");
          j++;
          k++;
          continue;
        } // if jo
        
        if(k < j)
        {
          k = j;
          System.out.println("i[" + i + "]: Lemaradt k: " + k + ", j: " + j);
          continue;
        } // if lemaradt
        
        if(vovel(name.charAt(k)))
        {
          //System.out.println("i[" + i + "]: k[" + k + "] vovel: " + name.charAt(k));
          k++;
          j = k;
          continue;
        } // nem jo veg
        
        if(vovel(name.charAt(j)))
        {
          //System.out.println("i[" + i + "]: j[" + j + "] vovel: " + name.charAt(j));
          j++;
          continue;
        } // if nem kezd
        
        if(k > (j + n - 1)) 
        {
          System.out.println("i[" + i + "]: HIBA: tul nagy k: " + k + ", j: " + j);
          break;
        }
        
        //System.out.println("i[" + i + "]: k[" + k + "] novel");
        k++;
      } // while j jo intervallumok
      
      
      eredmeny = 0;
      k = 0;
      for(j = 0; j < name.length(); j++)
      {
        if(k >= kezd.size())
        {
          break;
        } // if nincs tobb
          
        if(j > kezd.get(k))
        {
          k++;
          if(k >= kezd.size())
          {
            break;
          } // if nincs tobb
        } // if kovetkezo intervallum
        
        eredmeny += (name.length() - veg.get(k));
        
        
      } // for j szamol
      
      
      
      ki.write("Case #" + i + ": " + eredmeny + "\n");
    } // for i
    
    
    ki.flush();
    ki.close();
    be.close();
    
  } // main
  
} // class A


