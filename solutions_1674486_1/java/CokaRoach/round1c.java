import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class round1c{
	
	public static void main(String[] args){
		round1c.solve();
	}
	
	private static void solve(){
		String fileName = "A-large.in";
		String outputFileName = fileName;
		if(outputFileName.contains(".")){
			outputFileName = outputFileName.substring(0,outputFileName.indexOf("."));
		}
		outputFileName = outputFileName+".out";
        File file = new File(fileName); 

        try { 
        	FileWriter fstream = new FileWriter(outputFileName,true);
    		 BufferedWriter out = new BufferedWriter(fstream);
        	BufferedReader reader = new BufferedReader(new FileReader(file));       
        	
        	//Number of cases
        	String text = reader.readLine();
        	int NoCases = Integer.parseInt(text);
        	
        	for(int caseNo=0;caseNo<NoCases;caseNo++){
        		//Case line
        		text = reader.readLine();
        		int numnodes = Integer.parseInt(text);
        		
        		//System.out.println("Creating nodes");
        		
        		node[] nodes = new node[numnodes];
        		ArrayList<node> noparents = new ArrayList<node>();
        		for(int i=0;i<nodes.length;i++){
        			nodes[i] = new node();
        		}

        		//System.out.println("Loading nodes");
        		
        		for(int i=0;i<nodes.length;i++){
        			text = reader.readLine();
        			//System.out.println(text);
        			String[] data = text.split(" ");
        			int numparent = Integer.parseInt(data[0]);
        			if(numparent==0) noparents.add(nodes[i]);
        			for(int j=0;j<numparent;j++){
        				nodes[Integer.parseInt(data[j+1])-1].children.add(nodes[i]);
        			}
        		}
        		
        		boolean solved = false;

        		//System.out.println("Solving nodes");
        		
        		for(int i=0;!solved&&i<noparents.size();i++){
        			for(int j=0;j<nodes.length;j++){
        				nodes[j].seen = false;
        			}
        			solved = recurs(noparents.get(i));
        		}
        		
        		String answer = "";

        		if(solved)
        			answer = "Yes";
        		else
        			answer = "No";
        		
        		System.out.println("Case #"+(caseNo+1)+": "+answer);
        		out.write("Case #"+(caseNo+1)+": "+answer);
        		out.newLine();
        	}
        	out.close();
        } catch (Exception e) { 
            System.out.println(e); 
        }
	}
	
	public static boolean recurs(node n){
		if(n.seen){
			return true;
		}
		n.seen = true;
		for(int i=0;i<n.children.size();i++){
			if(recurs(n.children.get(i))){
				return true;
			}
		}
		return false;
	}
	
}
