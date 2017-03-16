import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.io.BufferedReader;

public class A{
  public static void main(String[] args){
    precompute(1000001);
    
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      int n=scanner.nextInt();
      System.out.println("Case #"+(t+1)+": "+solve(n));
    }
  }

  private static int solve(int n){
    return distance[n];
  }

  private static void precompute(int N){
    distance=new int[N];
    for(int i=0;i<N;i++)
      distance[i]=UNSEEN;
    Queue<Integer> q=new LinkedList<Integer>();
    distance[1]=1;
    q.add(1);
    while(!q.isEmpty()){
      int current=q.poll();
      int d=distance[current];

      int next=current+1;
      if(next<N && distance[next]==UNSEEN){
        int nd=d+1;
        distance[next]=nd;
        q.add(next);
      }
      next=reverse(current);
      if(next<N && distance[next]==UNSEEN){
        int nd=d+1;
        distance[next]=nd;
        q.add(next);
      }
    }
  }

  private static int reverse(int n){
    int result=0;
    while(n>0){
      result=10*result+(n%10);
      n/=10;
    }
    return result;
  }

  private static int[] distance;
  private static final int UNSEEN=-1;
}
