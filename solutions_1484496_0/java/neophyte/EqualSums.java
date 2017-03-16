package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;


public class EqualSums {

	private static int n;
	private static Map<Integer, String> values;
	private static List<Integer> s;
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		BufferedReader fin = null;
		int t = 0;
		StringTokenizer str = null;
		
		try {
			fin = new BufferedReader(new FileReader(new File("C-small-attempt0.in")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
			
			
			try {
				t = Integer.parseInt(fin.readLine());
				//System.out.println(t);
			} catch (NumberFormatException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			
			
			
			for(int i=0;i<t;i++){
				System.out.println("Case #"+(i+1)+": ");
				try {
					
					str=new StringTokenizer(fin.readLine());
					n = Integer.parseInt(str.nextToken());
					values = new HashMap<Integer,String>(1000);
					s = new ArrayList<Integer>();
					
					for(int j=0;j<n;j++){
					
					s.add(Integer.parseInt(str.nextToken()));
						
					}
					
				}
				catch (IOException e) {
					e.printStackTrace();
				}
				
			
				int setSize = s.size();
				int finalValue = (int) (Math.pow(2, setSize));
				String bValue1 = "";
				int i1;
				for (i1 = 0; i1 < finalValue; i1++) {
					bValue1 = Integer.toBinaryString(i1);
					int bValueSize = bValue1.length();
					for (int k = 0; k < (setSize - bValueSize); k++) {
						bValue1 = "0" + bValue1;
					}
					
					int sum =0;
					String bValue = new StringBuffer(bValue1).reverse().toString();
					for (int j = 0; j < setSize; j++) {
						if (bValue.charAt(n-j-1) == '1') {
							sum+=s.get(n-j-1);
						}
				
					}
					if(values.containsKey(sum)){
						for (int j = 0; j < setSize; j++) {
							if (values.get(sum).charAt(j) == '1')
							System.out.print(s.get(j)+" ");
					
						}
						System.out.println();
						for (int j = 0; j < setSize; j++) {
							if (bValue.charAt(j) == '1')
							System.out.print(s.get(j)+" ");
					
						}
						break;
					}
					else
						values.put(sum,bValue);
					
				}
				if(i1>=finalValue)
					System.out.println("Impossible");
					
				
			}
			
	}
}
