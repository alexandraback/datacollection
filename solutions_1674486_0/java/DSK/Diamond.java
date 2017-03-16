package b1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Diamond {
	final static String CASE_NO = "Case #";
	final static String SUFFIX = ": ";
	
	public static void main(String[] args) throws Exception {
		int total;
		int T; // nuber of test cases

		BufferedReader br = readFile("testA");

		T = Integer.parseInt(br.readLine());
		total = T;

		while (T > 0) {
			T--;
			int N = Integer.parseInt(br.readLine());
			int noOfClasses[] = new int[N];
			Map<Integer,Integer[]> classMap = new HashMap<Integer,Integer[]>();
			
			
			for(int x = 0; x<N; x++){
				String line = br.readLine();
				String[] input = line.split(" ");
				int i = 0;
				int y= Integer.parseInt(input[i++]);
				noOfClasses[x] = y ;
				Integer temp[] = new Integer[y];
				for(int j =0; j<y;j++){
					temp[j]=Integer.parseInt(input[i++]);
				}
				classMap.put(x+1, temp);
				
			}
			
			boolean done = false;
			for(int x = 0; x<N; x++){
				if(done)break;
				int no = noOfClasses[x];
				if( no > 1){
					List<Integer> path= new ArrayList<Integer>();
					getPathArray(classMap, x+1, path);
					Integer pathArray[]= new Integer[path.size()]; 
							path.toArray(pathArray);
							for(int m=0;m<pathArray.length;m++){
								if(done)break;
								for(int n=(m+1);n<pathArray.length;n++){
									if(pathArray[m]==pathArray[n]){
										System.out.println(CASE_NO + (total - T) + SUFFIX + "Yes");
										done= true;
										break;
									}
								}
							}
					
					
				}
				else{
					continue;
				}
			}
			if(!done)System.out.println(CASE_NO + (total - T) + SUFFIX + "No");
		}
	}
	
	private static void getPathArray(Map<Integer,Integer[]> m, int c, List<Integer> path){
		//List<Integer> path= new ArrayList<Integer>();
		
		Integer i[] = m.get(c);
		for(int x=0;x<i.length;x++){
			if(i[x]==0){
				return;
			}
			path.add(i[x]);
			getPathArray(m,i[x],path);
		}
	}
	private static BufferedReader readFile(String fileName)
			throws FileNotFoundException {

		FileReader fr = new FileReader(fileName);
		BufferedReader br = new BufferedReader(fr);
		return br;
	}
}
