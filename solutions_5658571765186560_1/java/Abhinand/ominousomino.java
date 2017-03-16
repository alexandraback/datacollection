import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Map;
import java.util.HashMap;


public class ominousomino {
	public static void main(String[] args)
	{
				
		try
		{
			
			BufferedWriter bw = new BufferedWriter(new FileWriter("test.out"));
			BufferedReader br = new BufferedReader(new FileReader("test.in"));
			
			int T, X, R, C;
			
			T = Integer.parseInt(br.readLine());
			
			for (int tc=1; tc<= T; tc++)
			{
				String[] line = br.readLine().split(" ");
				
				X = Integer.parseInt(line[0]);
				R = Integer.parseInt(line[1]);
				C = Integer.parseInt(line[2]);
				
				String winner = "";
				if(X >= 7 || R * C < X || (R * C) % X != 0 || (R < X && C < X))
					winner = "RICHARD";
				else
					winner = "GABRIEL";
				
				if(X == 3)
				{
					if (R == 1 || C == 1)
						winner = "RICHARD";
				}
				else if (X == 4)
				{
					if (R <= 2 || C <= 2)
						winner = "RICHARD";
				}
				else if (X == 5)
				{
					if (R <= 3 || C <= 3)
						winner = "RICHARD";
				}
				else if (X == 6)
				{
					if (R <= 3 || C <= 3)
						winner = "RICHARD";
				}
				
				
				bw.write("Case #"+ tc + ": " + winner);
				bw.newLine();
				
			}
			bw.close();
			br.close();
			
		}
		catch (Exception ex) 
		{
			System.out.println(ex.getMessage());
		}
	}
}
