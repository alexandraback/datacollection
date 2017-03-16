package gcj2014.qual;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P4().run();
    }
    PrintWriter pw;

    void run() throws Exception{
        File infile=new File("D-small-attempt0.in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            int result = 0;
            int N=sc.nextInt();
            List<Integer> ni=new ArrayList<Integer>();
            List<Integer> ki=new ArrayList<Integer>();
            
            for(int i=0;i<N;i++){
                double d=sc.nextDouble();
                int dd=(int) (d*10000);
                ni.add(dd);
            }
            for(int i=0;i<N;i++){
                double d=sc.nextDouble();
                int dd=(int) (d*10000);
                ki.add(dd);
            }
            Collections.sort(ni);
            Collections.sort(ki);
            Deque<Integer> nd=new ArrayDeque<Integer>(ni);
            Deque<Integer> kd=new ArrayDeque<Integer>(ki);
            int kscore=0;
            while(true){
                if(nd.isEmpty()) break;
                if(nd.getFirst()>kd.getFirst()){
                    nd.removeFirst();
                    kd.removeFirst();
                    continue;
                }
                if(nd.getFirst()<kd.getLast()){
                    kscore++;
                    nd.removeFirst();
                    kd.removeLast();
                }else{
                    break;
                }
            }
            int nscore1=N-kscore;
            List<thing> things=new ArrayList<thing>();
            for(int i=0;i<N;i++){
                things.add(new thing(ni.get(i),true));
            }
            for(int i=0;i<N;i++){
                things.add(new thing(ki.get(i),false));
            }
            Collections.sort(things);
            int kover=0;
            int nscore2=0;
            for(int i=2*N-1;i>=0;i--){
                thing t=things.get(i);
                if(!t.isnaomi){
                    kover++;
                }else{
                    if(kover>0){
                        kover--;
                    }else{
                        nscore2++;
                    }
                }
            }
            String outputstr=String.format("Case #%d: %d %d\n", case_i,nscore1,nscore2);
            pw.printf(outputstr);
            System.out.printf(outputstr);
        }
        pw.close();
    }

}
class thing implements Comparable<thing> {
    int w;
    boolean isnaomi;
    @Override
    public int compareTo(thing o) {
        return w-o.w;
    }

    public thing(int w, boolean isnaomi) {
        this.w = w;
        this.isnaomi = isnaomi;
    }
    
}