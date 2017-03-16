import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	static List<Outfit> outfitList = new ArrayList<Outfit>();
	static Map<PantShirtPair, Integer> pantShirtCount = new HashMap<PantShirtPair, Integer>();
	static Map<JacketPantPair, Integer> jacketPantCount = new HashMap<JacketPantPair, Integer>();
	static Map<JacketShirtPair, Integer> jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
	
	public static boolean tryOutfit(int j, int p, int s, int k){
		PantShirtPair psPair = new PantShirtPair(p, s);
		JacketPantPair jpPair = new JacketPantPair(j, p);
		JacketShirtPair jsPair = new JacketShirtPair(j, s);
		
		if(pantShirtCount.get(psPair) == null){
			pantShirtCount.put(psPair, 0);
		}
		if(jacketPantCount.get(jpPair) == null){
			jacketPantCount.put(jpPair, 0);
		}
		if(jacketShirtCount.get(jsPair) == null){
			jacketShirtCount.put(jsPair, 0);
		}
		int psCount = pantShirtCount.get(psPair);
		int jpCount = jacketPantCount.get(jpPair);
		int jsCount = jacketShirtCount.get(jsPair);
		
		if(psCount < k && jpCount < k && jsCount < k){
			pantShirtCount.put(psPair, psCount+1);
			jacketPantCount.put(jpPair, jpCount+1);
			jacketShirtCount.put(jsPair, jsCount+1);
			return true;
		}
		
		
		return false;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for(int count=1; count<=T; count++){
			int J = scanner.nextInt();
			int P = scanner.nextInt();
			int S = scanner.nextInt();
			int K = scanner.nextInt();
			
			List<Outfit> outfitListFinal = new ArrayList<Outfit>();
			
			outfitList = new ArrayList<>();
			pantShirtCount = new HashMap<PantShirtPair, Integer>();
			jacketPantCount = new HashMap<JacketPantPair, Integer>();
			jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
			
			for(int pCount = 1 ; pCount<= P; pCount++){
				for(int sCount = 1 ; sCount<= S; sCount++){
					for(int jCount = 1 ; jCount<= J; jCount++){
						if(tryOutfit(jCount, pCount, sCount, K)){
							outfitList.add(new Outfit(jCount, pCount, sCount));
						}
					}
				}
			}
			if(outfitListFinal.size() < outfitList.size()){
				outfitListFinal = outfitList;
			}
			
			outfitList = new ArrayList<>();
			pantShirtCount = new HashMap<PantShirtPair, Integer>();
			jacketPantCount = new HashMap<JacketPantPair, Integer>();
			jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
			
			for(int pCount = 1 ; pCount<= P; pCount++){
				for(int jCount = 1 ; jCount<= J; jCount++){
					for(int sCount = 1 ; sCount<= S; sCount++){
						if(tryOutfit(jCount, pCount, sCount, K)){
							outfitList.add(new Outfit(jCount, pCount, sCount));
						}
					}
				}
			}
			if(outfitListFinal.size() < outfitList.size()){
				outfitListFinal = outfitList;
			}
			
			outfitList = new ArrayList<>();
			pantShirtCount = new HashMap<PantShirtPair, Integer>();
			jacketPantCount = new HashMap<JacketPantPair, Integer>();
			jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
			
			for(int jCount = 1 ; jCount<= J; jCount++){
				for(int sCount = 1 ; sCount<= S; sCount++){
					for(int pCount = 1 ; pCount<= P; pCount++){
						if(tryOutfit(jCount, pCount, sCount, K)){
							outfitList.add(new Outfit(jCount, pCount, sCount));
						}
					}
				}
			}
			if(outfitListFinal.size() < outfitList.size()){
				outfitListFinal = outfitList;
			}
			
			outfitList = new ArrayList<>();
			pantShirtCount = new HashMap<PantShirtPair, Integer>();
			jacketPantCount = new HashMap<JacketPantPair, Integer>();
			jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
			
			for(int jCount = 1 ; jCount<= J; jCount++){
				for(int pCount = 1 ; pCount<= P; pCount++){
					for(int sCount = 1 ; sCount<= S; sCount++){
						if(tryOutfit(jCount, pCount, sCount, K)){
							outfitList.add(new Outfit(jCount, pCount, sCount));
						}
					}
				}
			}
			if(outfitListFinal.size() < outfitList.size()){
				outfitListFinal = outfitList;
			}
			
			outfitList = new ArrayList<>();
			pantShirtCount = new HashMap<PantShirtPair, Integer>();
			jacketPantCount = new HashMap<JacketPantPair, Integer>();
			jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
			
			for(int sCount = 1 ; sCount<= S; sCount++){
				for(int pCount = 1 ; pCount<= P; pCount++){
					for(int jCount = 1 ; jCount<= J; jCount++){
						if(tryOutfit(jCount, pCount, sCount, K)){
							outfitList.add(new Outfit(jCount, pCount, sCount));
						}
					}
				}
			}
			if(outfitListFinal.size() < outfitList.size()){
				outfitListFinal = outfitList;
			}
			
			outfitList = new ArrayList<>();
			pantShirtCount = new HashMap<PantShirtPair, Integer>();
			jacketPantCount = new HashMap<JacketPantPair, Integer>();
			jacketShirtCount = new HashMap<JacketShirtPair, Integer>();
			
			for(int sCount = 1 ; sCount<= S; sCount++){
				for(int jCount = 1 ; jCount<= J; jCount++){
					for(int pCount = 1 ; pCount<= P; pCount++){
						if(tryOutfit(jCount, pCount, sCount, K)){
							outfitList.add(new Outfit(jCount, pCount, sCount));
						}
					}
				}
			}
			if(outfitListFinal.size() < outfitList.size()){
				outfitListFinal = outfitList;
			}
			
			System.out.println("Case #"+count+": "+outfitListFinal.size());
			for(Outfit fit : outfitListFinal){
				System.out.println(fit.j + " "+fit.p+ " "+fit.s);
			}
			
		}
		scanner.close();
	}
}
class Outfit{
	int j;
	int p;
	int s;
	public Outfit(int j, int p, int s) {
		super();
		this.j = j;
		this.p = p;
		this.s = s;
	}
	
}
class PantShirtPair{
	int p;
	int s;
	public PantShirtPair(int p, int s) {
		super();
		this.p = p;
		this.s = s;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + p;
		result = prime * result + s;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		PantShirtPair other = (PantShirtPair) obj;
		if (p != other.p)
			return false;
		if (s != other.s)
			return false;
		return true;
	}
	
	
	
}
class JacketPantPair{
	int j;
	int p;
	public JacketPantPair(int j, int p) {
		super();
		this.j = j;
		this.p = p;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + j;
		result = prime * result + p;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		JacketPantPair other = (JacketPantPair) obj;
		if (j != other.j)
			return false;
		if (p != other.p)
			return false;
		return true;
	}
	
	
	
}
class JacketShirtPair{
	int j;
	int s;
	public JacketShirtPair(int j, int s) {
		super();
		this.j = j;
		this.s = s;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + j;
		result = prime * result + s;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		JacketShirtPair other = (JacketShirtPair) obj;
		if (j != other.j)
			return false;
		if (s != other.s)
			return false;
		return true;
	}
	
	
	
}
