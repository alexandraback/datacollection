package round1A;

import utils.IOHelper;

public class PasswordProblem
{
	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		try
		{
			String[] input = IOHelper.readFile(args[0], 2);
			double[] results = new double[input.length / 2];

			for (int line = 0; line < input.length; line++)
			{
				String[] token = input[line].split(" ");
				int typed = Integer.parseInt(token[0]);
				int pwLength = Integer.parseInt(token[1]);

				token = input[++line].split(" ");
				double[] prob = new double[token.length];
				for (int i = 0; i < token.length; i++)
				{
					prob[i] = Double.parseDouble(token[i]);
				}

				double[] toTypeOnAvg = new double[typed + 1];
				for (int i = 0; i < typed; i++)
				{
					double probAllRightExceptLastI = 1.0d;
					for (int j = 0; j < prob.length - i; j++)
					{
						probAllRightExceptLastI *= prob[j];
					}

					double probTypeAgain = 1.0d - probAllRightExceptLastI;

					// Keys + enter + Backspace hits + retype + enter.
					double types = probAllRightExceptLastI * ((pwLength - typed + i) + 1 + i)
							+ probTypeAgain * ((pwLength - typed + i) + 1 + i + 1 + pwLength);
					toTypeOnAvg[i] = types;
				}

				toTypeOnAvg[typed] = pwLength + 1 + 1;

				// Find smallest number of types.
				double smallest = Double.MAX_VALUE;
				for (int i = 0; i < toTypeOnAvg.length; i++)
				{
					if (smallest > toTypeOnAvg[i])
					{
						smallest = toTypeOnAvg[i];
					}
				}

				results[line / 2] = smallest;
			}

			IOHelper.writeFile(args[0].replace(".in", ".out"), results);
		}
		catch (IndexOutOfBoundsException e)
		{
			e.printStackTrace();
		}
	}
}
