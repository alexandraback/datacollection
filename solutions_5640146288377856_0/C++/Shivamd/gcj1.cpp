#include<bits/stdc++.h>
using namespace std;

int main()
{

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);


long long   n, t  , r , w , c ;

long long  test = 1 , ans ;

cin >> t ;
while(test<=t)
{

cin >> r >> c >>w   ;
if(w==1||w==c) ans = c ;

else {

	if(c%w==0)  ans = 0 ;
	else ans = 1 ;
	ans += c/w + w - 1 ;

}

ans = ans + c/w*(r-1) ;
cout<<"Case #"<<test<<": "<<ans<<endl;
test++;
}


return 0 ;


}
