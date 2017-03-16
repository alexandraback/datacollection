#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    int t;
    scanf("%d",&t);
    int k=0;
    while(t--){
        k++;
        int A,N;
        scanf("%d %d",&A,&N);
        int vals[N];
        for(int i=0;i<N;i++)
            scanf("%d",&vals[i]);
        sort(vals,vals+N);
        int currentsize=A;
        vector<int> possible;
        int added=0;
        int i;
        int p=0;
        for(i=0; i<N && i>=0 ;i++){
            if(vals[i]<currentsize){
                currentsize+=vals[i];
                p=0;
                //cout<<i<<endl;
            }
            else{
                //cout<<i<<endl;
                currentsize=2*currentsize-1;
                possible.push_back(N-i+added);
                added+=1;
                i--;
                p++;
            }
            if(p>N)
                break;
        }
        if(p<N)
        possible.push_back(added);
        else
        possible.push_back(N);
        sort(possible.begin(),possible.end());
        printf("Case #%d: %d\n",k,possible[0]);
    }
}
