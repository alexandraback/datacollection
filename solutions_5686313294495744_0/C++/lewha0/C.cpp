#include<map>
#include<string>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

#define MAXV 1000
struct MM
{
	vector< vector<int> > AL;
	int V1, V2, Mat1[MAXV], Mat2[MAXV], q[MAXV], head, tail, Back[MAXV], TM;

	MM(int v1, int v2) : V1(v1), V2(v2)
	{
		int l1;
		AL.clear(); AL.resize(V1);
		for(l1=0;l1<V1;l1++) Mat1[l1] = -1;
		for(l1=0;l1<V2;l1++) Mat2[l1] = -1;
		TM = 0;
	}
	void Add(int t1, int t2)
	{
		AL[t1].push_back(t2);
		if(Mat1[t1] == -1 && Mat2[t2] == -1)
		{
			Mat1[t1] = t2; Mat2[t2] = t1; TM++;
		}
	}
	int Go()
	{
		int l1, l2, t1, t2;
		while(1)
		{
			head = tail = 0;
			for(l1=0;l1<V1;l1++)
			{
				if(Mat1[l1] == -1) q[tail++] = l1;
				Back[l1] = -1;
			}
			while(head<tail)
			{
				l1 = q[head++];
				for(l2=0;l2<AL[l1].size();l2++)
				{
					if(Mat2[AL[l1][l2]] == -1) goto maki;
					else if(Back[Mat2[AL[l1][l2]]] == -1)
					{
						Back[Mat2[AL[l1][l2]]] = l1;
						q[tail++] = Mat2[AL[l1][l2]];
					}
				}
			}
			break; maki: l2 = AL[l1][l2];
			while(1)
			{
				t1 = Back[l1]; t2 = Mat1[l1];
				Mat1[l1] = l2; Mat2[l2] = l1;
				l1 = t1; l2 = t2;
				if(l1 == -1) break;
			}
			TM++;
		}
		return TM;
	}
};

map<string, int> M1, M2;
set< pair<string, string> > S;
int T;
int N;
string Str1, Str2;

int main(void)
{
	int l0, l1;

	cin >> T;
	for(l0 = 1; l0 <= T; l0++)
	{
		M1.clear();
		M2.clear();
		S.clear();

		cin >> N;
		for(l1 = 0; l1 < N; l1++)
		{
			cin >> Str1 >> Str2;
			S.insert(make_pair(Str1, Str2));

			if(M1.count(Str1) == 0)
			{
				int temp = M1.size();
				M1[Str1] = temp;
			}
			if(M2.count(Str2) == 0)
			{
				int temp = M2.size();
				M2[Str2] = temp;
			}
		}
		if(S.size() != N)
		{
			cerr << "-_-" << l0 << endl;
		}

		MM mm = MM(M1.size(), M2.size());

		set< pair<string, string> >::iterator it;
		for(it = S.begin(); it != S.end(); ++it)
		{
			mm.Add(M1[it->first], M2[it->second]);
		}

		cout << "Case #" << l0 << ": " << S.size() - M1.size() - M2.size() + mm.Go() << endl;
	}

	return 0;
}
