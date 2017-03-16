package utils;

public class Pair<A extends Comparable<A>, B extends Comparable<B>> implements
		Comparable<Pair<A, B>>
{
	public A a;
	public B b;
	public boolean flag;

	public Pair(A a, B b)
	{
		this.a = a;
		this.b = b;
		this.flag = false;
	}

	@Override
	public int compareTo(Pair<A, B> o)
	{
		if (this.a == o.a && this.b == o.b)
		{
			return 0;
		}
		else
		{
			if (this.a == o.a)
			{
				return this.b.compareTo(o.b);
			}
			else
			{
				return this.a.compareTo(o.a);
			}
		}
	}
}
