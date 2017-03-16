import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;

public class subset {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("test.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

		DecimalFormat df = new DecimalFormat();
		df.setMaximumFractionDigits(6);
		df.setMinimumFractionDigits(6);
		String line = "";
		line = br.readLine();
		int number = Integer.valueOf(line);
		for(int i = 1; i<= number; i++){
			line = br.readLine();
			String[] tokens = line.split(" ");
			int a = Integer.valueOf(tokens[0]);
			int[] b = new int[a];

			int num = 0;
			HashMap<Integer,String> sum = new HashMap<Integer,String>();
			ArrayList<Integer> now = new ArrayList<Integer>();
			for(int n = 1; n<=a; n++){
				b[n-1] = Integer.valueOf(tokens[n]);
				sum.put(b[n-1], ""+b[n-1]);
				now.add(b[n-1]);
			}
			int flag =0;
			int key = 0;
			int n =0;
			String value ="";
			while(flag != 1){
				ArrayList<Integer> pre = new ArrayList<Integer>();
				for(int j =0; j< now.size(); j++){
					key = now.get(j);
					value = sum.get(key);
					System.out.println("key:"+key+" j:"+j);
					for(n = 0; n<a; n++){
						if(key!= b[n] &&sum.containsKey(key+b[n])){

							String[] t = sum.get(key+b[n]).split(" ");
							int f = 0;
							for(int m = 0; m < t.length ;m++){

								System.out.println("key:"+key+b[n]+" "+Integer.valueOf(t[m])+" Value:"+b[n]);
								if(Integer.valueOf(t[m]) == b[n]){
									f =1;
									break;
								}
							}
							if(f == 0){
								flag =1;
								System.out.println(key+" "+b[n]);
								break;
							}
						}
						else{
							pre.add(key+b[n]);
							sum.put(key+b[n], value+" "+b[n]);
						}
					}
					if(flag == 1)
						break;
				}

				now = pre;
			}
			
			bw.append("Case #"+i+": ");
			bw.newLine();
			String tmp = value+" "+b[n];
			String[] token =  tmp.split(" ");
			int[] qw = new int[token.length];

			for(int c = 0; c< token.length; c++){
				qw[c] = Integer.valueOf(token[c]);
			}
			Arrays.sort(qw);
			for(int c = 0; c< token.length; c++){
				bw.append(qw[c]+" ");
			}
			bw.newLine();
			tmp = sum.get(key+b[n]);
			token =  tmp.split(" ");
			qw = new int[token.length];
			for(int c = 0; c< token.length; c++){
				qw[c] = Integer.valueOf(token[c]);
			}
			Arrays.sort(qw);
			for(int c = 0; c< token.length; c++){
				bw.append(qw[c]+" ");
			}
			bw.newLine();
		}
		br.close();
		bw.close();

		System.out.println("finished");
	}
}
