import java.util.Arrays;
import java.util.Comparator;
import java.io.*;

class twoStar implements Comparable
{
	public int ratingOne;
	public int ratingTwo;

	public boolean doneOne;
	public boolean doneTwo;


	public twoStar(int a, int b)
	{
		ratingOne = a;
		ratingTwo = b;

		doneOne = false;
		doneTwo = false;
	}

	@Override
	public int compareTo(Object arg0) {
		int a = ratingTwo;
		int b = ((twoStar)arg0).ratingTwo;
		
		if(a == b)
			return ((twoStar)arg0).ratingOne - ratingOne;
		else
			return a-b;
	}
}

class oneStar implements Comparable
{
	public twoStar level;

	public oneStar(twoStar s)
	{
		level = s;
	}

	@Override
	public int compareTo(Object arg0) {
		oneStar o = (oneStar)arg0;
		int a = level.ratingOne;
		int b = o.level.ratingOne;
		
		if(a == b)
			return  o.level.ratingTwo - level.ratingTwo;
		
		else
			return a-b;
	}

	public static oneStar[] create(twoStar[] levels)
	{
		oneStar[] stars = new oneStar[levels.length+1];
		for(int i = 0; i<levels.length;i++)
			stars[i]=new oneStar(levels[i]);

		stars[levels.length] = new oneStar(new twoStar(-1, -1));
		return stars;
	}

}
public class Kingdom {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt1.in"));
		PrintWriter pr = new PrintWriter(new FileWriter("output.txt"));
		String[] temp;
		int T = Integer.parseInt(br.readLine());
		
		for(int CASE = 1; CASE<=T; CASE++)
		{
			int LEVELS = Integer.parseInt(br.readLine());
			twoStar[] twoStars = new twoStar[LEVELS];
			oneStar[] oneStars;
			int points = 0;
			int turns;
			int index1 = 0;
			int index2 = 0;
			
			for(int i = 0; i<LEVELS; i++)
			{
				temp = br.readLine().split(" ");
				twoStars[i] = new twoStar(Integer.parseInt(temp[0]), Integer.parseInt(temp[1]));
			}
			
			Arrays.sort(twoStars);
			oneStars = oneStar.create(twoStars);
			Arrays.sort(oneStars);
			
			for(turns = 0; points < LEVELS*2; turns++)
			{
				if(twoStars[index2].ratingTwo <= points)
				{
					if(twoStars[index2].doneOne)
					{
						points++;
					}
					else
					{
						points += 2;
					}
					
					twoStars[index2].doneTwo = true;
					index2++;
				}
				else
				{
					while(index1 <= LEVELS && oneStars[index1].level.doneTwo)
						if(index1 <= LEVELS)
						index1++;
					
					if(index1<= LEVELS)
					if( oneStars[index1].level.ratingOne <= points)
					{
						points++;
						oneStars[index1].level.doneOne = true;
						index1++;
					}
					else
					{
						break;
					}
					else break;
				}
				
			}
			
			if(points < LEVELS*2)
			{
				pr.println("Case #" + CASE + ": Too Bad");
			}
			else
			{
				pr.println("Case #" + CASE + ": " + turns);
			}
			
		}//all
		
		pr.close();
		br.close();
	}

}
