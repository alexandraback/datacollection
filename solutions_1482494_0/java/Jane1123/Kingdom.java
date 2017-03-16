import java.util.*;
import java.io.*;

public class Kingdom{
  private static int min_times = Integer.MAX_VALUE;
  
  private static void go(int level, int locTimes, boolean[] oneStar, boolean[] twoStars, int locStar, int[] A, int[] B){
      int i = 0;
      for(i = 0; i < twoStars.length; i ++){
          if(twoStars[i] == false)
              break;
      }
      if(i == twoStars.length){
          if(locTimes < min_times){
              min_times = locTimes; 
          }
          return;
      }//if
      
      boolean isFound = false; int N = oneStar.length;
      for(i = 0; i < N; i ++){
          if(twoStars[i] == false && oneStar[i] == false && locStar >= A[i]){
              boolean[] oneStar1 = new boolean[N];
              boolean[] twoStars1 = new boolean[N];
              for(int i2 = 0; i2 < N; i2 ++){
                  oneStar1[i2] = oneStar[i2];
                  twoStars1[i2] = twoStars[i2];
              }
              oneStar1[i] = true;
              isFound = true;
              //System.out.println(locTimes);
              go(i, locTimes+1, oneStar1, twoStars1, locStar+1, A, B);
          }
          
          if(twoStars[i] == false && oneStar[i] == true && locStar >= B[i]){
              boolean[] oneStar1 = new boolean[N];
              boolean[] twoStars1 = new boolean[N];
              for(int i2 = 0; i2 < N; i2 ++){
                  oneStar1[i2] = oneStar[i2];
                  twoStars1[i2] = twoStars[i2];
              }
              twoStars1[i] = true;
              isFound = true;
              //System.out.println(locTimes);
              go(i, locTimes+1, oneStar1, twoStars1, locStar+1, A, B);
          }
          
          if(twoStars[i] == false && oneStar[i] == false && locStar >= B[i]){
              boolean[] oneStar1 = new boolean[N];
              boolean[] twoStars1 = new boolean[N];
              for(int i2 = 0; i2 < N; i2 ++){
                  oneStar1[i2] = oneStar[i2];
                  twoStars1[i2] = twoStars[i2];
              }
              twoStars1[i] = true;
              isFound = true;
              //System.out.println(locTimes);
              go(i, locTimes+1, oneStar1, twoStars1, locStar+2, A, B);
          }
          
      }//for
      
      if(isFound == false){
          min_times = Integer.MAX_VALUE;
          return;
      }
  }
  
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
        min_times = Integer.MAX_VALUE;
        
        line = txtFile.readLine();
        int N = Integer.parseInt(line);
        
        int[] A = new int[N];
        int[] B = new int[N];        
        
        for(int i1 = 0; i1 < N; i1 ++){
            line = txtFile.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            A[i1] = Integer.parseInt(st.nextToken());
            B[i1] = Integer.parseInt(st.nextToken());
        }//for
        
        boolean[] oneStar = new boolean[N];
        boolean[] twoStars = new boolean[N];
        for(int i1 = 0; i1 < N; i1 ++){
            oneStar[i1] = false;
            twoStars[i1] = false;
        }
        int locStar = 0; int locTimes = 0;
        
        while(true){
        
        int i1 = 0;
        for(i1 = 0; i1 < N; i1 ++){
            if(twoStars[i1] == false)
                break;
        }
        if(i1 == N){
            System.out.println("Case #"+Integer.toString(i+1)+": "+Integer.toString(locTimes));
            break;
        }//if
        
        
        for(i1 = 0; i1 < N; i1 ++){
            if(locStar >= B[i1] && oneStar[i1] == false && twoStars[i1] == false)
                break;
        }
        if(i1 < N){
            locStar += 2; locTimes ++;
            twoStars[i1] = true;
        }
        else{
            for(i1 = 0; i1 < N; i1 ++){
                if(locStar >= B[i1] && oneStar[i1] == true && twoStars[i1] == false)
                    break;
            }
            if(i1 < N){
                locStar += 1; locTimes ++;
                twoStars[i1] = true;
            }
            else{
                for(i1 = 0; i1 < N; i1 ++){
                    if(locStar >= A[i1] && oneStar[i1] == false)
                        break;
                }
                if(i1 < N){
                    locStar += 1; locTimes ++;
                    oneStar[i1] = true;
                }
                else{
                    System.out.println("Case #"+Integer.toString(i+1)+": Too Bad");
                    break;
                }
            }
        }
        
        }//while(1)
       

      }//for(int i = 0; i < T; i ++)
    }//try
    catch(IOException e) {
	e.printStackTrace();
    }
    
    
  }
}
