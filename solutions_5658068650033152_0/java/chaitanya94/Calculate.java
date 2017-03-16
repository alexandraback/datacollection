/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chaitanya
 */
public class Calculate {
    public long numStones(long n,long m,long k){
        long stones=0;
        if(n>3 && m>3){
            if(k<=12){
                long check =k;
                stones=0;
                while(true){
                    if(check-3>0){
                        check=check-3;
                        stones=stones+2;
                    }
                    else{
                        stones=stones+check;
                        break;
                    }
                }
            }
            else{
                stones=8;
                long check=k-12;
                
                stones=stones+check*2;
            }
        }
        
        else{
            if((k-2)%3==0)
                stones=2*(1+(k-2)/3);
        }
        return stones;
    }
    
    public long Ans(long m,long n,long k){
        long a = 0;
        long b = 0;
        boolean exit=false;
        
        for(a=1;a<k/2;a++){
            b=(k-(2*a))/(a+2);
            if(b>a){
                exit=true;
                break;
            }
           
        }
       // System.out.println(a);
        //System.out.println(b);
        //b=(k-(2*(a-1))/(a+1));
        long term1=2*(a+b);
        long term2=a*b;
        
        return term1;
    }
     
     
}
