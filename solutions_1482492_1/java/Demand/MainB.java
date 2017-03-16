import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;


public class MainB {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		class Positions {
			double x;
			double t;
			public Positions(double x, double t) {
				this.x = x;
				this.t = t;
			}
		}
		
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/alexander/Downloads/B-large.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintStream writer = new PrintStream("a.txt");
		//PrintStream writer = System.out;
		int N = Integer.parseInt(reader.readLine());
		for (int i =0; i<N; i++)
		{
			String[] items = reader.readLine().split(" ");
			Double distance = Double.parseDouble(items[0]);
			int posCount = Integer.parseInt(items[1]);
			int accs = Integer.parseInt(items[2]);
			ArrayList<Positions> positions = new ArrayList<Positions>();
			
			boolean flag = true;;
			for (int p = 0; p<posCount; p++)
			{
				String[] pos = reader.readLine().split(" ");
				Double x = Double.parseDouble(pos[1]);
				Double t = Double.parseDouble(pos[0]);
				if (x>distance)
				{
					Double V = 0.0;
					if (p>0)
						V = (x-positions.get(p-1).x)/(t-positions.get(p-1).t);
					else
						V = x/t;
					
					x = distance;
					if (p>0)
						t = (x-positions.get(p-1).x)/V;
					else
						t = x/V;
					positions.add(new Positions(x, t));
					flag = false;
				}
				if (flag)
					positions.add(new Positions(x, t));
			}
			
			String[] accString = reader.readLine().split(" ");
			writer.println("Case #"+(i+1)+":");
			for (int a = 0; a<accs; a++)
			{
				Double acc = Double.parseDouble(accString[a]);
				Double time = 0.0;
				Double dist = 0.0;
				Double V = 0.0;
				for (int j = 0; j<positions.size(); j++)
				{
					Double timeInPosition = (-V +Math.sqrt(V*V + 2*(positions.get(j).x-dist)*acc))/acc;
					if (time+timeInPosition<positions.get(j).t)
					{
						V=acc*(positions.get(j).t-time)*(positions.get(j).t-time)-positions.get(j).x+dist;
						dist = positions.get(j).x;
						time = positions.get(j).t;
					}
					else
					{
						time +=timeInPosition;
						dist += acc*timeInPosition*timeInPosition/2;
						V = V+acc*timeInPosition;
					}
				}
				writer.println(time);
			}
		}
		writer.flush();
		writer.close();
		System.out.println("ok");
	}

}
