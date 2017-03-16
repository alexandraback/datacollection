#include<iostream>
using namespace std;

string translateFromGooglerease(string  S)
{
string R = S;

string grs = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvqz";
string eng = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupzq";

for(int i=0;i<R.length();i++)
	{
		int grsIdx = grs.find(R[i]);
		if(grsIdx != string::npos)
			{
				R[i] = eng[grsIdx];
			}
	}
return R;
}


int main()
{
int N;
cin>>N;
string glang, eng;
getline(cin,glang);

for(int i=1;i<=N;i++)
	{
		getline(cin,glang);
		eng = translateFromGooglerease(glang);
		cout<<"Case #"<<i<<": "<<eng<<endl;
		//cout<<eng<<endl;
	}
return 0;
}
