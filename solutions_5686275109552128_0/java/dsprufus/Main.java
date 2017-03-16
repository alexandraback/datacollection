import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = Integer.parseInt(in.readLine());
        for(int k = 1; k <= t; k++){
            int maxPancakes = 0;
            int specialMinutes = 0;
            int n = Integer.parseInt(in.readLine());
            int[] numPlatesOfSizeN = new int[1000];
            String[] line = in.readLine().split(" ");
            for(int i = 0; i < n; i++){
                int p = Integer.parseInt(line[i]);
                numPlatesOfSizeN[p]++;
                if(p > maxPancakes){
                    maxPancakes = p;
                }
            }
            int minTime = maxPancakes;
            boolean reductionsRemaining = true;
            while(reductionsRemaining){
                reductionsRemaining = false;
                if(maxPancakes > 3) {
                    specialMinutes += numPlatesOfSizeN[maxPancakes];
                    if (maxPancakes % 2 == 0) {
                        numPlatesOfSizeN[maxPancakes / 2] += numPlatesOfSizeN[maxPancakes] * 2;
                    } else {
                        numPlatesOfSizeN[maxPancakes / 2] += numPlatesOfSizeN[maxPancakes];
                        numPlatesOfSizeN[maxPancakes / 2 + 1] += numPlatesOfSizeN[maxPancakes];
                    }
                    maxPancakes--;
                    reductionsRemaining = numPlatesOfSizeN[maxPancakes] > 0;
                    while(numPlatesOfSizeN[maxPancakes] == 0){
                        maxPancakes--;
                        reductionsRemaining = true;
                    }
                }
               if(maxPancakes + specialMinutes < minTime){
                  minTime = maxPancakes + specialMinutes;
               }
            }
            out.print("Case #" + k + ": " +minTime);
            if(k < t)
                out.println();
        }
        out.close();
    }
}
