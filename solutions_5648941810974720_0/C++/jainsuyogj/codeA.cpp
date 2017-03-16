#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define mat 1000006
vector<int> vc(26);
string arr[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string reso(char x,int r)
{
    string res="";
    int z=x-'A';
    int cnt=0;
    //cout<<" char x "<<z<<" "<<r<<" "<<vc[z]<<endl;
        for(int i=0;i<vc[z];i++){
            res=res+char('0'+r);
            cnt++;
        }
        //cout<<cnt<<endl;
        for(int i=0;i<cnt;i++){

            for(int j=0;j<arr[r].size();j++){

                    vc[arr[r][j]-'A']--;
                    //cout<<arr[r][j];
            }
        }
        return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        for(int i=0;i<26;i++)
            vc[i]=0;
        string s;
        cin>>s;
        int l=s.size();
        for(int i=0;i<l;i++){
            vc[s[i]-'A']++;
        }
        string res;
        res+=reso('Z',0);
        res+=reso('W',2);
        res+=reso('U',4);
        res+=reso('F',5);
        res+=reso('X',6);
        res+=reso('S',7);
        res+=reso('G',8);
        res+=reso('I',9);
        res+=reso('T',3);
        res+=reso('O',1);
        sort(res.begin(),res.end());
        cout<<"Case #"<<ii<<": "<<res<<endl;
    }
}
