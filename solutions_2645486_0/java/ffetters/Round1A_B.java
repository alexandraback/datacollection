import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by IntelliJ IDEA.
 * User: frankf
 * Date: 4/26/13
 * Time: 5:02 PM
 * To change this template use File | Settings | File Templates.
 */
public class Round1A_B {

    public static int MAX;
    public static void main(String[] args) throws Exception{
        String fileName = "/tmp/B-small-attempt0.in";
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        int totalCases = new Integer(br.readLine()).intValue();

        for( int x = 0; x< totalCases; x++){
            String[] nAndM = br.readLine().split(" ");
            int max = Integer.valueOf(nAndM[0]);
            MAX = max;
            int regain = Integer.valueOf(nAndM[1]);
            int eventCount = Integer.valueOf(nAndM[2]);

            String [] events = br.readLine().split(" ");

ArrayList<String> eList = new ArrayList<String>();
for(int xx=0;xx<events.length;xx++){
    eList.add(events[xx]);
}
            int result = eval(max, regain, 0, eList);
            //String result = evaluateLine(events,max,regain);


            System.out.println("Case #"+(x+1)+": "+result);
        }
    }


    public static String evaluateLine(String[]events, int max, int regain){
        int gain = 0;
        if( max==regain){
            int c = events.length;
            for(int a=0;a<c;a++){
                gain += Integer.valueOf(events[a]) * max;
            }
        }else{
            int c=  events.length;
            for(int a =0;a<c;a++){
                for( int b = 0;b<max;b++){

                }

            }
            return "";
        }
        return String.valueOf(gain);
    }

    public static int eval(int currentEnergy, int regain, int gained, ArrayList<String> eventsLeft){
        //System.out.println("CurrentEnergy="+currentEnergy+" gained="+gained +":eventsLeft="+eventsLeft);
        if( eventsLeft.size() == 0 ){
            return gained;
        }

        int maxGain = 0;
        for( int x=0;x<=currentEnergy;x++){
            String cur = eventsLeft.get(0);
            ArrayList<String> newEventsLeft = new ArrayList<String>();
            newEventsLeft.addAll(eventsLeft);
            newEventsLeft.remove(0);
            int thisGained = gained;
            thisGained = thisGained + (Integer.valueOf(cur)*x);

            int newEnergy = currentEnergy-x+regain;
            if(newEnergy > MAX){
                newEnergy = MAX;
            }
            int curGain = eval(newEnergy, regain, thisGained, newEventsLeft );
            if( maxGain < curGain){
                maxGain = curGain;
            }
        }
        return maxGain;
    }



}
