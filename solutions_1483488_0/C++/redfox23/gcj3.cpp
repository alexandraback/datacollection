#include <fstream>

using namespace std;

int main() {
	int test;
	ifstream fin;
	ofstream fout;
	fin.open("C-small-attempt0.in");
	fout.open("gcj3.out");
	fin>>test;
	int arr[7] = {1,10,100,1000,10000,100000,1000000};
	int mark[7];
	fin.get();
	int tc;
	int i,t,t1,t2,j,u,n;
	int a,b,mid;
	int count;
	int k;
	bool ok;
	for (tc = 0; tc < test; tc++) {
		fout<<"Case #"<<tc+1<<": ";
		
		fin>>a>>b;
		t = a;
		n = 0;
		while (t>0){
			t/=10;
			n++;
		}
		mid = (a+b)/2;
		count = 0;
		for (i = a; i<= b; i++){
			for (j = 0; j<7;j++) mark[j] = 0;
			for (j = 1; j<n; j++) {
				t1 = i/arr[j];
				t2 = i%arr[j];
				if (t2 == 0) continue;
				u = t2*arr[n-j]+t1;
				if (u>i)
					if ((u>=a)&&(u<=b)){
						ok=true;
						for (k=1;k<j;k++)
							if (mark[k] == u) {ok=false;break;}
						if (ok) count++;
						mark[j] = u;
					}
			}
		}
		fout<<count<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}