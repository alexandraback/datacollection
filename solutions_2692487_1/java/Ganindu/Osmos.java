
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
    
    static BufferedWriter bw;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("A-large (1).in"));
        bw = new BufferedWriter(new FileWriter(new File("output.txt")));
            
        int tc = sc.nextInt();
        for(int d=1;d<=tc;d++){
            bw.write("Case #"+String.valueOf(d)+": ");
            
            int a = sc.nextInt();
            int n = sc.nextInt();
            
            int[] sizes = new int[n];            
            for(int i=0;i<n;i++) sizes[i] = sc.nextInt();
            
            Arrays.sort(sizes);
            
            if(a==1){
                bw.write(String.valueOf(n));
                bw.newLine();
                bw.flush();
                continue;
            }
            
            int[] sum = new int[n];
            int[] add = new int[n];
            
            sum[0] = a;
            for(int i=0;i<n;i++){
                if(i>0){
                    sum[i] = sum[i-1]+sizes[i-1];
                    add[i] = add[i-1];
                }
                while(sum[i]<=sizes[i]){
                    sum[i] += sum[i]-1;
                    add[i]++;
                }
            }
            
            int minOp = n;
            for(int i=1;i<n;i++){
                int m = add[i-1]+n-i;
                if(m<minOp) minOp = m;
            }
            if(add[n-1]<minOp) minOp = add[n-1];
            
            bw.write(String.valueOf(minOp));
            bw.newLine();
            bw.flush();
                
        }
        sc.close();
        bw.close();
    }
    
}
