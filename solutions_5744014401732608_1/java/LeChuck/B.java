import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class B {

    public static void main(String[] args) throws NumberFormatException, IOException {
        String name = "B";
        // TODO READER
        boolean isSmall = false;

        BufferedReader br;//= new BufferedReader(new FileReader("bum.in"));
        if(isSmall) br = new BufferedReader(new FileReader(name+"-small-attempt0.in"));
        else br = new BufferedReader(new FileReader(name+"-large.in"));

        PrintWriter pw;
        if(isSmall) pw = new PrintWriter(name+"-small.txt", "UTF-8");
        else pw = new PrintWriter(name+"-large.txt", "UTF-8");

        int T=Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++){
            //int N=Integer.parseInt(br.readLine());
            String[] tab =br.readLine().split(" ");
            int B = Integer.parseInt(tab[0]);
            long M = Long.parseLong(tab[1]);

            /*int[] bff = new int[N+1];
            bff[0]=0;
            for(int j = 1; j < N+1; j++){
                bff[j]=Integer.parseInt(tab[j-1]);
            }*/
            String a = solution(B, M);


            System.out.print("Case #"+(i+1)+": "+a+"\n");
            pw.write("Case #"+(i+1)+": "+a+"\n");

        }
        pw.close();
    }


    static String solution(int B, long M){
        String s="POSSIBLE\n";
        long m=(long) Math.pow(2,B-2);
        //System.out.println(m);
        if (M>m) return "IMPOSSIBLE";
        boolean[] bits = new boolean[64];
        for (int i = 62; i >= 0; i--) {
            bits[i] = ((M-1) & (1 << i)) != 0;
        }

        System.out.println(M + " = " + Arrays.toString(bits));
        for(int i=0;i<B;i++) {
            for (int j = 0; j < B; j++) {
                if(i>=j)s+="0";
                else if(i==0&&j==B-1)s+="1";
                else if(j!=B-1) s+="1";
                else if(bits[i-1]) s+="1";
                else  s+="0";
            }
            if(i!=B-1)s+="\n";
        }


        System.out.println(B+" "+M);
        return s;
    }
}