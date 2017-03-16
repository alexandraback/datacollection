#include<fstream>
#include<string>
#include<iostream>
#include<vector>

using namespace std;
#define MOD 1000000007
typedef long long ll;
ll cnt[26][4] = {0}; //s,e,all,mid;

ll fact(ll a){
    ll ans = 1;
    while(a>0){
        ans = ans * a;
        ans = ans % MOD;
        a--;
    }
    return ans;

}
int main(){
    ifstream fin("B.in");
    ofstream fout("B.out");

    int T;
    fin>>T;
    for(int t=1; t<=T; t++){
        for(int i=0;i<26;i++){
            for(int j=0;j<4;j++)cnt[i][j] = 0;
        }
        int n;
        fin>>n;
        vector<string> v;
        fout<<"Case #"<<t<<": ";
        //-------------compression---------------
        while(n--){
            string s;
            fin>>s;

            string s2 = "";
            int l = s.size();
            char x = ' ';
            for(int i=0; i<l; i++){
                if(s[i]!=x){
                    x = s[i];
                    s2.push_back(x);
                }
            }
            cout<<s2<<endl;
            v.push_back(s2);



        }
        n = v.size();
        //--------------------end----------------

        for(int i=0; i<n; i++){
            string str = v[i];

            if(str.size()==1){
               char s = str[0];
               cnt[s-'a'][2]++;
            }
            if(str.size()==2){
                char s = str[0];
                char e = str[1];
                cnt[s-'a'][0]++;
                cnt[e-'a'][1]++;
            }
            if(str.size() > 2){
                int l = str.size();
                for(int i=1; i<l-1; i++){
                    char m = str[i];
                    cnt[m-'a'][3]++;
                }
                char s = str[0];
                char e = str[l-1];
                cnt[s-'a'][0]++;
                cnt[e-'a'][1]++;
            }


        }
        ll ans = 1;
        ll blk = 0;
        cout<<endl;
        cout<<t<<endl;

        for(int i=0; i<26; i++){


            if(cnt[i][3]>0){
                cout<<(char)('a'+i)<<endl;
                if(cnt[i][0] + cnt[i][1] + cnt[i][2] > 0){
                    ans = 0;
                    cout<<char(i+'a')<<" is invalid1"<<endl;
                    break;
                }
                if(cnt[i][3]> 1){
                    ans = 0;
                    cout<<char(i+'a')<<" is invalid2"<<endl;
                    break;
                }
                continue;

            }

            if(cnt[i][0]>1){
                ans = 0;
                cout<<char(i+'a')<<" is invalid3"<<endl;
                break;
            }
            if(cnt[i][1]>1){
                ans = 0;
                cout<<char(i+'a')<<" is invalid4"<<endl;
                break;
            }
            if(cnt[i][0]+cnt[i][1]+cnt[i][2]+cnt[i][3]==0)continue;
            //cout<<(char)('a'+i)<<" is valid "<<endl;
            //It can be a valid letter now.
            ans = ans * fact(cnt[i][2]);
            ans = ans % MOD;
            if(cnt[i][0]==0 && cnt[i][1] == 0){
                //cout<<" and makes a new block"<<endl;
                blk++;
                continue;
            }
            if(cnt[i][0]==1 && cnt[i][1]==0 ){
                //cout<<" and makes a new block"<<endl;;
                blk++;
                continue;

            }


        }
        cout<<blk<<endl;
        ans = ans * fact(blk);
        ans = ans % MOD;
        fout<<ans<<endl;
        cout<<ans<<endl;
    }
}
