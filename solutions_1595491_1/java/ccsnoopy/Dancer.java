import java.util.*;

class Dancer{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int testcase, numdancer, surprise, limit, counter, score;
    testcase = sc.nextInt();
    for(int i=1;i<=testcase;i++){
      counter = 0;
      System.out.print("Case #"+i+": ");
      numdancer = sc.nextInt();
      surprise = sc.nextInt();
      limit = sc.nextInt();
      for(int j=0;j<numdancer;j++){
        score = sc.nextInt();
        if(score==0){
          if(limit==0)
          counter++;
        }
        else if(score==1){
          if(limit <= 1)
          counter++;
        }
        else if(score == 2){
          if(limit<=1)
            counter++;
          else if(limit==2 && surprise>0){
            counter++;
            surprise--;
          }
        }
        else{
          switch(score%3){
            case 0:{
              if(score/3 >= limit)
              counter++;
              else if(surprise>0 && (score/3) + 1 >= limit){
                counter++;
                surprise--;
              }
            
            break;
            }
            case 1:{
              if((score/3)+1 >=limit)
                counter++;
              break;
            }
            case 2:{
              if((score/3)+1>=limit)
                counter++;
              else if(surprise>0 && (score/3)+2>=limit){
                counter++;
                surprise--;
              }
                break;
            }
          }
        }
      }
      System.out.println(counter);
    }
  }
}