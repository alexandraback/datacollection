import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

/***/
public class Treasure {
	public static Treasure treasure=new Treasure();
	
	public static Map<Integer,Key> mapKeys;
	public static Map<Integer,Chest> mapChests; 
	
	public static List<Integer> listSelected=null;

	/***/
	public class Key{
		public Integer keyId;
		public Integer count=0;
		public List<Integer> listChests=Collections.synchronizedList(new ArrayList<Integer>());
		
		public Key(Integer keyId){ this.keyId=keyId; } 
	}
	public Key newKey(Integer keyId){ return new Key(keyId); }
	
	/***/
	public class Chest{
		public Integer chestId;
		public Integer keyId;
		public List<Integer> listKeys=Collections.synchronizedList(new ArrayList<Integer>());
		
		public Chest(Integer chestId,Integer keyId){
			this.chestId=chestId;
			this.keyId=keyId; 
		}
	}
	public Chest newChest(Integer chestId,Integer keyId){ return new Chest(chestId,keyId); }	
	
	/**
	public class ListComparator implements Comparator<List<Integer>>{

		@Override
		public int compare(List<Integer> arg0, List<Integer> arg1) {
			for(int i=0;i!=arg0.size();i++){
				int c=arg0.get(i).compareTo(arg1.get(i));
				if(c!=0)
					return c; 
			}				
			return 0;
		}}
	public ListComparator newListComparator(){ return new ListComparator(); } */

	/**
	 */
	public static void main(String[] args) {

		try {

			LineNumberReader reader=new LineNumberReader(new FileReader(new File(args[0]))); // InputFile
			PrintStream printer=new PrintStream(new File(args[1])); // OutputFile
			
			Integer nTestCases=Integer.valueOf(reader.readLine().trim());
			for(int i=0;i!=nTestCases;i++){
			
				// System.err.println("Case #"+(i+1));
				
				String str=reader.readLine().trim();
				String[] s=str.split(" ", 2);
				// System.err.println("Keys Chests: "+str);
				Integer nKeys=Integer.valueOf(s[0].trim());
				Integer nChests=Integer.valueOf(s[1].trim());
				
				// Initial Keys				
				int[] rKeys=new int[201];
				String strKeys=reader.readLine().trim();
				// System.err.println("Keys: "+strKeys);
				String[] sKeys=strKeys.split(" ", nKeys);
				for(int k=0;k!=nKeys;k++)
					rKeys[Integer.valueOf(sKeys[k].trim())]++;
				
				// Keys/Chests
				mapKeys=Collections.synchronizedMap(new HashMap<Integer,Key>());
				mapChests=Collections.synchronizedMap(new HashMap<Integer,Chest>()); 
				for(int c=0;c!=nChests;c++){
					
					String strChestKeys=reader.readLine().trim();
					String[] t=strChestKeys.split(" ");
					// System.err.println(strChestKeys);
					Chest chest=treasure.newChest(c+1, Integer.valueOf(t[0].trim()));
					
					if(!mapKeys.containsKey(chest.keyId))
						mapKeys.put(chest.keyId, treasure.newKey(chest.keyId));
					mapKeys.get(chest.keyId).listChests.add(chest.chestId);
					
					// Chest'Keys
					int nChestKeys=Integer.valueOf(t[1].trim());
					for(int k=0;k!=nChestKeys;k++){
						int chestKeyId=Integer.valueOf(t[k+2].trim());
						chest.listKeys.add(chestKeyId);
						
						if(!mapKeys.containsKey(chestKeyId))
							mapKeys.put(chestKeyId, treasure.newKey(chestKeyId));
						mapKeys.get(chestKeyId).count++;
					}
														
					mapChests.put(chest.chestId, chest); 					
				}								
				
				/** Checks if there is enough keys for each Chest. */
				boolean bPossible=true;
				Iterator<Integer> iterKey=mapKeys.keySet().iterator();
				while(iterKey.hasNext()&&bPossible){
					Key key=mapKeys.get(iterKey.next());
					key.count+=rKeys[key.keyId];
					// System.err.println("Key("+key.keyId+")="+key.count+", Chests="+key.listChests.size());
					if(key.count<key.listChests.size())
						bPossible=false;
					Collections.sort(key.listChests);
				}
				
				if(bPossible){
					
					Iterator<Integer> iterChest=mapChests.keySet().iterator();
					while(iterChest.hasNext()&&bPossible){
						Chest chest=mapChests.get(iterChest.next());
						if(mapKeys.get(chest.keyId).count==0)
							bPossible=false;
					}
					
					/***/
					if(bPossible)
						openChest(0,rKeys,new boolean[201],Collections.synchronizedList(new ArrayList<Integer>())); 
				}				
				
				if(listSelected==null){

					// System.out.println("Case #"+(i+1)+": IMPOSSIBLE");
					printer.println("Case #"+(i+1)+": IMPOSSIBLE");
					
				}else{
					
					String sList="";
					Iterator<Integer> iter=listSelected.iterator();
					while(iter.hasNext())
						sList+=iter.next()+" ";
					// System.out.println("Case #"+(i+1)+": "+sList.trim());
					printer.println("Case #"+(i+1)+": "+sList.trim());
					
				}
				
				listSelected=null;
			}
			
			reader.close();
			printer.close();			
		} catch (FileNotFoundException e) {
			
			e.printStackTrace();
		} catch (IOException e) {
			
			e.printStackTrace();
		} 
		
	}
	
	/***/
	public static void openChest(int chestIndex,int[] rKeys,boolean[] bChests,List<Integer> prevChests){

		if(chestIndex==mapChests.size()){
			listSelected=prevChests;
			return;
		}
		
		/***/
		boolean bPossible=true;
		if(bPossible){
			
			int[] cKeys=new int[rKeys.length]; // Count of available Keys.
			int[] qKeys=new int[rKeys.length]; // Count of required Keys.
			for(int i=1;i!=cKeys.length;i++)
				cKeys[i]=rKeys[i];		// TODO
			
			Iterator<Integer> iterChest=mapChests.keySet().iterator();
			while(iterChest.hasNext()&&bPossible){
				Chest chest=mapChests.get(iterChest.next());
				if(!bChests[chest.chestId]){
					qKeys[chest.keyId]++;
					Iterator<Integer> iterChestKey=chest.listKeys.iterator();
					while(iterChestKey.hasNext()){
						Integer chestKey=iterChestKey.next();
						cKeys[chestKey]++;						
					}
				}
			}
			
			if(bPossible){
				for(int i=1;i!=cKeys.length;i++)
					if(cKeys[i]<qKeys[i])
						bPossible=false;				
			}
			
			if(bPossible){
				iterChest=mapChests.keySet().iterator();
				while(iterChest.hasNext()){
					Chest chest=mapChests.get(iterChest.next()); 
					if(!bChests[chest.chestId]){
						if((cKeys[chest.keyId]==0)||((cKeys[chest.keyId]==1)&&chest.listKeys.contains(chest.keyId)))
							bPossible=false;
					}
				}
			}
			
			if(!bPossible)
				return;										
		}
						
		/***/
		SortedSet<Integer> setChests=Collections.synchronizedSortedSet(new TreeSet<Integer>());
		Iterator<Integer> iterKey=mapKeys.keySet().iterator();
		while((listSelected==null)&&iterKey.hasNext()){
			Key key=mapKeys.get(iterKey.next());
			if(rKeys[key.keyId]>0){
				
				/***/
				Iterator<Integer> iterChest=key.listChests.iterator();
				while(iterChest.hasNext())
					setChests.add(iterChest.next());
				
			}
		}
		
		if(!setChests.isEmpty()){
			Iterator<Integer> iterChest=setChests.iterator();
			while(iterChest.hasNext()){
				Chest openedChest=mapChests.get(iterChest.next());
				if(!bChests[openedChest.chestId])
					_openChest(chestIndex,rKeys,bChests,prevChests,openedChest); 
			}
		}
		
	}
	
	/***/
	private static void _openChest(int chestIndex,int[] rKeys,boolean[] bChests,List<Integer> prevChests,Chest openedChest){		
		bChests[openedChest.chestId]=true;
			
		/**
		System.err.println("Chest="+openedChest.chestId+", keyId="+openedChest.keyId
				+", keys="+openedChest.listKeys 
				+", prevChests="+prevChests+"="+prevChests.size()); */
		// System.err.println(prevChests+" "+prevChests.size());
			
		int[] rNewKeys=new int[rKeys.length];
			
		for(int k=0;k!=rKeys.length;k++)
			rNewKeys[k]=rKeys[k];
		rNewKeys[openedChest.keyId]--;
			
		Iterator<Integer> iterChestKeys=openedChest.listKeys.iterator();
		while(iterChestKeys.hasNext())
			rNewKeys[iterChestKeys.next()]++;				
			
		/****/
		List<Integer> newChests=Collections.synchronizedList(new ArrayList<Integer>());
		newChests.addAll(prevChests);
		newChests.add(openedChest.chestId); 
			
		openChest(chestIndex+1,rNewKeys,bChests,newChests);
			
		bChests[openedChest.chestId]=false;
	}
	
}