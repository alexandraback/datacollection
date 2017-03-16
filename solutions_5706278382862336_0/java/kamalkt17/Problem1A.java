package codejam1cround2014;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Problem1A {
    public static void main(String[] args) throws IOException {

        //for reading from input file
        String inputfilename="C:\\Users\\kamal\\Downloads\\A-small-attempt0.in";
        //String inputfilename="";
        FileReader fileReader=new FileReader(inputfilename);
        Scanner scanner=new Scanner(fileReader);


        //for writong into output file
        String outputfilename="template.out";
        //String outputfilename="testout.out";
        String outputfile="C:\\CODEJAMOUTPUT\\"+outputfilename;
        FileWriter fileWriter=new FileWriter(outputfile);
        BufferedWriter bufferedWriter=new BufferedWriter(fileWriter);



        //reads testcases
        long testcases=scanner.nextLong();
        long alltestcases=testcases;


        while(testcases-->0){

            String s=scanner.next();
            String pq[]=s.split("/");
//            System.out.println(pq[0]);
//            System.out.println(pq[1]);

            long p=Long.parseLong(pq[0]);
            long q=Long.parseLong(pq[1]);


            long gcdval=findgcd(p,q);

//            System.out.println(gcdval);

            p=p/gcdval;
            q=q/gcdval;

            BigInteger qq=new BigInteger(String.valueOf(q));
            BigInteger qminausone=new BigInteger(String.valueOf(q-1));

            if ((qminausone.and(qq)).compareTo(new BigInteger("0"))==0){
                int count=0;
                while(p<q){
                    p=p*2;
                    count++;
                }
                bufferedWriter.write("Case #" + (alltestcases - testcases) + ": " + count);
                bufferedWriter.newLine();
                System.out.println("Case #" + (alltestcases - testcases) + ": " + count);

            }
            else {
                bufferedWriter.write("Case #" + (alltestcases - testcases) + ": impossible");
                bufferedWriter.newLine();
                System.out.println("Case #" + (alltestcases - testcases) + ": impossible");
            }



        }

        scanner.close();
        bufferedWriter.close();
        fileReader.close();
        fileWriter.close();
    }

    private static long findgcd(long a, long b) {

            if (b==0) return a;
            return findgcd(b, a % b);

    }
}
