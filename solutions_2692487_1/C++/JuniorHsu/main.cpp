#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<functional>
#include<time.h>
#include<iomanip>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

ll diff(ll a,ll b)
{
    return a>b ? a-b : b-a;
}

/*#define COMB_NUM 10001L
ll comb[COMB_NUM][COMB_NUM];
//need init_comb();
void init_comb()
{
    comb[0][0]=1;
    ll i,j;
    for(i=1;i<COMB_NUM;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(j=1;j<i;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}
*/

#define print(a)      for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define print2n(a,n)      for(int i=0;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

void llFromString(const string &s,ll &a,ll &b)
{
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
               
    istringstream buffer(replacedString);
    buffer>>a;
    if(buffer.good())
    {
        buffer>>b;
    }
    else
    {
        b=0;
    }
}


template<class T>
vector<T> split(const std::string &s) {
    
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
    
    vector<T> ret;
    istringstream buffer(replacedString);
    copy(istream_iterator<T>(buffer),
         istream_iterator<T>(), back_inserter(ret));
    return ret;    
}// vector<ll> k = split<ll>(s);

int main()
{
	fstream in,out;
	//in.open("test.in.txt",ios::in); out.open("test.out.txt",ios::out);
	//in.open("A-small-attempt1.in",ios::in); out.open("A-small-0.out",ios::out);
	  in.open("A-large.in",ios::in); out.open("A-large-0.out",ios::out);

	istream& input = in;
	ostream& output = out;

	ll case_id,total_case,temp,ans;

	input>>total_case; 
	ll I,H,K,L,N,a,n;
	ll m[101];
	for(case_id=1;case_id<=total_case;case_id++)
	{
        input>>a>>n;
        for(I=0;I<n;I++) input>>m[I];
        
        if(a==1)
        {
            ans = n;
            goto PRINT;
        }
        
        ans = INF;
        temp = 0;
        sort(m,m+n);
        
        for(I=0;I<n;I++)
        {
            //cout<<I<<" "<<m[I]<<endl;
            if(a>m[I])
            {
                a+=m[I];
                continue;
            }
            else
            {
                ans = min(ans, temp+n-I);
                //cout<<ans<<endl;
                while(a<=m[I])
                {
                    a=2*a-1;
                    temp++;
                }
                a+=m[I];
            }
        }
        
        ans = min(ans,temp);
        //cout<<ans<<endl;

PRINT:
        
		output<<"Case #"<<case_id<<": ";
		output<<ans;
		output<<endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}










