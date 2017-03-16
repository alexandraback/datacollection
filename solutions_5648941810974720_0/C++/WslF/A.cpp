//solution by Wsl_F
#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

int frequence[26];
int digits[10];
string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void update(int digit, char letter)
{
    digits[digit]= frequence[letter-'A'];
    for (char c : words[digit])
    {
        frequence[c-'A']-= digits[digit];
    }
}

void solve()
{
    string s;
    cin>>s;
    memset(frequence,0,sizeof(frequence));
    memset(digits,0,sizeof(digits));

    for (int i= s.length()-1; i>=0; i--)
        frequence[s[i]-'A']++;


    update(0,'Z');
    update(8,'G');
    update(2,'W');
    update(6,'X');

    update(7,'S');
    update(5,'V');
    update(4,'F');
    update(1,'O');
    update(3,'R');
    update(9,'I');


    for (int i= 0; i<10; i++)
        for (int j= 0; j<digits[i]; j++)
            cout<<i;
    cout<<endl;

}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 srand(__rdtsc());
 // LL a[110];
 // memset(a,0,sizeof(a));

 freopen("A-small-attempt0.in","r",stdin);
 freopen("output_A_small.txt","w",stdout);
 //cout<<fixed;
 //cout<<setprecision(9);

 int T;
 cin>>T;
 for (int testCase= 1; testCase <= T; testCase++)
 {
     cout<<"Case #"<<testCase<<": ";
     solve();
 }


 return 0;
}
