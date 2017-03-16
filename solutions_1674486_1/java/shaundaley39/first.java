import java.awt.List;
import java.io.*;
import java.util.ArrayList;
import java.util.Stack;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class first {
	public static void main(String args[]){
		File file = new File("../../Downloads/A-small-attempt1.in");
		StringBuffer output = new StringBuffer ("");
        try {
            Scanner scanner = new Scanner(file);
            int T= Integer.parseInt(scanner.nextLine());
            for(int i=0; i<T; i++) {
            	boolean Diamand = false;
            	int N = Integer.parseInt(scanner.nextLine());
            	boolean[] nodeRoot = new boolean[N];
            	boolean[] expanded = new boolean[N];
            	ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>();
            	for (int j=0; j<N; j++){
            		lists.add(new ArrayList<Integer>());
            	}
            	for (int j=0; j<N; j++){
            		nodeRoot[j] = true;
            		expanded[j]=false;
            		String[]  L = scanner.nextLine().split(" ");
            		if (Integer.parseInt(L[0])!=0){
            			nodeRoot[j] = false;
            			int[] L2 = new int[L.length-1];
                		for (int k=1; k<L.length; k++){
                			lists.get(Integer.parseInt(L[k]) -1).add(j);
                		}
            		}
                }
            	for (int j=0; j<N; j++){
            		if (nodeRoot[j]){
            			for (int m=0; m<N; m++){
            				expanded[m]=false;
            			}
            			Stack<Integer> S = new Stack<Integer>();
            			S.add(j);
            			while(S.isEmpty()==false){
            				int next = S.pop();
            				if(expanded[next]){
            					Diamand=true;
            				}
            				expanded[next]=true;
            				ArrayList<Integer> children =  lists.get(next);
            				for (int k=0; k<children.size(); k++){
            					S.push(children.get(k));
            				}
            			}
            		}
            	}
                output= output.append("Case #");
                output= output.append(i+1);
                output= output.append(": ");
                if (Diamand){
                	output = output.append("Yes \n");
                }else{
                	output = output.append("No \n");
                }
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try{
        	  FileWriter fstream = new FileWriter("../../Downloads/A-small.out");
        	  BufferedWriter out = new BufferedWriter(fstream);
        	  out.write(output.toString());
        	  out.close();
        	  }catch (Exception e){//Catch exception if any
        	  System.err.println("Error: " + e.getMessage());
        	  }
	}	
}