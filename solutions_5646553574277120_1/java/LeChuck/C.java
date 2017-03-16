import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.PriorityQueue;


public class C {



    public static void main(String[] args) throws NumberFormatException, IOException {
        // TODO READER

        //BufferedReader br= new BufferedReader(new FileReader("bum.in"));
        //BufferedReader br= new BufferedReader(new FileReader("C-small-attempt0.in"));
        BufferedReader br= new BufferedReader(new FileReader("C-large.in"));

        int T=Integer.parseInt(br.readLine());


        // TODO WRITER
        PrintWriter pw = new PrintWriter("C.txt", "UTF-8");


        for(int i = 0; i < T; i++){
            String[] tab =br.readLine().split(" ");
            int C = Integer.parseInt(tab[0]);
            int D = Integer.parseInt(tab[1]);
            int V = Integer.parseInt(tab[2]);
            String[] tab2 =br.readLine().split(" ");
            PriorityQueue<Integer> den = new PriorityQueue<Integer>();
            for(String s: tab2){
                den.add(Integer.parseInt(s));
            }
            int a = solution(C,D,V,den);

            System.out.print("Case #"+(i+1)+": "+a+"\n");
            pw.write("Case #"+(i+1)+": "+a+"\n");

        }
        pw.close();
    }

    static int solution(int C, int D,int V, PriorityQueue<Integer> den){
        int max=1;
        int added=0;
        ArrayList<Integer> list = new ArrayList<Integer>();
        while(max<=V){


            if(den.size()==0){
                list.add(max);
                max=max+C*max;
                added++;
                continue;
            }
            int next = den.peek();

            if(next<=max){
                den.poll();
                list.add(max);
                max=max+C*next;
                continue;
            }
            else{
                list.add(max);
                max=max+C*max;
                added++;
            }
        }


        return added;
    }
    /*public static boolean canDo(ArrayList<Integer>list, int max){

    }
    public static void addMax(ArrayList<Integer>list, int max, PriorityQueue<Integer> den){
        while(den.peek()<2*max-1){
            int polled =den.poll();
            list.add(polled);
            max=2*poll
        }
    }*/
}