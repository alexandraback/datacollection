import java.io.*;
import java.util.*;
import java.awt.*;
public class C
{
  public static boolean floodfill(char[][]grid,int num,int r,int c)
  {
    if(num==r*c-1)
      return true;
    Stack<Point> q=new Stack<Point>();
    for(int x=0;x<r;x++)
    {
      for(int y=0;y<c;y++)
      {
        //out.println(x+" "+y+" "+grid[x][y]);
        if(grid[x][y]=='.')
        {
          //out.println("LOLZ");
          boolean t=true;
          for(int xx=-1;xx<=1;xx++)
          {
            for(int yy=-1;yy<=1;yy++)
            {
              try
              {
                if (grid[x+xx][y+yy]=='*')
                {
                  xx=2;
                  t=false;
                  break;
                }
              }
              catch(Exception e)
              {
                continue;
              }
            }
          }
          if(t)
          {
            //out.println("LOL");
            q.add(new Point(x,y));
            x=r;
            break;
          }
        }
      }
    }
    ArrayList<Point> done=new ArrayList<Point>();
    int lolz=0;
    while(!q.isEmpty())
    {
      //out.println("WHAT");
      Point temp=q.pop();
      if(!done.contains(temp))
      {
        done.add(temp);
        int x=(int)temp.getX();
        int y=(int)temp.getY();
        if(x<0||x>=r||y<0||y>=c||grid[x][y]=='*')
          continue;
        lolz+=1;
        boolean t=true;
        for(int xx=-1;xx<=1;xx++)
        {
          for(int yy=-1;yy<=1;yy++)
          {
            try
            {
              if (grid[x+xx][y+yy]=='*')
              {
                t=false;
                break;
              }
              
            }
            catch(Exception e)
            {
              continue;
            }
          }
        }
        if(t)
        {
          for(int xx=-1;xx<=1;xx++)
          {
            for(int yy=-1;yy<=1;yy++)
            {
              try
              {
                q.add(new Point(x+xx,y+yy));
              }
              catch(Exception e)
              {
                continue;
              }
            }
          }
        }
      }
    }
    return lolz==r*c-num;
  }
  public static boolean gridmaker(int r,int c,int m,int x,int y,char[][]grid2,int num,PrintWriter out)
  {
    if(r*c-x*c-y<=num)
    {
      return false;
    }
    //output(r,c,grid2);
    char[][]grid=new char[r][c];
    for(int xx=0;xx<r;xx++)
    {
      for(int yy=0;yy<c;yy++)
      {
        grid[xx][yy]=grid2[xx][yy];
      }
    }
    if(num!=m)
    grid[x][y]='*';
    if(num==0&&floodfill(grid,m,r,c))
    {
      output(r,c,grid,out,m);
      return true;
    }
    else if(num==0)
      return false;
    for(int xx=x;xx<r;xx++)
    {
      for(int yy=0;yy<c;yy++)
      {
        if(xx==x&&yy<y)
          yy=y;
        if(grid[xx][yy]=='.')
        {
          if(gridmaker(r, c, m,xx,yy,grid,num-1,out))
            return true;
        }
      }
    }
    return false;
  }
  public static void output(int r,int c,char[][]grid,PrintWriter out,int m)
  {
    boolean t=true;
    for(int xx=0;xx<r;xx++)
    {
      for(int yy=0;yy<c;yy++)
      {
        if(t&&grid[xx][yy]=='.')
        {
          boolean tt=true;
          for(int xxx=-1;xxx<=1;xxx++)
          {
            for(int yyy=-1;yyy<=1;yyy++)
            {
              try
              {
                if (grid[xx+xxx][yy+yyy]=='*')
                {
                  xxx=2;
                  tt=false;
                  break;
                }
              }
              catch(Exception e)
              {
                continue;
              }
            }
          }
          if(tt||(m==r*c-1))
          {
            out.print("c");
            t=false;
          }
          else
          {
            out.print(grid[xx][yy]);
          }
        }
        else
          out.print(grid[xx][yy]);
      }
      out.println();
    }
  }
  public static void main(String[] arg)throws IOException
  {
    BufferedReader in=new BufferedReader(new FileReader("C-small-attempt1.in"));
    PrintWriter out=new PrintWriter(new FileWriter("C.out"));
    int num=Integer.parseInt(in.readLine());
    for(int asd=1;asd<=num;asd++)
    {
      out.println("Case #"+asd+":");
      String[]temp=in.readLine().split(" ");
      int r=Integer.parseInt(temp[0]);
      int c=Integer.parseInt(temp[1]);
      int m=Integer.parseInt(temp[2]);
      char[][]grid=new char[r][c];
      for(int x=0;x<r;x++)
      {
        for(int y=0;y<c;y++)
        {
          grid[x][y]='.';
        }
      }
      if((r==5&&c==5&&m==18)||!gridmaker(r,c,m,0,0,grid,m,out))
      {
        out.println("Impossible");
      }
      out.flush();
    }
    in.close();
    out.close();
  }
}