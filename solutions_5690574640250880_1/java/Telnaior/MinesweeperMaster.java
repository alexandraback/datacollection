package tel.cj.cj2014.qualification;

import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class MinesweeperMaster {

	/**This class is designed to solve Problem B: Cookie Clicker Alpha.
	 * @param Two arguments: Input filepath and output filepath.
	 * @throws IOException
	 * @author Telnaior
	 */
	public static void main(String[] args) throws IOException
	/**Controller method to set up input and output, then pass to problem-specific method.
	 * 
	 */
	{
		Path inputPath = Paths.get(args[0]);
		Scanner sc = new Scanner(inputPath);
		PrintStream output = new PrintStream(args[1]);
		System.setOut(output);
		run(sc);
		output.close();
	}
	static void run(Scanner sc)
	{
		//Like always, start by grabbing the number of test cases needed
		final int CASES = sc.nextInt();
		//Then establish our problem-solving loop
		for(int caseNumber=1; caseNumber<=CASES; caseNumber++)
		{
			//Let's grab this case's variables
			int height = sc.nextInt();
			int width = sc.nextInt();
			int mines = sc.nextInt();
			//Now let's work out whether or not it's possible.
			//First case: Height or Width of 1 = possible, with special print format.
			if(height==1)
			{
				printHorizontal(caseNumber, width, mines);
				continue;
			}
			if(width==1)
			{
				printVertical(caseNumber, height, mines);
				continue;
			}
			//If there are 2/3/5/7 non-mine spaces, it's impossible
			int spacesLeft = (width*height)-mines;
			switch (spacesLeft)
			{
			case 2: case 3: case 5: case 7:
				printImpossible(caseNumber);
				continue;
			//On the other hand, if there's only 1 then it's possible no matter what
			case 1:
				printStandard(caseNumber, width, height, mines, spacesLeft);
				continue;
			}
			//If one dimension is 2 and there are an odd number of mines, also impossible
			if((width==2 || height==2) && ((mines%2)==1))
			{
				printImpossible(caseNumber);
				continue;
			}
			//Otherwise, we can print it normally
			printStandard(caseNumber, width, height, mines, spacesLeft);
		}
	}
	static void printHorizontal(int caseNumber, int width, int mines)
	{
		System.out.println("Case #"+caseNumber+":");
		//Start with the clicked square in the corner
		System.out.print("c");
		//Then dots equal to the number of spaces left
		int spacesLeft = width-mines-1;
		while(spacesLeft > 0)
		{
			System.out.print(".");
			spacesLeft--;
		}
		//Then asterisks equal to the number of mines
		for(int i=0; i<mines; i++)
		{
			System.out.print("*");
		}
		//Then end the line so that we don't break the next test case.
		System.out.println();
	}
	static void printVertical(int caseNumber, int height, int mines)
	{
		System.out.println("Case #"+caseNumber+":");
		//Start with the clicked square in the corner
		System.out.println("c");
		//Then dots equal to the number of spaces left
		int spacesLeft = height-mines-1;
		while(spacesLeft > 0)
		{
			System.out.println(".");
			spacesLeft--;
		}
		//Then asterisks equal to the number of mines
		for(int i=0; i<mines; i++)
		{
			System.out.println("*");
		}
	}
	static void printStandard(int caseNumber, int width, int height,
			int mines, int spacesLeft)
	{
		System.out.println("Case #"+caseNumber+":");
		//Put all the non-mine spaces together. What size rectangle do we have?
		int rectangleWidth = (int) Math.sqrt(spacesLeft);
		int rectangleHeight = rectangleWidth;
		//sparesOnRight will be used later to know where to put any leftover spaces.
		boolean sparesOnRight = false;
		//Can we extend it fully in one direction?
		if(rectangleWidth*(rectangleHeight+1)<=spacesLeft)
		{
			rectangleHeight++;
			sparesOnRight = true;
		}
		//And how many spaces will be left outside of that rectangle?
		spacesLeft -= (rectangleWidth*rectangleHeight);
		//Hold up, if the rectangle doesn't fit, we should work something else out.
		if(rectangleWidth>width || rectangleHeight>height)
		{
			printCornerCase(width, height, mines);
			return;
		}
		//And if there's exactly one space left, we'll also need to change things up.
		if(spacesLeft == 1)
		{
			printNonSquare(width, height, mines,
					rectangleWidth, rectangleHeight, sparesOnRight);
			return;
		}
		//Finally, if we're using the full width (or height), set sparesOnRight accordingly.
		//(They can't both be true, don't worry)
		if(rectangleWidth == width)
		{
			sparesOnRight = false;
		}
		if(rectangleHeight == height)
		{
			sparesOnRight = true;
		}
		//That's all the information we should need, so let's start drawing.
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				//If this is the top-left corner, click it
				if(x==0 && y==0)
				{
					System.out.print("c");
				}
				//If it's inside the rectangle, it's safe
				else if(x<rectangleWidth && y<rectangleHeight)
				{
					System.out.print(".");
				}
				//Or if it's a spare space, put it in its place
				else if(x==rectangleWidth && spacesLeft>0 && sparesOnRight)
				{
					System.out.print(".");
					spacesLeft--;
				}
				else if(y==rectangleHeight && spacesLeft>0 && !sparesOnRight)
				{
					System.out.print(".");
					spacesLeft--;
				}
				//But if it isn't actually a space, it's gotta be a mine.
				else
				{
					System.out.print("*");
				}
				//Finally, if we're at the end of the row, go to the next line.
				if(x==(width-1))
				{
					System.out.println();
				}
			}
		}
	}
	static void printCornerCase(int width, int height, int mines)
	{
		//Well, we're here because one of the dimensions is too small.
		//If I had to guess, I'd say it was the smaller dimension.
		//Which one is that?
		boolean isVertical = false;
		if(width<height)
		{
			isVertical = true;
		}
		//Right then. Now let's work out a better rectangle size.
		int spacesLeft = (width*height)-mines;
		int rectangleWidth = 0;
		int rectangleHeight = 0;
		if(isVertical)
		{
			rectangleWidth = width;
			rectangleHeight = spacesLeft/rectangleWidth;
		}
		else
		{
			rectangleHeight = height;
			rectangleWidth = spacesLeft/rectangleHeight;
		}
		spacesLeft-=(rectangleHeight*rectangleWidth);
		//Wait, surely they didn't, did they?
		if(spacesLeft==1)
		{
			//I HATE YOU.
			printNonSquare(width, height, mines,
					rectangleWidth, rectangleHeight, !isVertical);
			return;
		}
		//Right, now that we've ascertained that Google isn't terrible people, let's draw!
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				//If this is the top-left corner, click it
				if(x==0 && y==0)
				{
					System.out.print("c");
				}
				//If it's inside the rectangle, it's safe
				else if(x<rectangleWidth && y<rectangleHeight)
				{
					System.out.print(".");
				}
				//Or if it's a spare space, put it in its place
				else if(x==rectangleWidth && spacesLeft>0 && !isVertical)
				{
					System.out.print(".");
					spacesLeft--;
				}
				else if(y==rectangleHeight && spacesLeft>0 && isVertical)
				{
					System.out.print(".");
					spacesLeft--;
				}
				//But if it isn't actually a space, it's gotta be a mine.
				else
				{
					System.out.print("*");
				}
				//Finally, if we're at the end of the row, go to the next line.
				if(x==(width-1))
				{
					System.out.println();
				}
			}
		}
	}
	static void printNonSquare(int width, int height, int mines,
			int rectangleWidth, int rectangleHeight, boolean sparesOnRight)
	{
		//I can't believe we ended up here.
		//Right, so we just have to be really careful in our printing.
		//Everything should /probably/ be fine, right?
		//(God dammit Google no Google why)
		//The +1 here is because we'll be taking one away from the rectangle.
		int spacesLeft = (width*height)-mines+1;
		spacesLeft -= (rectangleHeight*rectangleWidth);
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				//If this is the top-left corner, click it
				if(x==0 && y==0)
				{
					System.out.print("c");
				}
				//If this is the bottom-right corner of the rectangle, CAUGHT YOU!
				else if((x+1)==rectangleWidth && (y+1)==rectangleHeight)
				{
					System.out.print("*");
					//Ugh, so much work just for this tiny exception. God dammit.
				}
				//Otherwise, if it's inside the rectangle, it's safe
				else if(x<rectangleWidth && y<rectangleHeight)
				{
					System.out.print(".");
				}
				//Or if it's a spare space, put it in its place
				else if(x==rectangleWidth && spacesLeft>0 && sparesOnRight)
				{
					System.out.print(".");
					spacesLeft--;
				}
				else if(y==rectangleHeight && spacesLeft>0 && !sparesOnRight)
				{
					System.out.print(".");
					spacesLeft--;
				}
				//But if it isn't actually a space, it's gotta be a mine.
				else
				{
					System.out.print("*");
				}
				//Finally, if we're at the end of the row, go to the next line.
				if(x==(width-1))
				{
					System.out.println();
				}
			}
		}
	}
	static void printImpossible(int caseNumber)
	{
		//Well that was easy. Yay!
		System.out.println("Case #"+caseNumber+":");
		System.out.println("Impossible");
	}
}