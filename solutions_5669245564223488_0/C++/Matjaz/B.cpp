#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

long long mod=1000000007;

int n,T;

long long fact[105];

int left_edge[26];
int right_edge[26];
int fullstring[26];
int inside[26];
bool b=true;

int d[26];
vector<int> s[26];

void compute_stuff(string c){
     //printf("%s\n",c.c_str());
     int prev[26];
     memset(prev,-1,sizeof prev);
     for (int i=0;i<c.size();i++){
             if (prev[c[i]-'a']!=-1&&prev[c[i]-'a']!=i-1) b=false;
             prev[c[i]-'a']=i;
             }
     int l=0;
     for (int i=1;i<c.size();i++){
         if (c[i]!=c[i-1]){
            //printf("%c\n",c[i-1]);
            if (l==0) left_edge[c[i-1]-'a']++; else inside[c[i-1]-'a']++; 
            l=i;              
            }
         }
     if (l==0){
        fullstring[c[c.size()-1]-'a']++;       
        } else right_edge[c[c.size()-1]-'a']++; 
     
     if (c[0]!=c[c.size()-1]){
        d[c[c.size()-1]-'a']++;
        s[c[0]-'a'].push_back(c[c.size()-1]-'a');                     
        }      
     }
     
     
bool no_topological(){
     queue<int> Q;
     int in_line=0;
     for (int i=0;i<26;i++) if (d[i]==0) Q.push(i);
     while (!Q.empty()){
           int x=Q.front();
           Q.pop();
           in_line++;
           for (int i=0;i<s[x].size();i++){
               d[s[x][i]]--;
               if (d[s[x][i]]==0) Q.push(s[x][i]);
               }
           }    
     if (in_line<26) return true;
     return false;
     }

long long solve(){
     b=true;
     memset(d,0,sizeof d);
     for (int i=0;i<26;i++) s[i].clear();
     memset(left_edge,0,sizeof left_edge);
     memset(right_edge,0,sizeof right_edge);
     memset(fullstring,0,sizeof fullstring);
     memset(inside,0,sizeof inside);
     
     scanf("%d",&n);
     char buffer[105];
     for (int i=0;i<n;i++){
         scanf("%s",buffer);
         string cart=buffer;
         compute_stuff(cart);
         }
     for (int i=0;i<26;i++){
         if (!b) return 0;
         if (right_edge[i]>1) return 0;
         if (left_edge[i]>1) return 0;
         if (inside[i]>1) return 0;
         if (inside[i]==1&&left_edge[i]+right_edge[i]+fullstring[i]!=0) return 0;
         }    
     if (no_topological()) return 0;    
     long long res=1;
     for (int i=0;i<26;i++) res=(res*fact[fullstring[i]])%mod;
     int stevilo_kosov=n;
     for (int i=0;i<26;i++){
         if (fullstring[i]==0) continue;
         stevilo_kosov=stevilo_kosov-fullstring[i]+1;
         }  
     //printf("%d\n",stevilo_kosov);      
     for (int i=0;i<26;i++){
         int st=0;
         if (left_edge[i]==1) st++;
         if (right_edge[i]==1) st++;
         if (fullstring[i]>0) st++;
         //printf("%d\n",st);
         if (st==0) continue;
         stevilo_kosov=stevilo_kosov-st+1;
         }
     //printf("%d %d %d\n",left_edge[7],right_edge[7],fullstring[7]);    
     //printf("%d\n",stevilo_kosov); 
     //printf("%d\n",'i'-'a');      
     res=(res*fact[stevilo_kosov])%mod;
     return res;
     }


int main(){
    fact[0]=1;
    for (int i=1;i<=100;i++) fact[i]=(fact[i-1]*i)%mod;
    scanf("%d",&T);
    for (int t=1;t<=T;t++){
        printf("Case #%d: %I64d\n",t,solve());
        }
    return 0;
    }
