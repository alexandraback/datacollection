import java.io.*;
import java.util.StringTokenizer;

public class main_class
{
    public static void main(String []args)
    {
        try{
            FileInputStream fstream = new FileInputStream("C:/Users/klick the Bond/Downloads/A-small-attempt1.in");
              DataInputStream in = new DataInputStream(fstream);
              BufferedReader br = new BufferedReader(new InputStreamReader(in));
              String strLine,strnext_line;
              int n=0;
              int i;
            while ((strLine = br.readLine()) != null)
            {
                n=n+1;
                if (n==1) i = Integer.parseInt(strLine);
                else 
                {
                    
                    System.out.println(parse(strLine , n - 1));
                }
            }
  in.close();
    }catch (Exception e){//Catch exception if any
  System.err.println("Error: " + e.getMessage());
  }
    }

    private static String parse(String string1,int oo)
    {
        String str="";

        int i =0;
        int j = 0;
        int c = 0;
        int b = 0;

        double sum = 0;
        double[] p = new double[100000];
        double[] ans = new double[100000];
        double[] chote = new double[100000];
        double[] bade = new double[100000];
        int count=0;
        double chota_sum =0;
        
        String Ansstring = "";




        float[] E = new float[100000];
        float p1 = 0;
        float p2 = 0;
        float p3 = 0;
        float result = 0;

        float E1=0,E2=0,E3=0,E4=0,E5=0;


  	  StringTokenizer stringTokenizer = new  StringTokenizer(string1);
  	  	while(stringTokenizer.hasMoreTokens())
		  {
		  
                    p[i] = Float.parseFloat(stringTokenizer.nextToken());
                    i=i+1;
		  }



for (int k = 0; k < p[0] ;k++)
{
    sum = sum + p[k+1];
}



for (int l = 1; l < (p[0] + 1) ;l++)
{
    ans[l] = ( ( ((2*sum)/p[0]) - p[l] ) / sum )*100 ;

    if(ans[l]<0)
    {
        ans[l] = 0;
        count++;
    }
    else
    {
        chota_sum = chota_sum + p[l];
    }


}

for (int l = 1; l < (p[0] + 1) ;l++)
{
    if(ans[l]!=0)
    {
        ans[l] = ( ( ((chota_sum + sum)/(p[0]-count)) - p[l] ) / sum )*100 ;
    }
    if(ans[l]<0)
    {
        ans[l] = 0;
    }


}


for (int l = 1; l < (p[0] + 1) ;l++)
{

Ansstring = Ansstring + " "+String.format( "%3.6f", (ans[l]));

}





            
        return "Case #"+oo+":"+Ansstring;
     }





}