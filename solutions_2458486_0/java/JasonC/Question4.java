package question4;

import google.CaseData;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Question4 {

	Stack wastekeys = new Stack();
	Stack freekeys = new Stack();
	Stack main = new Stack();
	boolean[] cheststate;
	ArrayList<Key> keys = new ArrayList<Key>();
	ArrayList<Chest> chests = new ArrayList<Chest>();
	int linenub = 0;
	File input;
	BufferedReader br;
	FileInputStream in;
	InputStreamReader isr;
	
	int totalnub = 0;
	public Question4() throws IOException
	{
		input = new File("test4");
  		in = new FileInputStream(input);
  		isr = new InputStreamReader(in,"US-ASCII");
  		br = new BufferedReader(isr);
  		
	}
	
	void ouput() throws IOException
	{
		String tempstring = br.readLine();
		linenub++;
  		totalnub = Integer.valueOf(tempstring);
  		int intikey=0;
  		int chestnub=0;
  		int keynub=0;
  		int[] chesttype;
  		FileWriter writer = new FileWriter(new File("newdocument4"),true);
  		
  		for(int totali = 0; totali < totalnub; totali++)
  		{
  			System.out.println(linenub);
  			tempstring = br.readLine();
  			linenub++;
  			String[] mystring = tempstring.split(" ");
  			
  			intikey = Integer.valueOf(mystring[0]);
  			chestnub = Integer.valueOf(mystring[1]);
  			chesttype = new int[chestnub];
  			keynub=0;
  			
  			wastekeys.clear();
  			main.clear();
  			freekeys.clear();
  			cheststate = new boolean[chestnub];
  			keys.clear();
  			chests.clear();
  			
  			for(int i = 0;i<chestnub;i++)
  				cheststate[i] = false;
  			
  			tempstring = br.readLine();
  			linenub++;
  			mystring = tempstring.split(" ");
  			for(int i = 0; i < intikey;++i)
  			{
  				keys.add(new Key(Integer.valueOf(mystring[i])));
  				keynub++;
  				freekeys.push(new Node(Integer.valueOf(i),'k'));
  			}
  			
  			for(int i = 0; i < chestnub;++i)
  			{
	  			tempstring = br.readLine();
	  			linenub++;
	  			mystring = tempstring.split(" ");
	  			
	  			int nub = mystring.length;
	  			int keytype = Integer.valueOf(mystring[0]);
	  			
	  			chesttype[i] = keytype;
	  			chests.add(new Chest());
	  			if(Integer.valueOf(mystring[1]) != 0)
		  			for(int j = 1; j < nub; j++)
		  			{
		  				keys.add(new Key(Integer.valueOf(mystring[j])));
		  				keynub++;
		  				chests.get(i).addkey(keynub-1);
		  			}
  			}
  			
  			for(int i = 0; i<chesttype.length;i++)
  			{
  				for(int j=0;j<keys.size();j++)
  				{
  					if(keys.get(j).keytype == chesttype[i])
  						keys.get(j).addchest(i);
  				}
  			}
  			System.out.println(String.valueOf(totali));
  			if(calculate()){
  				writer.write("Case #"+String.valueOf(totali+1)+": "+main.output()+"\n");
  			}
  			else
  				writer.write("Case #"+String.valueOf(totali+1)+": IMPOSSIBLE\n");
  		}
  		
  		br.close();
  		isr.close();
  		in.close();
  		writer.close();
	}
	void getdata()
	{
//		cheststate = new boolean[3];
//		for(int i = 0;i<3;i++)
//			cheststate[i] = false;
//		freekeys.push(new Node(0,'k'));
//		freekeys.push(new Node(2,'k'));
//		
//		int[] myint1 = {0,1};
//		Key key1 = new Key(myint1);
//		
//		int[] myint2 = {0,1};
//		Key key2 = new Key(myint2);
//		
//		int[] myint3 = {2};
//		Key key3 = new Key(myint3);
//		keys.add(key1);
//		keys.add(key2);
//		keys.add(key3);
//		
//		int[] myint4 = {-1};
//		Chest chests1 = new Chest(myint4);
//		
//		int[] myint5 = {1};
//		Chest chests2 = new Chest(myint5);
//		
//		int[] myint6 = {-1};
//		Chest chests3 = new Chest(myint6);
//		
//		chests.add(chests1);
//		chests.add(chests2);
//		chests.add(chests3);
		
	}
	boolean isfinished()
	{
		for(int i = 0; i < cheststate.length; ++i)
			if(!cheststate[i])
				return false;
		return true;
	}
	boolean calculate()
	{
		while(true)
		{
			if(isfinished())
			{
				main.print();
				return true;
			}
			if(main.isempty()&&freekeys.isempty())
			{
				System.out.println("IMPOSSIBLE");
				return false;
			}
//			main.print();
			if(!freekeys.isempty())
			{
				
				Node temp = freekeys.pop();
				int tempnub = keys.get(temp.nub).getNext(cheststate);
				if(tempnub != -1)
				{
					main.push(temp);
					main.push(new Node(tempnub,'c'));
					cheststate[tempnub] = true;
				}
				else
				{
					wastekeys.push(temp);
				}
			}
			else{
				Node temp = main.pop();
				if(temp.type == 'c')
				{
					cheststate[temp.nub] = false;
					deletekeys(chests.get(temp.nub).getKey());
				}
				else
				{
					int nub = keys.get(temp.nub).getNext(cheststate);
					if(nub == -1)
						wastekeys.push(temp);
					else
					{
						main.push(temp);
						main.push(new Node(nub,'c'));
						cheststate[nub] = true;
						ArrayList<Integer> newkey = chests.get(nub).getKey();
						clearwaste();
						
						if(newkey!=null)
						{
							for(int i=0;i<newkey.size();i++)
							{
								freekeys.push(new Node(newkey.get(i),'k'));
							}
						}
						
					}
				}
			}
			
		}
		
	}
	
	void clearwaste()
	{
		while(!wastekeys.isempty())
		{
			Node temp = wastekeys.pop();
			keys.get(temp.nub).setback();
			freekeys.push(temp);
		}
	}
	void deletekeys(ArrayList<Integer> target)
	{
		if (target == null)
				return;
		for(int i=0;i<target.size();i++)
		{
			for(int j=0;j<wastekeys.myint.size();j++)
			{
				if(wastekeys.myint.get(j).nub == target.get(i))
				{
					wastekeys.myint.remove(j);
					break;
				}
			}
		}
		
	}
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Question4 myq = new Question4();
		myq.ouput();
// 		myq.calculate();
	}

}
