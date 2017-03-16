import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;


public class DancingGooglers {

    /**
     * Google Code Jam 2012: Problem B. Dancing With the Googlers
     * @author hullarb
     * @param args
     * @throws IOException 
     * @throws NumberFormatException 
     */
    public static void main(String[] args) throws NumberFormatException, IOException {
	BufferedReader input = new BufferedReader(new FileReader(args[0]));
	OutputStreamWriter out = new OutputStreamWriter(new FileOutputStream(args[0].contains("in")?args[0].replace("in", "out"):args[0] + ".out"));
	int testCases = Integer.parseInt(input.readLine());
	for(int i = 0; i < testCases; i++) {
	    String[] parts = input.readLine().split(" ");
	    int N = Integer.parseInt(parts[0]);
	    int S = Integer.parseInt(parts[1]), p = Integer.parseInt(parts[2]);
	   // System.out.println("N: " + N + " S: " + S + " p: " +p);
	    int t[] = new int[N];
	    int bests[] = new int[N];
	    for(int j = 0; j < N; j++) {
		t[j] = Integer.parseInt(parts[3 + j]);
		bests[j] = notSurp(t[j]);
		//System.out.println("NotSurp(" +t[j] + "): " + bests[j]);
	    }
	    for(int j = 0; j < N; j++) {
		if(S == 0)
		    break;
		if((t[j] > 1 && t[j] < 29) && (bests[j] == -1 ||
			bests[j] < p)) {
		    int ns = surp(t[j]);
		    //System.out.println("Surp(" +t[j] + "): " + ns);
		    if(bests[j] == -1 && ns == -1) {
			System.err.print("Something went wrong with t: " + t[j]);
		    	continue;
		    }
		    if(ns >= p) {
			bests[j] = ns;
			S--;
		    }else{
			if(bests[j] == -1){
			    S--;
			}
		    }		    
		}
	    }
	    int result = 0;
	    for(int j = 0; j < N; j++)
		if(bests[j] >= p)
		    result++;
	    out.write("Case #" + (i + 1) + ": " + result + "\n");
	}
	out.close();
	input.close();
    }

    private static int surp(int i) {
	if(i == 2)
	   return 2;
	if((i - 2) % 3 == 0)
	    return (i - 2) / 3 + 2;
	if((i - 3) % 3 == 0)
	    return (i - 3) / 3 + 2;
	if(i > 3 && (i - 4) % 3 == 0)
	    return (i - 4) / 3 + 2;
	return -1;
    }

    private static int notSurp(int i) {
	if(i == 0)
	    return 0;
	if(i < 3 )
	    return 1;
	if((i - 2) % 3 == 0)
	    return (i - 2) / 3 + 1;
	if((i - 1) % 3 == 0)
	    return (i - 1) / 3 + 1;
	if(i % 3 == 0)
	    return i / 3;
	return -1;
    }

}
