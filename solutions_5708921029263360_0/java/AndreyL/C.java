package round1.roundC;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class C {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader("src/round1/roundC/C-small-attempt2.in"));
        PrintWriter pw = new PrintWriter("src/round1/roundC/C-large.out");
        int testCases = sc.nextInt();
//        testCases = 1;

        for (int casen = 0; casen < testCases; casen++) {
            pw.printf("Case #%d: ",casen+1);
            int j = sc.nextInt();
            int p = sc.nextInt();
            int s = sc.nextInt();
            int k = sc.nextInt();
            Map<String,Integer> mj=new HashMap<String,Integer>();
            Map<String,Integer> mp=new HashMap<String,Integer>();
            Map<String,Integer> ms=new HashMap<String,Integer>();
            List<String> result=new ArrayList<>();



            for (int i = 1; i <= j; i++) {//j
                for (int l = 1; l <= p; l++) {//p
                    for (int m = 1; m <= s; m++) {//s
                        if(i==l&&l==m) continue;
                        if(mj.getOrDefault(l+" "+m,-1)>=k||mp.getOrDefault(i+" "+m,-1)>=k||ms.getOrDefault(i+" "+l,-1)>=k) continue;
                        //System.out.println(mj);
                        if(mj.get(l+" "+m)!=null){
                            mj.put(l+" "+m,mj.get(l+" "+m)+1);
                        }else{
                            mj.put(l+" "+m,1);
                        };
                        if(mp.get(i+" "+m)!=null){
                            mp.put(i+" "+m,mp.get(i+" "+m)+1);
                        }else{
                            mp.put(i+" "+m,1);
                        };
                        if(ms.get(i+" "+l)!=null){
                            ms.put(i+" "+l,ms.get(i+" "+l)+1);
                        }else{
                            ms.put(i+" "+l,1);
                        }
                        result.add(i+" "+l+" "+m);
                    }
                }
            }

            for (int i = 1; i <= j; i++) {//j
                for (int l = 1; l <= p; l++) {//p
                    for (int m = 1; m <= s; m++) {//s
                        if(i==l&&l==m) {
                            if (mj.getOrDefault(l + " " + m, -1) >= k || mp.getOrDefault(i + " " + m, -1) >= k || ms.getOrDefault(i + " " + l, -1) >= k)
                                continue;
                            //System.out.println(mj);
                            if (mj.get(l + " " + m) != null) {
                                mj.put(l + " " + m, mj.get(l + " " + m) + 1);
                            } else {
                                mj.put(l + " " + m, 1);
                            }
                            ;
                            if (mp.get(i + " " + m) != null) {
                                mp.put(i + " " + m, mp.get(i + " " + m) + 1);
                            } else {
                                mp.put(i + " " + m, 1);
                            }
                            ;
                            if (ms.get(i + " " + l) != null) {
                                ms.put(i + " " + l, ms.get(i + " " + l) + 1);
                            } else {
                                ms.put(i + " " + l, 1);
                            }
                            result.add(i + " " + l + " " + m);
                        }
                    }

                }

            }

//            System.out.println(result.size());
//            System.out.println(result);
            pw.println(result.size());
            for (int i = 0; i < result.size(); i++) {
                pw.println(result.get(i));
            }

            pw.flush();
        }



        pw.close();
        sc.close();

    }



}
