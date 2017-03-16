package codeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class NewLotteryGame{

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new FileReader("_input.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("_output.in"));

        br.readLine();//first line for the case count
        String line = null;
        int index = 1;
        
        while((line = br.readLine())!=null){
            int ans = 0;
            String[] input = line.split(" ");
            int A = Integer.parseInt(input[0]);
            int B = Integer.parseInt(input[1]);
            int K = Integer.parseInt(input[2]);
            
            if(K>=A && K>=B){
                ans = A * B;
            }
            else if(K<A && K<B){
                ans += K * B + (A-K) * K;
                for(int i = K; i<A; i++){
                    for(int j = K; j<B; j++){
                        if((i & j) < K){
                            ans++;
                        }
                    }
                }
            }
            else {
                ans = A*B;
            }
            bw.append("Case #" + index++ + ": " + ans + "\n");
        }

        br.close();
        bw.close();

    }

}
