#include <iostream>
using namespace std;

int main(){
	freopen("f.txt","r",stdin);
	freopen("fout.txt","w",stdout);
	int t,r,c,w;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> r >> c >> w;
		cout << "Case #" << i << ": " << (r - 1) * (int)(c / w) + (int)((c - 1) / w) + w << '\n';
	}


	return 0;
}

/*#include <iostream>
#include <unordered_set>
using namespace std;
int c,d,v;
int den[10000],p[1000];
unordered_set<int> uset;
void g(int s[],int p,int k,int t[],int q=0,int r=0)
{
    if(q==k){
		int sum = 0;
        for(int i = 0; i < k; i++)
			sum += t[i];
		if(sum <= v)
		uset.insert(sum);

    }
    else{
        for(int i = r; i < p; i++){
            t[q] = s[i];
            g(s,p,k,t,q+1,i+1);
        }
    }
}
int main(){
	freopen("f.txt","r",stdin);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> c >> d >> v;
		uset.clear();
		for(int j = 0; j < d; j++){
			cin >> den[j];
			uset.insert(den[j]);
		}
		for(int j = 2; j <= d; j++)
			g(den,d,j,p);
		cout << "Case #" << i << ": "<< v - uset.size() << '\n'; 

	}


	return 0;
}*/