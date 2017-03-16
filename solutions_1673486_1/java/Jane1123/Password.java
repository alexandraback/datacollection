import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class Password{
  
  public static void main(String[] args){
    try{
      FileReader fin = new FileReader(args[0]);
      BufferedReader txtFile = new BufferedReader(fin);
    
      //FileWriter fout = new FileWriter(args[1]);
      //BufferedWriter out = new BufferedWriter(fout);
			
      String line = null;     
      line = txtFile.readLine();
      int T = Integer.parseInt(line);
      //System.out.println(T);
      for(int i = 0; i < T; i ++){
        line = txtFile.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        
        double[] p = new double[A];
        line = txtFile.readLine();
        st = new StringTokenizer(line, " ");        
        for(int i1 = 0; i1 < A; i1 ++)
            p[i1] = Double.parseDouble(st.nextToken());           
        
        double[] psum = new double[A];
        for(int i1 = 0; i1 < A; i1 ++){
            psum[i1] = 1.0;
            for(int i2 = 0; i2 <= i1; i2 ++)
                psum[i1] *= p[i2];
        }
        //psum[A] = 1;
        
        double avg = psum[A-1] * (B-A+1) + (1-psum[A-1]) * (B-A+1+B+1);
        int k = 1;
        for(int i1 = A-2; i1 >= 0; i1 --){
            double tmp = psum[i1] * (2*k+B-A+1) + (1-psum[i1]) * (2*k+B-A+1+B+1);
            k ++;
            if(tmp < avg)
                avg = tmp;
        }//for
        
        //System.out.println(avg);
        
        if(avg > 2*A+B-A+1)
            avg = 2*A+B-A+1;
            
        //System.out.println(avg);
        if(avg > 1+B+1)
            avg = 1+B+1;
            
        //System.out.println(avg);
        DecimalFormat df = new DecimalFormat(".######");
        System.out.println("Case #"+Integer.toString(i+1)+": "+df.format(avg));
      }//for(int i = 0; i < T; i ++)
    }//try
    catch(IOException e) {
	e.printStackTrace();
    }    
  }
}
