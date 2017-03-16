#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
#include <fstream>
#define DEBUG
#ifdef DEBUG
ifstream fin("C.in");
ofstream fout("C.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int R,C,M,T,fc,fr,mines,counter;
char m[50][50],t[10][10];
bool used[10][10];
int movement[8][2]={{0,-1},{0,1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool found;
/*
class Cor{
public:
int r;
int c;
Cor(int r,int c):r(r),c(c){}
};


bool expend(int r,int c){
memset(used,false,sizeof(used));
//if(t[0][0]=='*'&&t[0][1]=='*'&&t[2][3]=='*'&&r==3&&c==0)
//	cout<<"hehe"<<endl;
if(!noMine(r,c))
return false;
int counter=0;
deque<Cor> q;
q.push_back(Cor(r,c));
used[r][c]=true;
while(q.size()){
Cor tmp=q.front();
q.pop_front();
counter++;
if(!noMine(tmp.r,tmp.c)){
t[tmp.r][tmp.c]=(char)('0'+mines);
continue;
}
else{
t[tmp.r][tmp.c]='0';
}
for(int i=0;i<8;i++){
int rr=tmp.r+movement[i][0];
int cc=tmp.c+movement[i][1];
if(inRange(rr,cc)&&t[rr][cc]=='.'&&!used[rr][cc]){
used[rr][cc]=true;
q.push_back(Cor(rr,cc));
}
}
}
//cout<<"counter: "<<counter<<endl;
return counter==R*C-M;
}

void output(){
for(int i=0;i<R;i++){
for(int j=0;j<C;j++){
cout<<m[i][j];
}
cout<<endl;
}
/*
cout<<endl;
cout<<endl;
for(int i=0;i<R;i++){
for(int j=0;j<C;j++){
cout<<t[i][j];
}
cout<<endl;
}
*/
/*
}
*/
bool inRange(int r,int c){
	return 0<=r&&r<R&&0<=c&&c<C;
}
int noMine(int r,int c){
	int mi=0;
	for(int i=0;i<8;i++){
		int rr=r+movement[i][0];
		int cc=c+movement[i][1];
		if(inRange(rr,cc)&&m[rr][cc]=='*')
			mi++;
	}
	return mi;
}
void output(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<m[i][j];
		}
		cout<<endl;
	}
}

bool expend(int r,int c){
	used[r][c]=true;
	counter--;
	if(counter==0){
		return true;
	}
	int rr,cc;
	if(noMine(r,c)==0){
		for(int i=0;i<8;i++){
			rr=r+movement[i][0];
			cc=c+movement[i][1];
			if(inRange(rr,cc)&&!used[rr][cc]){
				if(expend(rr,cc))
					return true;
			}
		}
	}
	return false;
}
bool test(){
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(m[i][j]!='*'){
				memset(used,false,sizeof(used));
				counter=R*C-M;
				if(expend(i,j)){
					fr=i;
					fc=j;
					return true;
				}
			}
			return false;
}
void search(int r,int c,int mm){
	if(found)
		return;
	if(r==R){
		if(mm!=0)
			return;
		if(test()){
			m[fr][fc]='c';
			output();
			found=true;
		}
	}
	else if(c==C){
		search(r+1,0,mm);
	}
	else{
		if(mm>0){
			m[r][c]='*';
			search(r,c+1,mm-1);
			m[r][c]='.';
		}
		if(!found){
			search(r,c+1,mm);
		}
	}
}


int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<":"<<endl;
		cin>>R>>C>>M;
		counter=R*C-M;
		found=false;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				m[i][j]='.';
		search(0,0,M);
		if(!found)
			cout<<"Impossible"<<endl;
		/*
		cout<<R<<" "<<C<<" "<<M<<endl;
		int k=R*C-M;
		for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		m[i][j]='.';
		if(R==1){
		for(int i=0;i<M;i++)
		m[0][i]='*';
		m[0][C-1]='c';
		k=0;
		}
		else if(C==1){
		for(int i=0;i<M;i++)
		m[i][0]='*';
		m[R-1][0]='c';
		k=0;
		}
		else{
		for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		m[i][j]='*';
		m[0][0]=m[0][1]=m[1][0]=m[1][1]='.';
		k-=4;
		int r=0,c=2;
		if(C%2==0){
		while(k>0){
		if(k==2&&r==0){
		if(r+1<R){
		m[r][c]=m[r+1][c]='.';
		k=0;
		}
		else{
		k=-1;
		}
		continue;
		}
		if(c==C){
		if(r!=0)
		c=0;
		else
		c=2;
		r++;
		}
		else{
		if(k==3){
		if(r==0){
		k=-1;
		break;
		}
		if(c<C-2){
		m[r][c]=m[r][c+1]=m[r][c+2]='.';
		k-=3;
		}
		else{
		if(c>2){
		m[r-1][c]='*';
		m[r+1][0]=m[r+1][1]=m[r+1][2]='.';
		k-=3;
		}
		else{
		k=-1;
		break;
		}
		}
		}
		else{
		m[r][c]=m[r][c+1]='.';
		c+=2;
		k-=2;
		}
		}
		}
		}
		else{
		lastLine=false;
		while(k>0){
		if(c==C){
		if(r+2==R-1){
		lastLine=true;
		}
		r+=2;
		c=0;
		}
		else{
		if(k==2&&c==0){
		if(C>=2){
		m[r][c]=m[r][c+1]='.';
		k-=2;
		break;
		}
		}
		if(k==3&&!lastLine){
		if(c>2){
		m[r+2][0]=m[r+2][1]=m[r+2][2]='.';
		k=0;
		}
		else{
		k=-1;
		break;
		}
		}
		else{
		if(!lastLine){
		m[r][c]=m[r+1][c]='.';
		k-=2;
		c++;
		}
		else{
		if(c+1<C){
		m[r][c]=m[r][c+1]='.';
		k-=2;
		c+=2;
		}
		else{
		m[r][c]='.';
		k-=1;
		c+=1;
		}
		}
		}
		}
		}
		}
		m[0][0]='c';
		}

		if(k==0)
		output();
		else
		cout<<"Impossible"<<endl;
		}
		*/
	}

	return 0;
}