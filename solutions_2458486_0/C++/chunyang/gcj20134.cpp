#include<iostream>
#include<fstream>
using namespace std;

struct conf
{
	conf()
	{
		totnow = 0;
		for (int i = 0; i < 500; i ++) {
			keytype[i] = 0;
			nowkeys[i] = 0;
			open[i] = false;
		}
		for (int i = 0; i < 500; i ++)
			for (int j = 0; j < 500; j ++) ckeys[i][j] = 0;
	}
	int keytype[500];
	int ckeys[500][500];
	int nowkeys[500];
	
	int maxk;
	int maxc;

	bool open[500];
	int ans[500];
	int totnow;
};

conf cfs[30];

void search(bool & fin, conf & cf, int & step)
{
	if (step > 10000000) {
		fin = true;
		cf.totnow = 0;
		return;
	}
	for (int i = 1; i <= cf.maxc; i ++)
	{
		if (!cf.open[i] && cf.nowkeys[cf.keytype[i]] > 0)
		{
			cf.open[i] = true;
			cf.nowkeys[cf.keytype[i]] --;
			cf.ans[cf.totnow] = i;
			cf.totnow ++;

			if (cf.totnow == cf.maxc)
			{
				fin = true;
				break;
			}

			for (int j = 1; j <= cf.maxk; j ++)
			{
				cf.nowkeys[j] += cf.ckeys[i][j];
			}
			step ++;
			search(fin, cf, step);

			for (int j = 1; j <= cf.maxk; j ++)
			{
				cf.nowkeys[j] -= cf.ckeys[i][j];
			}

			if (fin) break;

			cf.totnow --;
			cf.nowkeys[cf.keytype[i]] ++;
			cf.open[i] = false;
		}
	}
}

void subtask(conf & cf)
{
	bool finished = false;
	int step = 0;
	search(finished, cf, step);
}

int main()
{
	ifstream ifs("D-small-attempt2.in");
	

	int tot;
	ifs >> tot;
	for (int i = 0; i < tot; i ++)
	{
		int tmp;
		ifs >> tmp >> cfs[i].maxc;
		for (int j = 0; j < tmp; j ++)
		{
			int tmp2;
			ifs >> tmp2;
			cfs[i].nowkeys[tmp2] ++;
		}
		for (int j = 1; j <= cfs[i].maxc; j ++)
		{
			ifs >> cfs[i].keytype[j];
			if (cfs[i].maxk < cfs[i].keytype[j]) cfs[i].maxk = cfs[i].keytype[j];
			int tmp2;
			ifs >> tmp2;
			for (int k = 0; k < tmp2; k ++)
			{
				int tmp3;
				ifs >> tmp3;
				cfs[i].ckeys[j][tmp3] ++;
			}
		}
	}
	ifs.close();

	ofstream ofs("output.txt");

	for (int i = 0; i < tot; i ++)
	{
		subtask(cfs[i]);
		cout << i << endl;
	}

	for (int i = 0; i < tot; i ++)
	{
		if (cfs[i].totnow != 0)
		{
			ofs << "Case #" << i + 1 << ":";
			for (int j = 0; j < cfs[i].maxc; j ++)
			{
				ofs << " "<< cfs[i].ans[j];
			}
			ofs << endl;
		} else {
			ofs << "Case #" << i + 1 << ": IMPOSSIBLE\n";
		}
	}

	ofs.close();
	
	return 0;
}