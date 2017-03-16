#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <queue>
using namespace std;
    bool open[201],open2[201];
    int seq[201],key[201],key2[201],opc[201],nche[201],che[201][401],keynow[201];
    int need[201];
    int n;
void initialise(int k){
     for (int i=0; i<n; ++i)
         open2[i]=open[i];
     open2[k]=true;
     memset(need,0,sizeof need);
     for (int i=0; i<=200; ++i)
        key2[i]=key[i];
     key2[opc[k]]--;
     for (int j=0; j<nche[k]; ++j)
         key2[che[k][j]]++;
     for (int i=0; i<n; ++i){
         if (!open2[i]){
              need[opc[i]]++;
         }
     }
}
bool allopen(){
     for (int i=0; i<n; ++i){
         if (!open2[i]){
            return false;
         }
     }
     return true;
}
void openit(int k){
     key2[opc[k]]--;
     need[opc[k]]=max(0,need[opc[k]]-1);
     for (int j=0; j<nche[k]; ++j)
         key2[che[k][j]]++;
     open2[k]=true;
     //cout<<"Open: "<<k<<endl;
}
bool canopen(int k){
     return key2[opc[k]] >0;
}
bool bigcanopen(int k){
     return key[opc[k]] >0;
}
void bigopenit(int k){
     key[opc[k]]--;
     for (int j=0; j<nche[k]; ++j)
         key[che[k][j]]++;
     open[k]=true;
}
bool checkflow(){
     bool ok=true;
     int i,j,k;
//     cout<<"KEY: ";
//               for (k=1; k<=13; ++k)
//               cout<<key2[k]<<" ";
//               cout<<endl;
//          cout<<"Need: ";
//               for (k=1; k<=13; ++k)
//               cout<<need[k]<<" ";
//               cout<<endl;
     while (!allopen()){
           bool reopen=true;
           while (reopen){
           for (i=0; i<=200; ++i){
               if (key2[i]>=need[i] && need[i]!=0){
                  need[i]=0;
               }
           } 
           reopen=false;
           for (i=0; i<n; ++i){
               if (!open2[i] && need[opc[i]]==0){
                  openit(i);
                  reopen=true;
               }
           }
           }//end of reopen
//                cout<<"KEY after reopen: ";
//               for (k=1; k<=13; ++k)
//               cout<<key2[k]<<" ";
//               cout<<endl;
//          cout<<"Need: ";
//               for (k=1; k<=13; ++k)
//               cout<<need[k]<<" ";
//               cout<<endl;
             //  cout<<allopen()<<endl;
           if (allopen())
              break;
           else{
                int toopen=-1;
                int max=0;
                int temp;
                for (i=0; i<n; ++i){
                    if (!open2[i] && canopen(i)){
                        temp=0;
                        for (j=0; j<nche[i]; ++j){
                            if (need[che[i][j]]>0)
                               temp++;
                        }
                        if (temp>max || toopen==-1){
                           toopen=i;
                           max=temp;
                        }
                    }
                }
                if (toopen==-1){
                   ok=false;
                   break;
                }
                else{
                     openit(toopen);
                }
           }
     }//end of while allopen
     return ok;
}
int main(){
    int t,z,i,j,k,a;
    cin>>t;
    for (z=1; z<=t; ++z){
        memset(open,false,sizeof open);
        memset(open2,false,sizeof open2);
        memset(seq,0,sizeof seq);
        memset(key,0,sizeof key);
        memset(key2,0,sizeof key2);
        memset(opc,0,sizeof opc);
        memset(che,0,sizeof che);
        cin>>k>>n;
        for (i=0; i<k; ++i){
            cin>>a;
            key[a]++;
        }
        for (i=0; i<n; ++i){
            cin>>opc[i];
            cin>>nche[i];
            for (j=0; j<nche[i]; ++j)
                cin>>che[i][j];
        }
        bool fail=false;
        for (i=0; i<n; ++i){
            bool ok=false;
            for (j=0; j<n; ++j){
                if (!open[j] && bigcanopen(j)){
                  // cout<<j<<endl;
                   initialise(j);
                   ok=checkflow();
                   if (!ok)
                      open2[j]=false;
                   else
                       break;
                }
            }
            if (ok){
               seq[i]=j;
               bigopenit(j);
              // cout<<i<<" open: "<<j<<endl;
            }
            else{
                 fail=true;
                 break;
            }
        }
        if (!fail){
                 cout<<"Case #"<<z<<":";
                 for (j=0; j<n; ++j)
                     cout<<" "<<seq[j]+1;
                 cout<<endl;        
        }
        else
        cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl; 
    }    
    return 0;
}
