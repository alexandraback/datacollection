
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author ABDULRAHUMAN
 */
public class Fractiles {
    
    public static void main(String args[]) throws FileNotFoundException, IOException{
        
        Scanner in=new Scanner(new FileReader("E:\\d.in"));
        PrintWriter out=new PrintWriter(new FileWriter("E:\\d.out"));
        
        int t=in.nextInt();
        for(int z=1;z<=t;z++){
            
            int k=in.nextInt();
            int c=in.nextInt();
            int s=in.nextInt();
            
            if(c==1&&k<=s){
                System.out.print("Case #"+z+": ");
                out.print("Case #"+z+": ");
                for(int i=1;i<=k;i++){
                    System.out.print(i+" ");
                    out.print(i+" ");
                }
                System.out.println();
                out.println();
                continue;
            }
            if(k==1&&s>=1){
                System.out.println("Case #"+z+": 1");
                out.println("Case #"+z+": 1");
                continue;
            }
            
            if(c==1&&s<k){
                System.out.println("Case #"+z+": IMPOSSIBLE");
                out.println("Case #"+z+": IMPOSSIBLE");
                continue;
            }
            int reqS=k/2+1;
            if(s<reqS){
                System.out.println("Case #"+z+": IMPOSSIBLE");
                out.println("Case #"+z+": IMPOSSIBLE");
                continue;
            }
            
            ArrayList<Integer> inPos=new ArrayList<Integer>();
            ArrayList<Integer> outPos=new ArrayList<Integer>();
            
            
            if(k%2==1){
                for(int i=1,j=2;i<=k;i=i+2,j=j+2){
                inPos.add(i);
                if(i!=k)
                outPos.add(j);
            }
            }
            else{
                for(int i=1,j=2;i<=k;i=i+2,j=j+2){
                
                if(i!=k){
                    inPos.add(i);
                    outPos.add(j);
                }
                
                else
                    inPos.add(j);
                }
            }
           
            
            System.out.print("Case #"+z+": ");
            out.print("Case #"+z+": ");
            int length=outPos.size();
            for(int i=0;i<inPos.size();i++){
                System.out.print(((inPos.get(i)*k)-k)+(outPos.get(i%length))+" ");
                out.print(((inPos.get(i)*k)-k)+(outPos.get(i%length))+" ");
            }
            
            System.out.println();
            out.println();
        }
        out.close();
    }
    
}
