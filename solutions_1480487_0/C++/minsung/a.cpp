#include<cstdio>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

struct ele{
	int idx;
	double x,a;
};
int t;
int n;
vector<ele> data;

int cmp(ele a,ele b){
	return a.x < b.x;
}
int cmp2(ele a,ele b){
	return a.idx < b.idx;
}

int main(){
    int i,j;
    double k;
    int sum,m;
    ele u;
    FILE *in= fopen("input.txt","r");
    FILE *out = fopen("ouput.txt","w");
    fscanf(in, "%d", &t);
    for(int tcc = 1; tcc<= t; tcc++){
		data.clear();
		fscanf(in, "%d",&n);
		sum = 0;
		for(i=0;i<n;i++){
			u.idx = i;
			fscanf(in, "%d", &j);
			sum+=j;
			u.x = (double)j;
			u.a = 0;
			data.push_back(u);
		}
		sort(data.begin(), data.end(), cmp);
		m = sum;
		for(i=1;i<n;i++){
			if (data[i].x == data[i-1].x)
				continue;
			k = min((double)m, (data[i].x-data[i-1].x)*i);
			m-= k;
			for(j=0;j<i;j++){
				data[j].x += (double)k/i;
				data[j].a += (double)100*k/i/sum;
			}
		}
		if (m != 0){
			for(i=0;i<n;i++){
				data[i].x += (double)m/n;
				data[i].a += (double)100*m/n/sum;
			}
		}
		sort(data.begin(), data.end(), cmp2);
		printf("case: %d\n", tcc);
		fprintf(out, "Case #%d:", tcc);
		for(i = 0;i<n;i++){
			fprintf(out, " %lf", data[i].a);
		}
		fprintf(out, "\n");
    }
    return 0;
}
