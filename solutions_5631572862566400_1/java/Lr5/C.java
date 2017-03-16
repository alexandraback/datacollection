import java.util.*;

public class C
{
  class Node
  {
    int id;
    boolean visited;
    boolean isStart;
    List<Node> neighbors = new ArrayList<Node>();
  }

  int N;
  List<Node> startNodes = new ArrayList<Node>();
  List<Node> endNodes = new ArrayList<Node>();
  List<Node> allNodes = new ArrayList<Node>();
  

  public C(int N)
  {
    this.N = N;
    
    for(int i = 0; i < N; ++i)
    {
      Node start = new Node();
      start.id = i;
      start.isStart = true;
      
      Node end = new Node();
      end.id = i;
      
      start.neighbors.add(end);
      
      startNodes.add(start);
      endNodes.add(end);
      allNodes.add(start);
      allNodes.add(end);
    }
  }
  
  public void setBFF(int node, int bffNode)
  {
    endNodes.get(node).neighbors.add(startNodes.get(bffNode));
  }
  
  public int solve()
  {
    //System.err.println();
  
    int result = -1;
  
    for(int i = 0; i < N; ++i)
    {
      resetState();
    
      int now = solveCyclic(i);
      
      if(now > result)
        result = now;
    }
  
    resetState();
    
    int anotherResult = solveAcyclic();
    
    if(anotherResult > result)
      result = anotherResult;
    
    return result;
  }
  
  public void resetState()
  {
    for(Node node : allNodes)
      node.visited = false;
  }
  
  public int solveCyclic(int startNode)
  {
    List<Node> goneThrough = new ArrayList<Node>();
    Node now = null;
    
    for(Node n : startNodes)
    {
      if(n.id == startNode)
      {
        now = n;
        break;
      }
    }
    
    if(now == null)
      return -1;
    
    int hops = 0;
    
    while(!now.visited)
    {
      //System.err.print(now.id + " ");
      goneThrough.add(now);
    
      now.visited = true;
    
      if(now.neighbors.size() != 1)
        System.err.println("SIZEERR");
        
      now = now.neighbors.get(0);
      ++hops;
    }
    
    if(now.id != startNode)
    {
      return -1; // No result
    }
    
    for(Node n : goneThrough)
    {
      // Can be part of only one cycle
      startNodes.remove(n);
      endNodes.remove(n);
      allNodes.remove(n);
    }
    
    //System.err.println();
      
    if(hops%2 != 0)
      System.err.println("ERRR");
      
    return hops/2;
  }
  
  
  
  public int solveAcyclic()
  {
    resetState();
  
    for(int i = 0; i < startNodes.size(); ++i)
    {
      for(int e = 0; e < endNodes.size(); ++e)
      {
        if(endNodes.get(e).neighbors.get(0).id == startNodes.get(i).neighbors.get(0).id && 
          endNodes.get(i).neighbors.get(0).id == startNodes.get(e).neighbors.get(0).id)
        {
          startNodes.get(e).visited = true;
          startNodes.get(i).visited = true;
          endNodes.get(e).visited = true;
          endNodes.get(i).visited = true;
        }
      }
    }
    
    all_again:
    while(true)
    {
      for(Node n : allNodes)
      {
        if(n.neighbors.get(0).visited)
        {
          n.visited = true;
        }
      }
      
      break;
    }
    
    int count = 0;
    
    for(int i = 0; i < allNodes.size(); ++i)
    {
      if(allNodes.get(i).visited)
        ++count;
    }
    
    return count/2;
  }

  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    
    int T = in.nextInt();
    
    for(int i = 0; i < T; ++i)
    {
      int caseT = i+1;
      
      int N = in.nextInt();
      
      C c = new C(N);
      
      for(int e = 0; e < N; ++e)
      {
        int bff = in.nextInt()-1;
        c.setBFF(e,bff);
      }
      
      int result = c.solve();
      
      String resultString = ""+result;
      
      System.out.println("Case #"+caseT+": "+resultString);
    }
  }
}
