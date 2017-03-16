import java.io.BufferedReader;
import java.io.FileReader;

/**
 * Created by IntelliJ IDEA.
 * User: frankf
 * Date: 4/26/13
 * Time: 5:02 PM
 * To change this template use File | Settings | File Templates.
 */
public class Round1A_A {

    public static void main(String[] args) throws Exception{
        String fileName = "/tmp/A-small-attempt0.in";
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        int totalCases = new Integer(br.readLine()).intValue();

        for( int x = 0; x< totalCases; x++){
            String[] nAndM = br.readLine().split(" ");
            int r = Integer.valueOf(nAndM[0]);
            int t = Integer.valueOf(nAndM[1]);

            String result = evaluateLine(r,t);


            System.out.println("Case #"+(x+1)+": "+result);
        }
    }


    public static String evaluateLine(int radius, int paintLeft){
        int ringsPainted = 0;
        int alreadyCovered = radius*radius;
        int r = radius;
        r=r+1;
        while( paintLeft > 0){

            int fullCirclePaint = r*r;
            int requiredPaint = fullCirclePaint - alreadyCovered;
            //System.out.println("required="+requiredPaint+" left="+paintLeft);
            if( requiredPaint <= paintLeft ){
                ringsPainted++;
            }else{
                break;
            }
            paintLeft -= requiredPaint;

            r = r+1;
            alreadyCovered = r*r;

            r=r+1;
            //System.out.println("PaintLeft="+paintLeft+": and ringsDone="+ringsPainted);
        }
        return String.valueOf(ringsPainted);
    }

}
