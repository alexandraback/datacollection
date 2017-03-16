import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class mainClass {

	public static void main(String[] args) {
		File f = new File("C-small-attempt10.in");
		File out = new File("minesweeperMiner10.out");
		FileInputStream fin;
		Scanner sin = null;
		try {
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int xSize = sin.nextInt();
					int ySize = sin.nextInt();
					int mines = sin.nextInt();
					int cX = xSize-1, cY = ySize-1, m0 = mines;
					int availX = xSize, availY = ySize;
					boolean[][] board = new boolean[xSize][ySize]; //1=mine, 0=board
					boolean impossible = false;
					
					if(mines==xSize*ySize-1)
					{
						for(int x=0; x<xSize; x++)
						{
							for(int y=0; y<ySize; y++)
							{
								board[x][y] = true;
							}						
						}
						board[0][0] = false;
						cX = 0;
						cY = 0;
						try {
							fout.write("Case #" + (casenum+1) + ":\n");
							printBoard(fout, board, cX, cY);
							fout.flush();
						} catch (IOException e1) {e1.printStackTrace();}
						continue;
					}
					
					for(int x=0; x<xSize; x++)
					{
						for(int y=0; y<ySize; y++)
						{
							board[x][y] = false;
						}						
					}
					
					//Place mines across the edge, then recurse.
					//if mines is ever a multiple of availX or availY(and they're >1), then
					//simply place mines along that side
					if(availX-mines%availX>=2&&availY-mines/availX-1>=2||mines%availX==0&&availY-mines/availX>=2)
					{
						//Place mines along rows of avalX until it is 0.
						while(mines>0)
						{
							for(int x=xSize-availX; x<xSize&&mines>0; x++)
							{
								if(!board[x][ySize-availY])
								{
									board[x][ySize-availY] = true;
									mines--;
								}
							}
							availY--;
						}
					}
					else if(availY-mines%availY>=2&&availX-mines/availY-1>=2||mines%availY==0&&availX-mines/availY>=2)
					{
						//Place mines along rows of avalY until it is 0.
						while(mines>0)
						{
							for(int y=ySize-availY; y<ySize&&mines>0; y++)
							{
								if(!board[xSize-availX][y])
								{
									board[xSize-availX][y] = true;
									mines--;
								}
							}
							availX--;
						}
					}
					
					while(mines>=availX+availY-1)
					{
						//if mines is ever a multiple of availX or availY(and they're >1), then
						//simply place mines along that side
						if(availX-mines%availX>=2&&availY-mines/availX-1>=2||mines%availX==0&&availY-mines/availX>=2)
						{
							//Place mines along rows of avalX until it is 0.
							while(mines>0)
							{
								for(int x=xSize-availX; x<xSize&&mines>0; x++)
								{
									if(!board[x][ySize-availY])
									{
										board[x][ySize-availY] = true;
										mines--;
									}
								}
								availY--;
							}
							break;
						}
						else if(availY-mines%availY>=2&&availX-mines+2/availY-1>=2||mines%availY==0&&availX-mines/availY>=2)
						{
							//Place mines along rows of avalY until it is 0.
							while(mines>0)
							{
								for(int y=ySize-availY; y<ySize&&mines>0; y++)
								{
									if(!board[xSize-availX][y])
									{
										board[xSize-availX][y] = true;
										mines--;
									}
								}
								availX--;
							}
							break;
						}
						else
						{
							//across first available row and column
							for(int x=xSize-availX; x<xSize; x++)
							{
								if(!board[x][ySize-availY])
								{
									board[x][ySize-availY] = true;
									mines--;
								}
							}
							for(int y=ySize-availY; y<ySize; y++)
							{
								if(!board[xSize-availX][y])
								{
									board[xSize-availX][y] = true;
									mines--;
								}
							}
							availX -= 1;
							availY -= 1;
						}
					}
					if(((availX==1&&availY!=mines-1)||(availY==1&&availX!=mines-1))&&(xSize!=1&&ySize!=1))
					{
						impossible = true;
					}
					while(mines>0&&!impossible)
					{
						//in a board with 
						//#mines < x+y-1
						int beforeMines = mines;
						if((availX==1&&availY!=mines-1)||(availY==1&&availX!=mines-1))
						{
							impossible = true;
						}
						else if(availX-mines%availX>=2&&availY-mines/availX-1>=2||mines%availX==0&&availY-mines/availX>=2)
						{
							//Place mines along rows of avalX until it is 0.
							while(mines>0)
							{
								for(int x=xSize-availX; x<xSize&&mines>0; x++)
								{
									if(!board[x][ySize-availY])
									{
										board[x][ySize-availY] = true;
										mines--;
									}
								}
								availY--;
							}
							break;
						}
						else if(availY-mines%availY>=2&&availX-mines+2/availY-1>=2||mines%availY==0&&availX-mines/availY>=2)
						{
							//Place mines along rows of avalY until it is 0.
							while(mines>0)
							{
								for(int y=ySize-availY; y<ySize&&mines>0; y++)
								{
									if(!board[xSize-availX][y])
									{
										board[xSize-availX][y] = true;
										mines--;
									}
								}
								availX--;
							}
							break;
						}
						else if(availX>3)
						{
							//place one column then try again
							for(int y=ySize-availY; y<ySize-2/* 2 buffer required to reveal the edge-thing */&&mines>0; y++)
							{
								if(!board[xSize-availX][y])
								{
									board[xSize-availX][y] = true;
									mines--;
								}
							}
							availX--;
						}
						else if(availY>3)
						{
							for(int x=xSize-availX; x<xSize-2/* 2 buffer required to reveal the edge-thing */&&mines>0; x++)
							{
								if(!board[x][ySize-availY])
								{
									board[x][ySize-availY] = true;
									mines--;
								}
							}
							availY--;
						}
						if(beforeMines==mines)
							impossible = true;
					}
					
					try {
						
						fout.write("Case #" + (casenum+1) + ":\n");
						if(impossible)
						{
							fout.write("Impossible");
							fout.write("\n");
						}
						else
							printBoard(fout, board, cX, cY);
						fout.flush();
					} catch (IOException e1) {e1.printStackTrace();}
				}
			} finally {
				sin.close();
				fout.close();
			}
		}
		catch(IOException e)
		{}
	}

	public static void printBoard(FileWriter fout, boolean[][] board, int clickX, int clickY) throws IOException
	{
		for(int x=0; x<board.length; x++)
		{
			for(int y=0; y<board[x].length; y++)
			{
				if(!board[x][y])
				{
					if(x!=clickX||y!=clickY)
						fout.write(".");
					else
						fout.write("c");
				}
				else
					fout.write("*");
			}
			fout.write("\n");
		}
	}
	
	
}
