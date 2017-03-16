#include <bits/stdc++.h>

#define mp make_pair
#define ft first
#define sc second

using namespace std;

int main(){
	
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int teskes;
	scanf("%d",&teskes);
	
	for(int tc=1;tc<=teskes;tc++){
		vector<pair<pair<int,int>,int> >ans;
		map<pair<pair<int,int>,int> , int>pet;
		int a,b,c,k;
		scanf("%d%d%d%d",&a,&b,&c,&k);
		
		int offsety=0, offsetz=0;
		for(int x=1;x<=a;x++){
			offsety++;
			offsetz=0;
			for(int y=1;y<=b;y++){
				offsetz++;
				for(int z=1;z<=c;z++){
					pair<pair<int,int>,int> aa, bb, cc;
					
					int xx = x;
					int yy = y+offsety; yy%=b; yy++;
					int zz = z+offsetz; zz%=c; zz++;
					aa=mp(mp(0,yy),zz);
					bb=mp(mp(xx,0),zz);
					cc=mp(mp(xx,yy),0);
					
					bool g=true;
					if(pet[aa]>=k)g=false;
					if(pet[bb]>=k)g=false;
					if(pet[cc]>=k)g=false;
					
					if(g==true){
						pet[aa]++;
						pet[bb]++;
						pet[cc]++;
						ans.push_back(mp(mp(xx,yy),zz));
					}
				}
			}
		}
		printf("Case #%d: %d\n",tc,ans.size());
		for(int x=0;x<ans.size();x++){
			printf("%d %d %d\n",ans[x].ft.ft,ans[x].ft.sc,ans[x].sc);
		}	
	}
	
	return 0;
}
