
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ahmad
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static int memo[]=new int[1000010];
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        Scanner input=new Scanner(new File("input.in"));
        int tc=input.nextInt();
        int n;
        solve();
        for (int i = 0; i < tc; i++) {
            n=input.nextInt();
           
            System.out.printf("Case # %d: %d \n",(i+1),memo[n]);
        }
        
        
    }
    
    static void solve(){
        memo[1] = 1;
        Arrays.fill(memo, 1000000);
	for(int i = 1; i < 1000000; i++) {
		int reverse = flip(i);
		memo[i+1] = Math.min(memo[i+1], memo[i] + 1);
		memo[reverse] = Math.min(memo[reverse], memo[i] + 1);
               
	}
        
    }
    static int flip (int n){
        StringBuffer nn=new StringBuffer(n+"");
        nn=nn.reverse();
        return Integer.parseInt(nn.toString());
    }
}
