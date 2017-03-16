#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;

#define For(Q,W) for(int Q=0;Q<W;Q++)
#define LLD long long
#define mkp make_pair
#define pf printf
#define sf scanf

#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif

int t;

int main(){
    scanf("%d ",&t);
    
    For(j,t){
             int moja;
             int n;         
             scanf("%d %d ",&moja,&n);
             //db(n);
             //db(moja);
             vector<int>ake(n);
             For(i,n) scanf("%d ",&ake[i]);
             sort(ake.begin(),ake.end());
             
             if(moja!=1){
                 vector<int> moznosti;
                 int kolko=0;
                 
                 For(i,n){
                          if(ake[i]<moja) moja+=ake[i];
                          else{
                               moznosti.push_back(kolko+n-i);
                               while(ake[i]>=moja){
                                                             kolko++;
                                                             moja= 2*moja-1;
                                                   }
                               moja+=ake[i];
                          }         
                 }
                 moznosti.push_back(kolko);
                 sort(moznosti.begin(), moznosti.end());
                 
                 
                 printf("Case #%d: %d\n",j+1,moznosti[0]);
                 }
             else printf("Case #%d: %d\n",j+1,n);
             }
    return 0;   
}
