#include<iostream>
#include<vector>
#define big 2000000000LL*1000000000

using namespace std;
	int T;
	string C,J;
bool can_eq(string a, string b){
    for(int i=0; i<a.length(); i++)
	if(a[i]!='?' && b[i]!='?' && a[i]!=b[i])return false;
    return true;
}
bool make_eq(string & a, string & b){
    for(int i=0; i<a.length(); i++){
	if(a[i]=='?'){
	    if(b[i]=='?')a[i]=b[i]='0';
		else a[i]=b[i];
	}
	if(b[i]=='?' )b[i]=a[i];
    }
}
bool can_sm(string a, string b, int n){
    if(n>=a.length())return false;
    for(int i=0; i<a.length(); i++){
	if(a[i]=='?')a[i]='0';
	if(b[i]=='?')b[i]='9';
    }
    if(a.substr(n)<b.substr(n))return true;
    else return false;
}
long long finish(string & a, string & b){
    for(int i=0; i<a.length(); i++){
	if(a[i]=='?')a[i]='9';
	if(b[i]=='?')b[i]='0';
    }
    long long res = stoll(b)-stoll(a);
    return res;
}
long long try_sm(string a, string b, string &na, string &nb){
    na=a; nb=b;
    for(int i=0; i<a.length(); i++){
	if(a[i]>b[i] && a[i]!='?')return big;
	if(a[i]=='?'){
	    if(b[i]=='?'){
		if(!can_sm(a,b, i+1)){
		    na[i]='0'; nb[i]='1';
		    return finish(na,nb);
		}else{
		    na[i]=nb[i]='0';
		}
	    }else{
		if(b[i]>'0'){
		}
		if(!can_sm(a, b, i+1)){
		    if(b[i]=='0')return big;
		    na[i] = nb[i]-1;
		    return finish(na,nb);
		}else{
		    na[i]=nb[i];
		    string na2=na, nb2=nb, nb3=na, na3=na;
		    if(nb[i]=='0')continue;
		    na2[i]=nb[i]-1;
		    if(finish(na2, nb2)<=try_sm(na.substr(i+1), nb.substr(i+1), na3, nb3))
			{
			    na=na2; nb=nb2; return finish(na, nb);
			}
		}
	    }
	}else{
	    if(b[i]=='?'){
		if(!can_sm(a,b, i+1)){
		    if(a[i]=='9')return big;
		    nb[i]=na[i]+1;
		    return finish(na,nb);
		}else{
		    nb[i]=na[i];
		}
	    }else{
		if(a[i]<b[i]){
		    return finish(na,nb);
		}
	    }
    
	}
    }
}
 
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
	    cin>>C>>J;
//cout<<C<<" "<<J<<"\n";
	    if(can_eq(C, J)){
		make_eq(C,J);
		cout<<"Case #"<<j+1<<": " <<C<<" "<<J<<"\n";
		continue;
	    }
	    string nc1, nj1, nc2, nj2;
	    long long r1 = try_sm(C, J, nc1, nj1 );
	    long long r2 = try_sm(J, C, nj2, nc2 );
	    if(r1==r2){
		if(nc1<nc2 || (nc1==nc2 && nj1<nj2))
		cout<<"Case #"<<j+1<<": " <<nc1<<" "<<nj1<<"\n";
		else
		cout<<"Case #"<<j+1<<": " <<nc2<<" "<<nj2<<"\n";
	    }else if(r1<r2)
		cout<<"Case #"<<j+1<<": " <<nc1<<" "<<nj1<<"\n";
	    else
		cout<<"Case #"<<j+1<<": " <<nc2<<" "<<nj2<<"\n";
	    cout.flush();

	}
	
}
