import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {
    static final String filename = "C";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        C solver = new C();
        solver.solve(s, w);
        w.close();
    }

    List<BigInteger>list;

    void solve(Scanner s, Writer w) throws IOException {
        BigInteger MAX=BigInteger.valueOf(10);
        MAX=MAX.pow(14);
        //for(int i=2;i<=100;i++)
            //MAX=MAX.multiply(BigInteger.valueOf(10));
        list=new ArrayList<BigInteger>();
        BigInteger bi=BigInteger.valueOf(1);
        BigInteger bis=BigInteger.valueOf(1);
        list.add(BigInteger.valueOf(1));
        while(bis.compareTo(MAX)==-1){
            bi=bi.add(BigInteger.valueOf(1));
            if(!isP(bi.toString()))
                continue;
            bis=bi.multiply(bi);
            //System.out.println(bi+"|"+bis);
            if(isP(bis.toString()))
                list.add(bis);
        }
        Collections.sort(list);
        //System.out.println(list);
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            long a=s.nextLong();
            long b=s.nextLong();
            String ans=solve(BigInteger.valueOf(a),BigInteger.valueOf(b));

            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";

            w.write(out);
            System.out.print(out);
        }

    }

    String solve(BigInteger a,BigInteger b){
        int r=0;
        for(int i=0;i<list.size();i++){
            BigInteger x=list.get(i);
            if(b.compareTo(x)==-1)
                break;
            if(a.compareTo(x)<=0&&b.compareTo(x)>=0)
                r++;
        }
        return r+"";
    }

    boolean isP(String str){
        int l=0;
        int r=str.length()-1;
        while(l<r){
            if(str.charAt(l)!=str.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}