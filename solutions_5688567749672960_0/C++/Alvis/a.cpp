//Template

// By Anurag :P
//Includes
#include <bits/stdc++.h>

using namespace std;

//Shortforms
typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vl;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(s,n); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
//int cou[1000005];

int* cou = new int[1000003];

ll reverseit(ll num){
   ll reverse =0;
   for( ; num!= 0 ; )
   {
      reverse = reverse * 10;
      reverse = reverse + num%10;
      num = num/10;
   }
   
   return reverse;

}
int  numDigits(ll number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

ll count(ll number){
	if(cou[number] != -1) return cou[number];
   if(number <20){cou[number] = number; return number;}
   //cout<<"wtf number"<<number<<endl;
   ll reverse = reverseit(number);
   if (reverseit(number) < number) 
   {
	   //cout<< "number is "<<number<<" "<<count(reverseit(number))+1 << " and "<<count(number-1)+1<<endl;
	   if(numDigits(reverse) == numDigits(number)){
		   cou[number] = min(  count(reverseit(number))+1,count(number-1)+1); return min(  count(reverseit(number))+1,count(number-1)+1);
	   }
	   else { cou[number] = count(number-1) +1;return count(number-1) +1;}
   }
   else{ cou[number] = count(number-1) +1; return (count(number-1)+1);}
}
   
	




int main()
{
	for(int i=0;i<1000003;i++) cou[i]=-1;
	int t;
	cin>>t;
	int number;
	for(int i=1;i<1000003;i++) cou[i] = count(i); 
	for(int i=1;i<=t;i++){
		cin>>number;
		cout<<"Case #"<<i<<": "<<count(number)<<endl;
	}
	
	
	
	return 0;
}
