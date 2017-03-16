package question4;

import java.util.ArrayList;

public class Key {

	ArrayList<Integer> mychest = new ArrayList<Integer>();
	int keytype;
	int pointer = -1;
	public Key(int nub)
	{
		keytype = nub;
	}
	public void addchest(int nub)
	{
		mychest.add(nub);
	}
	public int getNext(boolean[] chests)
	{
		++pointer;
		while( pointer < mychest.size())
		{
			if(chests.length > mychest.get(pointer))
				if(!chests[mychest.get(pointer)])
					break;
			pointer++;
		}
		if(pointer >= mychest.size())
			return -1;
		return mychest.get(pointer);
	}
	public void setback()
	{
		pointer = -1;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
