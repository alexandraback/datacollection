#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>

using namespace std;

char t[4][10];

int main ()
{
    int z,l1,l2,a,b,c,d;
    bool krop;
    
    scanf ("%d", &z);
    
    for (a=1; a<=z; a++)
    {
        krop=0;
        scanf ("%s%s%s%s", t[0], t[1], t[2], t[3]);
        
        for (b=0; b<4; b++)
            for (c=0; c<4; c++)
                if (t[b][c]=='.')
                   krop=1;
        
        for (b=0; b<4; b++)
        {
            l1=l2=0;
            
            for (c=0; c<4; c++)
            {
                if (t[b][c]=='X')
                   l1++;
                
                if (t[b][c]=='O')
                   l2++;
                
                if (t[b][c]=='T')
                {
                                 l1++;
                                 l2++;
                }
            }
            
            if (l1==4)
            {
                      printf ("Case #%d: X won\n", a);
                      break;
            }
            
            if (l2==4)
            {
                      printf ("Case #%d: O won\n", a);
                      break;
            }
            
            l1=l2=0;
            
            for (c=0; c<4; c++)
            {
                if (t[c][b]=='X')
                   l1++;
                
                if (t[c][b]=='O')
                   l2++;
                
                if (t[c][b]=='T')
                {
                                 l1++;
                                 l2++;
                }
            }
            
            if (l1==4)
            {
                      printf ("Case #%d: X won\n", a);
                      break;
            }
            
            if (l2==4)
            {
                      printf ("Case #%d: O won\n", a);
                      break;
            }
        }
        
        if (b<4)      
           continue;
           
        l1=l2=0;
        
        for (b=0; b<4; b++)
        {
                if (t[b][b]=='X')
                   l1++;
                
                if (t[b][b]=='O')
                   l2++;
                
                if (t[b][b]=='T')
                {
                                 l1++;
                                 l2++;
                }
        }
            
        if (l1==4)
        {
                      printf ("Case #%d: X won\n", a);
                      continue;
        }
            
        if (l2==4)
        {
                      printf ("Case #%d: O won\n", a);
                      continue;
        }
        
        l1=l2=0;
        
        for (b=0; b<4; b++)
        {
                if (t[b][3-b]=='X')
                   l1++;
                
                if (t[b][3-b]=='O')
                   l2++;
                
                if (t[b][3-b]=='T')
                {
                                 l1++;
                                 l2++;
                }
        }
            
        if (l1==4)
        {
                      printf ("Case #%d: X won\n", a);
                      continue;
        }
            
        if (l2==4)
        {
                      printf ("Case #%d: O won\n", a);
                      continue;
        }
        
        if (!krop)
           printf ("Case #%d: Draw\n", a);
        else
            printf ("Case #%d: Game has not completed\n", a);
    }
        
    getchar();
    getchar();
    return 0;
}
