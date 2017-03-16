#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std ;

unsigned long long Recurse(int ind,int ind1,unsigned long long A[],int Atype[],unsigned long long B[],int Btype[],int &n,int &m)
{
    if(ind >= n || ind1 >= m)
         return 0 ;
    if(Atype[ind] == Btype[ind1]){
                  if(A[ind] > B[ind1]){
                            unsigned long long m1 = Recurse(ind+1,ind1,A,Atype,B,Btype,n,m) ;
                            A[ind] = A[ind]-B[ind1] ;
                            unsigned long long m2 = B[ind1]+Recurse(ind,ind1+1,A,Atype,B,Btype,n,m) ;
                            A[ind] = A[ind]+B[ind1] ;
                            return max(m1,m2) ;
                  }else{
                        unsigned long long m1 = Recurse(ind,ind1+1,A,Atype,B,Btype,n,m) ;
                        B[ind1] = B[ind1]-A[ind] ;
                        unsigned long long m2 = A[ind]+Recurse(ind+1,ind1,A,Atype,B,Btype,n,m) ;
                        B[ind1] = B[ind1]+A[ind] ;
                        return max(m1,m2) ;
                  }
    }
    return max(Recurse(ind+1,ind1,A,Atype,B,Btype,n,m),Recurse(ind,ind1+1,A,Atype,B,Btype,n,m)) ;
}
    
int main()
{
    int t ;
    scanf("%d",&t) ;
    int ctr = 1 ;
    while(t--){
               int n,m ;
               cin >> n >> m ;
               unsigned long long A[n] ;
               int Atype[n] ;
               for(int i=0;i < n;i++){
                       cin >> A[i] ;
                       cin >> Atype[i] ;
               }
               unsigned long long B[m] ;
               int Btype[m] ;
               for(int i=0;i < m;i++){
                       cin >> B[i] ;
                       cin >> Btype[i] ;
               }
               unsigned long long ans = Recurse(0,0,A,Atype,B,Btype,n,m) ;
               cout << "Case #" << ctr++ << ": " << ans << endl ;
    }
    //system("pause") ;
    return 0 ;
}
