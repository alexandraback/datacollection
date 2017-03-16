import java.util.*;
class B{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int testcase,level,stars,numgame,max,remember;
    int[][] levels;
    testcase = sc.nextInt();
    boolean finished=false,found=false;
    for(int i=1;i<=testcase;i++){
      
      stars = 0;
      level = sc.nextInt();
      levels = new int[level][3];
      for(int j=0;j<level;j++){
        levels[j][0] = sc.nextInt();
        levels[j][1] = sc.nextInt();
      }
      numgame = 0;
      while(true){
        max = 0;
        remember = -1;
        found = false;
        finished = false;
        for(int k=0;k<level;k++){
          if(stars>=levels[k][1] && levels[k][2]==0){
            finished = true;
            stars+=2;
            levels[k][2] = 2;
            found = true;
            numgame++;
          }
        }
        if(!found){
          for(int k=0;k<level;k++){
            if(stars>=levels[k][1] && levels[k][2]==1){
              finished = true;
              stars++;
              levels[k][2] = 2;
              found = true;
              numgame++;
              break;
            }
          }
        }
        if(!found){
          for(int k=0;k<level;k++){
            if(stars>=levels[k][0] && levels[k][2]==0){
              if(levels[k][1]>max){
                max = levels[k][1];
                remember = k;
              }
            }
          }
          if(remember>=0){
              finished = true;
              stars++;
              levels[remember][2] = 1;
              numgame++;
              found = true;
          }
        }
            
        
        if(!finished)
          break;
        
        if(stars==2*level){
          finished = true;
          break;
        }
      }
      
      
      System.out.print("Case #"+i+": ");
      if(finished){
        System.out.println(numgame);
      }
      else{
        System.out.println("Too Bad");
      }
    }
  }
}