#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define mp make_pair
#define long long long
using namespace std;
ifstream cin("input.in");
ofstream cout("output.txt");



long t,n,a[1234567];
string s;

bool sogl(char c){
if (c=='a' || c=='o' || c=='e' || c=='i' || c=='u' ){
return 0;
cout<<"FF";
}
return 1;
}

int main()
{
cin>>t;
for (long i=1;i<=t;i++){

vector<long> bs;
vector<long> bl;

cin>>s>>n;
long l=s.length();

long j=0;
long tek=0;
long tb=0;

while (j<l){
if (tek==n){
    while (j<l && sogl(s[j]))   j++,tek++;
bs.push_back(tb);
bl.push_back(tek);
tek=0;
tb=j;
}
else{
    if (sogl(s[j])){
        tek++;
    }
    else{
        tb=j+1;
        tek=0;
    }
j++;
}
}
if (tek==n){
bs.push_back(tb);
bl.push_back(tek);
}
/*for (long y=0;y<bs.size();y++)
cout<<bs[y]<<" ";
*/long ans=0;
if (bs.size()>=1){
long lb=bs[bs.size()-1];

for (long j=0;j<l;j++){
    if (!sogl(s[j])){
        if (lb>j)
            ans=ans-*upper_bound(bs.begin(),bs.end(),j)-n+l+1;
    }
    else{
        if (j>=lb){
            if (bl[bl.size()-1]+bs[bs.size()-1]>=j+n)
                ans=ans+l-j-n+1;
        }
        if (j<lb && j>=bs[0]){
            long q=upper_bound(bs.begin(),bs.end(),j)-bs.begin();
            q--;
            if(bs[q]+bl[q]>=j+n){
                ans=ans+l-j-n+1;
            }
            else{
            q++;
            //j=bs[j];
            ans=ans-bs[q]-n+l+1;
            }

        }
        if (j<bs[0]){
        ans=ans-*upper_bound(bs.begin(),bs.end(),j)-n+l+1;
        }
    }
}

cout<<"Case #"<<i<<": "<<ans<<endl;
}
else
cout<<"Case #"<<i<<": "<<0<<endl;
}

    return 0;
}
