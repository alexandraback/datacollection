package com.google.codejam.B;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Diamond {
	public static void main(String[] args) {
		String line = null;
		BufferedReader reader = null;
		File file = new File("c:\\write.txt");
		BufferedWriter  output = null;
		try {
			output = new BufferedWriter(new FileWriter(file));
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			reader = new BufferedReader(new FileReader("c:\\temp1.txt"));
			line = reader.readLine();
			int n = Integer.parseInt(line);
			for (int i=0;i<n;i++){
				line = reader.readLine();
				int nodes = Integer.parseInt(line);
				Node[] nodeArr = new Node[nodes];
				for (int j=0;j<nodes;j++){
					nodeArr[j] = new Node();
				}
				for (int j=0;j<nodes;j++){
					line = reader.readLine();
					String arr[] = line.split(" ");
					int d = Integer.parseInt(arr[0]);
					Node node = nodeArr[j];
					for (int k=0;k<d;k++){
						int nodeno = Integer.parseInt(arr[k+1]);
						node._providers.add(nodeArr[nodeno-1]);
						nodeArr[nodeno-1]._consumers.add(node);
					}
				}
				boolean isLoop = false;
				for (int j=0;j<nodes;j++){
					if (nodeArr[j]._providers.size()==0){
						isLoop = checkifLoop(nodeArr[j],nodeArr);
						if (isLoop){
							break;
						}
					}
				}
				if (isLoop){
					output.write("Case #"+(i+1)+": Yes");
				}else{
					output.write("Case #"+(i+1)+": No");
				}
				if (i!=n){
					output.write("\n");
				}
//				output.write(count+"");
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				reader.close();
				output.close();
			
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}

	private static boolean checkifLoop(Node node, Node[] nodeArr) {
		for (int i=0;i<nodeArr.length;i++){
			nodeArr[i].visited=false;
		}
		Queue<Node> queue = new LinkedList<Node>();
		node.visited=true;
		queue.add(node);
		while (!queue.isEmpty()){
			Node n = queue.remove();
//			n.visited=true;
			List<Node> list = n._consumers;
			for (Node nn: list){
				if (nn.visited==true){
					return true;
				}
				nn.visited=true;
				queue.add(nn);
			}
		}
		return false;
	}

}

class Node{
	int n;
	boolean visited = false;
	List<Node> _providers = new ArrayList<Node>();
	List<Node> _consumers = new ArrayList<Node>();
}
