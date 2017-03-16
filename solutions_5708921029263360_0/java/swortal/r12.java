import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class r12 {
    public static void main(String[] args) {
        try {
            Scanner input=new Scanner(new File(args[0]));
            PrintWriter output=new PrintWriter(args[1]) ;
            int casenumber = input.nextInt();
            input.nextLine();
            for(int i=0;i<casenumber;i++){
                int j= input.nextInt(), p = input.nextInt(), s=input.nextInt(), k=input.nextInt();
                List<List<Integer>> result = new ArrayList<List<Integer>>();
                int[][] mjp = new int[j][p], mjs =new int[j][s], mps=new int[p][s];
                int count=0;
                for(int iters=0;iters<s;iters++)   {
                    for(int iterp=0;iterp<p;iterp++){
                        for(int iterj=0;iterj<j;iterj++)  {
                             if(mjp[iterj][iterp]<k && mjs[iterj][iters]<k &&mps[iterp][iters]<k )  {
                                 count++;
                                 mjp[iterj][iterp]++;
                                 mjs[iterj][iters]++;
                                 mps[iterp][iters]++;
                                 List<Integer>  oner=new ArrayList<Integer>();
                                 oner.add(iterj+1);
                                 oner.add(iterp+1);
                                 oner.add(iters+1);
                                 result.add(oner);

                             }
                        }
                    }
                }
                        output.println("Case #" + (i + 1) + ": " + count);
                  for(int j1=0;j1<count;j1++){
                      List<Integer>  oner=result.get(j1);
                      output.println(oner.get(0)+" "+oner.get(1)+" "+oner.get(2));
                  }


            }
            output.flush();
        } catch (Exception e){
            e.printStackTrace();
        }
    }


}
