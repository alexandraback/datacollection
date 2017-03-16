// =====================================================================================
//       Filename:  ManageEngery.cpp
//    Description:  
//        Created:  04/27/2013 08:17:50 AM
//         Author:  BrOkEN@!
// =====================================================================================

#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define FOR(i,a,b) for(typeof((a)) i=(a); i <= (b) ; ++i)       
#define FOREACH(it,x) for(typeof((x).begin()) it=(x).begin(); it != (x).end() ; ++it)   
#define MAX 101


using namespace std;

typedef pair<int,int> PI;
typedef vector<PI> VI;

int e,r,n,max1;
int v[100];

void solve(int pos,int en,int gain)
{
                   if(pos==n)
                   {
                             
                                   //cout<<en<<"\n";
                             max1=max(max1,gain);
                             return ;          
                   }
                   
                   
                   for(int i=0;i<=en;i++)
                   {
                                         if((en-i+r)<=e)
                                         solve(pos+1,(en-i)+r,gain+v[pos]*i);        
                                         else
                                         solve(pos+1,e,gain+v[pos]*i);
                   }
                   
                   return ;
}

int main(){
	int T=0;
	scanf("%d",&T);
	FOR(t,1,T){
		cin>>e>>r>>n;
               	FOR(i,0,n-1)
			cin>>v[i];
                max1=0;
                solve(0,e,0); 
		
		printf("Case #%d: %d\n",t,max1);
	}

	return 0;
}

