import java.lang.Math;
import java.util.ArrayList;

public class War{
	static String[] sets;
	static String result="";
	static ArrayList<Float> roundSetKen,roundSetNaomi;
	static int scoreWar,scoreDeceitfullWar;

	public static void main(String[] args){
		sets=args[0].split("\n");
		int T= Integer.parseInt(sets[0]);
		for (int set=0;set<T;set++)
		game(set);

		System.out.println("\nOutput\n"+result);
	}

	public static void game(int set){
		scoreWar=0;
		scoreDeceitfullWar=0;
		int nRound=Integer.parseInt(sets[set*3+1]);
		String[] roundSetNaomiString=sets[set*3+2].split(" ");
		String[] roundSetKenString=sets[set*3+3].split(" ");
		roundSetKen=new ArrayList<Float>();
		roundSetNaomi=new ArrayList<Float>();
		for (int round=0;round<nRound;round++){
			roundSetKen.add(Float.parseFloat(roundSetKenString[round]));
			roundSetNaomi.add(Float.parseFloat(roundSetNaomiString[round]));
		}
		war(nRound);
		for (int round=0;round<nRound;round++){
			roundSetKen.add(Float.parseFloat(roundSetKenString[round]));
			roundSetNaomi.add(Float.parseFloat(roundSetNaomiString[round]));
		}
		deceitfullWar(nRound);
		result=result+"Case #"+(set+1)+": "+scoreDeceitfullWar+" "+scoreWar+"\n";
	}

	public static void war(int nRound){
		for(int round=0;round<nRound;round++){
			float chosenNaomi=naomiChoice();
			if (chosenNaomi>kenChoice(chosenNaomi)) scoreWar++;
			roundSetNaomi.remove(chosenNaomi);
		}
	}

	public static float naomiChoice(){
		float minimalWeight;
		minimalWeight=1f;
		for (float weight:roundSetNaomi){
			if(weight<minimalWeight) minimalWeight=weight;
		}
		
		return minimalWeight;
	}

	public static float kenChoice(float chosenNaomi){
		float minimalWeight,optimizedWeight;
		minimalWeight=1f;
		optimizedWeight=1f;
		for (float weight:roundSetKen){
			if(weight>chosenNaomi && weight<optimizedWeight) optimizedWeight=weight;
			if(weight<minimalWeight) minimalWeight=weight;
		}
		if(optimizedWeight<1f){
			roundSetKen.remove(optimizedWeight);
			return optimizedWeight;
		} else {
			roundSetKen.remove(minimalWeight);
			return minimalWeight;
		}
	}

	public static void deceitfullWar(int nRound){
		for(int round=0;round<nRound;round++){
			float kensBest=pickKensBest();
			float kensSmallest=pickKensSmallest();
			float naomiChoice=naomiDChoice(kensSmallest);
			float naomiTold;
			if(naomiChoice>kensSmallest) naomiTold=kensBest+Float.MIN_NORMAL*(round+1);
			else naomiTold=naomiChoice;

			if (naomiChoice>kenChoice(naomiTold)) {
				scoreDeceitfullWar++;
			}
		}
	}

	public static float pickKensBest(){
		float maximalWeight=0f;
		for (float weight:roundSetKen){
			if(weight>maximalWeight) maximalWeight=weight;
		}
		return maximalWeight;
	}

	public static float pickKensSmallest(){
		float minimalWeight=1f;
		for (float weight:roundSetKen){
			if(weight<minimalWeight) minimalWeight=weight;
		}
		return minimalWeight;
	}

	public static float naomiDChoice(float kensSmallest){
		float minimalWeight,optimizedWeight;
		minimalWeight=1f;
		optimizedWeight=1f;
		for (float weight:roundSetNaomi){
			if(weight>kensSmallest && weight<optimizedWeight) optimizedWeight=weight;
			if(weight<minimalWeight) minimalWeight=weight;
		}
		if(optimizedWeight<1f){
			roundSetNaomi.remove(optimizedWeight);
			return optimizedWeight;
		} else {
			roundSetNaomi.remove(minimalWeight);
			return minimalWeight;
		}
	}

}