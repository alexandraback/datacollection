import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Victor on 4/15/2016.
 */
public class lastword {


    public static void main(String [] args) {
        String filePath = "C:\\Users\\Victor\\IdeaProjects\\googleJam\\files\\A-large.in";
        try {
            BufferedReader br = new BufferedReader(new FileReader(filePath));
            BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\Victor\\IdeaProjects\\googleJam\\files\\lastWordResult.txt"));

            Integer n = Integer.parseInt(br.readLine());
            int count = 1;
            for (int nn = 0;  nn < n; nn++){
                String input = br.readLine();
                StringBuilder sb = new StringBuilder();
                char last = 'Z';
                for (char c: input.toCharArray()){
                    if(sb.toString().length() == 0) {
                        sb.reverse();
                        sb.append(c);
                        sb.reverse();
                        last = c;
                    }else {
                        if (c >= last){
                            sb.reverse();
                            sb.append(c);
                            sb.reverse();
                            last = c;
                        }else {
                            sb.append(c);
                        }
                    }
                }

                bw.write("Case #" + count + ": " + sb.toString());
                bw.newLine();
                count++;

            }
            br.close();
            bw.close();

        } catch (Exception ex) {
            ex.printStackTrace();
        }

    }
}


