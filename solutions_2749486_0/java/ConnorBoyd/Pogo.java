
public class Pogo {
	
	int x, y, nextMove, currentX, currentY;
	public Pogo(int ex, int why)
	{
		x = ex; y = why; nextMove = 1;
		currentX = 0; currentY = 0;
	}
	
	public String getMoves()
	{
		
		return getToX() + getToY();
		
		
//		return "";
	}
	
	private String getToX()
	{
		String moves = "";
		if(x > 0)//go East
		{
			while(currentX < x)
			{
				currentX += nextMove;
				++nextMove;
				moves += "E";
			}
			if(x == currentX) return moves;
			
			//Now go west until currentX == x
			
			while(currentX != x)
			{
				currentX += nextMove; moves += "E"; ++nextMove;
				if(currentX == x) return moves;
				currentX -= nextMove; moves += "W"; ++nextMove;
			}
			
		}
		else	//go West
		{
			while(currentX > x)
			{
				currentX -= nextMove;
				++nextMove;
				moves += "W";
			}
			if(x == currentX) return moves;
			
			//Now go west until currentX == x
			
			while(currentX != x)
			{
				currentX -= nextMove; moves += "W"; ++nextMove;
				if(currentX == x) return moves;
				currentX += nextMove; moves += "E"; ++nextMove;
			}
		}
		
		
		return moves;
	}
	
	private String getToY()
	{
		String moves = "";
		if(y > 0)//go North
		{
			while(currentY < y)
			{
				currentY += nextMove;
				++nextMove;
				moves += "N";
			}
			if(y == currentY) return moves;
			
			//Now go south until currentY == y
			
			while(currentY != y)
			{
				currentY += nextMove; moves += "N"; ++nextMove;
				if(currentY == y) return moves;
				currentY -= nextMove; moves += "S"; ++nextMove;
			}
			
		}
		else	//go South
		{
			while(currentY > y)
			{
				currentY -= nextMove;
				++nextMove;
				moves += "S";
			}
			if(y == currentY) return moves;
			
			//Now go west until currentY == y
			
			while(currentY != y)
			{
				currentY -= nextMove; moves += "S"; ++nextMove;
				if(currentY == y) return moves;
				currentY+= nextMove; moves += "N"; ++nextMove;
			}
		}
		
		
		return moves;
		
		
//		return "";
	}
	
	private String getBothPast()
	{
		String moves = "";
		int xdir, ydir;
		String xmov, ymov;
		
		if(x > 0)
		{
			xdir = 1; xmov = "E";
		}
		else
		{
			xdir = -1; xmov = "W";
		}
		
		if(y > 0)
		{
			ydir = 1; ymov = "N";
		}
		else
		{
			ydir = -1; ymov = "S";
		}
		
		
		
		
		return moves;
	}
}
