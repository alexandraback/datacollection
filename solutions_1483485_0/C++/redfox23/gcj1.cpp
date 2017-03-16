#include <fstream>
#include <cstring>

using namespace std;

int main() {
	int t;
	char arr[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	ifstream fin;
	ofstream fout;
	fin.open("A-small-attempt0.in");
	fout.open("A-small-attempt0.out");
	fin>>t;
	fin.get();
	char *s = new char [105];
	int j,l;
	for (int i = 0; i< t ; i++) {
		fout<<"Case #"<<i+1<<": ";
		fin.getline(s,101);
		l = strlen(s);
		for (j= 0; j<l;j++)
			if (s[j] == ' ') fout<<' '; else
			fout<<arr[s[j]-'a'];
		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}