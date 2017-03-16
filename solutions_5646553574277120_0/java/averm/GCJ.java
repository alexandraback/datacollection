
/**
 *
 * @author amit
 */
import java.io.*;
import java.util.*;

public class GCJ {

    BufferedReader rin;
    BufferedWriter wout;
    int numCases;

    public String getNextInput() {
        try {
            String[] line = rin.readLine().split(" ");
            int c = Integer.parseInt(line[0]);
            int d = Integer.parseInt(line[1]);
            long v = Long.parseLong(line[2]);
            line = rin.readLine().split(" ");
            
            List<Integer> cl = new LinkedList<Integer>();
            for (int i=0;i<line.length;i++)
                cl.add(Integer.parseInt(line[i]));
           
            int num=0;
            long mr = 0;
            int i=0;
            while(mr<v) {
                if(i<cl.size()){
                    if(mr+1<cl.get(i)){
                        mr =  mr + mr + 1;
                        num++;
                    }
                    else {
                        mr += cl.get(i);
                        i++;
                    }
                }
                else {
                    mr =  mr + mr + 1;
                    num++;
                }
            }
            
            return Integer.toString(num);
        } catch (IOException e) {
            System.out.println("File Error! Could not read line from file");
        }
        return null;
    }

    public void writeNextOutput(String s) {
        try {
            wout.write(s);
            wout.write("\n");
        } catch (IOException e) {
            System.out.println("Error! Could not write to the file!");
        }
    }

    public GCJ(String s1, String s2) {
        try {
            rin = new BufferedReader(
                    new FileReader(s1));
            wout = new BufferedWriter(new FileWriter(s2));
            numCases = Integer.parseInt(rin.readLine());

            for (int i = 1; i <= numCases; i++) {
                System.out.println("case#" + i);
                String sout = getNextInput();
                sout = "Case #" + Integer.toString(i) + ":" + " " + sout;
                writeNextOutput(sout);
                //System.out.println("case#" + i);
            }
            rin.close();
            wout.close();
        } catch (IOException e) {
            System.out.println("File error");
            System.exit(0);
        }
    }

    public static void main(String[] args) {/*
         if (args.length!=2) {
         System.out.println("Enter input file!");
         System.exit(0);
         }*/

        GCJ a = new GCJ("infile.txt", "out.txt");
    }
}
