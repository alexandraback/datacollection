
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class HallOfMirrors {
    
    
    static class Node
    {
        
        private ArrayList<Node> children;
        private int number;
        public Node(int number)
        {
            this.number=number;
            children=new ArrayList<Node>();
        }
        
        public ArrayList<Node> getChildren()
        {
            return children;
        }
        
        public void addChild(Node child)
        {
            children.add(child);
        }
        
        public int getNumber()
        {
            return number;
        }
        
    }
    
    public static void main(String[] args) throws FileNotFoundException
    {
        FileInputStream file = new FileInputStream("C:\\Users\\Taghi\\Downloads\\A-small-attempt.in");
        DataInputStream in2 = new DataInputStream(file);
        Scanner in=new Scanner(new InputStreamReader(in2));
       // Scanner in=new Scanner(System.in);
        int numberOfTests=in.nextInt();
        for (int i=0;i<numberOfTests;i++)
        {
            int numberOfClasses=in.nextInt();
            Node[] classes=new Node[numberOfClasses];
            for (int j=0;j<numberOfClasses;j++)
            {
                classes[j]=new Node(j);
                int numberOfInheritance=in.nextInt();
                
            for (int k=0;k<numberOfInheritance;k++)
            {
              int child=in.nextInt();
              classes[j].addChild(new Node(child));
            }
           // System.out.println(classes[j].getChildren());
            }
            
            boolean found=false;
            for (int j=0;j<numberOfClasses;j++)
            {
                ArrayList<Integer> allChildren=new ArrayList<Integer>();
                ArrayList<Integer> allChild=new ArrayList<Integer>();
                addAllChild(classes[j],allChildren,classes);
                //System.out.println(allChildren);
                
                for (int k=0;k<allChildren.size()-1;k++)
                {
                    for (int p=k+1;p<allChildren.size();p++)
                    {
                        //System.out.println(allChildren.get(k).intValue()+" "+allChildren.get(p).intValue());
                        if (allChildren.get(k).intValue()==allChildren.get(p).intValue())
                            found=true;
                    }
                }
                
            }
            if (found)
            System.out.println("Case #"+(i+1)+": Yes");
            else
                 System.out.println("Case #"+(i+1)+": No");
        }
        
    }
    
    public static void addAllChild(Node node,ArrayList<Integer> allChildren,Node[] classes)
    {
        //int counter=0;
        for (Object o:node.getChildren())
        {
            Node tmp=(Node)o;
            allChildren.add(tmp.getNumber());
            //System.out.println(tmp.getNumber());
            addAllChild(classes[tmp.getNumber()-1],allChildren,classes); 
        }
    }
    
}
