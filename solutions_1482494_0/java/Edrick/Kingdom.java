import java.util.*;

class Kingdom
{

	static int a[] = new int[1000];
	static int b[] = new int[1000];
	static int levelNumber;
	static int point;

	static boolean check()
	{
		if (point==2*levelNumber) return true;
		return false;
	}

	static int searchA (int x)
	{
		int i;
		for (i=0; i<levelNumber; i++)
			if (a[i]<=x) return i;
		return -1;
	}

	static int searchB (int x)
	{
		int i;
		for (i=0; i<levelNumber; i++)
			if (b[i]<=x) return i;
		return -1;
	}

	static int solve()
	{
		int move;
		int findB;
		int findA;
		move = 0;
		while (!check())
		{
			findB=searchB(point);
			if (findB!=-1)
			{
				if (a[findB]==5000000) point++;
				else point=point+2;
				a[findB]=5000000;
				b[findB]=5000000;
				move++;
			}
			else
			{
				findA=searchA(point);
				if (findA!=-1)
				{
					point++;
					a[findA]=5000000;
					move++;
				}
				else
					return -1;
			}
		}
		return move;
	}

	
	public static void main(String[] args)
	{
		Scanner myInput = new Scanner(System.in);
		int i;
		int result;
		int caseNumber;
		int caseCurrent;
		caseNumber = myInput.nextInt();
		for (caseCurrent=1; caseCurrent<=caseNumber; caseCurrent++)
		{
		levelNumber = myInput.nextInt();
		point = 0;
		for (i=0; i<levelNumber; i++)
		{
			a[i]=myInput.nextInt();
			b[i]=myInput.nextInt();
		}

		result=solve();
		if (result==-1) System.out.println("Case #"+caseCurrent+": Too Bad");
		else
			System.out.println("Case #"+caseCurrent+": "+result);
		}
	}
}
