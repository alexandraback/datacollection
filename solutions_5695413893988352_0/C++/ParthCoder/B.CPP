#include<bits/stdc++.h>
#define mod 1000000007
#define SIZE 1000007
#define ll long long
#define INF INT_MAX
#define fr(i,a,b) for(i=a;i<=b;i++)
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
vs::iterator itr,itr1;

int val(string str){
    int n=str.length(),i;
    int ans=0;
    for(i=0;i<n;i++){
        ans = ans*10+((int)str[i]-48);
    }
    return ans;
}

int main() {
    freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
    //ios::sync_with_stdio(0);
    int tc,i,k,m,n,o,c_val,j_val,c_len,j_len;
    char ch,ch1,ch2;
    int diff,mn;
    cin>>tc;
    string c,j;
    for(int t=1;t<=tc;t++){
        cin>>c>>j;
        c_len = c.length();
        j_len = j.length();
        if(c.find("?")!=string::npos&&j.find("?")!=string::npos){
            vs c_all,j_all;

            //computing c_all
            int idx[3]; k =0;
            for(i=0;i<c_len;i++)
                if(c[i]=='?')
                    idx[k++] = i;
            string temp;
            if(c_len==1) temp=" ";
            else if(c_len==2) temp="  ";
            else temp="   ";
            for(n=0;n<c_len;n++)
                if(c[n]!='?')
                    temp[n]=c[n];
            if(k==1){
                for(ch='0';ch<='9';ch++){
                    temp[idx[0]] = ch;
                    c_all.push_back(temp);
                }
            }
            else if(k==2){
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    c_all.push_back(temp);
                }
            }
            else{
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++)
                for(ch2='0';ch2<='9';ch2++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    temp[idx[2]]=ch2;
                    c_all.push_back(temp);
                }
            }

            //computing j_all
            k =0;
            for(i=0;i<j_len;i++)
                if(j[i]=='?')
                    idx[k++] = i;
            if(j_len==1) temp=" ";
            else if(j_len==2) temp="  ";
            else temp="   ";
            for(n=0;n<j_len;n++)
                if(j[n]!='?')
                    temp[n]=j[n];
            if(k==1){
                for(ch='0';ch<='9';ch++){
                    temp[idx[0]] = ch;
                    j_all.push_back(temp);
                }
            }
            else if(k==2){
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    j_all.push_back(temp);
                }
            }
            else{
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++)
                for(ch2='0';ch2<='9';ch2++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    temp[idx[2]]=ch2;
                    j_all.push_back(temp);
                }
            }
            string ans_c,ans_j;
            mn = INF;
            for(itr=c_all.begin();itr!=c_all.end();itr++)
            for(itr1=j_all.begin();itr1!=j_all.end();itr1++){
                diff = abs(val(*itr)-val(*itr1));
                if(diff<mn){
                    ans_c = *itr;
                    ans_j = *itr1;
                    mn = diff;
                }
            }
            c = ans_c;
            j = ans_j;
        }
        else if(c.find("?")!=string::npos){// c has ?
            j_val = val(j);
            vs c_all;
            int idx[3]; k =0;
            for(i=0;i<c_len;i++)
                if(c[i]=='?')
                    idx[k++] = i;
            string temp;
            if(c_len==1) temp=" ";
            else if(c_len==2) temp="  ";
            else temp="   ";
            for(n=0;n<c_len;n++)
                if(c[n]!='?')
                    temp[n]=c[n];
            if(k==1){
                for(ch='0';ch<='9';ch++){
                    temp[idx[0]] = ch;
                    c_all.push_back(temp);
                }
            }
            else if(k==2){
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    c_all.push_back(temp);
                }
            }
            else{
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++)
                for(ch2='0';ch2<='9';ch2++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    temp[idx[2]]=ch2;
                    c_all.push_back(temp);
                }
            }
            string ans_c;
            mn = INF;
            for(itr=c_all.begin();itr!=c_all.end();itr++){
                diff = abs(val(*itr)-j_val);
                if(diff<mn){
                    ans_c = *itr;
                    mn = diff;
                }
            }
            c = ans_c;
        }
        else{
            c_val = val(c);
            vs j_all;
            int idx[3]; k =0;
            for(i=0;i<j_len;i++)
                if(j[i]=='?')
                    idx[k++] = i;
            string temp;
            if(j_len==1) temp=" ";
            else if(j_len==2) temp="  ";
            else temp="   ";
            for(n=0;n<j_len;n++)
                if(j[n]!='?')
                    temp[n]=j[n];
            if(k==1){
                for(ch='0';ch<='9';ch++){
                    temp[idx[0]] = ch;
                    j_all.push_back(temp);
                }
            }
            else if(k==2){
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    j_all.push_back(temp);
                }
            }
            else{
                for(ch='0';ch<='9';ch++)
                for(ch1='0';ch1<='9';ch1++)
                for(ch2='0';ch2<='9';ch2++){
                    temp[idx[0]]=ch;
                    temp[idx[1]]=ch1;
                    temp[idx[2]]=ch2;
                    j_all.push_back(temp);
                }
            }
            string ans_j;
            mn = INF;
            for(itr=j_all.begin();itr!=j_all.end();itr++){
                diff = abs(val(*itr)-c_val);
                if(diff<mn){
                    ans_j = *itr;
                    mn = diff;
                }
            }
            j = ans_j;
        }
		cout<<"Case #"<<t<<": "<<c<<" "<<j<<"\n";
	}
	return 0;
}

