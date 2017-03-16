//lukewillson
import java.io.*;
import java.util.*;

public class Sums {

    public static void main(String[] args) throws Exception {
        new DoSums();
    }
}

class DoSums {
    HashMap<Integer, ArrayList<String>> map ;
    public DoSums() throws Exception {
        System.setOut(new PrintStream(new File("Sums.out")));
        Scanner sc = new Scanner(new File("Sums.in"));
        int runs = Integer.parseInt(sc.nextLine());
        int run = 0;
        while (run++ < runs) {
            System.out.println("Case #" + run + ": ");
            int length=sc.nextInt();
            map = new HashMap<Integer, ArrayList<String>>();
            int[] ary = new int[length];
            for (int i = 0; i < ary.length; ++i) {
                ary[i] = sc.nextInt();
            }
            ArrayList<String>result=null;
            int max = (int) Math.pow(2, ary.length);
            for (int i = 1; i < max&&!done(); ++i) 
            {
                int sum = 0;
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
            dance:for(int i:map.keySet())
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
        for(int i:map.keySet())
        {
            if(map.get(i).size()>1)
                return true;
        }
        return false;
    }
    public String str(int i, int max) {
        String s = Integer.toBinaryString(i);
        while (s.length() < max) {
            s = "0" + s;
        }
        return s;
    }
}
