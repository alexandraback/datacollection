#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#define MM 105
#define LL long long
using namespace std;
 
int test,num,ptr;
LL tmp[2][MM],arr2[2][MM],arr3[MM][MM],ext1;

 
inline void reverse(int i,int j,LL nxt) {
    ext1=max(ext1,nxt);
    if(nxt<arr3[i][j]) return;
    arr3[i][j]=nxt;
    
    if(i>num || j>ptr) return;
    if(tmp[0][i]==tmp[1][j]) {
        LL cc=min(arr2[0][i],arr2[1][j]);
        if(arr2[0][i]<arr2[1][j]) {
            arr2[1][j]-=cc;
            reverse(i+1,j,nxt+cc);
            arr2[1][j]+=cc;
        }
        else if(arr2[0][i]==arr2[1][j]) reverse(i+1,j+1,nxt+cc);
        else {
            arr2[0][i]-=cc;
            reverse(i,j+1,nxt+cc);
            arr2[0][i]+=cc;
        }
    }
    reverse(i+1,j,nxt);
    reverse(i,j+1,nxt);
}
 
int main()
{
    ifstream f("input");
    ofstream g("output");
	//test cases
    cin>>test;
    for(int k=1; k<=test; ++k) {
        cin>>num>>ptr;
        memset(arr3,0,sizeof(arr3));
      
        
        memset(arr3,0,sizeof(arr3));
        for(int i=1; i<=num; ++i) cin>>arr2[0][i]>>tmp[0][i];
        for(int i=1; i<=ptr; ++i) cin>>arr2[1][i]>>tmp[1][i];
        ext1=0;
        reverse(1,1,0);
       
        cout<<"Case #"<<k<<": "<<ext1<<'\n';
        char c;
        
    }
    return 0;
}
 