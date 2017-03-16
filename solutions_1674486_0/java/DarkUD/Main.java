package rni.co.codeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {

	/**
	 * @param args
	 */
	
	private static CodeJam jam;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub$$
		
		jam = new CodeJam();
		jam.solve();	
	}
	
	public static class CodeJam {

		public static final String inputName = "input";
		public static final String outputName = "output";
			
		private ArrayList<String> input;
		private ArrayList<String> output;
		
		private int Ryan = 0;
				
		public CodeJam()
		{
			input = new ArrayList<String>();
			output = new ArrayList<String>();
		}
		
		public void solve()
		{
			//Let s load input
			System.out.println("\n----Input");
			read();		
			
			//Here is the solution
			if(input.size() == 0)
			{
				//If the input file provided is empty....
				System.out.println("input is empty");
				return;
			}		
			
			//T : nb of tests
						
			int T = Integer.parseInt(input.get(0));
									
			long startTime = System.currentTimeMillis();
			int testCase = 1;
			
			for(int i = 1;i<input.size();i++)
			{			
				String out = "Case #"+testCase+": ";
						
				int N = parseInt(input.get(i));
				
				classes = new ArrayList<Main.CodeJam.Classe>();
				classes.add(new Classe());//Dummy
				
				int id = 1;
				
				for(int j = i+1;j<i+N+1;j++)
				{
					
					String line[] = input.get(j).split(" ");
					
					//System.out.println("processed : " + input.get(j));
					
					Classe c = new Classe();
					int nbInherits = parseInt(line[0]);
					
					c.id = id;
					
					for(int k = 0;k<nbInherits;k++)
					{
						c.inherits.add(parseInt(line[1+k]));
					}					
					
					System.out.println(testCase + " : " + c);
					
					classes.add(c);
					id++;		
					
				}
				
				//Now we treat the test case ...
				
				boolean diamond = false;
				
				for(int m = 1;m<classes.size();m++)
				{
					for(int n = 1;n<classes.size();n++)
					{
						classes.get(n).paths = 0;
					}
					
					Classe c = classes.get(m);
					
					for(int n = 1;n<classes.size();n++)
					{
						c.paths = 0;
						if(n != m)
						{
							if(c.inherits.contains(n))
							{
								//System.out.println("direct !");
								c.paths = 1;
								getPathEx(m, n,n);
							}else
							{
								getPath(m, n);
							}						
							
							if(c.paths>=2)
							{
								diamond = true;
								out += "Yes";
								break;
							}
						}
										
					}
					
					if(diamond)break;					
				}
							
				i += N;
							
				if(!diamond)out+= "No";
				output.add(out);
				testCase ++;
			}		
			
			System.out.println("Processed in " + (System.currentTimeMillis() - startTime) + "" );
			//Let s write the output
			System.out.println("----Output :");
			write();
		}		
			
		ArrayList <Classe> classes;
		
		public class Classe
		{
			int id;
			ArrayList<Integer> inherits;
			int paths;
			
			public Classe()
			{
				inherits = new ArrayList<Integer>();
				paths = 0;
			}
			
			@Override
			public String toString() {
				
				String res = id + " | " ;
				
				for(int i = 0;i<inherits.size();i++)
				{
					res += inherits.get(i) + " ";
				}				
				
				return res;
			}
		}
		
		public String getPathEx(int idA,int idB,int id)
		{
			String path = "";
					
			int nbPaths = 0;
						
			for(int i = 0;i<classes.get(idA).inherits.size();i++)
			{
				int idNext = classes.get(idA).inherits.get(i);
				
				if(idNext == id)continue;
							
				path = getPath(idNext,idB);
							
				if(path.endsWith("S"))
				{						
					nbPaths ++;
				}
			}
					
			classes.get(idA).paths += nbPaths;		
					
			return path;
		}
			
		
		public String getPath(int idA,int idB)
		{
			String path = "";
			
			for(int i = 0;i<classes.get(idA).inherits.size();i++)
			{
				if(classes.get(idA).inherits.get(i) == idB)
				{
					classes.get(idA).paths += 1;
					return "S";
				}
			}
			
			int nbPaths = 0;
						
			for(int i = 0;i<classes.get(idA).inherits.size();i++)
			{
				int idNext = classes.get(idA).inherits.get(i);
							
				path = getPath(idNext,idB);
						
				if(path.endsWith("S"))
				{						
					nbPaths ++;
				}
			}
								
			classes.get(idA).paths += nbPaths;		
					
			return path;
		}
				
		public int parseInt(String str)
		{
			return Integer.parseInt(str);
		}
		
		public double parseDouble(String str)
		{
			return Double.parseDouble(str);
		}
		
		public float parseFloat(String str)
		{
			return Float.parseFloat(str);
		}
		
		public void read()
		{
			input = new ArrayList<String>();
			
			File file = new File(inputName);
			
			try
			{			
				FileInputStream fis = new FileInputStream(file);
				InputStreamReader in = new InputStreamReader(fis);
				BufferedReader br = new BufferedReader(in);
				
				String line  = "";
				
				while((line = br.readLine())!=null)
				{
					input.add(line);
					System.out.println(line);
				}
				
				br.close();
				in.close();
				fis.close();
				
			}catch(Exception e)
			{
				System.out.println("Error read : " + e.getMessage());
			}	
			
		}
		
		public void write()
		{	
			File file = new File(outputName);
			
			try
			{
				FileOutputStream fos = new FileOutputStream(file);
				OutputStreamWriter out = new OutputStreamWriter(fos);
				BufferedWriter bw = new BufferedWriter(out);
				
				for(int i = 0;i<output.size();i++)
				{
					System.out.println(output.get(i));
					bw.write(output.get(i) + "\n");
				}
				
				bw.close();
				out.close();
				fos.close();
						
			}catch(Exception e)
			{
				System.out.println("Error write : " + e.getMessage());
			}		
		}
	}	
}
