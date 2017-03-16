
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class R1AB {    
    public static void main(String[] args){                  
        
        try{
            Scanner sc = new Scanner(new File("B-large.in"));    
            BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")));
            int t = sc.nextInt();
            
            for(int i=0;i<t;i++){
                int n = sc.nextInt();
                boolean[] done = new boolean[n];
                boolean[] half = new boolean[n];
                int[] a1 = new int[n];
                int[] a2 = new int[n];
                int[] s2 = new int[n];
                for(int j=0;j<n;j++){
                    a1[j] = sc.nextInt();
                    a2[j] = sc.nextInt();
                    s2[j] = j;
                }
                final int[] b1 = a1;
                final int[] b2 = a2;               
                
              /*  Arrays.sort(s2,new Comparator<Integer>(){
                    @Override
                    public int compare(Integer o1, Integer o2) {
                        return b2[o1]-b2[o2];
                    }                    
                });*/
                
                insertionSort(s2, b2);
                
                int b = 0;
                int m = 0;
                int s = 0;
                while(b<n){
                    while(true){
                        if(b2[s2[b]]<=s){
                            done[s2[b]] = true;
                            s += half[s2[b]]?1:2;
                            b++; m++;
                            if(b>=n)break;
                        }
                        else break;
                    }
                    if(b>=n)break;
                    boolean lost = true;
                    for(int a=n-1;a>=0;a--){
                        if(done[s2[a]])break;
                        if(half[s2[a]])continue;
                        if(b1[s2[a]]<=s){
                            lost = false;
                            s++; m++;
                            half[s2[a]] = true;
                            break;
                        }
                    }
                    if(lost) break;
                }
                
                bw.write("Case #"+String.valueOf(i+1)+": ");
                if(b>=n) bw.write(String.valueOf(m));
                else bw.write("Too Bad");
                bw.newLine();
                bw.flush();
            }
            bw.close();
        
        } catch (Exception ex) {
            Logger.getLogger(QA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public static void insertionSort(int[] x,int[] y){
        int a = 1;
        while(a<x.length){
            int temp = x[a];
            int r = a-1;
            while(r>=0 && y[x[r]]>y[x[a]])r--;
            for(int i=a-1;i>r;i--){
                x[i+1]=x[i];
            }
            x[r+1] = temp;
            a++;
        }               
    }
}
