import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: yilin
 * Date: 14-4-12
 * Time: 下午2:27
 * To change this template use File | Settings | File Templates.
 */
public class war {

    public static int normalWar(List<Double> a, List<Double> b){
        int wins=0;
        int i=0,j=0;
        int n = a.size();
        while(i<n){
            while( j<n && b.get(j)<a.get(i)){
                wins++;
                j++;
            }
            if (j==n)
                return wins;
            i++;
            j++;
        }
        return wins;
    }

    public static int deceitfulWar(List<Double> a, List<Double> b){
        int wins=0;
        int i=0,j=0;
        int n = a.size();
        while(i<n){
            while( j<n){
                if(a.get(i)>b.get(j)){
                    wins++;
                    i++;
                    j++;
                }else{
                    i++;
                }
                if(i==n){
                    return wins;
                }
            }
        }
        return wins;
    }


    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("input"));
        PrintWriter writer = new PrintWriter("output");
        input.nextLine();
        int counter =0;
        while(input.hasNext()){
            counter++;
            input.nextLine();
            String aStr = input.nextLine();
            String bStr = input.nextLine();
            List<Double> a = new ArrayList<Double>();
            List<Double> b = new ArrayList<Double>();
            for(String s : aStr.split(" ")){
                a.add(Double.parseDouble(s));
            }
            for(String s : bStr.split(" ")){
                b.add(Double.parseDouble(s));
            }
            Collections.sort(a);
            Collections.sort(b);

            writer.printf("Case #%d: ", counter);
            writer.print(deceitfulWar(a,b)+" ");
            writer.println(normalWar(a,b));
        }
        writer.close();

    }

}
