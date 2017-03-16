package question4;

import java.util.ArrayList;

public class Stack {
	
	ArrayList<Node> myint = new ArrayList<Node>();
	public void push(Node nub)
	{
		myint.add(nub);
	}
	public Node pop()
	{
		int size = myint.size();
		Node returnint = myint.get(size-1);
		myint.remove(size-1);
		return returnint;
	}
	boolean isempty()
	{
		return(myint.size() == 0);
	}
	void print()
	{
		for(int i = 0; i < myint.size();i++)
			System.out.print(myint.get(i).print());
		System.out.print("\n");
	}
	String output()
	{
		String mystring = "";
		for(int i = 1; i < myint.size(); i+=2)
		{
			mystring+=String.valueOf(myint.get(i).nub+1);
			if(i < myint.size())
				mystring+=" ";
		}
		return mystring;
	}
	void clear()
	{
		myint.clear();
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
