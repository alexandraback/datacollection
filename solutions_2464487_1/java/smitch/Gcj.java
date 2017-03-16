import java.util.*;
import java.io.*;
import java.math.*;

public class Gcj {
    private int num_case;
    private BufferedReader buff;
    private BigInteger r, t;

    Gcj(){
        buff=new BufferedReader(new InputStreamReader(System.in));
        try{
            num_case=Integer.parseInt(buff.readLine());
        }
        catch(Exception e){
            System.err.println(e);
        }
        // System.out.println(T);
    }

    private void read_args(){
        String line;
        String[] str;
        try{
            line=buff.readLine();
            str=line.split(" ");
            r=new BigInteger(str[0]);
            t=new BigInteger(str[1]);
            System.err.println("");
            System.err.println("r="+r+", "+"t="+t);
        }
        catch(Exception e){
            System.err.println(e);
        }
        return;
    }

    private int paint_volume(int r, int n){
        return 2*n*n+(2*r-1)*n;
    }

    private BigInteger paint_volume(BigInteger r, BigInteger n){
        BigInteger tmp1=((n.pow(2)).multiply(new BigInteger("2")));
        // System.out.println("tmp1="+tmp1);
        BigInteger tmp2=((((r.shiftLeft(1)).subtract(BigInteger.ONE)).multiply(n)));
        // System.out.println("tmp2="+tmp2);
        BigInteger vol=(tmp1.add(tmp2));
        // System.out.println("vol="+vol);
        return vol;
        // return 2*n*n+(2*r-1)*n;
    }

    private void solve(){
        int res=0;
        boolean updated=true;
        // for(int i=1; i<1000; i++){
        BigInteger upper=new BigInteger("2000000000");
        BigInteger lower=new BigInteger("1");
        while(upper.subtract(lower).compareTo(BigInteger.ONE)>0){
            BigInteger med=upper.add(lower).shiftRight(1);
            if(paint_volume(r, med).compareTo(t) <= 0){
                lower=med;
            }
            else{
                upper=med;
            }
        }
        System.out.println(lower);
        return;
    }

    public int get_num_case(){
        return num_case;
    }

    public void run(int case_num){
        System.out.print(String.format("Case #%d: ", case_num+1));
        read_args();
        solve();
        //        System.out.println(Arrays.toString(input));
        return;
    }

    public static final void main(final String[] args) {
        Gcj gcj_instance=new Gcj();

        int num_case=gcj_instance.get_num_case();
        for(int i=0; i<num_case; i++)
            gcj_instance.run(i);

        return;
    }
}
