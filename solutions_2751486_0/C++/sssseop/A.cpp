#include <fstream>
#include <string>

using namespace std;

int main()
{
	int i;
	int t;
	int j, k, l;
	int dap,cnt,max;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> t;
	
	string str;
	int n;
	for(i=0; i<t; i++){
		in >> str >> n;
		dap = 0;
		cnt = 0;
		max = 0;
		for(j=0; j<str.length(); j++){
			for(k=j; k<str.length(); k++){
				for(l=j; l<=k; l++){
					if(str[l] != 'a' && str[l] != 'e' && str[l] != 'u' && str[l] !='o' && str[l] !='i')
						cnt++;
					else cnt = 0;
					if(max < cnt)max = cnt;
				}
				if(max >= n){
					dap++;
				}		
				max = 0;
				cnt = 0;
			}
		}
		out << "Case #"<<i+1<<": "<<dap<<endl;
	}

	return 0;
}