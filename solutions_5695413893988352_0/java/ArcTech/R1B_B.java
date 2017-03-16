import java.io.IOException;

public class R1B_B {

	public static void main(String[] args) throws IOException
	
	{
		InputReader in = new InputReader("B-small-attempt0.in");
		OutputWriter out = new OutputWriter("Bsmall.txt");
		int cases = Integer.parseInt(in.getCur());	
		for (int num = 1; num <= cases; num++)
		{
			String outline = "";
			String inscores = in.getNext();
			int space = inscores.indexOf(' ');
			String inc = inscores.substring(0, space);
			String inj = inscores.substring(space+1);
			String outc = "";
			String outj = "";
			int i = 0;
			while (inc.charAt(i) == inj.charAt(i) || inc.charAt(i) == '?' || inj.charAt(i) == '?')
			{
				if (inc.charAt(i) == inj.charAt(i))
				{
					if (inj .charAt(i) == '?')
					{
						outc += 0;
						outj += 0;
					}
					else
					{
						outc += inc.charAt(i);
						outj += inj.charAt(i);
					}
				}
				else
				{
					if (inc.charAt(i) == '?')
					{
						outc += inj.charAt(i);
						outj += inj.charAt(i);
					}
					else
					{
						outc += inc.charAt(i);
						outj += inc.charAt(i);
					}			
				}
				i++;
				if (i >= inc.length())
					break;
			}
			if (i < inc.length())
			{
				int cadd = 0;
				if (inc.charAt(i) < inj.charAt(i))
					cadd = 9;
				int jadd = 9-cadd;
				for (int j = i; j < inc.length(); j++)
				{
					if (inc.charAt(j) == '?')
						outc += cadd;
					else
						outc += inc.charAt(j);
					if (inj.charAt(j) == '?')
						outj += jadd;
					else
						outj += inj.charAt(j);
				}
			}
			outline = outc + " " + outj;	
			if (num < cases)
				outline += "\n";
			out.writeCase(outline, num);
		}	
	out.close();
	}
}

		