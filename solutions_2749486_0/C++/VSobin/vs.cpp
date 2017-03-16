#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define N 10000000

using namespace std;

int n;

int a[1000][1000];

int T;

int x,y,q1,q2,xx,yy,t;


string ans,p;

struct qq{
	int x,y,t;
	string s;
} q[N];

void rec(int t,int xx,int yy,string p){
    if (t>500 || xx<0 || xx>1000 || yy<0 || yy>1000 || a[xx][yy]==1 || ans!="") return ;
    a[xx][yy]=1;
    if (xx==x && yy==y) ans=p;
    q[q1].x=xx;
    q[q1].y=yy;
    q[q1].t=t;
    q[q1++].s=p;       
}
        

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> T ;
	int v=0;
	
	while (T--){
		memset(a,0,sizeof(a));
		cin >> x >> y;
		ans="";
		q1=0;q2=0;
		x+=500,y+=500;
		rec(0,500,500,"");
		while (q1!=q2){
			xx=q[q2].x;
			yy=q[q2].y;
			t=q[q2].t;
			p=q[q2].s;
    		rec(t+1,xx-(t+1),yy,p+'W');
		    rec(t+1,xx+(t+1),yy,p+'E');
    		rec(t+1,xx,yy+(t+1),p+'N');
    		rec(t+1,xx,yy-(t+1),p+'S');
    		q2++;
		}                 	
		v++;
		cout << "Case #" << v << ": " << ans << endl;	

	}

	return 0;
}
                    