import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/*
public class FizzBuzz{	public FizzBuzz(){for(int a=1;a<=100;a++){if(a%3==0&&a%5!=0)System.out.println("Fizz");else if(a%3==0&&a%5!=0)System.out.println("Buzz");else if(a%3==0&&a%5==0)System.out.println("FizzBuzz");else System.out.println(a);}}public static void main(String[]args){FizzBuzz f=new FizzBuzz();}}

 */

public class F{
  public static void main(String[] arg0) throws FileNotFoundException{
    System.setOut(new PrintStream(new File("output.txt")));
	Scanner sc = new Scanner(new File("jinput.txt"));
    int nocases = sc.nextInt();
    cases: for(int i = 1;i<=nocases;i++){
    	int noclasses = sc.nextInt();
    	//amount of classes total
    	HashMap<Integer,HashSet<Integer>> supclss = new HashMap<Integer, HashSet<Integer>>();
    	HashMap<Integer,HashSet<Integer>> subclss = new HashMap<Integer, HashSet<Integer>>();
    	//the set of all my superclasses
    	int[] refcount = new int[noclasses+1];
    	ArrayDeque<Integer> superclasses = new ArrayDeque<Integer>();
    	
    	for(Integer in = 1;in<=noclasses;in++){
    		supclss.put(in, new HashSet<Integer>());
    		subclss.put(in, new HashSet<Integer>());
    	}
    	for(int j = 1;j<=noclasses;j++){
    		int nosuperclasses = sc.nextInt();
    		refcount[j]=nosuperclasses;
    		if(nosuperclasses==0){
    			superclasses.add(j);
    		}
    		for(;nosuperclasses>0;nosuperclasses--){
    			int sucl = sc.nextInt();
    			supclss.get(j).add(sucl);
    			subclss.get(sucl).add(j);
    		}
    	}
    	HashSet<Integer> s1;HashSet<Integer> s2;
    	while(!superclasses.isEmpty()){
    		Integer next = superclasses.pollFirst();
    		for(Integer edge:subclss.get(next)){
    			refcount[edge]--;
    			if(refcount[edge]==0){
    				superclasses.addLast(edge);
    			}
    			s1=supclss.get(next);
    			s2=supclss.get(edge);
    			for(Integer scl:s1){
    				if(s2.contains(scl)){
    					System.out.println("Case #"+i+": Yes");
    					continue cases;
    				}
    				s2.add(scl);
    			}
    		}
    		
    	}
    	System.out.println("Case #"+i+": No");
    }
  }
}