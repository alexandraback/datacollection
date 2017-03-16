
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ProblemB {
    
    static BufferedWriter bw;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("C-small-attempt1.in"));
        bw = new BufferedWriter(new FileWriter(new File("output.txt")));
            
        int tc = sc.nextInt();
        for(int k=1;k<=tc;k++){
            bw.write("Case #"+String.valueOf(k)+": ");

            int c = sc.nextInt();
            int d = sc.nextInt();
            int v = sc.nextInt();
            
            int[] co = new int[d];
            for(int a=0;a<d;a++) co[a] = sc.nextInt();
            boolean[] ic = new boolean[v+1];
            boolean[] vc = new boolean[v+1];
            vc[0] = true;
            for(int a=d-1;a>=0;a--){
                ic[co[a]] = vc[co[a]] = true;
                //if(k==1)System.out.println(co[a]);
                for(int b=v-1; b>=co[a]+1;b--){
                    if(vc[b] && b+co[a]<=v){
                        //if(k==1 && !vc[b+co[a]])System.out.println("x"+b+co[a]+"c"+(b+co[a]));
                        vc[b+co[a]] = true;
                    }
                    
                }
            }
            
            int newCoins = 0;
            while(true){
                int[] m = new int[v+1];
                boolean on = false;
                for(int a=1;a<=v;a++){
                    if(!vc[a]){
                        on = true;
                        for(int b=1;b<=a;b++){
                            if(!ic[b] && vc[a-b]) m[b]++;
                        }
                    }
                }
                if(!on) break;
                int mx = 0, mi = -1;
                for(int a=1;a<=v;a++){
                    if(m[a]>mx){
                        mx = m[a];
                        mi = a;
                    }
                }
                for(int a=v;a>=0;a--){
                    if(vc[a] && a+mi<=v) vc[a+mi] = true;
                }
                ic[mi] = true;
                newCoins++;
            }

            bw.write(String.valueOf(newCoins));
            bw.newLine();
            bw.flush();   
        }
        
        sc.close();
        bw.close();
    }
}
