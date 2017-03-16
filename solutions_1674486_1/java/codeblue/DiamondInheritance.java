import java.util.Scanner;
import java.io.File;

import java.util.ArrayList;


public class DiamondInheritance
 {
 	private int traceBuffer[];
 	private Node[] nodes;
 	private boolean diamondFound;
 	
 	public void analyzeInputFile(String fileName) throws Exception
 	 {
	   Scanner fileScanner = new Scanner (new File (fileName) ); 	
 	   
 	   String line;
 	   
 	   line = fileScanner.nextLine();
 	   
 	   int numberOfTestCases = Integer.parseInt(line.trim());
 	   
 	   int N,S,p;
 	   
 	   for(int i = 1; i<= numberOfTestCases ; i++)
 	    { 
 	       line = fileScanner.nextLine();	
 	       	 	
 	       Scanner lineScanner = new Scanner(line);
 	       
 	       N = 	 Integer.parseInt(lineScanner.next().trim());
 	       
 	       nodes = new Node[N+1];
 	       
 	       int Mi;
 	       
 	       for(int k=1; k<=N; k++)
 	       {
 	       	  nodes[k] = new Node(k);
 	       }
 	       
 	       
 	       for (int k = 1; k<=N ; k++ )
 	        {
 	           	
 	           
 	           
 	           line = fileScanner.nextLine();
 	           lineScanner = new Scanner(line);
 	           
 	           Mi = Integer.parseInt(lineScanner.next().trim());
 	           
 	           for(int linkedNodes = 1; linkedNodes<=Mi; linkedNodes++)
 	            {
 	               	int id;
 	               	id =  Integer.parseInt(lineScanner.next().trim());
 	               	nodes[k].addLink(nodes[id]);
 	            }
 	           
 	        }
 	        
 	        
 	        traceBuffer = new int[N+1];
 	        
 	        diamondFound = false;
 	        
 	        analysisLoop:
 	        for(int k=1; k<=N; k++)
 	         {
 	            int size = nodes[k].getNumberOfLinks();
 	           
 	            diamondFound = false; 
 	            traceBuffer = new int[N+1];
 	           
 	            if(size>=2)
 	             {
 	             	ArrayList<Node> list = nodes[k].getList();
 	             	
 	             	for(Node node : list)
 	             	 {
 	             	    int id = node.getID();
 	             	    
 	             	    traceBuffer[id]++;
 	             	    if(traceBuffer[id]>=2)
 	             	     {
 	             	       diamondFound = true; //System.out.println("yeah!");
 	             	       break analysisLoop;	
 	             	     }	
 	             	     
 	             	     completeTraceForNode(node);
 	             	     if(diamondFound == true)
 	             	      {
 	             	      	 break analysisLoop;
 	             	      }
 	             	 }
 	             }	
 	             
 	             //traceBuffer = new int[N+1];
 	         }
 	        
 	        if(diamondFound == false) 
 	         {
 	         	System.out.println("Case #"+i+": No");
 	         }
 	        else
 	         {
 	            System.out.println("Case #"+i+": Yes");	
 	         }
 	        
 	     }
 	
      }
      
    public void completeTraceForNode(Node k)
     {
        ArrayList<Node> list = k.getList();
        
        for(Node node : list) 
         {
            int id = node.getID();
            
            traceBuffer[id]++;	
            
            if(traceBuffer[id]>=2)
 	           {
 	             diamondFound = true;
 	             return;	
 	           }	
            
            completeTraceForNode(node);
            
            if(diamondFound == true)
             {
               return;	
             }
         }	
     }  
      
 	public static void main(String[] args) throws Exception
 	 {
 	     DiamondInheritance DI = new DiamondInheritance();
     	 String inputFile; //
     	 //inputFile = "sample.txt";
     	 //inputFile = "A-small-attempt0.in";
     	 inputFile = "A-large.in";
     	 
     	 DI.analyzeInputFile(inputFile);	
 	 } 
 }


class Node
 {
 	private int ID;
 	private ArrayList<Node> linked;
 	
 	
 	public Node (int id)
 	 {
 	   this.ID = id;	
 	   linked = new ArrayList<Node>();
 	 } 
 	
 	public int getNumberOfLinks()
 	 {
 	   return linked.size();	
 	 }
 	
 	public int getID() 
 	 {
 	   return ID;	
 	 } 
 	 
 	public void addLink(Node newNode)
 	 {
 	 	linked.add(newNode);
 	 }
 	
 	public ArrayList<Node> getList()
 	 {
 	   return linked;	
 	 }
 	 
 } 