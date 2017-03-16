#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n,s,p,ans,in;
int main()
{
        freopen("in-small-B.txt","r",stdin);
        freopen("out-small-B.txt","w",stdout);
        scanf("%d",&t);
        int ch;
        for(int i=1;i<=t;i++)
        {
                scanf("%d %d %d",&n,&s,&p);
                ans=0;
                for(int j=0;j<n;j++)
                {
                      scanf("%d",&in);
                      ch = max((p-1),0);
                      if(in>=p+ch+ch) {
                                ans++;
                        }
                        else {
                                ch = max((p-2),0);
                                if(in>=p+ch+ch && s!=0) {
                                          s--;
                                          ans++;
                                        }
                                }
                        }
                        printf("Case #%d: %d\n",i,ans);
                }
                //system("pause");
        }
