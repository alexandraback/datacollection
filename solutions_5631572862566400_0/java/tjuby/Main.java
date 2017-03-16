import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	public static List<Integer> list;
	
	public static class Node{
		public int value;
		public int depth = 0;
		public boolean t = false; 
		public boolean r = false;
		public Node(int value){
			this.value = value;
		}
	}
	
	public static int findLongest(Node[] f, int index, int count){
		f[index].t = true;
		if(!f[f[index].value].t){
			f[index].depth = count;
			return findLongest(f, f[index].value, count+1);
		}
		else{
			int value = index;
			int initialValue = value;
			f[value].r = true;
			value = f[index].value;
			while(initialValue != value){
				f[value].r = true;
				value = f[value].value;
			}
			int result = count - f[f[index].value].depth + 1;
			if(result == 2){
				list.add(index);
				list.add(f[index].value);
			}
			if(result == 2 && count > 2){
				for(int i = 0; i < f.length; ++i){
					if(!f[i].t && f[i].value == index){
						++count;
						break;
					}
				}
				return count;
			}else
				return result;
		}
	}
	
	public static void twoT(Node[] nodes, int index){
		if(!nodes[index].t){
			nodes[index].t = true;
			if(nodes[index].value == -1)
				return;
			twoT(nodes, nodes[index].value);
		}
	}
	
	
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		//Scanner scanner = new Scanner(new FileInputStream(new File("C-small-attempt2.in")));
		//FileOutputStream fo = new FileOutputStream(new File("output.out"));
		int t = scanner.nextInt();
		for(int x = 1; x <= t; ++x){
			int n = scanner.nextInt();
			List<Integer> size = new ArrayList<Integer>();
			Node[] f = new Node[n];
			list = new ArrayList<Integer>();
			for(int i = 0; i < n; ++i){
				f[i] = new Node(scanner.nextInt()-1);
			}
			for(int i = 0; i < n; ++i){
				if(!f[i].r){
					size.add(findLongest(f, i, 1));
				}
				for(int j = 0; j < f.length; ++j)
					f[j].t = false;
			}
			Node[] nodes = new Node[n];
			for(int i = 0; i < f.length; ++i){
				nodes[f[i].value] = new Node(i);
			}
			for(int i = 0; i < f.length; ++i){
				if(nodes[i] == null)
					nodes[i] = new Node(-1);
			}
			for(int i = 0; i < list.size(); ++i){
				twoT(nodes, list.get(i));
			}
			int sum = 0;
			for(int i = 0; i < nodes.length; ++i){
				if(nodes[i].t)
					++sum;
			}
			int result = Math.max(sum, Collections.max(size));
			String output = "Case #" + x + ": " + result + "\n";
			System.out.print(output);
			//fo.write(output.getBytes());
		}
		//fo.flush();
		//fo.close();
	}
}
