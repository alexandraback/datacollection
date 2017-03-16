import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class kingdom {
		public static int getMinValueIndex(int[] numbers){
		  int minValue = Integer.MAX_VALUE;
		  int index = -1;
		  for(int i=0;i<numbers.length;i++){
		    if(numbers[i] < minValue && numbers[i] != -1){
			  minValue = numbers[i];
			  index = i;
			}
		  }
		  return index;
		}
		
		private static void sortarray(int[] a1, int[] a2){
			   
			int i,j;

			for (i=0; i<a1.length; i++)
			        for (j=a1.length -1; j>=i+1; j--)
			        if (a1[j-1] > a1[j])
			        {
			            int t =   a1[j-1];
			            a1[j-1] = a1[j];
			            a1[j] = t;
			            t =   a2[j-1];
			            a2[j-1] = a2[j];
			            a2[j] = t;
			        }
			}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		FileInputStream file = new FileInputStream(args[0]);
        //DataInputStream in = new DataInputStream(file);
        Scanner ins = new Scanner(file);
        BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
        int t = ins.nextInt();      
        for (int i = 0; i < t; i++){
        	int n = ins.nextInt();
        	int p[] = new int[n];
        	int s[] = new int[n];
        	for (int j = 0; j < n; j++){
        		p[j] = ins.nextInt();
        		s[j] = ins.nextInt();
        	}
        	sortarray(s, p);
        	int stars = 0;
        	boolean changed = true;
        	int played = 0;
        	while (changed){
        		changed = false;
        		for (int k = 0; k < s.length; k++){
        			if (s[k] != -1 && s[k] <= stars){
        				stars++;
            			s[k] = -1;
            			if (p[k] != -1){
            			    p[k] = -1;
            			    stars++;
            			}
            			changed = true;
            			played++;
        			}
        		}
        		if (!changed) {
        			for (int k = s.length -1; k >= 0; k--){
        				if (p[k] != -1 && p[k] <= stars){
        					played++;
            		    	p[k] = -1;
            		    	stars++;
            		    	changed = true; break;
        				}
        			}
        		}
        	}
        	int si = getMinValueIndex(s);
        	if (si == -1){ 
        		out.write("Case #"+ (i+1) +": " + played);
        		out.newLine();
        	}else{
        		out.write("Case #"+ (i+1) +": Too Bad");
        		out.newLine();
        	}
        }
        ins.close();
        out.close();
        file.close();

	}

}
