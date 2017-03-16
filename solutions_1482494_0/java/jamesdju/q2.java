import java.util.*;

class q2
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int numCase, numLevel, count_game, total_star;
    int [][] levels;
    boolean level_found = false;
    
    numCase = sc.nextInt();
    
    for(int i = 0; i < numCase; i++)
    {
      numLevel = sc.nextInt();
      levels = new int[numLevel][2];
      for(int j = 0; j < numLevel; j++)
      {
        levels[j][0] = sc.nextInt();
        levels[j][1] = sc.nextInt();
      }
      
      total_star = 0;
      count_game = 0;
		
		for(int j = numLevel-1; j >= 1; j--)
		{
			int index = j;

			for(int k = 0; k < j; k++)
				if(levels[k][1] < levels[index][1])
					index = k;

			int temp = levels[index][0];
			int temp2 = levels[index][1];
			levels[index][0] = levels[j][0];
			levels[index][1] = levels[j][1];
			levels[j][0] = temp;
			levels[j][1] = temp2;
		}

      while(total_star < 2*numLevel)
      {
        level_found = false;
        for(int j = 0; j < numLevel; j++)
        {
          if(levels[j][1] <= total_star)
          {
            if(levels[j][0] != Integer.MAX_VALUE)
              total_star += 2;
            else
              total_star += 1;
            levels[j][1] = Integer.MAX_VALUE;
            levels[j][0] = Integer.MAX_VALUE;
            level_found = true;
            count_game++;
          }
          if(level_found)
            break;
        }
        
        if(!level_found)
        {
          for(int j = 0; j < numLevel; j++)
          {
            if(levels[j][0] <= total_star)
            {
              total_star += 1;
              levels[j][0] = Integer.MAX_VALUE;
              level_found = true;
              count_game++;
            }
            
            if(level_found)
              break;
          }
        }
        
        if(!level_found)
          break;
      }
      System.out.print("Case #"+ (i+1) + ": ");
      if(total_star < 2*numLevel)
        System.out.println("Too Bad");
      else
        System.out.println(count_game);
    }
  }
}
