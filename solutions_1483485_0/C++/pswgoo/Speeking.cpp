#include<fstream>
#include<string>
using namespace std;

//char map[26]={'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};
char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    ifstream fin("A-small-attempt2.in");
	ofstream fout("A-small-attempt0.out");
	int N;
    fin>>N;
	string line;
	getline(fin,line);
	for(int i=0; i!=N; ++i)
	{   getline(fin,line);
	    string str("Case #");
		if(i+1>=10)
		{   str.push_back((i+1)/10+'0');
		    str.push_back((i+1)%10+'0');
		}
		else
		   str.push_back('0'+i+1);
		str += ": ";
		for(int j=0;j!=line.size();++j)
		    if(line.at(j)!=' ') 
			    str.push_back(map[line.at(j)-'a']);
			else
			    str.push_back(' ');
		fout<<str<<endl;
	}
	return 0;
}