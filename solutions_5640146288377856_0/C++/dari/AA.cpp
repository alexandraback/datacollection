#include<iostream>

using namespace std;
int main(){
    int x, a1, a2, a3,i;
    cin >> x;
    for (i=1; i<=x; i++){
	    int res = 0;
	    cin>>a1>>a2>>a3;
	    res = a2 / a3 *a1;
	    res += a3 - 1;
	    if (a2%a3 != 0)
		    res++;
		    cout<<"Case #"<<i<<": "<<res<<endl;
    }
     
return 0;
}