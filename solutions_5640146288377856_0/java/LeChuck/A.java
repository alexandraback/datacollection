import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class A {



    public static void main(String[] args) throws NumberFormatException, IOException {
        // TODO READER

        //BufferedReader br= new BufferedReader(new FileReader("bum.in"));
        BufferedReader br= new BufferedReader(new FileReader("A-small-attempt2.in"));
        //BufferedReader br= new BufferedReader(new FileReader("A-large-attempt0.in"));

        int T=Integer.parseInt(br.readLine());


        // TODO WRITER
        PrintWriter pw = new PrintWriter("A.txt", "UTF-8");


        for(int i = 0; i < T; i++){

            String[] tab =br.readLine().split(" ");
            int R = Integer.parseInt(tab[0]);
            int C = Integer.parseInt(tab[1]);
            int W = Integer.parseInt(tab[2]);
            int a = solution(R,C,W);

            System.out.print("Case #"+(i+1)+": "+a+"\n");
            pw.write("Case #"+(i+1)+": "+a+"\n");

        }
        pw.close();
    }

    static int solution(int R, int C, int W){
        if(W==1) return R*C;
        if(W==C) return R+W-1;
        int firstHit = R*(C/W);
        if(C%W==0) return firstHit+W-1;





        return firstHit+W;
    }
}
