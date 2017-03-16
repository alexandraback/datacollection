#include<iostream>
#include<vector>
#include<string>
#define ll long long
#define md 1000000007

using namespace std;
	long long  l;
    
	int T, N;
ll fac(int n){
    ll res=1;
    while(n>1){res = (res*n)%md; n--; }
    return res;
}
bool allc(string s){
    if(s.length()<=1)return true;
    for(int i=1; i<s.length(); i++){
	if(s[i]!=s[0])return false;
    }
    return true;
}
void count(vector<string> & st, char c, int & beg, int & med, int & en){
    beg = med=en=0;
    for(int i=0; i<N; i++){

	if(st[i]=="")continue;		
	int len = st[i].length();
	if(st[i][0]==c)beg++;
	if(st[i][len-1]==c)en++;
	for(int j=1; j<len-1; j++ ){
	    if(st[i][j]==c && st[i][j-1]!=c){
		med++;
	    }
	}
    }
}
void trim(string & s){
    int len = s.length();
    if(len==1)return;
    int c=len-2;
    while(s[c]==s[len-1])c--;
    s = s.substr(0, c+2);
    
}
bool connect(vector<string> & st, char c){
    int i1=0; int i2=0;
    for(int i=0; i<N; i++){
	if(st[i]=="")continue;		
	int len = st[i].length();
	if(st[i][0]==c){i1=i;}	
	if(st[i][len-1]==c){i2=i;}	
    }
    if(i1==i2) return false;
    st[i1] = st[i2]+st[i1]; st[i2]="";
    return true;
}
int main(){

	cin>>T; 
	l=1;
	for(int j=0; j<T; j++){
		cin>>N;
		vector<string> st(0); string s;
		for(int i=0; i<N; i++){cin>>s; st.push_back(s);}
		vector<int> num_allc(26, 0);
		bool good =true;
		string tot = "";
		ll res=1;
		for(int i=0; i<N; i++){
		    if(allc(st[i])){num_allc[st[i][0]-'a']++;st[i]="";}
		    trim(st[i]);
		}
		for(int i=0; i<26; i++){
		    res=(res*fac(num_allc[i]))%md;
		}
		for(int i=0; i<26; i++){
		    int n_beg=0;
		    int n_end=0;
		    int n_mid=0;
		    count(st, 'a'+i, n_beg, n_mid, n_end);
		    if(n_beg>1 || n_mid>1 || n_end>1){good=false; break;}
		    if(n_mid && (n_beg || n_end || num_allc[i])){
//			    cout<<n_beg<<" "<<n_mid<<" "<<n_end<<" "<<num_allc[i]<<"\n";
			    //cout<<string(1, 'a'+i)<<"p2";
			    good=false; break;}
		    if(n_beg&& n_end){
			good = connect(st, 'a'+i); num_allc[i]=0;
//			cout<<good;
		    }else
		    if(n_beg || n_end )num_allc[i]=0;
		    
		}
		if(good){
		    int t = 0;
		    for(int i=0; i<N; i++) if(st[i]!="")t++;
		    for(int i=0; i<26; i++) if(num_allc[i])t++;
		    res=(res*fac(t))%md;
		}else{
		    res=0;
		}
		cout<<"Case #"<<j+1<<": "<<res<<"\n" ;

	}
	
}
