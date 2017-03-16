/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Test
{
	
	public void divide(int a,int b)
{
	try{
		int c=a/b;
	}
	catch (Exception e)
	{
		System.out.println("A");
	}
	finally
	{
		System.out.println("B");
	}
}
public static void main (String[] args) throws java.lang.Exception
	{
int a=4,b=0;
divide(a,b);
}

}
