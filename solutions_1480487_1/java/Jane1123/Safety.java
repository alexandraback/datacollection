import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class Safety{
  
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
        int N = Integer.parseInt(st.nextToken());
        int[] J = new int[N]; int X = 0;
        for(int j = 0; j < N; j ++){
            J[j] = Integer.parseInt(st.nextToken());
            X += J[j];
        }
        
        double[] diff = new double[N]; double sum = 0.0;
        for(int j = 1; j < N; j ++){ //Y_j - Y_0
            diff[j] = (J[0]-J[j])/(double)X; sum += diff[j];
            //System.out.println(diff[j]);
        }
        //System.out.println(sum);
        double[] result = new double[N]; 
        for(int j = 0; j < N; j ++) result[j] = 1;
        int N0 = N;
        int start = 0;
        while(true){
            //if(sum <= 1){
                result[start] = (1-sum)/(double)N0; boolean recompute = false;
                //System.out.println(result[start]);
                if(result[start] < 0) { result[start] = 0; recompute = true; }
                for(int j = start+1; j < N; j ++){
                    if(result[j] != 0){
                        result[j] = result[start] + diff[j];
                        //System.out.println(result[j]);
                        if(result[j] < 0) { result[j] = 0; recompute = true;}
                    }
                }
                if(recompute == false) break;
            //}
            //else{
                start = 0; N0 = 0;
                for(int j = 0; j < N; j ++){
                    if(result[j] != 0) { start = j; N0 ++; break;}
                }
                sum = 0.0;
                for(int j = start + 1; j < N; j ++){ //Y_j - Y_0
                    if(result[j] != 0){
                        diff[j] = (J[start]-J[j])/(double)X; 
                        N0 ++;
                        sum += diff[j];
                    }
                    //System.out.println(diff[j]);
                }
                //for(int j = 0; j < N; j ++)
                //System.out.println(diff[j]);
                //N = N0;
                
            //}
        }

        System.out.print("Case #"+Integer.toString(i+1)+":");
        for(int j = 0; j < N; j ++)
            System.out.print(" "+result[j]*100);
        System.out.println();
      }//for(int i = 0; i < T; i ++)
    }//try
    catch(IOException e) {
	e.printStackTrace();
    }    
  }
}
