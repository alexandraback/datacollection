import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;


public class C {



    public static void main(String[] args) throws NumberFormatException, IOException {
        String name = "C";

        // TODO READER
        boolean isSmall = true;
        BufferedReader br;

        //br= new BufferedReader(new FileReader("bum.in"));
        if(isSmall) br = new BufferedReader(new FileReader(name+"-small-attempt2.in"));
        else br = new BufferedReader(new FileReader(name+"-large.in"));

        PrintWriter pw;
        if(isSmall) pw = new PrintWriter(name+"-small.txt", "UTF-8");
        else pw = new PrintWriter(name+"-large.txt", "UTF-8");

        int T=Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++){
            int N=Integer.parseInt(br.readLine());
            String[] tab =br.readLine().split(" ");
            int[] bff = new int[N+1];
            bff[0]=0;
            for(int j = 1; j < N+1; j++){
                bff[j]=Integer.parseInt(tab[j-1]);
            }
            int a = solution(bff, N);


            System.out.print("Case #"+(i+1)+": "+a+"\n");
            pw.write("Case #"+(i+1)+": "+a+"\n");

        }
        pw.close();
    }


    static int solution(int[] bff, int N){
        int max1=findMaxCycle(bff, N);
        int max2=0;
        for(int i=1; i<N+1;i++){
            int max=0;
            if(bff[bff[i]]==i&&i<bff[i]) {
          //      System.out.println("checking "+i+" "+bff[i]);
                if (findMaxTree(bff, N, i, bff[i]) > max) max = findMaxTree(bff, N, i, bff[i]);
            }
            max2+=max;
        }


        return Math.max(max1,max2);
    }
    static int findTreeA(int[] bff, int N, int I, int a, int b){
        if(I==a||I==b)return 1;
        boolean[] used = new boolean[N+1];
        used[a]=true;
        used[b]=true;
        used[I]=true;
        int length =2;
        int next= bff[I];
        while(!used[next]){
            used[next]=true;
            next=bff[next];
            length++;
        }
        //System.out.println("tree from "+I+" "+next);
        if(next==a)return length;
        else return 1;
    }
    static int findTreeB(int[] bff, int N, int I, int a, int b){
        if(I==a||I==b)return 1;
        boolean[] used = new boolean[N+1];
        used[a]=true;
        used[b]=true;
        used[I]=true;
        int length =2;
        int next= bff[I];
        while(!used[next]){
            used[next]=true;
            next=bff[next];
            length++;
        }
        //System.out.println("tree from "+I+" "+next);
        if(next==b)return length;
        else return 1;
    }

    static int findMaxTree(int[] bff, int N, int a, int b){
        int maxA =1;
        int maxB =1;
        for(int i=1; i<N+1;i++){
            if(findTreeA(bff, N, i, a, b) > maxA)maxA=findTreeA(bff,N,i,a,b);
        }
        for(int i=1; i<N+1;i++){
            if(findTreeB(bff, N, i, a, b)>maxB)maxB=findTreeB(bff, N, i, a, b);
        }
        return maxA+maxB;
    }





    static int findMaxCycle(int[] bff, int N){
        int max =1;
        for(int i=1; i<N+1;i++){
            if(findCycle(bff,N,i)>max)max=findCycle(bff,N,i);
        }
        return max;
    }
    static int findCycle(int[] bff, int N, int I){
        boolean[] used = new boolean[N+1];
        used[I]=true;
        int length =1;
        int next= bff[I];
        while(!used[next]){
            used[next]=true;
            next=bff[next];
            length++;
        }
        //System.out.println("last station from "+I+" "+next);
        if(next==I)return length;
        else return 0;
    }
}