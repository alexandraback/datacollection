import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;


public class codejam111 {
	public static void main(String[] args) throws IOException{
		readFile();
	}
	public static String[] getResult(int[] array, int sum, int count){
		String[] results = new String[count]; 
		DecimalFormat df = new DecimalFormat("0.000000");
		for(int i=0; i<count; i++){
			double perct =(2.0*sum/count - array[i])*100/sum;
			results[i] = df.format(perct);
		}
		return results;
	}
	public static void readFile() throws IOException{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
            FileReader input = new FileReader("in.txt");
            BufferedReader bufRead = new BufferedReader(input);	
            String line = bufRead.readLine();
            int i = 1;
            while (line != null){
            	String[] splitResult = line.split(" ");
            	int sum = 0;
            	int count = Integer.parseInt(splitResult[0]);
            	int array[] = new int[count];
            	for(int j = 0; j< count; j++){
            		array[j] = Integer.parseInt(splitResult[j+1]);
            		sum = sum + array[j];
            	}
            	out.write("Case #" + i + ":");
            	String[] results = getResult(array,sum,count);
            	for(int j = 0; j< count; j++){
            		out.write(" " + results[j]);
            	}
          	  	line = bufRead.readLine();
          	  if(line!=null)
        	  		out.write('\n');
          	  	i++;
            }             
            bufRead.close();
            out.close();
	}
}
