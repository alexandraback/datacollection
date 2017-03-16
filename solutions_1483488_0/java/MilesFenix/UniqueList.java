

public class UniqueList {
	private int[] number;
	private int totalSize, size;
	
	public UniqueList(int allocatedSize)
	{
		totalSize = allocatedSize;
		number = new int[totalSize];
		size = 0;
	}
	public void add(int n)
	{
		for (int i = 0; i < size; i++)
		{
			if (number[i] == n) return;
		}
		number[size ++] = n;
	}
	
	public int getSize()
	{
		return size;
	}

}
