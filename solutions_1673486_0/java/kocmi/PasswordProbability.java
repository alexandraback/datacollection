package passwordprobability;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author Kocmi
 */
public class PasswordProbability {

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st;

            st = new StringTokenizer(br.readLine());
            int tests = Integer.parseInt(st.nextToken());
            double[] results = new double[tests]; //final result
            int typed, length;
            double[] probabilities;
            
            for (int i = 0; i < tests; i++) {
                st = new StringTokenizer(br.readLine());
                typed = Integer.parseInt(st.nextToken());
                length = Integer.parseInt(st.nextToken());
                
                
                
                probabilities = new double[typed];
                st = new StringTokenizer(br.readLine());
                
                for (int j = 0; j < typed; j++) {
                    probabilities[j] = Double.parseDouble(st.nextToken());
                }
                
                results[i] = lessKeystrokes(typed, length, probabilities);
            }
            
            for (int i = 0; i < tests; i++) {
                System.out.println("Case #"+(i+1)+": "+results[i]);
            }
        } catch (Exception ex) {
        }
    }
    
    public static double lessKeystrokes(int typed, int length, double[] probabilities){
        double best = Double.POSITIVE_INFINITY;
        double correctly=1;
        double temp;
        
        //give up
        temp=(2+length);
        best=temp;
        
        //press few times backspace
        for (int i = 0; i <= typed; i++) {
            correctly=1;
            for (int j = 0; j < typed-i; j++) {
                correctly*=probabilities[j];
            }
            temp = (length-typed+1+2*i)*correctly + (length-typed+1+length+1+2*i)*(1-correctly);
            if(temp<best){best=temp;}
        }
        
        
        return best;
    }
}
