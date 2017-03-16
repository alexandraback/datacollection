//Kholofelo Moyaba
//Problem C codejam
//14 April 2012

import java.util.Scanner;
import java.util.LinkedList;

class DiamondInheritance
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int cases = input.nextInt();
        int[][] adj;
        for(int i=1;i<=cases;i++)
        {
            int n = input.nextInt();
            adj = new int[n][];
            for(int j=0;j<n;j++){
                adj[j] = new int[input.nextInt()];
                for(int k=0;k<adj[j].length;k++)
                    adj[j][k]=input.nextInt()-1;
            }
            String result = "No";
            for(int j=0;j<n;j++){
                BFS tree = new BFS(adj,j);
                if(!tree.build()){
                    result = "Yes";
                    break;
                }
            }
            System.out.println("Case #"+i+": "+result);
        }
    }
}
class BFS//tree
{
    Node root;
    boolean[] mark;
    int adj[][];
    
    public BFS(int[][] adj,int id)
    {
        this.adj = adj;
        root=new Node(id);
        mark = new boolean[adj.length];
        
        root.children = new Node[adj[id].length];
        for(int i=0;i<root.children.length;i++){
            mark[adj[id][i]]=true;//mark occurance
            root.children[i] = new Node(adj[id][i]);
        }
    }
    
    public boolean build()
    {
        for(int i=0;i<root.children.length;i++)
            if(!build(root.children[i]))
                return false;
        return true;
    }
    
    private boolean build(Node n)
    {
        int c = adj[n.id].length;
        if(c==0)
            return true;//stop case
        n.children = new Node[c];
        for(int i=0;i<c;i++){
            if(mark[adj[n.id][i]])
                return false;//fail diamond present
            else
                mark[adj[n.id][i]]=true;//mark occurance
            n.children[i] = new Node(adj[n.id][i]);
        }
        for(int i=0;i<c;i++)
            if(!build(n.children[i]))
                return false;
        return true;
    }
    class Node
    {
        int id;
        Node[] children;
        public Node(int id)
        {this.id = id;}
    }
}