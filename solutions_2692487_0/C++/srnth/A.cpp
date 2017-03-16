#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(int a, int *s, int n){
    if(n==0){
        return 0;
    } else {
        if(a>s[0])
            return solve(a+s[0],s+1,n-1);
        else {
            if(a==1)
                return 1+solve(a,s+1,n-1);
            else
                return min(1+solve(2*a-1,s,n),1+solve(a,s+1,n-1));
        }
    }
}

#define MAXN 1000
int T,A,N;
int m[MAXN];

int main(){
    cin >> T;
    for(int t=0;t<T;t++){
        cout << "Case #" << t+1 <<": ";
        cin >> A >> N;
        for(int i=0;i<N;i++)
            cin >> m[i];
        
        sort(m,m+N);
        
        cout << solve(A,m,N) << "\n";
    }
    
    return 0;
}

