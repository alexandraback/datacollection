#include <stdio.h>
#include <queue>
using namespace std;
int n,m,map[101][101][2];
double print,check[101][101],w;
struct q{
	int i,j;
	double time;
};
struct comp{
	bool operator() (q& a,q& b){
		return a.time>b.time;
	}
};
priority_queue<q,vector<q>,comp> que;
void pro(){
	int a,go[4][2]={1,0,0,1,-1,0,0,-1},i,j;
	q save,save2;
	save.i=save.j=save.time=0;
	if(map[0][0][0]-w>=50){
		check[0][0]=0;
		que.push(save);
		while(1){
			save=que.top();
			if(save.time!=0 || (save.i==n-1 && save.j==m-1)) break;
			que.pop();
			i=save.i;
			j=save.j;
			for(a=0;a<4;a++){
				if(i+go[a][0]>=0 && i+go[a][0]<n && j+go[a][1]>=0 && j+go[a][1]<m){
					if(map[i+go[a][0]][j+go[a][1]][0]-map[i][j][1]<50 || map[i+go[a][0]][j+go[a][1]][0]-map[i+go[a][0]][j+go[a][1]][1]<50 || map[i][j][0]-map[i+go[a][0]][j+go[a][1]][1]<50) continue;
					if(map[i+go[a][0]][j+go[a][1]][0]-w<50){
						save2.i=i+go[a][0];
						save2.j=j+go[a][1];
						save2.time=(w-map[i+go[a][0]][j+go[a][1]][0]+50)/10;
						if(w-save2.time*10-map[i][j][1]>=20)
							save2.time++;
						else
							save2.time+=10;
						if(check[i+go[a][0]][j+go[a][1]]>save2.time){
							check[i+go[a][0]][j+go[a][1]]=save2.time;
							que.push(save2);
						}
					}
					else{
						save2.i=i+go[a][0];
						save2.j=j+go[a][1];
						save2.time=0;
						if(check[i+go[a][0]][j+go[a][1]]!=0){
							check[i+go[a][0]][j+go[a][1]]=0;
							que.push(save2);
						}
					}
				}
			}
		}
	}
	else{
		save.time=(w-(map[0][0][0]-50))/10.0;
		check[0][0]=save.time;
		que.push(save);
	}
	while(1){
		save=que.top();
		que.pop();
		if(save.i==n-1 && save.j==m-1) break;
		if(check[save.i][save.j]<save.time) continue;
		i=save.i;
		j=save.j;
		for(a=0;a<4;a++){
			if(i+go[a][0]>=0 && i+go[a][0]<n && j+go[a][1]>=0 && j+go[a][1]<m){
				if(map[i+go[a][0]][j+go[a][1]][0]-map[i][j][1]<50 || map[i+go[a][0]][j+go[a][1]][0]-map[i+go[a][0]][j+go[a][1]][1]<50 || map[i][j][0]-map[i+go[a][0]][j+go[a][1]][1]<50) continue;
				if(map[i+go[a][0]][j+go[a][1]][0]-(w-save.time*10)<50){
					save2.i=i+go[a][0];
					save2.j=j+go[a][1];
					save2.time=(w-map[i+go[a][0]][j+go[a][1]][0]+50)/10.0;
					if(w-save2.time*10-map[i][j][1]>=20)
						save2.time++;
					else
						save2.time+=10;
					if(check[i+go[a][0]][j+go[a][1]]>save2.time){
						check[i+go[a][0]][j+go[a][1]]=save2.time;
						que.push(save2);
					}
				}
				else{
					save2.i=i+go[a][0];
					save2.j=j+go[a][1];
					save2.time=save.time;
					if(w-save2.time*10-map[i][j][1]>=20)
						save2.time++;
					else
						save2.time+=10;
					if(check[i+go[a][0]][j+go[a][1]]>save2.time){
						check[i+go[a][0]][j+go[a][1]]=save2.time;
						que.push(save2);
					}
				}
			}
		}
	}
	print=save.time;
}
int main(){
	int testt,test,i,j;
	FILE *in,*out;
	in=fopen("input.in","r");
	fscanf(in,"%d",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fscanf(in,"%lf %d %d",&w,&n,&m);
		while(!que.empty())
			que.pop();
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				fscanf(in,"%d",&map[i][j][0]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				check[i][j]=10000000;
				fscanf(in,"%d",&map[i][j][1]);
			}
		}
		pro();
		fprintf(out,"Case #%d: %lf\n",test,print);
	}
	fcloseall();
	return 0;
}
