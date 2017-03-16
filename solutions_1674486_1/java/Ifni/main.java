import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;


public class main {
	 static public void publishResult(boolean test, int N){
		 System.out.print("Case #"+N+": ");
		 if(test)
			 System.out.print("Yes");
		 else
			 System.out.print("No");
		 System.out.println(); 
	 }
	
	 public static boolean aux(Node node, Node[] graphe){
		 for(int i = 0; i<node.link.length; i++){
			 if(graphe[node.link[i]].seen){
				 if(graphe[node.link[i]].from!=node.id)
					 return true;}
			 else{
				 graphe[node.link[i]].seen= true;graphe[node.link[i]].from=node.id;graphe[node.link[i]].start =true;
				 if(aux(graphe[node.link[i]], graphe))
					 return true;
			 }	 
		 }
		 return false;
	 }
	 
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		//Scanner res = new Scanner( new File("/home/loic/INF422/workspace/CodeJam1/bin/Result.txt"));
		int T = sc.nextInt(); int N; Node[] graphe; boolean test;
		for(int z = 0; z<T; z++){
			test= false;
			N = sc.nextInt(); graphe = new Node[N];
			for (int i = 0; i<N; i++){
				graphe[i]=new Node(i, sc.nextInt());
				for (int j = 0; j<graphe[i].link.length; j++)
					graphe[i].link[j]=sc.nextInt()-1;
			}
			for(int i = 0; i<N; i++){
				for (int j = 0; j<N; j++)
					graphe[j].seen = false;
				if(graphe[i].start)
					continue;
				test = aux(graphe[i], graphe);
				if(test)
					break;
			}
			publishResult(test, z+1);
		}
	}
}
