/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class fsgenerator {
    public static void main(String[] args) {
        List<BigInteger> list = new ArrayList<BigInteger>();
        BigInteger down = new BigInteger("0");
        BigInteger one = new BigInteger("1");
        BigInteger up = new BigInteger("10000");
        while(!down.equals(up)){
            down=down.add(one);
            String p = down.toString();
              StringBuilder b = new StringBuilder();
                for (int idx = p.length() - 1; idx >= 0; idx--){
                        b.append(p.charAt(idx));
                }
              String c = b.toString();
              p=p.concat(c);
              BigInteger u = new BigInteger(p);
              u=u.multiply(u);
              String q = u.toString();
              if(q.charAt(q.length()-1)==0) continue;
              StringBuilder d = new StringBuilder();
                for (int idx = q.length() - 1; idx >= 0; idx--){
                        d.append(q.charAt(idx));
                }
              String e = d.toString();
              if(e.equals(q)) //System.out.println(e);
              list.add(u);
              
        }
        down = new BigInteger("0");
        while(!down.equals(up)){
            down=down.add(one);
            String p = down.toString();
              StringBuilder b = new StringBuilder();
                for (int idx = p.length() - 2; idx >= 0; idx--){
                        b.append(p.charAt(idx));
                }
              String c = b.toString();
              p=p.concat(c);
              BigInteger u = new BigInteger(p);
              u=u.multiply(u);
              String q = u.toString();
              if(q.charAt(q.length()-1)==0) continue;
              StringBuilder d = new StringBuilder();
                for (int idx = q.length() - 1; idx >= 0; idx--){
                        d.append(q.charAt(idx));
                }
              String e = d.toString();
              if(e.equals(q)) //System.out.println(e);
              list.add(u);
        }
        Collections.sort(list);
        for(int l=0;l<list.size();l++){
            System.out.println(list.get(l));
        }
    }
}
