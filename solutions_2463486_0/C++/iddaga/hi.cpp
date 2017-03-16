#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> r;
int n;
vector<int> a, s;
void back(int p)
{
	int i, j, k;
	
	if (p <= n-1-p) {		
		for (k = p==0; k <= 9; k++) {
			a[p] = a[n-1-p] = k;
			
			for (i = 0; i < s.size(); i++) s[i] = 0;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++)
					s[i+j] += a[i]*a[j];
			}
			for (i = 0; i < s.size(); i++) {
				if (s[i] > 9) break;
			}
			if (i >= s.size()) back(p+1);
			
			a[p] = a[n-1-p] = 0;
		}
	}
	else {
		for (i = 0; i < s.size(); i++) s[i] = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				s[i+j] += a[i]*a[j];
		}
		
		string str = "";
		for (i = 0; i < s.size(); i++)
			str += s[i]+'0';
		r.push_back(str);
	}
}
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j;
	char str[128];
	string A, B;

	r.clear();
	for (n = 1; n <= 50; n++) {
		printf("n = %d\n",n);
		a = vector<int>(n,0);
		s = vector<int>(2*n-1,0);
		back(0);
	}
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		fprintf(out,"Case #%d: ",t);
		
		fscanf(in,"%s",str); A = str;
		fscanf(in,"%s",str); B = str;
		j = 0;
		for (i = 0; i < r.size(); i++) {
			if (r[i].size() < B.size()) j++;
			if (r[i].size() == B.size() && r[i] <= B) j++;
		}
		for (i = 0; i < r.size(); i++) {
			if (r[i].size() < A.size()) j--;
			if (r[i].size() == A.size() && r[i] < A) j--;
		}
		fprintf(out,"%d\n",j);
	}
	fclose(in);
	fclose(out);
	return 0;
}