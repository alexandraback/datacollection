import java.util.*;

class Recycle{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int testcase, A, B;
    testcase = sc.nextInt();
    for(int i=1;i<=testcase;i++){
      A = sc.nextInt();
      B = sc.nextInt();
      System.out.println("Case #"+i+": "+countpair(A,B));
    }
  }
  
  public static int countpair(int A, int B){
    int numdigit, temp = A, temp2, counter;
    int[] remember;
    counter = 0;
    while(A<=B){
      remember = new int[7];
     numdigit = (int)Math.log10((double)A) + 1;
     temp = A;
     for(int i=0;i<numdigit;i++){
       temp2 = temp%10;
       temp/=10;
       temp+=temp2*(int)Math.pow(10,numdigit-1);

       if(check(temp, A, B, remember)){
         counter++;
       }
     }
     A++;
    }
    return counter;
  }
  
  public static boolean check(int checker, int A, int B, int[] remember){
    boolean checked = false;
    boolean alreadyhave = false;
    int i = 0;
      if(checker> A && checker<=B){
        for(i=0;i<remember.length;i++){
          if(remember[i] == checker){
            alreadyhave = true;
            break;
          }
        }
        if(!alreadyhave){
          i=0;
          while(remember[i]!=0)
            i++;
          remember[i] = checker;
          checked = true;
        } 
      }
    return checked;

  }
}
  