#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define mod 1000000007
#define pinf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a);
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define ps(a) printf("%s",a);
#define nline printf("\n")
#define pc(a) printf("%c",a)
#define ll long long
#define MAX(a,b,c) ((a>b)?(a>c?a:c):(b>c?b:c))
#define MIN(a,b,c) ((a<b)?(a<c?a:c):(b<c?b:c))

int main()
{
int t,p;
char ch;
FILE * fp,*fw;
fp=fopen("A-small-attempt0.in","r");
fw=fopen("output.txt","w");
fscanf(fp,"%d",&t);
for(p=1;p<=t;p++)
    {
        int i,j,countdot,f1=0,f2=0,f3=0,f4=0;
        char a[4][5];
        for(i=0;i<4;i++)
            fscanf(fp,"%s",a[i]);
          fscanf(fp,"%c",&ch);
        countdot=0;
        for(i=0;i<4;i++)
                {
                 int count1=0,count2=0,count3=0;
                 for(j=0;j<4;j++)
                    {
                    if(a[i][j]=='X')
                        count1++;
                    else if(a[i][j]=='O')
                        count2++;
                    else if(a[i][j]=='T')
                        count3++;
                    else if(a[i][j]=='.')
                        countdot++;
                    }
                        if(((count1==3)&&(count3==1))||count1==4)
                            {
                            f1=1;
                            fprintf(fw,"Case #%d: X won\n",p);
                                }
                            else if(((count2==3)&&(count3==1))||count2==4)
                                {
                            f1=1;
                            fprintf(fw,"Case #%d: O won\n",p);
                                }
                if(f1)
                                break;
                }


                if(f1)
                    continue;

                  for(j=0;j<4;j++)
                {
                 int count1=0,count2=0,count3=0;
                 for(i=0;i<4;i++)
                    {
                    if(a[i][j]=='X')
                        count1++;
                    else if(a[i][j]=='O')
                        count2++;
                    else if(a[i][j]=='T')
                        count3++;
                    }
                        if(((count1==3)&&(count3==1))||count1==4)
                            {
                            f2=1;
                            fprintf(fw,"Case #%d: X won\n",p);
                                }
                            else if(((count2==3)&&(count3==1))||count2==4)
                                {
                            f2=1;
                            fprintf(fw,"Case #%d: O won\n",p);
                                }
                            if(f2)
                                break;
                }
                    if(f2)
                        continue;

      int count1=0,count2=0,count3=0;

        for(i=0;i<4;i++)
                    {

                    j=i;
                    if(a[i][j]=='X')
                        count1++;
                    else if(a[i][j]=='O')
                        count2++;
                    else if(a[i][j]=='T')
                        count3++;
                    }

        if(((count1==3)&&(count3==1))||count1==4)
                            {
                           f3=1;
                            fprintf(fw,"Case #%d: X won\n",p);
                                }
        else if(((count2==3)&&(count3==1))||count2==4)
                                {
                            f3=1;
                            fprintf(fw,"Case #%d: O won\n",p);
                                }

                if(f3)
                            continue;

            count1=0,count2=0,count3=0;

            for(i=0;i<4;i++)
                    {
                    j=3-i;
                    if(a[i][j]=='X')
                        count1++;
                    else if(a[i][j]=='O')
                        count2++;
                    else if(a[i][j]=='T')
                        count3++;
                    }

        if(((count1==3)&&(count3==1))||count1==4)
                            {
                           f4=1;
                            fprintf(fw,"Case #%d: X won\n",p);
                                }
                            else if(((count2==3)&&(count3==1))||count2==4)
                                {
                                f4=1;
                            fprintf(fw,"Case #%d: O won\n",p);
                                }
                  if(f4)
                            continue;

                    if(countdot!=0)
                        fprintf(fw,"Case #%d: Game has not completed\n",p);
                    else
                       fprintf(fw,"Case #%d: Draw\n",p);
    }
return 0;
}
