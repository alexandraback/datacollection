import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Ehelepola on 10/05/2015.
 */
public class Brattleship {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for(int i=0;i<t;i++){

            String [] numbers=br.readLine().split(" ");

            int r=Integer.parseInt(numbers[0]);
            int c=Integer.parseInt(numbers[1]);
            int w=Integer.parseInt(numbers[2]);

            System.out.println("Case #"+(i+1)+": "+slove(r,w,c));

        }
    }
    public static int slove(int r,int w,int c){
        int x = r * (c/w);
        if(c % w > 0){
            x = x + w;
        }else{
            x = x + w - 1;
        }
        return x;
    }
}
