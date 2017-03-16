#include"iostream"
#include"stdio.h"
#include"string.h"
#include"string"
#include"vector"
#include"algorithm"
#include"math.h"
using namespace std;
#define FOR(i,a,b)	for(i=a;i<b;i++)
int main()
	{
		int TC,co,t,n,l,i,j,k,ans;
		char S[105];
		cin>>t;
		FOR(TC,1,t+1)
			{
				ans=0;
				getchar();
				scanf("%s",S);
				l=strlen(S);
				cin>>n;
				//cout<<S<<" "<<n<<endl;
				FOR(i,0,l)
					{
						FOR(j,i,l)
							{
								co=0;
								FOR(k,i,j+1)
									{
										if(S[k]=='a'||S[k]=='i'||S[k]=='o'||S[k]=='e'||S[k]=='u')	co=0;
										else	co++;
										if(co>=n)	{ans++;	break;}
									}
							}
					}
				cout<<"Case #"<<TC<<": "<<ans<<endl;
			}
		return 0;
	}