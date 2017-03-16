#include <fstream>
#include <string.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int visit[1000001] = {0, };

void prs(int ta)
{
	char str[1000002];
	int dap = 0;
	int i, n;
	int cnt = 0;
	int len = 0;

	in >> str >> n;
	int length = strlen(str);
	for(i=0; i<=1000000; i++)visit[i] = 0;

	for(i=0; i<n; i++){
		if(str[i] != 'a' && str[i] != 'e' && str[i] !='i' && str[i] !='o' && str[i] != 'u')cnt++;
	}
	if(cnt == n)visit[len++] = n-1;
	
	for(i=n; i<length; i++){
		if(str[i-n] != 'a' && str[i-n] != 'e' && str[i-n] !='i' && str[i-n] !='o' && str[i-n] != 'u')cnt--;
		if(str[i] != 'a' && str[i] != 'e' && str[i] !='i' && str[i] !='o' && str[i] != 'u')cnt++;
		if(cnt == n)visit[len++] = i;
	}
	if(len > 0){
		dap += (visit[0] - n + 2) * (length - visit[0]);
		for(i=1; i<len; i++){
			dap+= (visit[i] - visit[i-1]) * (length - visit[i]);
		}

	}
	out << "Case #"<<ta+1<<": "<<dap<<endl;
}
int main()
{
	int t;
	int i;
	in >> t;
	for(i=0; i<t; i++){
		if(i==20){
			i =i;
		}
		prs(i);
	}

	return 0;
}