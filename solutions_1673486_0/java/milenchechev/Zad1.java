
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Milen
 */
public class Zad1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        Formatter out = new Formatter(new File("output.txt"));
        int tests = in.nextInt();
        for(int k = 0 ; k < tests ; k++){
            int symbols = in.nextInt();
            int length = in.nextInt();
            double[] prop = new double[symbols];
            for(int i = 0 ; i < prop.length ; i ++){
                prop[i] = in.nextDouble();
            }
            double[] accProp = new double[symbols+1];
            double last = 1;
            for(int i = 1 ; i < accProp.length;i++){
                accProp[accProp.length-i]= last * (1-prop[i-1]);
                last *= prop[i-1];
            }
            accProp[0] = last;
            double minRes = 100000000;
            for(int i = 0 ; i < symbols+1; i++){
                double acc = 0;//last*(length-symbols+1);
                for(int j = 0 ; j < accProp.length;j++){
                    if(j <= i){
                        acc +=accProp[j]*(length-symbols+1 + i*2);
                    }else{
                        acc +=accProp[j]*(2*length-symbols+2 + i*2);
                    }
                }
                if(minRes > acc){
                    minRes = acc;
                }
            }
            if(minRes > length+2){
                minRes = length +2;
            }
            out.format("Case #%d: %.6f\n", k+1,minRes);
        }
        out.close();
    }
    public static void dfs(int l, int currentL, int sum){
        
    }
}
