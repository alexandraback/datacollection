#include <iostream>
#include <cstdio>
using namespace std;
int L,X,n,arr[10001];
string s;
int mat[4][4] {
    {1,2,3,4},
    {2,-1,4,-3},
    {3,-4,-1,2},
    {4,3,-2,-1}
};
int ABS(int x){
    return ( (x<0)? -x:x );
}
int val(char c){
    if(c=='i') return 2;
    if(c=='j') return 3;
    return 4;
}

int mult(int x,int y){
    int sign(1);
    if(x<0) sign *= -1;
    if(y<0) sign *= -1;
    x = ABS(x);
    y = ABS(y);
    return sign * mat[x-1][y-1];
}

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    int T,tc(1);
    cin >> T;
    while(T--){
        cin >> L >> X;
        cin >> s;
        string p = s;
        s = "";
        while(X--) s+=p;
        n = (int) s.size();
        arr[0] = val(s[0]);
        for(int i=1;i<n;i++){
            arr[i] = val(s[i]);
            arr[i] = mult(arr[i-1],arr[i]);
        }
        cout << "Case #" << tc++ << ": ";
        for(int i=0;i<n-2;i++){
            if(arr[i]==2){
                for(int j=i+1;j<n-1;j++){
                    if(mult(-arr[i],arr[j])==3){
                        if(mult(-arr[j],arr[n-1])==4){
                            cout << "YES" << endl;
                            goto here;
                        }
                    }
                }
            }
        }
        cout << "NO" << endl;
here:;
    }
    return 0;
}
