#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<queue>
#include<limits>
using namespace std;

/*problems
*/

/*plans
*/

//classes & definitions
typedef pair<int,int> P;
typedef long long LL;
class tri
{
public:
	int x,y,z;
	tri() {x=y=z=0;}
	tri(int a, int b, int c) {x=a; y=b; z=c;}
};

#define clr(x) memset((x), 0, sizeof(x))
#define stop system("pause")

//input & output
ifstream fin;
ofstream fout,foot;
int T,N;
int a[2000],b[2000];


//constants
const int INF=INT_MAX/2;

//variables

//data structures
tri l1[2000];
priority_queue<P,vector<P>,greater<P>> l2;

//functions
bool comp(tri t1, tri t2)
{
	if(t1.x!=t2.x)return t1.x<t2.x;
	else return t2.y<t1.y;
}

void solve()
{
	sort(l1,l1+N,comp);

	int star=0;
	int cnt=0;
	int nxt1=0;
	bool used1[2000];
	bool used2[2000];
	memset(used1,0,sizeof(used1));
	memset(used2,0,sizeof(used2));

	while(l2.size()>0){
		if(star>=l2.top().first){
			used2[l2.top().second]=1;
			star+=2;
			cnt++;

			cout<<l2.top().second<<"-"<<2<<endl;
			l2.pop();
		}
		else if(nxt1<N && l1[nxt1].x<=star && used1[l1[nxt1].z]==0 && used2[l1[nxt1].z]==0){
					used1[l1[nxt1].z]=1;
			        
					cout<<l1[nxt1].z<<"-"<<1<<endl;

				    star++;
				    cnt++;
				    nxt1++;
		}
		else{
			int koho=-1;
		    for(int i=0; i<N; i++){
				if(a[i]<=star && used1[i]==0){
					if(koho==-1 || b[koho]<b[i])koho=i;
				}
				if(koho>=0){
					used1[koho]=1;
					star++;
					cnt++;
				}
				else{
					fout<<"Too Bad"<<endl;
					return;
				}
			}
		}
	}
	fout<<cnt<<endl;
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\B-small-attempt6.in");
	fout.open("C:\\Users\\fumi\\Downloads\\B-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\BB.txt");

	fin>>T;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";
		cout<<"Case #"<<i+1<<endl;
		foot<<"Case #"<<i+1<<endl;
		fin>>N;
		foot<<N<<endl;
		while(!l2.empty())l2.pop();

		for(int j=0; j<N; j++){
			fin>>a[j]>>b[j];
			l1[j]=tri(a[j],b[j],j);
			l2.push(P(b[j],j));
			foot<<a[j]<<" "<<b[j]<<endl;
		}

		solve();
	}

	stop;
	return 0;
}