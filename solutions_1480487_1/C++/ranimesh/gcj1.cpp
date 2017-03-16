#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,c=1;
    cin >> T;
    while(T--){
        long long int n,i,j=0;
        double a[400],s=0,y,y2,m=0.0;
        cin >> n;
        for(i=0;i<n;i++){
            cin >> a[i];
            s+=a[i];
            if(a[i] > m) m = a[i];
        }
        double x = 2.0,y3;
        y = (x * s)/(double)(n);
        y3 = (x * s);
        for(i=0;i<n;i++){
            if(y < a[i]) { y3-=a[i]; j++; }
        }
        y3 = y3/(double)(n-j);
        cout << "Case #"<<c<<": ";
        c++;
        for(i=0;i<n;i++){
            if(y >= a[i])
                cout << ((y3 - a[i])/s)*100.0 <<" ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
