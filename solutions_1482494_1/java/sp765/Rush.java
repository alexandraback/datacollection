import java.util.*;
import java.lang.*;

//Google Code Jam 2012. Round 1A, Problem B

public class Rush
{
    static int min;
    public static void try_all(int N, int count, int stars, int[] a, int[] b, int[] c){
 //           System.out.println(count + " " + stars);
            int i;
            for(i = 0; i < N; i++)
                if(c[i]!=2)
                    break;
            if(i==N){
               // System.out.println(" yo " + count + " " + min);
                min = Math.min(min,count);
                return; // finished game
            }

            int index = -1, maxStarGain = 0;

            for(i = 0; i < N; i++){
            if(c[i]==0 && stars >= b[i]){  // complete with star 2
                c[i] = 2; stars += 2;
                try_all(N,count+1,stars,a,b,c);
                return;
            } 
            }
 
            int maxB = -1; 

            for(i = 0; i < N; i++){
            if(c[i]==1 && stars >= b[i]){  // complete with star 2
                c[i] = 2; stars++;
                try_all(N,count+1,stars,a,b,c);
                return;
            } 
            }

            for(i = 0; i < N; i++){
            if(c[i] == 0 && stars >= a[i]) // complete with star 1
            {
                if (b[i] > maxB)//(a[i] < minStarReq || (a[i] <= minStarReq && 1 >= maxStarGain))
                {
                    index = i; maxB = b[i];
                //    minStarReq = a[i];
                //    maxStarGain = 1;
                }
            }/*if(c[i]==2 && stars >= b[i]){  // complete with star 2
                if (2-c[i] > maxStarGain)// (b[i] < minStarReq || (b[i] <= minStarReq && (2-c[i]) >= maxStarGain))
                {
                    index = i;
                   // minStarReq = b[i];
                    maxStarGain = 2-c[i];
                }
            } */
            }

            if(maxB != -1) //inStarReq < 100000000)
            {
               c[index]=1; stars++;
     //          System.out.println("choosing to level " + (index+1) + " to star " + c[index]);
               try_all(N,count+1,stars,a,b,c);
            }else return;
        
     /*       for(i = 0; i < N; i++){
            if(c[i]==0 && stars >= a[i]) // complete with star 1
            {
                stars++;
                c[i]++;
   //             System.out.println("level " + i + " completed with 1 star");
                try_all(N,count+1,stars,a,b,c);
     //           System.out.println("backgrace");
                c[i]--;
                stars--;
            }if(c[i]<2 && stars >= b[i]){  // complete with star 2
                stars += 2-c[i];
                int temp = c[i];
                c[i] = 2;
       //         System.out.println("level " + i + " completed with 2 star");
                try_all(N,count+1,stars,a,b,c);
         //       System.out.println("backtrace");
                c[i] = temp;
                stars -= 2-c[i];
            }
            } */
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();


        int N, a[], b[], c[];

        for(int i = 0; i < T; i++)
        {
            N = in.nextInt();
            a = new int[N]; b = new int[N];

            for(int j = 0; j < N; j++)
            {
                a[j] = in.nextInt(); b[j] = in.nextInt();
            }    

            c = new int[N]; 
            min = 10*N;
            try_all(N, 0, 0, a, b, c);
           
//            System.out.println(min); 
            if(min != 10*N)
                System.out.println("Case #" + (i+1) + ": " + min);
            else
                System.out.println("Case #" + (i+1) + ": Too Bad");
        }

    }    



}
