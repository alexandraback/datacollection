#include<iostream>
#include<algorithm>
#include<cstdio>

#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    CASET{
        long long int n,max1 = 0,count = 0;;
        cin>>n;
        if(n<=20)
			count = n;
		else{
			int i=0,n1=1;
			while(n1<=n){
				int rev=0;
				max1 = n1;
                while (n1 != 0){
					  rev = rev * 10;
					  rev = rev + n1%10;
					  n1 = n1/10;
                }
				n1 = max1;
				if(rev > max1)
					n1 = rev;
				else n1++;
				count++;
			}
		}
        cout<<"Case #"<<case_n<<": "<<count <<endl;
        case_n++;
    }
}
