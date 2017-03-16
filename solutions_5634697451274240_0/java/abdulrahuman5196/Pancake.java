
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 *
 * @author ABDULRAHUMAN
 */
public class Pancake {
    
    public static void main(String args[]) throws IOException{
        
        Scanner in=new Scanner(new FileReader("E:\\b.in"));
        PrintWriter out=new PrintWriter(new FileWriter("E:\\b.out"));
        int t=in.nextInt();
        in.nextLine();
        for(int z=1;z<=t;z++){
            String str=in.nextLine();
            int length=str.length();
            int flips=0;
            for(int i=0;i<length;i++){
                if(i==0&&str.charAt(i)=='-'){
                    flips++;
                }
                else if(i>0&&str.charAt(i)=='-'&&str.charAt(i-1)=='-'){
                    
                }
                else if(str.charAt(i)=='-'){
                    flips+=2;
                }
                else{
                    
                }
            }
            System.out.println("Case #"+z+": "+flips);
            out.println("Case #"+z+": "+flips);
        }
        out.close();
        
    }
    
}
