#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std ;

bool BFS(int ind,vector< vector<int> > &vv,int &n)
{
     bool visited[n] ;
     for(int i=0;i < n;i++)
             visited[i] = false ;
     visited[ind] = true ;
     queue<int> Q ;
     Q.push(ind) ;
     while(!Q.empty()) {
                       int temp  = Q.front() ;
                       Q.pop() ;
                       for(int i=0;i < vv[temp].size();i++){
                               if(visited[vv[temp][i]])
                                                      return true ;
                               else{
                                    visited[vv[temp][i]] = true ;
                                    Q.push(vv[temp][i]) ;
                               }
                       }
     }
     return false ;
}

/*bool F = false ;

void DFS(int ind,vector< vector<int> > &vv,int &n,bool visited[])
{
     if(F)
          return ;
     visited[ind] = true ;
     for(int i=0;i < vv[ind].size();i++){
             if(visited[vv[ind][i]]){
                  F = true ;
                  return ;
             }else{
                  visited[vv[ind][i]] = true ;
                  DFS(vv[ind][i],vv,n,visited)  ;
             }
     }
}*/
     
int main()
{
    int t ;
    scanf("%d",&t) ;
    int ctr = 1 ;
    while(t--) {
               int n ;
               scanf("%d",&n) ;
               vector< vector<int> > vv ;
               bool T[n] ;
               for(int i=0;i < n;i++)
                       T[i] = false ;
               for(int i=0;i < n;i++){
                       int m ;
                       scanf("%d",&m) ;
                       vector<int> v ;
                       while(m--) {
                                  int x ;
                                  scanf("%d",&x) ;
                                  T[x-1] = true ; 
                                  v.push_back(x-1) ;
                       }
                       vv.push_back(v) ;
               }
               bool visited[n] ;
               for(int i=0;i < n;i++)
                       visited[i] = false ;
               vector<int> start ;
               for(int i=0;i < n;i++)
                       if(!T[i])
                                start.push_back(i) ;
               bool flag = false ;
               for(int i=0;i < start.size();i++)
                       if(BFS(start[i],vv,n)){
                             flag = true ;
                             break ;
                       }
               if(flag)
                       cout << "Case #" << ctr++ << ": " << "Yes\n" ;
               else
                   cout << "Case #" << ctr++ << ": " << "No\n" ;
    }
    //system("pause") ;
    return 0 ;
}
