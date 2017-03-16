#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{

freopen("in.txt","r",stdin); 
freopen("out.txt","w",stdout);


ll  i , j , k , l  , n;

int t  , r , w , c ;
cin >> t ;
int tt = 0 ;int ans ;
while(t--)
{
tt++;

cin >> r >> c >>w      ; 





if(c==w||w==1) ans = c ;

else {
	
	if(c%w==0)  ans = 0 ;
	else ans = 1 ;
	ans += c/w + w - 1 ;
	
}

ans = ans + c/w*(r-1) ;

cout<<"Case #"<<tt<<": "<<ans<<endl;

}


return 0 ;


}

