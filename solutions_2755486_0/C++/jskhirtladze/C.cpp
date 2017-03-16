#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

int need[801],answer;
struct attack{
 int d,l,r,s;
 attack(int d,int l,int r,int s): d(d), l(l), r(r), s(s) {}
};
bool operator < (attack A,attack B) { return A.d<B.d; };
vector <attack> history;

void read_data(){
 int cnt,d,n,w,e,s,dd,dp,ds,i;
 history.clear();
 cin>>cnt;
 while ( cnt-- )
  {
   cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
   for ( i=1;i<=n;i++ )
    {
     history.push_back(attack(d,w+400,e-1+400,s));
     d+=dd;
     w+=dp;
     e+=dp;
     s+=ds;
    }
  }
 sort(history.begin(),history.end());
 for ( i=0;i<=800;i++ )
  need[i]=0;

//////////////
// cout<<endl;
// for ( i=0;i<history.size();i++ )
//  cout<<history[i].d<<" "<<history[i].l<<" "<<history[i].r<<" "<<history[i].s<<endl;
// cout<<endl;
// system("pause");
///////////////////

}

void work()
{
 answer=0;
 int i,k,j,l;
 for ( i=0;i<history.size(); )
  {
  // cout<<answer<<endl;
  // cout<<"i= "<<i<<endl;

   j=i;
   while ( j<history.size() && history[j].d==history[i].d )
    j++;

 //  for ( k=0;k<=10;k++ ) cout<<need[k]<<" "; cout<<endl;
 //  cout<<"to see "<<history[i].l<<" "<<history[i].r<<endl;

   for ( k=i;k<j;k++ )
    for ( l=history[k].l;l<=history[k].r;l++ )
     if ( history[k].s > need[l] )
      {
       answer++;
       break;
      }

   for ( k=i;k<j;k++ )
    for ( l=history[k].l;l<=history[k].r;l++ )
     need[l]=max(need[l],history[k].s);

   i=j;
  }
}

main()
{
 int t,l;
 cin>>t;
 for ( l=1;l<=t;l++ )
  {
   read_data();
   work();
   printf("Case #%d: %d\n",l,answer);
  }
}
