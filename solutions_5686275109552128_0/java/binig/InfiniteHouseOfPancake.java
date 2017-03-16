import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by benoi_000 on 4/11/2015.
 */
public class InfiniteHouseOfPancake {


    public static void main(String args[]) throws IOException {
        InputStream inputStream = args.length<1?System.in:Thread.currentThread().getContextClassLoader().getResourceAsStream(args[0]);
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        PrintStream out = args.length<2?System.out:new PrintStream(new FileOutputStream(args[1]));
        int nbPb = Integer.parseInt( reader.readLine());
        for (int i=0;i<nbPb;i++) {
            processLine(i+1, Integer.valueOf(reader.readLine()), reader.readLine(),out);
        }

    }

    // you need to move at least 2 to be worth it
    // and have a stack of 4 , moving 2 from 3 is useless
    // decide how to split ?  well if
    private static void processLine(int caseNb, int nbPlate , String s, PrintStream out) {

        List<Integer> plates= new ArrayList<Integer>();
        int startIdx =0;
        for (int i=0;i<nbPlate;i++) {
            int spaceIdx = s.indexOf(' ',startIdx);
            plates.add(Integer.valueOf( i==nbPlate-1?s.substring(startIdx):s.substring(startIdx, spaceIdx)));
            startIdx = spaceIdx+1;
        }


        int min = processPlates(0, plates);



        out.println( "Case #" +
                + caseNb+
                ": " +
                min  );
    }

    private static int processPlates(int exchange, List<Integer> plates) {
        Collections.sort(plates);
        int max = plates.get(plates.size()-1);
        int min = max+exchange;
        if (max>exchange+2) {
            for (int i = 1; i <= max / 2; i++) {
                List<Integer> platesRec = new ArrayList<Integer>(plates.size() + 1);
                if (plates.size()>1)
                    platesRec.addAll(plates.subList(0, plates.size() - 1));
                platesRec.add(i);
                platesRec.add(max - i);
                min = Math.min(processPlates(exchange + 1, platesRec), min);
            }
            return min;
        } else {
            return exchange+max;
        }
    }

    private static int processRecurse(int exchange, List<Integer> plates) {
        int max = plates.get(plates.size()-1);
        int min = max;
        while (max>exchange+2) {
            //special case with 9
            boolean onlyNine = plates.size()<2 || plates.get(plates.size()-1)!=9;
            int toMove =max==9&&onlyNine?3: max/2;
            plates.set(plates.size()-1,toMove);
            plates.add(max-toMove);
            Collections.sort(plates);
            max = plates.get(plates.size()-1);
            exchange ++;
            min = Math.min(exchange+max,min);
        }
        return min;
    }


}
