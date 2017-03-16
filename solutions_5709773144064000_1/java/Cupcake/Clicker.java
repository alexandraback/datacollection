import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: yilin
 * Date: 14-4-12
 * Time: 上午12:14
 * To change this template use File | Settings | File Templates.
 */
public class Clicker {
    public static double time(double c, double f, double x){
        double cookiePerSecond =2;
        double buyingTime=c/cookiePerSecond;
        double minTime=c/f;
        double reachingTime=x/cookiePerSecond;
        double totalTime=0;
        while(reachingTime>minTime+buyingTime){
            //brought farm
            totalTime+=buyingTime;
            cookiePerSecond+=f;

            buyingTime=c/cookiePerSecond;
            reachingTime=x/cookiePerSecond;
        }
        return totalTime+reachingTime;

    }
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("input"));
        PrintWriter  writer = new PrintWriter("output");
        input.nextLine();
        int counter =0;
        double c,f,x;
        while(input.hasNext()){
            counter++;
            c=input.nextDouble();
            f=input.nextDouble();
            x=input.nextDouble();
            writer.printf("Case #%d: ", counter);
            writer.println(time(c, f, x));
            System.out.println(time(c,f,x));
        }
        writer.close();

    }
}
