#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef __int64 LONG; 

struct Node
{
	Node():X(-999999),Y(-999999){}
	Node(int x, int y):X(x),Y(y){}

	bool IsDummy() {return X == -999999 && Y == -999999; }

	bool operator ==(const Node& o)const
	{
		return this->X == o.X && this->Y == o.Y;
	}

	bool operator !=(const Node& o)const
	{
		return this->X != o.X || this->Y != o.Y;
	}

	bool operator <(const Node& o)const
	{
		if (this->X == o.X)
			return this->Y < o.Y;

		return this->X < o.X;
	}

	int Distance (const Node& o)
	{
		int x =this->X -o.X;
		int y =this->Y -o.Y;

		int d = x*x + y*y;
		int s =1;

		if (x ==0)
		{
			s = y>0? 1 : -1;
		}
		else
		{
			s = x>0? 1 : -1;
		}

		return d *s;
	}

	bool InDistance (const Node& o, int d)
	{
		int x =this->X -o.X;
		int y =this->Y -o.Y;

		return x*x + y*y <= d*d;
	}
	
	int X;
	int Y;
};

struct IMirror
{
	virtual bool CanReflect(Node node) = 0;
	virtual Node Reflect(Node node) = 0;

	Node Posi;
};

int CalcRef (int m, int n)
{
	return m -(n-m)-1;
}

struct UpM : public IMirror
{
	UpM (int x, int y, int len)
	{
		Posi.X =x;
		Posi.Y =y;
		Len =len;
	}

	virtual bool CanReflect(Node node)
	{
		return node.Y >= Posi.Y;
	}

	virtual Node Reflect(Node node)
	{
		return Node(node.X, CalcRef(Posi.Y, node.Y));
	}

	int  Len;
};

struct DownM : public IMirror
{
	DownM (int x, int y, int len)
	{
		Posi.X =x;
		Posi.Y =y;
		Len =len;
	}

	virtual bool CanReflect(Node node)
	{
		return node.Y < Posi.Y;
	}

	virtual Node Reflect(Node node)
	{
		return Node(node.X, CalcRef(Posi.Y, node.Y));
	}

	int  Len;
};

struct LeftM : public IMirror
{
	LeftM (int x, int y, int len)
	{
		Posi.X =x;
		Posi.Y =y;
		Len =len;
	}

	virtual bool CanReflect(Node node)
	{
		return node.X >= Posi.X;
	}

	virtual Node Reflect(Node node)
	{
		return Node(CalcRef(Posi.X, node.X), node.Y);
	}

	int  Len;
};

struct RightM : public IMirror
{
	RightM (int x, int y, int len)
	{
		Posi.X =x;
		Posi.Y =y;
		Len =len;
	}

	virtual bool CanReflect(Node node)
	{
		return node.X < Posi.X;
	}

	virtual Node Reflect(Node node)
	{
		return Node(CalcRef(Posi.X, node.X), node.Y);
	}

	int  Len;
};

struct UpLeftC : public IMirror
{
	UpLeftC (int x, int y)
	{
		Posi.X =x;
		Posi.Y =y;
	}

	virtual bool CanReflect(Node node)
	{
		return node.X >= Posi.X && node.Y >= Posi.Y;
	}

	virtual Node Reflect(Node node)
	{
		return Node(CalcRef(Posi.X, node.X), CalcRef(Posi.Y, node.Y));
	}

	int  Len;
};

struct UpRightC : public IMirror
{
	UpRightC (int x, int y)
	{
		Posi.X =x;
		Posi.Y =y;
	}

	virtual bool CanReflect(Node node)
	{
		return node.X < Posi.X && node.Y >= Posi.Y;
	}

	virtual Node Reflect(Node node)
	{
		return Node(CalcRef(Posi.X, node.X), CalcRef(Posi.Y, node.Y));
	}

	int  Len;
};

struct DownRightC : public IMirror
{
	DownRightC (int x, int y)
	{
		Posi.X =x;
		Posi.Y =y;
	}

	virtual bool CanReflect(Node node)
	{
		return node.X < Posi.X && node.Y < Posi.Y;
	}

	virtual Node Reflect(Node node)
	{
		return Node(CalcRef(Posi.X, node.X), CalcRef(Posi.Y, node.Y));
	}

	int  Len;
};

struct DownLeftC : public IMirror
{
	DownLeftC (int x, int y)
	{
		Posi.X =x;
		Posi.Y =y;
	}

	virtual bool CanReflect(Node node)
	{
		return node.X >= Posi.X && node.Y < Posi.Y;
	}

	virtual Node Reflect(Node node)
	{
		return Node(CalcRef(Posi.X, node.X), CalcRef(Posi.Y, node.Y));
	}

	int  Len;
};

int H, W, D;
Node ME;
vector<string>	ROOM;
vector<IMirror*> ms;
set<Node>	AllRefNodes;

bool InLine (vector<Node>& line, Node node)
{
	if (line.size() ==0)
		return false;

	return (line[0].X - ME.X) * (node.Y - ME.Y) == (line[0].Y - ME.Y) * (node.X - ME.X);
}

void AddAllRef (Node srcNode, set<Node>& refNodes)
{
	vector<Node> ln;
	ln.push_back(srcNode);

	for (int i=0; i<(int)ms.size(); i++)
	{
		IMirror* pMir =ms[i];

		if (pMir->CanReflect(srcNode))
		{
			Node ref =pMir->Reflect(srcNode);

			if (srcNode!=ME && InLine(ln, ref))
			{
				int dx =(srcNode.X -ME.X) *(ME.X -ref.X);
				int dy =(srcNode.Y -ME.Y) *(ME.Y -ref.Y);
				
				if (dx<0 || dy<0)
					continue;
			}

			if (ME!=ref && ME.InDistance(ref,D))
			{
				pair<set<Node>::iterator, bool> ir =AllRefNodes.insert(ref);
				if (ir.second)
				{
					refNodes.insert(ref);
				}
			}
		}
	}
}

void PickLine (vector<Node>& line)
{
	Node posNode;
	Node nagNode;

	for (int i=0; i<(int)line.size(); i++)
	{
		int d =ME.Distance(line[i]);

		if (d>0)
		{
			if (posNode.IsDummy() || d< ME.Distance(posNode))
			{
				posNode = line[i];
			}
		}
		else
		{
			if (nagNode.IsDummy() || d> ME.Distance(nagNode))
			{
				nagNode = line[i];
			}
		}
	}

	if (!posNode.IsDummy())
	{
		AllRefNodes.insert(posNode);
	}
	if (!nagNode.IsDummy())
	{
		AllRefNodes.insert(nagNode);
	}
}

void RemoveInlineNodes()
{
	vector<vector<Node> > lines;

	for (set<Node>::iterator it = AllRefNodes.begin(); it !=AllRefNodes.end(); it++)
	{
		bool findLine = false;

		for (int i=0; i<(int)lines.size(); i++)
		{
			if (InLine(lines[i], *it))
			{
				lines[i].push_back(*it);
				findLine = true;
				break;
			}
		}
		if (!findLine)
		{
			vector<Node> nl;
			nl.push_back(*it);
			lines.push_back(nl);
		}
	}

	AllRefNodes.clear();
	for (int i=0; i<(int)lines.size(); i++)
	{
		PickLine (lines[i]);
	}

}

int Solve()
{
	ms.clear();
	AllRefNodes.clear();

	ms.push_back (new UpM(1,1,W-2));
	ms.push_back (new DownM(1,H-1,W-2));
	ms.push_back (new LeftM(1,1,H-2));
	ms.push_back (new RightM(W-1,1,H-2));

	//ms.push_back (new UpLeftC(1,1));
	//ms.push_back (new UpRightC(W-1,1));
	//ms.push_back (new DownLeftC(1,H-1));
	//ms.push_back (new DownRightC(W-1,H-1));

	set<Node> srcNodes;
	set<Node> refNodes;
	srcNodes.insert(ME);

	set<Node>* pSrc =&srcNodes;
	set<Node>* pRef =&refNodes;

	while (!pSrc->empty())
	{
		pRef->clear();
		for (set<Node>::iterator it =pSrc->begin(); it !=pSrc->end(); it++)
		{
			AddAllRef (*it, *pRef);
		}

		set<Node>* pTmp =pSrc; 
		pSrc =pRef;
		pRef =pTmp;
	}

	RemoveInlineNodes();

	return AllRefNodes.size();
}

void RunCase (ifstream& fin, ofstream& fout)
{
	ROOM.clear();

	fin>>H>>W>>D;

	for (int i=0; i<H; i++)
	{
		string s;
		fin>>s;

		int x = s.find('X');
		if (x>=0)
		{
			ME.X =x;
			ME.Y =ROOM.size();
		}

		ROOM.push_back(s);
	}

	int r =Solve();
	fout<<r;
}

void RunAll(const char* fnameIn, const char* fnameOut)
{
	ifstream fin(fnameIn);
	ofstream fout(fnameOut);

	int caseCount;
	fin >> caseCount;

	for (int i=0; i<caseCount; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		RunCase (fin, fout);
		fout<<"\n";
	}
}

void main()
{
	RunAll("D-small-attempt5.in", "D-small-attempt5.out");

	return;
}