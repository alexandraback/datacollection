//lukewillson
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Sums {

    public static void main(String[] args) throws Exception {
        new DoSums();
    }
}

class DoSums {
    HashMap<Long, ArrayList<String>> map ;
    public DoSums() throws Exception {
        System.setOut(new PrintStream(new File("Sums.out")));
        Scanner sc = new Scanner(new File("Sums.in"));
        int runs = Integer.parseInt(sc.nextLine());
        int run = 0;
        while (run++ < runs) {
            System.out.println("Case #" + run + ": ");
            int length=sc.nextInt();
            map = new HashMap<Long, ArrayList<String>>();
            long[] ary = new long[length];
            for (int i = 0; i < ary.length; ++i) {
                ary[i] = sc.nextLong();
            }
            ArrayList<String>result=null;
            BigInteger b=BigInteger.ONE;
            b=b.add(BigInteger.ONE);
            b=b.pow(ary.length);
            
            for (BigInteger i=BigInteger.ONE;i.compareTo(b)<0;i=i.add(BigInteger.ONE)) 
            {
                long sum = 0;
                String s = str(i, ary.length);
                //System.out.println(s);
                for (int j = 0; j < ary.length; ++j) 
                    if (s.charAt(j) == '1')
                        sum += ary[j];              
                //System.out.println("found sum");
                if(sum<=0)
                    continue;
                if (map.containsKey(sum)) 
                    map.get(sum).add(s);
                else 
                {
                    map.put(sum, new ArrayList<String>());
                    map.get(sum).add(s);
                }
            }
            dance:for(long i:map.keySet())
            {
                if(map.get(i).size()>1)
                {
                    result=map.get(i);
                    break dance;
                }
            }String print="";
            if(result==null)
                System.out.println("Impossible");
            
            else 
            {
                Collections.sort(result);
                for(String s:result)
                {
                    for(int i=0;i<s.length();++i)
                        if(s.charAt(i)=='1')
                            print+=ary[i]+" ";
                    System.out.println(print.trim());
                    print="";
                }
                
            }
        }
    }
    public boolean done()
    {
        for(long i:map.keySet())
        {
            if(map.get(i).size()>1)
                return true;
        }
        return false;
    }
    public String str(BigInteger b, int max) {
        String s = b.toString(2);
        while (s.length() < max) {
            s = "0" + s;
        }
        return s;
    }
}
