package coogle.code.jam;

import java.io.*;
import java.util.Arrays;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 03.05.14
 * Time: 20:22
 * To change this template use File | Settings | File Templates.
 */
public class NewLotteryGame {

    public static void main(String[] args){
        BufferedReader buffer = null;
        BufferedWriter bw = null;

        try{
            buffer = new BufferedReader(new FileReader("D:\\jam\\Test-A.in"));
            File file = new File("D:\\jam\\Test-A.out");
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            bw = new BufferedWriter(fw);

            String line = buffer.readLine();
            if(line != null ){
                Integer caseCount = Integer.parseInt(line);
                for(int i=1; i<= caseCount; i++ ){
                    System.out.println("-------CASR="+i+"-------------------------");
                    StringBuffer output = new StringBuffer();
                    line = buffer.readLine();
                    String[] l = line.split(" ");

                    Long A = Long.parseLong(l[0]);
                    Long B = Long.parseLong(l[1]);
                    Long K = Long.parseLong(l[2]);

                    Long totalVariants = (A-0)*(B-0);
                    Long left = A - K;
                    Long right = B - K;
                    Long spor = left*right;

                    long bigger = 0;
                    for(long k=K; k<A; k++ ){
                        for(long kk=K; kk<B; kk++){
                            //System.out.println("k="+k+"kk="+kk);
                            if((kk&k)>(K-1)) bigger++;
                        }
                    }

                    long result = totalVariants - bigger;
                    //System.out.println("A="+A+" B="+B+" K="+K);
                    //System.out.println("result="+result+" totalVar="+totalVariants+" spor="+spor+" bigger="+bigger);

                    boolean isResult;
                    isResult = true;
                    long maxNodesResult = result;

                    output.append("Case #"+i+": "+maxNodesResult+"\n");
                    bw.write(output.toString());
                }

            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
        finally {
            try {

                if (buffer != null) buffer.close();
                if (bw != null) bw.close();

            } catch (IOException ex) {
                ex.printStackTrace();
            }


        }

    }


}
