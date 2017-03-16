import java.util.*;

class D{

   public static int war(List<Double> A, List<Double> B){
      int score = 0;

      TreeSet<Double> tree = new TreeSet<Double>(B);

      for(Double x : A){
         Double upper = tree.higher(x);

         if(upper == null){
            score++;
            tree.remove(tree.first());
         }else{
            tree.remove(upper);
         }
      }

      return score;
   }

   public static void main(String args[]){
      Scanner in = new Scanner(System.in);

      int NC = in.nextInt();
      for(int nc=1;nc<=NC;nc++){
         int N = in.nextInt();
         List<Double> A = new LinkedList<Double>();
         List<Double> B = new LinkedList<Double>();

         for(int i=1;i<=N;i++)A.add(in.nextDouble());
         for(int i=1;i<=N;i++)B.add(in.nextDouble());

         int war_score = war(A,B);
         int deceitful_war_score = N - war(B,A);

         System.out.printf("Case #%d: %d %d\n",nc,deceitful_war_score,war_score);
      }
   }
}