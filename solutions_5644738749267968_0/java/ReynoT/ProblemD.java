import java.io.*; 
import java.util.*; 
import java.text.DecimalFormat; 

public class ProblemD
{
    
    public static void main (String [] args) throws IOException
    {
      Scanner in = new Scanner (new FileReader ("D-small-attempt0.in")); 
      PrintWriter out = new PrintWriter (new FileWriter ("Dout.txt")); 
      int asdfg = in.nextInt (); 
      long time1 = System.currentTimeMillis ();
      for (int cases = 0; cases < asdfg; cases++)
      {
       int blocks = in.nextInt (); 
       ArrayList <Double> naomi = new ArrayList <Double> ();
       ArrayList <Double> ken = new ArrayList <Double> ();
       ArrayList <Double> naomi1 = new ArrayList <Double> ();
       ArrayList <Double> ken1 = new ArrayList <Double> ();
       double [] n = new double [blocks];
       double [] k = new double [blocks]; 
       for (int x = 0; x < blocks; x++)
       {
         n [x] = in.nextDouble ();  
       }
       for (int x = 0; x < blocks; x++)
       {
         k[x] = in.nextDouble ();  
       }
       Arrays.sort (n); 
       Arrays.sort (k); 
       
       
       for (int x = 0; x < blocks; x++)
       {
         naomi.add (new Double (n[x]));  
         ken.add (new Double (k[x]));  
         naomi1.add (new Double (n[x]));  
         ken1.add (new Double (k[x])); 
         
       }
       
       int z = 0; 
       
       lol:
       while (naomi.size () != 0)
       {
         for (int y = 0; y < ken.size (); y++)
         {
           
           if (ken.get(y).doubleValue () > naomi.get(0).doubleValue())
           {
             ken.remove (y); 
             naomi.remove (0); 
             continue lol;
           }
         }
         ken.remove (0); 
         naomi.remove (0); 
         z++; 
       }
       
       int y = 0; 
       
       lol1:
       while (naomi1.size () != 0)
       {
             for (int x = 0; x < naomi1.size (); x++)
             {
             if (ken1.get(ken1.size () - 1).doubleValue () < naomi1.get(x).doubleValue())
             {
             y++; 
             ken1.remove (ken1.size () - 1); 
             naomi1.remove (x);
             continue lol1;
             }
             }
           ken1.remove (ken1.size () - 1); 
           naomi1.remove (0); 
       }
       out.println ("Case #" + (cases + 1) + ": " + y + " " + z);
       
       
      }    
      in.close ();
      out.close ();
      System.out.println (System.currentTimeMillis () - time1); 
    }
}
