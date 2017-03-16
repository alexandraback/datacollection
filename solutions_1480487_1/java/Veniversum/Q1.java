import java.io.*;

/**
 * Created by IntelliJ IDEA.
 * User: Foton
 * Date: 5/5/12
 * Time: 6:46 PM
 */
public class Q1 {
    static String in = "";
    static String out = "";
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("in.txt"));
            int cases = Integer.parseInt(br.readLine());
            for (int i =0; i<cases;i++){
                out+="Case #"+(i+1)+": ";
                String[] tmp = br.readLine().split(" ");
                int people = Integer.parseInt(tmp[0]);
                double score[] = new double[people];
                double x = 0;

                double avg2 = 0;
                double[] perc = new double[people];
                int ppl = people;
                int ttl=0;
                for(int j = 0;j<people;j++){
                    ppl = people;
                    x+=Integer.parseInt(tmp[j+1]);
                    score[j]= Integer.parseInt(tmp[j+1]);
                }
                double avg = (2*x)/people;
                for(int j = 0;j<people;j++){
                if (score[j]>=avg){
                    ppl--;
                } else {
                    ttl+= score[j];
                }
                }
                avg2 = (x+ttl)/ppl;
                for(int j = 0;j<people;j++){
                    if (ppl==people){
                        perc[j]=(avg-score[j])/(x)*100;
                    }
                    else{
                        if(score[j]<avg){
                            perc[j]=(avg2-score[j])/(x)*100;
                        }else{
                            perc[j]=0;
                        }
                    }
                    out+= perc[j];
                    if(j!=people-1){
                        out+=" ";
                    }
                }
                out+= "\n";
            }

            br.close();

            PrintWriter pw = new PrintWriter(new FileOutputStream("out.txt"));
            pw.print(out);
            pw.close();
            pw.flush();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
