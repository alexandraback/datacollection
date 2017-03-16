import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("c.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("c.out"));
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			int J = s.nextInt();
			int P = s.nextInt();
			int S = s.nextInt();
			K = s.nextInt();
			out.write("Case #"+t+": "); 
			list = new ArrayList<Node>();
			for(int i=1; i<=J; i++){
				for(int j=1; j<=P; j++){
					for(int k=1; k<=S; k++){
						list.add(new Node(i,j,k));
					}
				}
			}
			ans=0;
			m12 = new int[4][4];
			m13 = new int[4][4];
			m23 = new int[4][4];
			doit(0, 0, new LinkedList<Node>());
			out.write(ans+"\n");
			for(Node n : ansList){
				out.write(n.x+" "+n.y+" "+n.z+"\n");
			}
		}
		out.close();
	}
	
	public static void doit(int curr, int answer, LinkedList<Node> currList){
		if(answer+list.size()-curr<ans)
			return;
		if(curr>=list.size()){
			updateAnswer(answer, currList);
			return;
		}
		Node n = list.get(curr);
		if(m12[n.x][n.y]<K && m13[n.x][n.z]<K && m23[n.y][n.z]<K){
			m12[n.x][n.y]++;
			m13[n.x][n.z]++;
			m23[n.y][n.z]++;
			currList.addLast(n);
			doit(curr+1, answer+1, currList);
			currList.removeLast();
			m12[n.x][n.y]--;
			m13[n.x][n.z]--;
			m23[n.y][n.z]--;
		}
		doit(curr+1, answer, currList);
	}
	
	private static void updateAnswer(int answer, LinkedList<Node> currList) {
		if(answer>ans){
			ans=answer;
			ansList= new LinkedList<Node>(currList);
		}
	}

	static int ans;
	static int K;
	static List<Node> ansList;
	static List<Node> list;
	static int[][] m12;
	static int[][] m13;
	static int[][] m23;
	
	public static class Node{
		int x,y,z;

		public Node(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
	}
	
	/**
	 * 
	 * @param value - array of bits to modified
	 * @param index - index of the bit to turn on
	 * @return array modified
	 */
	public static int onB(int value, int index){
    	return value|(1<<index);
    }
    
	/**
	 * 
	 * @param value - array of bits to modified
	 * @param index - index of the bit to turn off
	 * @return array modified
	 */
    public static int offB(int value, int index){
    	int aux = (1<<index);
    	return value & (~aux);
    }
    
    /**
     * 
     * @param value - array of bits
     * @param index - index of the bit to return
     * @return true if the bit is on, false otherwise
     */
    public static boolean getB(int value, int index){
    	return (value>>index)%2==1;
    }
}