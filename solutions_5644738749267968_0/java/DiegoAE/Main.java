
import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		Double[] vieja, man;
		for(int c = 1; c <= T; c++){
			int N = sc.nextInt();
			vieja = new Double[N];
			man = new Double[N];
			for(int i = 0; i < N; i++) vieja[i] = sc.nextDouble();
			for(int i = 0; i < N; i++) man[i] = sc.nextDouble();
			//optimal war
			Arrays.sort(vieja);
			Arrays.sort(man);
			int points = 0;
			int j = 0;
			for(int i = 0; i < N; i++){
				while(j < N && man[j] < vieja[i])
					j++;
				if (j < N)
					j++;
				else
					points++;
			}
			int other = points;
			// real game
			TreeSet<Double> sv = new TreeSet<Double>();
			TreeSet<Double> sm = new TreeSet<Double>();
			for(int i = 0; i < N; i++){
				sv.add(vieja[i]);
				sm.add(man[i]);
			}
			points = 0;
			while(sv.size() > 0){
				double lv = sv.first();
				double lm = sm.first();
				if (lv > lm){
					sv.pollFirst();
					sm.pollFirst();
					points++;
				}
				else{
					sv.pollFirst();
					sm.pollLast();
				}
			}
			System.out.printf("Case #%d: %d %d\n",c, points, other);
		}
	}
}
