
import com.sun.xml.internal.ws.api.pipe.NextAction;
import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Mahmoud J00N
 */
public class template {
    public static void main(String []args){
        try{
            Scanner in = new Scanner(new File("bbb.in"));
            Formatter out = new Formatter("out.txt");
            int numTestCase = in.nextInt();
            for(int kk=0;kk<numTestCase;kk++){
                int A = in.nextInt();
                int B = in.nextInt();
                int K = in.nextInt();
                int nA = numBit(A);
                int nB = numBit(B);
                int nK = numBit(K);
                int total = 0;
                for(int i =0;i<A;i++){
                    for(int j=0;j<B;j++){
//                        for(int k = 0 ; k <K;k++){
                            if((i&j)<K)
                                total++;
//                        }
                    }
                }
                System.out.println("Case #"+(kk+1)+": "+total);
                out.format("Case #"+(kk+1)+": "+total+"\n");
            }
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    private static int numBit(int B) {
        int ret = 0;
        while(B>0){
            B/=2;
            ret++;
        }
        return ret;
    }

}
