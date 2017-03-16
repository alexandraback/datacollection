#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;


class game{
private:
	_int64 P;
	_int64 Q;
	string temp;
	int DFS(_int64 pp,_int64 qq);
	_int64 GetMaxDiv(_int64 x, _int64 y);
public:
	void set(ifstream& fin);
	int result();

};




void game::set(ifstream& fin){
	fin>>temp;
	//cout<<temp<<endl;
	int i=0;
	P=0;Q=0;
	for(i=0;i<temp.size();i++){
		if(temp[i]=='/')
			break;
		P*=10;
		P+=(_int64)(temp[i]-'0');	
	}
	i++;
	for(;i<temp.size();i++){
		Q*=10;
		Q+=(_int64)(temp[i]-'0');		
	}
	//cout<<P<<" "<<Q<<endl;
}


_int64 game::GetMaxDiv(_int64 x, _int64 y)
{
	while(y)
	{
		_int64 tmp = y;
		y = x%y;
		x = tmp;
	}
	return x;
}

int game::result(){
	_int64 temp=GetMaxDiv(Q,P);
	Q/=temp;
	P/=temp;
	_int64 ww;
	//cout<<P<<" "<<Q<<endl;
	int i=0;
	for(i=0;i<=40;i++){
		ww=P<<i;
		if(ww>=Q)
			break;  
	}
	if(ww<Q)
		return -1;
	while(Q>1){
		if( Q%2 == 1){
			//cout<<"Q: "<<Q<<endl;
			return -1;
		}
		Q/=2;
	}
	return i;
}



void main(){
	ifstream fin;
	ofstream fout;
	fin.open("A-large.in");
	fout.open("A-large.out");
	game solve;
	int T;
	fin>>T;
	int res;
	for(int i=0;i<T;i++){
		cout<<i<<endl;
		solve.set(fin);
		res=solve.result();
		if(res==-1)
			fout<<"Case #"<<i+1<<": impossible"<<endl;
		else
			fout<<"Case #"<<i+1<<": "<<res<<endl;

	}
	fin.close();
	fout.close();
}