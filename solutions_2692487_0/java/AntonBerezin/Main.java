import java.io.*;
import java.util.*;

public class Main {

    private long[] other;
    private int n;
    private long A;
    private int curIndex;
    private long curMot;



    private void solve(){
        Scanner scanner;
        PrintStream out;
        try{
            scanner = new Scanner(new File("A-small-attempt1.in"));
            out = new PrintStream("outputA-small.txt");
            try{
                int numberOfCases = scanner.nextInt();

                inputs:
                for(int caseNum = 0;caseNum<numberOfCases;caseNum++){
                    //System.out.println(caseNum);
                    String res = "Case #"+Integer.toString(caseNum+1)+": ";
                    A = scanner.nextLong();
                    n = scanner.nextInt();
                    other = new long[n];
                    for(int i = 0;i<n;i++) {
                        other[i] = scanner.nextLong();
                    }
                    Arrays.sort(other);
                    long result = Long.MAX_VALUE;
                    if(A == 1){
                        result = n;
                        res+= result;
                    } else{
                        curIndex = 0;
                        curMot = A;


                        long adds = 0;
                        while(curIndex<n){

                            while(curIndex<n){
                                if(other[curIndex]<curMot){
                                    curMot+=other[curIndex];
                                } else break;
                                curIndex++;
                            }

                            result = Math.min(result,adds+n-curIndex);

                            if(curIndex>=n)
                                break;

                            while(curMot<=other[curIndex]){
                                curMot+=curMot - 1;
                                adds++;
                            }
                            //System.out.print("["+curIndex+" "+curMot+"]");
                            result = Math.min(result,adds+n-curIndex);
                            if(curIndex==n-1){
                                break;
                            }
                        }

                        res+=result;
                    }
                     //System.out.println();
                    out.println(res);

                }
            } finally{
                out.close();
                scanner.close();
            }

        } catch (IOException ex){
            System.out.println(ex.getMessage());
        }


    }

    public static void main(String[] args) {
       new Main().solve();
    }
}
