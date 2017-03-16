import java.util.Scanner;
import java.io.BufferedReader;

public class C{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    inialize();

    for(int t=0;t<cases;t++){
      System.out.println("Case #"+(t+1)+": "+(solve(scanner)?"YES":"NO"));
    }
  }

  private static class quaternion{
    public quaternion(int value,boolean positive){
      this.value=value;
      this.positive=positive;
    }

    public void negate(){
      positive=!positive;
    }

    public quaternion copy(){
      return new quaternion(value,positive);
    }

    public boolean equals(quaternion a){
      return value==a.value && positive==a.positive;
    }

    public int value;
    public boolean positive;
  };

  private static final quaternion ONE=new quaternion(0,true);
  private static final quaternion NONE=new quaternion(0,false);
  private static final quaternion I=new quaternion(1,true);
  private static final quaternion NI=new quaternion(1,false);
  private static final quaternion J=new quaternion(2,true);
  private static final quaternion NJ=new quaternion(2,false);
  private static final quaternion K=new quaternion(3,true);
  private static final quaternion NK=new quaternion(3,false);

  private static quaternion[] ALL=new quaternion[8];
  private static quaternion[][] M=new quaternion[4][4];
  private static quaternion[] CHARACTER_GOAL=new quaternion[3];
  
  private static void inialize(){
    CHARACTER_GOAL[0]=I;
    CHARACTER_GOAL[1]=J;
    CHARACTER_GOAL[2]=K;

    ALL[0]=ONE;
    ALL[1]=NONE;
    ALL[2]=I;
    ALL[3]=NI;
    ALL[4]=J;
    ALL[5]=NJ;
    ALL[6]=K;
    ALL[7]=NK;

    M[0][0]=ONE;
    M[0][1]=I;
    M[0][2]=J;
    M[0][3]=K;

    M[1][0]=I;
    M[1][1]=NONE;
    M[1][2]=K;
    M[1][3]=NJ;

    M[2][0]=J;
    M[2][1]=NK;
    M[2][2]=NONE;
    M[2][3]=I;

    M[3][0]=K;
    M[3][1]=J;
    M[3][2]=NI;
    M[3][3]=NONE;
  }

  private static quaternion multiply(quaternion a,quaternion b){
    quaternion result=M[a.value][b.value].copy();
    if(!a.positive)
      result.negate();
    if(!b.positive)
      result.negate();
    return result;
  }

  // a * result = b
  private static quaternion divide(quaternion a,quaternion b){
    for(int i=0;i<ALL.length;i++)
      if(multiply(a,ALL[i]).equals(b))
        return ALL[i];
    throw new RuntimeException();
  }

  private static int index(quaternion a){
    for(int i=0;i<ALL.length;i++)
      if(ALL[i].equals(a))
        return i;
    throw new RuntimeException();
  }

  private static quaternion get(char c){
    if(c=='i') return I;
    if(c=='j') return J;
    if(c=='k') return K;
    throw new RuntimeException();
  }

  private static boolean compute(int all_index,int character,int n,String s){
    if(character>2) return false;
    if(n==s.length()){
      if(character!=2)
        return false;
      return ALL[all_index].equals(CHARACTER_GOAL[2]);
    }

    if(n>s.length())
      throw new RuntimeException();

    if(ALL[all_index].equals(CHARACTER_GOAL[character]) && character!=2){
      boolean next=answer[0][character+1][n];
      if(next)
        return true;
    }

    quaternion now=ALL[all_index];
    int nai=index(multiply(now,get(s.charAt(n))));
    //if(all_index==0 && character==2 && n==2)
      //System.out.println(" sp nai: "+nai);
      //System.out.println(" char: "+s.charAt(n));
    return answer[nai][character][n+1];
  }

  private static boolean answer[][][];

  private static boolean solve(Scanner scanner){
    scanner.nextInt();
    int copies=scanner.nextInt();
    String start=scanner.next();
    StringBuilder sb=new StringBuilder();
    for(int i=0;i<copies;i++)
      sb.append(start);

    String s=sb.toString();

    answer=new boolean[ALL.length][3][s.length()+1];

    for(int n=s.length();n>=0;n--)
      for(int character=2;character>=0;character--)
        for(int index=0;index<ALL.length;index++){
          answer[index][character][n]=compute(index,character,n,s);
          //System.out.println(" "+index+", "+character+", "+n+": "+answer[index][character][n]);
        }
    return answer[0][0][0];
  }
}
