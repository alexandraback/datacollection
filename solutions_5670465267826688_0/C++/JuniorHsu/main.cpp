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

struct Q {
    Q(char _c = '1', int _s = 1)
        :c(_c), s(_s) {
    }
    int s;
    char c;
    Q& operator *= (const Q& rhs) {
        s *= rhs.s;
        if(c=='1') c=rhs.c;
        else if(rhs.c=='1') {}
        else if(c == rhs.c) {
            c = '1';
            s *= -1;
        } else {
            if( c==rhs.c+1 || (c=='i'&&rhs.c=='k') ) s*=-1;
            c = 'i' + 'j' + 'k' - c - rhs.c;
        }
        return *this;
    }
    
    /*Q& operator /= (const Q& rhs) {
        *this *= rhs;
        *this *= rhs;
        *this *= rhs;
        return *this;
    }*/
};

Q operator*(Q lhs, const Q& rhs) {
    return lhs *= rhs;
}
/*
Q operator/(Q lhs, const Q& rhs) {
    return lhs /= rhs;
}*/


std::ostream& operator<<(std::ostream& out, const Q& q){
   return out << q.s << "*" << q.c <<" ";
}

int main()
{
	fstream in,out;
	//in.open("test.in.txt",ios::in); out.open("test.out.txt",ios::out);
	in.open("C-small-attempt1.in",ios::in); out.open("C-small-0.out",ios::out);
	//in.open("C-large.in",ios::in); out.open("C-large-0.out",ios::out);

	istream& input = in;
	ostream& output = out;

	ll case_id,total_case,temp, max;
    
	input>>total_case; 
	ll I,H,K,L,X, e1, e2;
	string s, ans;
	Q f1, f2, f3;
	for(case_id=1;case_id<=total_case;case_id++)
	{
        input>>L>>X>>s;
        //if (X > 20) X=20;
        ans = "NO";
        if(L*X<3) goto ANS;
        f1 = Q('1');
        for(e1=1;e1<L*X;e1++) {
            f1 *= Q(s[(e1-1)%L]);
            if(f1.c != 'i' || f1.s != 1) continue;
            f2 = Q('1');
            f3 = Q('1');
            for(I=e1;I<L*X;++I) f3 *= Q(s[I%L]);

            for(e2=e1+1;e2<=L*X;e2++) {
                f2 *= Q(s[(e2-1)%L]);
                f3 = Q(s[(e2-1)%L]) *  Q(s[(e2-1)%L]) *  Q(s[(e2-1)%L]) * f3;
                //cout<<e1<<" "<<e2<<endl;
                //cout<< f1<<f2<<f3<<endl;
                if(f2.c == 'j' && f2.s == 1 
                && f3.c == 'k' && f3.s == 1)
                {
                    ans = "YES"; goto ANS;
                }
            }
        }
        
ANS:        
		output<<"Case #"<<case_id<<": ";
		output<<ans;
		output<<endl;
	}
    //system("PAUSE");
    return EXIT_SUCCESS;
}











