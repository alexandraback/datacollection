#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;


void solve(long long n);
long long ans;

void getBase(long long x){
    solve(x-1);
    ans++;
}

long long getRev(long long n, int x){
    int y = (x+1)/2;
    long long wqe = (long long)(pow(10,y) + 0.4);
    long long yy = n%wqe;
    n/=wqe;
    int z = 0;
    while(n>0){
        z*=10;
        z+=(n%10);
        n/=10;
    }
if(z == 1)
	return z+yy-1;

    return z+yy;
}

void solve(long long n){
int x = floor(log10(n));
        x++;
		if(n<=20)
			ans = n;
		else{
            int cccc = x-1;
            long long zz = (long long)(pow(10,cccc) + 0.4);
            getBase(zz);
            if(n != zz){

                if(n%10 == 0){
                    n--;
					ans++;
				}
                long long awe = getRev(n,x);
                ans += awe;
            }
		}

}
int main(){



    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int TC;
    cin>>TC;
    for(int ZZ=1;ZZ<=TC;ZZ++){
        ans = 0;

        long long n;
        cin>>n;

        solve(n);
        cout<<"Case #"<<ZZ<<": "<<ans<<endl;
    }

    return 0;
}
