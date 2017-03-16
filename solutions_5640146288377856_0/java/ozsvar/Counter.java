package mushroom;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Counter {

		List<Integer> cases = new ArrayList<Integer>();
		List<Integer> R =  new ArrayList<Integer>();
		List<Integer> C =  new ArrayList<Integer>();
		List<Integer> W =  new ArrayList<Integer>();
		List<Integer> res =  new ArrayList<Integer>();
		/*
		 * Read file method
		 */
		public void readFile(String fileName)
		{
			Scanner scanner;
			try {
				scanner = new Scanner(new File(fileName));

				int testCases = scanner.nextInt();
	 
				scanner.nextLine();
				for(int i=0; i<testCases; ++i)
				{
					R.add(scanner.nextInt());
					C.add(scanner.nextInt());
					W.add(scanner.nextInt());
					
				}
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			
			
		}
		
		/*
		 * Write file method
		 */
		public void writeFile(String fileName)
		{
			PrintWriter writer;
			try {
				writer = new PrintWriter(fileName);
				
				int counter = 0;
				for(int i=0; i<res.size();++i)
				{
					writer.print("Case #" + (++counter) + ": " + res.get(i));
					if(counter<res.size())
					{
						writer.println();
					}
				}
				
				writer.close();
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			
			
		} 
		
		
		
		
		public void solve2()
		{
			for(int i=0; i<W.size(); ++i)
			{
				int w = W.get(i);
				int r = R.get(i);
				int c = C.get(i);
				
				int val;
				
				int valami;
				int utolso;
				
				if(c%w == 0)
				{
					valami = 0;
					utolso = 0;
				} else 
				{
					valami = 2*w - (w-1+1+(c%w))+1;
					//utolso = valami + (w-valami)-1;
					utolso = 1;
				}
				
				//System.out.println("valami: " + valami);
				//System.out.println("utolso: " + utolso);
				
				if(c*r==w)
				{
					val = w;
					res.add(val);
					continue;
				}
						
				if(r==1){
					val = (int) ((Math.floor(c / w) + (w -1))) + utolso; 
					res.add(val);
					continue;
				}
				
				if(r>1){
					val = (int) ((r-1) * (Math.floor(c / w))) + (int)(Math.floor(c / w) +  (w -1)) + utolso; 
					
					res.add(val);
					continue;
				}
				
			}
			
			for(int v : res)
			{
				System.out.println(v);
			}
				
		}
		
		public static void main(String[] args)
		{
			Counter so = new Counter();
			
			//so.readFile("A-large.in");
			so.readFile("A-small-attempt1.in");
			
			so.solve2();
			
			so.writeFile("A-small-attempt1.out");
		}

}
