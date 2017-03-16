import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class FairAndSquare {

    public static void main(String args[]) throws IOException {
        long l=System.currentTimeMillis();
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("C-large-1.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("large1C.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
        PrintWriter out = new PrintWriter(outputStream);
        FairAndSquare solver = new FairAndSquare();
        solver.solve( in, out);
        out.close();
        System.out.println("time =:"+(System.currentTimeMillis()-l));

    }

    private void solve(BufferedReader in, PrintWriter out) throws IOException {
        int t=Integer.parseInt(in.readLine());
        ArrayList<String> al=createPalindrome();
        //System.out.println(al.size());
        ArrayList<Long> ll=new ArrayList<Long>();
        for(int i=0;i<al.size();i++){
            ll.add(Long.parseLong(al.get(i)));
        }
        Collections.sort(ll);
        ll.remove(0);
        ArrayList<BigInteger> list=getAllFAS(ll) ;

        for(int i=0;i<t;i++){
            out.print("Case #"+(i+1)+": ");
            StringTokenizer st=new StringTokenizer(in.readLine());
            String a=st.nextToken();
            String b=st.nextToken();
            BigInteger aa=new BigInteger(a);
            BigInteger bb=new BigInteger(b);
            BigInteger ans=BigInteger.ZERO;
            for(int j=0;j<list.size();j++){
               BigInteger sq=list.get(j);
                if(sq.compareTo(aa)>=0&&sq.compareTo(bb)<=0&&isPalindrome(sq.toString())){
                    ans=ans.add(BigInteger.ONE);
                }
            }

            out.println(ans);

        }

    }

    private ArrayList<BigInteger> getAllFAS(ArrayList<Long> ll){
        ArrayList<BigInteger> fas=new ArrayList<BigInteger>();
        String tt=""+1;
        for(int i=0;i<15;i++){
            tt+=""+0;
        }

        BigInteger aaa=new BigInteger(""+1);
        BigInteger bbb=new BigInteger(""+tt);
        BigInteger anss=BigInteger.ZERO;
        for(int j=0;j<ll.size();j++){
            BigInteger vv=new BigInteger(""+ll.get(j));
            BigInteger sq=vv.multiply(vv);
            //System.out.println(sq);
            if(sq.compareTo(aaa)>=0&&sq.compareTo(bbb)<=0&&isPalindrome(sq.toString())){
                fas.add(sq);
                anss=anss.add(BigInteger.ONE);
            }
        }
        return fas;
    }
    int max[]={0,9,99,999,9999,99999};
    int min[]={0,1,10,100,1000,10000};
    private ArrayList<String> createPalindrome(){
        ArrayList<String> al=new ArrayList<String>(1000000);
        for(int i=1;i<=8;i++){
            if(i%2!=0){
               for(int k=0;k<=9;k++){
                    for(int j=min[i/2];j<=max[i/2];j++){
                        if(j!=0)
                            al.add(j+""+k+""+rev(j));
                        else{
                            al.add(""+k);
                        }
                    }
               }

            }
            else{
                for(int j=min[i/2];j<=max[i/2];j++){
                    al.add(j+""+rev(j));
                }

            }
        }
        return al;
    }
    private String rev(int a){
        String s=""+a;
        StringBuilder sb=new StringBuilder(s.length());
        for(int i=0;i<s.length();i++){
            sb.append(s.charAt(s.length()-1-i));
        }
        return sb.toString();

    }

    private boolean isPalindrome(String p){
        int l=p.length()/2+p.length()%2;
        for(int i=0;i<l;i++){
            if(p.charAt(i)!=p.charAt(p.length()-1-i))return false;
        }
        return true;
    }
}
