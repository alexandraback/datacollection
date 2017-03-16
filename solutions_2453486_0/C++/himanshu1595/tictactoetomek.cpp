#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

int t, flag, ans, counter;
char str[10][10];

int main()
{
    cin>>t;
    counter=1;
    while(t--)
    {
        ans=0;
        flag=0;
        for(int i=0; i<4; i++)
            cin>>str[i];
        // For X
        for(int i=0; i<4; i++)
        {
            flag=0;
            for(int j=0; j<4; j++)
            {
                if(str[i][j]=='O'||str[i][j]=='.')
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                ans=1;
        }
        for(int j=0; j<4; j++)
        {
            flag=0;
            for(int i=0; i<4; i++)
            {
                if(str[i][j]=='O'||str[i][j]=='.')
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                ans=1;
        }
        flag=0;
        for(int i=0; i<4; i++)
        {
            if(str[i][i]=='O'||str[i][i]=='.')
                flag=1;
        }
        if(!flag)
            ans=1;
        flag=0;
        for(int i=0; i<4; i++)
        {
            if(str[i][3-i]=='O'||str[i][3-i]=='.')
                flag=1;
        }
        if(!flag)
            ans=1;
        if(ans==1)
            printf("Case #%d: X won\n",counter++);
        else
        {
            // For O
            for(int i=0; i<4; i++)
            {
                flag=0;
                for(int j=0; j<4; j++)
                {
                    if(str[i][j]=='X'||str[i][j]=='.')
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    ans=2;
            }
            for(int j=0; j<4; j++)
            {
                flag=0;
                for(int i=0; i<4; i++)
                {
                    if(str[i][j]=='X'||str[i][j]=='.')
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    ans=2;
            }
            flag=0;
            for(int i=0; i<4; i++)
            {
                if(str[i][i]=='X'||str[i][i]=='.')
                    flag=1;
            }
            if(!flag)
                ans=2;
            flag=0;
            for(int i=0; i<4; i++)
            {
                if(str[i][3-i]=='X'||str[i][3-i]=='.')
                    flag=1;
            }
            if(!flag)
                ans=2;
            if(ans==2)
                printf("Case #%d: O won\n",counter++);
            else
            {
                flag=0;
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                        if(str[i][j]=='.')
                            flag=1;
                }
                if(flag)
                    printf("Case #%d: Game has not completed\n", counter++);
                else
                    printf("Case #%d: Draw\n", counter++);
            }
        }
    }
    return 0;
}
