import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.Map.Entry;

public class Second {

	private String filename;
	private String outputName;
	private int numberOfCases;
	private List<Map<Integer,Integer>> maps;
	private List<PriorityQueue<Integer>> results;


	public Second(String filename,String outputName){
		this.filename = filename;
		this.outputName = outputName;
		maps = new ArrayList();
		results = new ArrayList();
	}

	public void start(){
		readFromFile();

		computeResults();

		writeOutput();

	}




	private void computeResults() {

		for(int i = 0; i<numberOfCases;i++){
			Map<Integer,Integer> myMap = maps.get(i);
			PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
			for (Entry<Integer, Integer> entry : myMap.entrySet()) {
				if(entry.getValue()%2==1){
					pq.add(entry.getKey());
				}			

			}
			
			results.add(pq);
		}


	}

	public void readFromFile(){
		numberOfCases=0;
		Scanner scanner;
		try {
			scanner = new Scanner(new File(filename));

			numberOfCases=scanner.nextInt();


			for(int i=0;i<numberOfCases;i++){
				Map<Integer,Integer> heightMap = new HashMap<Integer,Integer>();
				String s=scanner.next();
				int N = Integer.parseInt(s);	
				for(int k =0; k<2*N-1;k++){
					for(int j= 0 ; j<N;j++){
						int height = scanner.nextInt();
						if(heightMap.containsKey(height)){
							int temp = heightMap.get(height);
							temp++;
							heightMap.put(height, temp);
						}else{
							heightMap.put(height, 1);
						}
					}
				}
				maps.add(heightMap);
			}

			scanner.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void writeOutput(){
		File file = new File(outputName);

		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		FileWriter fw;
		try {
			fw = new FileWriter(file.getAbsoluteFile());

			BufferedWriter bw = new BufferedWriter(fw);
			for(int i = 0; i<results.size(); i++){
				PriorityQueue<Integer> pq = results.get(i);
				bw.write("Case #"+(i+1)+": "+pq.poll());
				
				while(pq.peek()!=null){
					bw.write(" "+pq.poll());
				}
				bw.newLine();   
				
			}

			bw.close();

		}catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
