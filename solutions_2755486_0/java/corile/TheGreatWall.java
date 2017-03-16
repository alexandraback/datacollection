import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class TheGreatWall {

	/**
	 * @param args
	 * @throws IOException 
	 */

	public static ArrayList<Tribe> tribes;
	public static int height[] = new int[601]; 
	private static int numSuccessful=0;
	private static int day=0;

	public static void main(String[] args) throws IOException {

		BufferedReader br=null;
		try {
			br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//FileWriter fstream = new FileWriter("out.txt");
		//BufferedWriter out = new BufferedWriter(fstream);

		int casenum = 0;

		casenum = Integer.parseInt(br.readLine());

		for(int j = 0; j < casenum; j++)
		{
			int numTribes = Integer.parseInt(br.readLine());

			for(int i=-300;i<300;i++)
				setHeight(i,0);

			tribes = new ArrayList<Tribe>();
			numSuccessful=0;
			day=0;

			for(int i =0;i<numTribes;i++)
			{
				String[] s = null;

				s = br.readLine().split(" ");
				Tribe t = new Tribe(Integer.parseInt(s[0]),Integer.parseInt(s[1]),Integer.parseInt(s[2]),Integer.parseInt(s[3]),Integer.parseInt(s[4]),Integer.parseInt(s[5]),Integer.parseInt(s[6]),Integer.parseInt(s[7]));
				tribes.add(t);
			}

			while(!tribes.isEmpty()&&day<676061)
			{
				attackOfTheDay();
				removeFinishedTribes();
				day++;
			}


			System.out.println("Case #"+(j+1)+": "+numSuccessful);

		}
		br.close();

	}

	private static void removeFinishedTribes() {
		int size = tribes.size();
		for(int i=0;i<size;i++)
		{
			Tribe t= tribes.get(i);
			if(t.getNumAttacksLeft()<=0)
			{
				tribes.remove(i);
				i--;
				size--;
			}
		}
	}

	private static void attackOfTheDay()
	{
		ArrayList<Tribe> successfulTribes = new ArrayList<Tribe>();
		for(Tribe t:tribes)
		{
			if(t.getNextAttack()==day)
			{
				if(isSuccessful(t.getWest(), t.getEast(), t.getStrength()))
				{
					numSuccessful++;
					successfulTribes.add(t);
				}
				else
					t.prepareForNextAttack();
			}
		}

		for(Tribe t:successfulTribes)
		{
			setHeight(t.getWest(), t.getEast(),t.getStrength());
			t.prepareForNextAttack();
		}
	}

	private static void setHeight(int x,int h)
	{
		height[x+300] = h;
	}

	private static void setHeight(int x,int y,int h)
	{
		for(int i=x+1;i<=y;i++)
		{
			if(height[i+300]<h)
				setHeight(i, h);
		}
	}

	private static boolean isSuccessful(int x,int y,int h)
	{
		for(int i=x+1;i<=y;i++)
		{
			if(height[i+300]<h)
				return true;
		}
		return false;
	}

}
