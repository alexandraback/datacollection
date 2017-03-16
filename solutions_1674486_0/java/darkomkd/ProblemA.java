import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;


public class ProblemA {

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileInputStream fstream = new FileInputStream("problemA.txt");
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		FileWriter outFile = new FileWriter("problemAout.txt");
		PrintWriter out = new PrintWriter(outFile);
		String strLine;
		int n=Integer.parseInt(br.readLine());
		for (int i=0;i<n;i++){
			boolean hasDiamond=false;
			int k=Integer.parseInt(br.readLine());
			int [][]graph=new int[k][k];
			for (int j=0;j<k;j++)
				for (int z=0;z<k;z++)
					graph[j][z]=0;
			for (int j=0;j<k;j++){
				strLine=br.readLine();
				String[] lineNum=strLine.split(" ");
				int l=Integer.parseInt(lineNum[0]);
				for (int z=0;z<l;z++){
					graph[j][Integer.parseInt(lineNum[z+1])-1]=1;
				}
			}
			LinkedList<Integer> roots=new LinkedList<Integer>();
			LinkedList<Integer> leafes=new LinkedList<Integer>();
			for (int j=0;j<k;j++){
				int z;
				for (z=0;z<k;z++)
					if (graph[j][z]!=0)
						break;
				if (z==k)
					roots.add(j);
				z=0;
				for (z=0;z<k;z++)
					if (graph[z][j]!=0)
						break;
				if (z==k)
					leafes.add(j);
			}
			System.out.println("Roots:"+roots);
			System.out.println("Leafes:"+leafes);
			for (int a=0;a<roots.size();a++)
				for (int b=0;b<leafes.size();b++)
				{
					if (hasDiamond)
						break;
					int root=roots.get(a);
					int leaf=leafes.get(b);
					
					int ways=0;
					LinkedList<Integer> stack=new LinkedList<Integer>();
					stack.add(root);
//					System.out.println("Stack:"+stack);
					while (stack.size()!=0&&ways!=2){
						int current=stack.removeFirst();
						if (current==leaf){
							ways++;
							if (ways==2)
								hasDiamond=true;
						}
						for (int j=0;j<k;j++)
							if (graph[j][current]==1)
								stack.addLast(j);
//						System.out.println("Stack:"+stack);
					}
				}
			if (i<n-1)
				out.println("Case #"+(i+1)+": "+(hasDiamond ?"Yes":"No"));
			else
				out.print("Case #"+(i+1)+": "+(hasDiamond ?"Yes":"No"));
//			System.out.println("HasDiamond:"+hasDiamond);
//			for (int j=0;j<k;j++){
//				for (int z=0;z<k;z++)
//					System.out.print(graph[j][z]+" ");
//				System.out.println();
//			}
		}
		out.close();
		
	}

}
