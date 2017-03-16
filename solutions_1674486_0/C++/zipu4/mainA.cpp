#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef vector<int> vi;
typedef vi::iterator ivi;
typedef set<int> si;
typedef si::iterator isi;
typedef map<int,si> misi;
typedef misi::iterator imisi;
typedef map<int,bool> mib;
typedef mib::iterator imib;
typedef map<int,mib> mimib;
typedef mimib::iterator imimib;

int main(){
	FILE* input = fopen("C:\\codejam\\data.in","r");
	FILE* output = fopen("C:\\codejam\\data.out","w");
	FILE* logput = fopen("C:\\codejam\\data.log","w");
	int T,N;
	misi downmap,upmap;
	mimib routmapA, routmapB;
	si downactive,upactive;
	fscanf(input,"%d\n",&T);
	for(int t=0;t<T;t++){
		printf("case %d\n",t+1);
		fprintf(logput,"case %d\n",t+1);
		fscanf(input,"%d\n",&N);
		downmap.clear();
		downactive.clear();
		upactive.clear();
		upmap.clear();
		routmapA.clear();
		routmapB.clear();
		for(int n=0;n<N;n++){
			int M,temp;
			fscanf(input,"%d",&M);
			for(int m=0;m<M;m++){
				fscanf(input,"%d",&temp);
				routmapA[n+1][temp] = true;
				routmapB[n+1][temp] = true;
				downmap[temp].insert(n+1);
				upmap[n+1].insert(temp);
			}
		}
		fprintf(logput,"\tdownactive:\n");
		for(imisi i= downmap.begin();i!=downmap.end();i++){
			if(i->second.size() > 1){
				downactive.insert(i->first);
				fprintf(logput,"\t\t%d\n",i->first);
			}
		}
		if(downactive.size() == 0){
			goto fail;
		}
		fprintf(logput,"\tupactive:\n");
		for(imisi i=upmap.begin();i!=upmap.end();i++){
			if(i->second.size() > 1){
				upactive.insert(i->first);
				fprintf(logput,"\t\t%d\n",i->first);
			}
		}
		if(upactive.size() == 0){
			goto fail;
		}
		for(isi i=downactive.begin();i!=downactive.end();i++){
			for(isi j=upactive.begin();j!=upactive.end();j++){
				if(*i == *j){
					continue;
				}
				vi tempvi;
				tempvi.resize(min(downmap[*i].size(),upmap[*j].size()));
				ivi tempivi = set_intersection(downmap[*i].begin(),downmap[*i].end(),upmap[*j].begin(),upmap[*j].end(),tempvi.begin());
				int count = tempivi - tempvi.begin();
				if(routmapA[*j][*i]){
					count++;
				}
				fprintf(logput,"\tintersect (%d,%d) %d\n",*i,*j,count);
				if(count > 1){
					goto succes;
				}
			}
		}
		for(int i=0,changed = 1;i<N && changed > 0;i++){
			changed = 0;
			for(imimib i=routmapA.begin();i!=routmapA.end();i++){
				for(imib j=routmapA[i->first].begin();j!=routmapA[i->first].end();j++){
					for(imib k=routmapA[j->first].begin();k!=routmapA[j->first].end();k++){
						if(!routmapA[i->first][k->first]){
							changed++;
							routmapA[i->first][k->first] = true;
						}
					}
				}
			}
			fprintf(logput,"\tchanged %d\n",changed);
		}
		fprintf(logput,"\tlast check\n");
		for(isi i=downactive.begin();i!=downactive.end();i++){
			for(isi j=upactive.begin();j!=upactive.end();j++){
				fprintf(logput,"\t\t%d vs %d\n",*i,*j);
				if(*i == *j){
					continue;
				}
				vi tempvi;
				tempvi.resize(min(downmap[*i].size(),upmap[*j].size()));
				ivi tempivi = set_intersection(downmap[*i].begin(),downmap[*i].end(),upmap[*j].begin(),upmap[*j].end(),tempvi.begin());
				int count = tempivi - tempvi.begin();
				if(routmapB[*j][*i]){
					count++;
				}
				if(count > 1){
					goto succes;
				}
				fprintf(logput,"\t\t\tcount before check %d\n",count);
				for(isi ii = downmap[*i].begin();ii!=downmap[*i].end();ii++){
					for(isi jj = upmap[*j].begin();jj!=upmap[*j].end();jj++){
						fprintf(logput,"\t\t\tcheck (%d,%d) ",*jj,*ii);
						if(routmapA[*jj][*ii]){
							count++;
							fprintf(logput,"V\n");
							if(count > 1){
								goto succes;
							}
						}else{
							fprintf(logput,"X\n");
						}
					}
				}
				fprintf(logput,"\t\t\tcount %d\n",count);
			}
		}
		fail:
		fprintf(output,"Case #%d: No\n",t+1);
		continue;
		succes:
		fprintf(output,"Case #%d: Yes\n",t+1);
	}
	fclose(input);
	fclose(output);
	return 0;
}