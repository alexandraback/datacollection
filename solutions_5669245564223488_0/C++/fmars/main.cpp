#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<list>
using namespace std;
int N;
typedef long long ll;
vector<string>cars(100);
vector<string>f;
ll fac(ll x) {
    if(x==0 || x==-1)return 1;
  return (x == 1 ? x : x * fac(x - 1));
}
bool check(string&str,int x){
    bool f=true;
    for(int i=x-1;i>=0;i--)
    if(str[i]!=str[x]){
        f=false;
        break;
    }
    if(f)return true;
    f=true;
    for(int i=x+1;i<str.size();i++)
    if(str[i]!=str[x]){
        f=false;
        break;
    }
    return f;
}
bool valid(){
    int fre[30];
    int mid[30];
    for(int i=0;i<30;i++){
        fre[i]=0;mid[i]=0;
    }
    for(int i=0;i<N;i++){
        int frea[30];
        for(int k=0;k<30;k++)
            frea[k]=0;
        for(int j=0;j<cars[i].size();j++)
            frea[cars[i][j]-'a']=1;
        for(int j=0;j<30;j++)
            if(frea[j])fre[j]++;
        for(int j=1;j<cars[i].size()-1;j++){
            if(!check(cars[i],j))
                mid[cars[i][j]-'a']=1;
        }
    }
    for(int i=0;i<26;i++)
        if(mid[i] && fre[i]>1)
            return false;
    return true;
}
bool bar(){
    for(int i=0;i<f.size();i++){
        if(f[i].size()>1 && f[i][0]!=f[i][1])
        for(int j=i+1;j<f.size();j++){
            if(f[j].size()>1){
            if(f[i][0]==f[j][1]){
                f[i][0]=f[j][0];
                f[i][1]=f[i][1];
                f.erase(f.begin()+j);
                return true;
            }
            if(f[i][1]==f[j][0]){
                f[i][0]=f[i][0];
                f[i][1]=f[j][1];
                f.erase(f.begin()+j);
                return true;
            }
            }
        }
    }
    return false;
}
void foo(){
    for(int i=0;i<N;i++){
        if(cars[i].size()==1)
            f.push_back(cars[i]);
        else{
            string str;
            if(cars[i][0]==cars[i][cars[i].size()-1])
                str+=cars[i][0];
            else{
                str+=cars[i][0];
                str+=cars[i][cars[i].size()-1];
            }
            f.push_back(str);
        }
    }
    if(bar())bar();
    for(int i=0;i<f.size();i++)
        if(f[i][0]==f[i][1]){
            string s;s+=f[i][0];
            f[i]=s;
        }

}
bool barr(ll&res){
    if(f.empty())return false;
    for(int i=0;i<f.size();i++){
        if(f[i].size()==2){
            int l=-1,r=-1;
            for(int j=0;j<f.size();j++){
                if(f[j][0]==f[i][0])l++;
                if(f[j][0]==f[i][1])r++;
            }
            res=res*fac(l)*fac(r);
            char c1=f[i][0],c2=f[i][1];
            for(int k=f.size()-1;k>=0;k--)
                if(f[k][0]==c1 || f[k][0]==c2)
                    f.erase(f.begin()+k);
            return true;
        }
    }
    for(int i=0;i<f.size();i++){
        if(f[i].size()==1){
            int l=0;
            for(int j=0;j<f.size();j++)
                if(f[j][0]==f[i][0])l++;
            res=res*fac(l);
            char c=f[i][0];
            for(int k=f.size()-1;k>=0;k--)
                if(f[k][0]==c)
                    f.erase(f.begin()+k);
            return true;
        }
    }
}
ll calc(){
    ll res=1;
    for(int i=0;i<f.size();i++)
        if(f[i].size()>1){
            for(int j=i+1;j<f.size();j++)
                if(f[j].size()>1 && (f[i][0]==f[j][0]|| f[i][1]==f[j][1]))
                    return 0;
        }
    int n=0;
    while(barr(res)){n++;}
    res=res*fac(n);
    res=res %1000000007;
    return res;

}
int main()
{
	freopen("in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i,j, TC, T;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
        cin>>N;
        for(i=0;i<N;i++)
            cin>>cars[i];
        if(!valid()){
            cout<<0<<endl;
            continue;
        }
        f.clear();
        foo();
        ll res=calc();
		cout<<res<<endl;
	}
	return 0;
}
