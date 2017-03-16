import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.NumberFormat;
import java.util.Arrays;


public class Round1BA {
    public static void main(String[] args) {
        try {
            FileReader input = new FileReader(args[0]);
            BufferedReader in = new BufferedReader(input);
            FileWriter output = new FileWriter("Round1BA.out");
            BufferedWriter out = new BufferedWriter(output);
            
            String line;
            int count = 1;
            
            line = in.readLine();
            int cases = Integer.parseInt(line);
            line = in.readLine();
            
            while (line != null && count <= cases) {
                if (count != 1) {
                    out.write("\n");
                }
                
                String outStr = "Case #" + count + ":" + getSmallestPercentage(line);
                System.out.println(outStr);
                out.write(outStr);
                
                line = in.readLine();
                count++;
            }
            
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getSmallestPercentage(String line) {
        String[] lineArr = line.split(" ");
        int N = Integer.parseInt(lineArr[0]);
        int[] sArr = new int[lineArr.length-1];
        double X = 0;
        
        for (int i = 1; i < lineArr.length; i++) {
            int si = Integer.parseInt(lineArr[i]);
            X += si;
            sArr[i-1] = si;
        }
        
        double raw_score = 2*X/N;
        double score = raw_score;
        
        boolean scoreFlag = false;
        int[] sArrCopy = Arrays.copyOf(sArr,sArr.length);
        Arrays.sort(sArrCopy);
        int cnt = 0;
        do {
            scoreFlag = false;
            
            if (sArrCopy[sArrCopy.length-1-cnt] > score) {
                scoreFlag = true;                
                score = ((score*(N-cnt))-sArrCopy[sArrCopy.length-1-cnt])/(N-cnt-1);
                cnt++;
            }
            
        } while (scoreFlag);
        
        String mStr = "";
        NumberFormat nf = NumberFormat.getInstance();
        nf.setMaximumFractionDigits(6);
        nf.setMinimumFractionDigits(6);
        nf.setGroupingUsed(false);
        for (int i = 0; i < sArr.length; i++) {
            double Yi = ((double) (score - sArr[i])) / X * 100;
            if (raw_score < sArr[i]) {
                Yi = 0;
            }
            mStr += " " + nf.format(Yi);
        }
        
        return mStr;
    }
}
