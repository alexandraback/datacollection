
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chaitanya
 */
public class Calculate {
    
    public boolean checkPossibility(int numerator,int denominator){
        int d = denominator;
        boolean b =true;
        while(true){
            if(d==0)
                return true;
            
            if(d%2==0)
                d=d/2;
            else{
                b=false;
                break;
            }
        }
        
        if(numerator%d==0)
            return true;
        else
            return false;
    }
    
    public int generation(int numerator,int denominator){
        
        int i=1;
        
        while(true){
            int term = (((int)Math.pow(2,i))*numerator)/denominator;
            
            if(term-1>=0 && term-1<=1)
                break;
            else
                i++;
        }
        return i;
    }
}
