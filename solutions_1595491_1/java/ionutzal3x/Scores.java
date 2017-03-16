/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dance;

/**
 *
 * @author ALEX
 */
public class Scores {
    int first;
    int second;
    int third;
    int total;
    boolean s;
    public Scores(int total)
    {
        this.total=total;
    }
    public int getMaxS()
    {
        int max=0;
        for(int i=0;i<=10;i++)
            for(int j=i;(j<=i+2)&&(j<=10);j++)
                for(int k=j;(k<=j+2)&&(k<=i+2)&&(k<=10);k++)
                    if((i+j+k==total)&&(i+2==j||i+2==k)){
                        if(i>max)
                            max=i;
                        if(j>max)
                            max=j;
                        if(k>max)
                            max=k;
                    }
        return max;
    }
    public int getMaxUnS()
    {
        int max=0;
        for(int i=0;i<=10;i++)
            for(int j=i;(j<=i+2)&&(j<=10);j++)
                for(int k=j;(k<=j+2)&&(k<=i+2)&&(k<=10);k++)
                    if((i+j+k==total)&&(i+2!=j&&i+2!=k)){
                        if(i>max)
                            max=i;
                        if(j>max)
                            max=j;
                        if(k>max)
                            max=k;
                    }
        return max;
    }
    public void setFirstSurprize()
    {
        for(int i=0;i<=10;i++)
            for(int j=i;(j<=i+2)&&(j<=10);j++)
                for(int k=j;(k<=j+2)&&(k<=i+2)&&(k<=10);k++)
                    if((i+j+k==total)&&(i+2==j||i+2==k)){
                        first=i;
                        second=j;
                        third=k;
                        s=true;
                        return;
                    }                        
    }
    public void setFirstNormal(){
        for(int i=1;i<=10;i++)
            for(int j=i;(j<=i+2)&&(j<=10);j++)
                for(int k=j;(k<=j+2)&&(k<=i+2)&&(k<=10);k++)
                    if((i+j+k==total)&&(i+2==j||i+2==k)){}
                    else {
                        first=i;
                        second=j;
                        third=k;
                        s=false;
                        return;
                    }
    }
}
