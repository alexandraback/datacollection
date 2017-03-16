import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.HashSet;
import java.util.Set;

public class Sheep {


    public static void main(String[] args) throws Exception {
    	Sheep object = new Sheep();
        String className = object.getClass().getSimpleName();

        FileReader fileReader = new FileReader(new File(className.toLowerCase()
                + ".in"));
        StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

        FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

        st.nextToken();
        int testCases = (int) st.nval;

        for (int tc = 1; tc <= testCases; tc++) {

            System.out.println("At test " + tc + "/" + testCases);

            st.nextToken();
            int N = (int) st.nval;


            String result = object.solve(N);
            wr.write("Case #" + tc + ": " + result + "\r\n");
        }

        wr.close();
    }

    public String solve(long N) {

    	if(N == 0){
    		return "INSOMNIA";
    	}
    	
    	Set<Integer> left = new HashSet<>();
    	for(int i=0; i<10; i++)
    		left.add(i);
    	
    	for(int i=1; i <= 1000000000 && left.size() != 0; i++){
    		
    		long current = N * i;
    		long z = current;
    		
    		while(z > 0){
    			left.remove((int)(z % 10));
    			z /= 10;
    		}
    		
    		if(left.size() == 0){
    			return String.valueOf(N * i);
    		}
    	}
    	
    	return "INSOMNIA";    	
    }
}
