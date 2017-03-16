import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;


public class DiamondInheritance {

	private static FileReader freader;
	private static BufferedReader buffreader;
	private static FileWriter fwriter;
	private static BufferedWriter buffwriter;
	
	public static void main(String[] args) throws IOException {
		freader = new FileReader("A-small-attempt0.in");
		buffreader = new BufferedReader(freader);
		fwriter= new FileWriter("result-small.txt");
		buffwriter = new BufferedWriter(fwriter);
		String str = null;
		int linenum = 0;
		int i=1;
		while((str=buffreader.readLine())!=null){
			if(i==1)
				linenum=Integer.parseInt(str);
			else{
				int num = Integer.parseInt(str);
				ArrayList<Integer>[] graph = new ArrayList[num];
				for(int j=0; j<num; j++){
					str=buffreader.readLine();
					int links = Integer.parseInt(str.split(" ")[0]);
					graph[j] = new ArrayList<Integer>();
					for(int k=0; k<links; k++){
						int node = Integer.parseInt(str.split(" ")[k+1]);
						graph[j].add(node-1);
					}						
				}
				boolean flag = diamondInheritCheck(num, graph);
				String finalStr = "Case #"+Integer.toString(i-1)+": ";
				if(flag==true)
					finalStr+="Yes\n";
				else
					finalStr+="No\n";
				System.out.println(finalStr);
				buffwriter.write(finalStr);
			}
			i++;
		}
		buffwriter.close();
		fwriter.close();
		buffreader.close();
		freader.close();

	}
	
	public static boolean diamondInheritCheck(int size, ArrayList<Integer>[] graph){
		int[] count = new int[size];
		for(int i=0; i<size; i++){
			Arrays.fill(count, 0);
			LinkedList<Integer> queue = new LinkedList<Integer>();
			queue.add(i);
			while(queue.size()>0){
				int node = queue.remove(0);
				count[node]++;
				if(count[node]>=2)
					return true;
				for(int val: graph[node])
					queue.add(val);
			}
		}
		return false;
	}

}
