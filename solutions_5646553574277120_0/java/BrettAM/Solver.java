import java.io.*;
import java.util.*;

public class Solver {
    static Scanner input;
    static Writer  output;
    public static void main(String args[]) {
        if(args.length != 1){
            System.out.println("Please specify the input file");
            return;
        }

		String filename = args[0];
		File f = new File(filename);
		BufferedReader br;

        if (!f.exists()) {
            System.out.println("Couldn't find file "+filename);
            return;
        } else if (f.isDirectory()) {
            System.out.println(filename+" is a directory");
            return;
        }

        try {
			br = new BufferedReader (new FileReader (f));
			input = new Scanner(br);
        } catch (IOException iox){
		    System.out.println("Problem reading " + filename );
        }

        try {
            output = new BufferedWriter(
                        new OutputStreamWriter(
                            new FileOutputStream(filename+".out"), "utf-8"));
            solve();
        } catch (IOException ex) {
            System.out.println("Couldn't open an output file");
            return;
        }

        try{
            output.close();
            input.close();
        } catch (IOException ex) {
        }
    }

    public static void solve() throws IOException {
        int T = input.nextInt();
        for(int caseNum=0; caseNum<T; caseNum++){
            int  C = input.nextInt();
            int  D = input.nextInt();
            long V = input.nextInt();
            List<Integer> denom = new ArrayList<Integer>(D+1);
            System.out.println("using "+C+" reps to "+V+" :");
            for(int i=0; i<D; i++){
                int tmp = input.nextInt();
                denom.add(tmp);
                System.out.print(tmp+" ");
            }

            System.out.println();
            //input is presorted

            long cV = C;
            long newCoins = 0;
            if(denom.get(0)!=1){
                newCoins++;//adding a 1 coin
            } else {
                denom.remove(0);//pull the existing 1 coin
            }
            for(Integer d : denom){

                //does this make a gap?
                while(d > (cV+1)){
                    if(cV >= V) break;
                    //add coins to close gap, minding cap of V
                    System.out.println("     Adding a "+(cV+1)+" coin ("+cV+")");
                    cV += C*(cV+1);
                    newCoins++;
                }

                if(cV >= V) break;
                System.out.println("    taking a "+d+" coin ("+cV+")");
                cV += C*d;
            }
            while(V > cV){
                //add coins to close gap, minding cap of V
                System.out.println("     Adding a "+(cV+1)+" coin ("+cV+")");
                cV += C*(cV+1);
                newCoins++;
            }

            System.out.println("new coins: "+newCoins);
            output.write("Case #"+(caseNum+1)+": ");
            output.write(""+newCoins);
            output.write("\n");
        }
    }
}

