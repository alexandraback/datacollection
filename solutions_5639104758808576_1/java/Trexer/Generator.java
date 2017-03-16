package ranGen;

import java.util.Random;

public class Generator
{

	public static String stringGen(int length, String chars)
	{
		char[] stringArr = new char[length];
		Random gen = new Random();
		for(int i=0; i<length; i++)
		{
			stringArr[i] = chars.charAt(gen.nextInt(chars.length()));
		}
		String result = new String(stringArr);
		return result;
	}
	
}