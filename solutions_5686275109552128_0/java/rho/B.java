import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.Scanner;
import java.util.TreeSet;

class Int implements Comparable<Int>
{
    int num=0;
    int spl=0;
    
    public Int(int n)
    {
    	num=n;
    }
    
    public void splt()
    {
    	spl++;
    }
  
    public int getVal()
    {
    	if(spl==0)
    		return num;
    	if(num%(spl+1)==0)
	    	return num/(spl+1);
    	else
    		return num/(spl+1)+1;
    }
	
	public int compareTo(Int o) {
		return o.getVal()-getVal();
	}
	
	@Override
	public String toString() {
		return num+" "+spl+" "+getVal()+"|";
	}
}

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner sc = new Scanner(new File("B.in"));
		int numT = sc.nextInt();
		for(int test=1; test<=numT; ++test)
		{
			int N = sc.nextInt();
			PriorityQueue<Int> set = new PriorityQueue<Int>();
			for(int i=0; i<N; ++i)
			{
				int q = sc.nextInt();
				set.add(new Int(q));
			}

			int best=set.peek().getVal(), lim=best;
			for(int i=1; i<=lim; ++i)
			{
				Int first = set.poll();
				first.splt();
				set.add(first);
				if(set.peek().getVal()+i<best)
					best=set.peek().getVal()+i;
				//System.out.print(best);
				//System.out.println(set);
			}
			

					
			
			System.out.printf("Case #%d: %d\n", test, best);
		}
	}

}
