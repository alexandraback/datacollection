#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int x, y, n, pre;
	char ch;
	Node(int a = 0, int b = 0, int c = 0, char d = '0', int e = 0)
	{
		x = a, y = b, n = c, ch = d, pre = e;
	}
	Node(Node &node)
	{
		x = node.x, y = node.y, n = node.n, ch = node.ch, pre = node.pre;
	}
};
Node q[100000];

int desx, desy;	

int abs(int x)
{
	return x < 0 ? -x : x;
}

string dfs(int x,int y, int n)
{
	for (int i = 0; i < 4; i++)
	{
		int tx = x, ty = y, tn = n+1;
		string tch;
		if (i == 1)			tx += tn, tch = 'E';
		else if(i == 2)		ty += tn, tch = 'N';
		else if(i == 3)		tx -= tn, tch = 'W';
		else				ty -= tn, tch = 'S';
		cout << tx << " " << ty << " " << tn << endl;
		if (tx == desx && ty == desy)
		{
			return tch;
		}
		if (tn > 10 || abs(tx) > abs(desx) * 2 || abs(ty) > abs(desy) * 2)	return "";
		string ret = dfs(tx, ty, tn);
		if (ret != "")
			return tch + ret;
	}
	return string("");
}

string f()
{
	cin >> desx >> desy;
	if (desx < 0)	desx = -desx;
	if (desy < 0)	desy = -desy;
	return dfs(0, 0, 0);
	/*int st = 0, ed = 0;
	q[ed++] = Node(0, 0, 0, 0, -1);	

	while (ed - st != 0)
	{
		Node top = q[st++];
		if (top.x > 300 || top.y > 300)	continue;
		for (int i = 0; i < 4; i++)
		{
			Node tem(top);
			tem.n = top.n + 1, tem.pre = st - 1;
			if (i == 0)	
				tem.x += tem.n, tem.ch = 'E';
			else if(i == 1)
				tem.y += tem.n, tem.ch = 'N';
			else if(i == 2)
				tem.x -= tem.n, tem.ch = 'W';
			else 
				tem.y -= tem.n, tem.ch = 'S';
			q[ed++] = tem;		cout << tem.x << " " << tem.y << " " << tem.n << " "<< tem.pre<< " " << endl;
			if (tem.x == desx && tem.y == desy)
			{
				int id = ed - 1;
				string ans = "";
				while (id != -1)
				{
					ans = q[id].ch + ans;
					id = q[id].pre;
				}
				return ans;
			}
		}
	}*/
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;	cin >> tc;
	for (int T = 1; T <= tc; T++)
	{
		int N;	cin >> N;
		int a[10][8];
		for (int i = 0; i < N; i++)	
			for (int j = 0; j < 8; j++)	
				cin >> a[i][j];

		int rest = N, ans = 0;
		int b[10][8];	//cur date, num(include), west, east, height
		for (int i = 0; i < N; i++)
		{
			b[i][0] = a[i][0];	b[i][1] = a[i][1];	b[i][2] = a[i][2]; b[i][3] = a[i][3]; b[i][4] = a[i][4]; 
		}

		int wall[3000] = {0};
		for (int day = 0; ; day++)
		{
			bool atta = 0;
			bool suc = 1;
			for (int i = 0; i < N; i++)
				if (b[i][1] > 0 && b[i][0] == day)
				{
					atta = 1;
					for (int j = b[i][2]; j <= b[i][3]; j++)
						if (wall[j+1000] < b[i][4])
						{
								suc = 0;	//cout << i << " " << day << " " << j << " " << wall[j+1000]<<b[i][4]<<endl;
								break;
						}
					if (!suc)	break;
				}

			if (!atta)	continue;
			if (atta && !suc)	{ans++;}
			//if(atta)	cout << day<< " " << !suc << endl;
			for (int i = 0; i < N; i++)
				if (b[i][1] > 0 && b[i][0] == day)
				{
					for(int j = b[i][2]; j <= b[i][3]; j++)
					{
						if (wall[j+1000] < b[i][4])
							wall[j+1000] = b[i][4];
					}

					b[i][0] += a[i][5];	b[i][1] --;	
					if(b[i][1] == 0)		
					{
						rest--;
						if(rest == 0)	break;
					}
					if (a[i][6] > 0)
					b[i][3] += a[i][6];	
					else
						b[i][2] += a[i][6];
					b[i][4] += a[i][7];
				}
			if (rest == 0)	break;
		}



		cout << "Case #" << T << ": " << ans<< endl;
	}

}