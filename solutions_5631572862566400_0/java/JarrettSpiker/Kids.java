import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Kids {
	public static void main(String[] args){
		Kids k = new Kids();
		k.run();
	}
	
	
	
	List<Pair> kids;
	Set<List<Integer>> independantUnits;
	
	public void run(){
		Scanner in = new Scanner(System.in);
		int t = Integer.parseInt(in.nextLine());
		
		for(int caseNum = 1; caseNum<=t; caseNum++){
			 kids= new ArrayList<Pair>();	
			int numberOfKids = Integer.parseInt(in.nextLine());
			String[] blah = in.nextLine().split(" ");
			for(int i = 0; i<blah.length; i++){
				kids.add(new Pair(i+1, Integer.parseInt(blah[i])));
			}
			
			independantUnits= new HashSet<List<Integer>>();
			int highest = 0;
			for(int i =0; i<numberOfKids; i++){
				Pair startKid = kids.get(i);
				List<Pair> runningList = new ArrayList<Pair>();
				runningList.add(startKid);
				int res = alg2(runningList);
				
				if(highest<res){
					highest = res;
				}
			}
			
			System.out.println("Case #" + caseNum+": " + highest);
			
		}
	}
	
	private void addIu(List<Integer> in){
		for(List<Integer> iu : independantUnits){
			if((in.get(in.size()-1).equals(iu.get(iu.size()-1)))||(in.get(in.size()-1).equals(iu.get(iu.size()-2)))){
				if(in.size() > iu.size()){
					independantUnits.remove(iu);
				}else{
					return;
				}
			}
		}
		independantUnits.add(in);
	}
	
	private boolean disjoint(List<Integer> in1, List<Integer> in2){
		for(Integer i : in1){
			if(in2.contains(i)){
				return false;
			}
		}
		return true;
	}
	
	private List<Pair> alg1(List<Pair> currentList){
		Pair endKid = currentList.get(currentList.size()-1);
		Pair bff = getKidWithId(endKid.bff);
		if(!currentList.contains(bff)){
			currentList.add(bff);
			return alg1(currentList);
		}
		else{
			return currentList;
		}
	}
	
	private int alg2(List<Pair> startKid){
		List<Pair> fromStart = alg1(startKid);
		List<Pair> remainingKids = new ArrayList<Pair>();
		for(Pair kid : kids){
			if(!fromStart.contains(kid)){
				remainingKids.add(kid);
			}
		}
		
		
		Pair endKid = fromStart.get(fromStart.size()-1);
		Pair endBff = getKidWithId(endKid.bff);
		int highest = 0;
		if(fromStart.indexOf(endBff) ==  fromStart.size()-2){
			highest = fromStart.size();
			//pick new kid, add them, repeat
			for(Pair kid : remainingKids){
				
				List<Pair> foo = new ArrayList<Pair>();
				for(Pair p : fromStart){
					foo.add(p);
				}
				foo.add(kid);
				int bar = alg2(foo);
				if(bar > highest){
					highest = bar;
				}
			}
			
			
		}
		else if(fromStart.indexOf(endBff) == 0){
			if(highest<fromStart.size()){
				highest = fromStart.size();
			}
		}
		
		return highest;
	}
	
	private Pair getKidWithId(int id){
		for(Pair kid : kids){
			if(kid.id ==  id){
				return kid;
			}
		}
		return null;
	}
	
	
	private class Pair{
		public int id;
		public int bff;
		public Pair(int id, int bff){
			this.bff = bff;
			this.id = id;
		}
		
		@Override
		public boolean equals(Object o){
			if(getClass() != o.getClass()){
				return false;
			}
			return id == ((Pair)o).id;
		}
		
		@Override
		public String toString(){
			return String.valueOf(id);
		}
	}
}
