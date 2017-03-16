import java.lang.Math;

public class Cookie{
	static double X,C,F;
	static String[] sets;
	static String result="";

	public static void main(String[] args){
		sets=args[0].split("\n");
		int T= Integer.parseInt(sets[0]);
		for (int round=0;round<T;round++)
		set(round);

		System.out.println("\nOutput\n"+result);
	}

	public static void set(int round){
		String[] roundSet=sets[round+1].split(" ");
		C=Double.parseDouble(roundSet[0]);
		F=Double.parseDouble(roundSet[1]);
		X=Double.parseDouble(roundSet[2]);

		result=result+test(round+1);
	}

	public static String test(int round){
		double newSecond= X/2;
		double n=0d;
		double buyNFarm=0;
		double minSecond;
		do{
			minSecond=newSecond;
			n++;
			buyNFarm+=C/(2+(n-1)*F);
			newSecond=buyNFarm+X/(2+n*F);

		}while (newSecond < minSecond);

		return "Case #"+round+": "+minSecond+"\n";
	}

}