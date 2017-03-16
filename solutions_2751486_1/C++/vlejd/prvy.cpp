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

//#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif

void solve(int kolko){
     string meno;
     cin>>meno;
     int n;
     cin>>n;
     vector<int> cisla(1,0);
     bool samohlaska=true;
     For(i,meno.size()){
                        
                        if(meno[i]=='a' || (meno[i]=='e' || (meno[i]=='i' || (meno[i]=='o' || meno[i]=='u')))){
                                        if(!samohlaska){
                                                        cisla.push_back(-1);
                                                        samohlaska=true;
                                                        }
                                        else cisla[cisla.size()-1]--;
                        
                        }       
                        
                        else {
                             if(samohlaska){
                                            cisla.push_back(1);
                                            samohlaska=false;
                             }     
                             else cisla[cisla.size()-1]++;
                             
                        }
                        
     }
     /*
     For(i,cisla.size()) cout<<cisla[i]<<" ";
     cout<<endl;
     */
     vector<int> skupin(4,0);
     
     For(i,cisla.size()){
                         if(cisla[i]>=n) skupin.push_back(cisla[i]);
                         else{
                              if(skupin.back()<=0) skupin[skupin.size()-1]-=abs(cisla[i]);
                              else skupin.push_back(0-abs(cisla[i]));
                              
                         }                  
     }
     skupin.push_back(0);
     skupin.push_back(0);
     skupin.push_back(0);
     /*
     For(i,skupin.size()) cout<<skupin[i]<<" ";
     cout<<endl;
    */
     LLD vys=0;
     int pred=0;
     For(i,skupin.size()-2){
         if(skupin[i]>=n){
                          LLD komb=(long long) skupin[i]-n+1;
                          LLD najprv=(long long) pred;
                          vys+=komb*najprv;
                          LLD potom=abs(skupin[i+1])+min(n-1,skupin[i+2]);
                          vys+=potom*komb;
                          vys+=potom*najprv;
                          vys+=komb*(komb+1)/2;
                       
                          db(vys);
                          db(najprv);
                          db(potom);
                          db(komb);
                          db(i);
                          dbn();            
         }
         pred+=abs(skupin[i]);         
     }
     cout<<"Case #"<<kolko<<": ";
     cout<<vys;
     cout<<endl;
}

int T;

int main(){
    cin>>T;
    For(t,T){
         solve(t+1);    
    }
    return 0;   
}
