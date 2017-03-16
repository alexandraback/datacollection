//
// Qualification round 2014  problem B
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

static vector<string> transpose( vector<string> v )
{
     vector<string> w;
     unsigned int i,j;
     if (v.size())
     {
	  for (j=0; j<v.at(0).size(); j++)
	  {
	       string s;
	       for (i=0; i<v.size(); i++)
	       {
		    s += v.at(i).at(j);
	       }
	       w.push_back(s);
	  }
     }
     return w;
}

static unsigned int count( vector<string> v, char c )
{
     unsigned int m=0;
     for (auto a : v)
     {
	  for (auto b : a)
	  {
	       if (b == c) m++;
	  }
     }
     return m;
}

static unsigned int count_bombs( vector<string> v )
{
     return count(v,'*');
}

static unsigned int count_c( vector<string> v )
{
     return count(v,'c');
}

bool is_bomb( vector<string> v, unsigned int i, unsigned int j )
{
     if (i < v.size() && j < v.at(0).size())
	 return v.at(i).at(j) == '*';
     else
	  return false;
}
bool is_revealed( vector<string> v, unsigned int i, unsigned int j )
{
     if (i < v.size() && j < v.at(0).size())
	 return v.at(i).at(j) == 'c';
     else
	  return false;
}
unsigned int score(vector<string> v, unsigned int i, unsigned int j )
{
     unsigned int s=0;
     s += is_bomb(v,i-1,j-1);
     s += is_bomb(v,i-1,j  );
     s += is_bomb(v,i-1,j+1);

     s += is_bomb(v,i  ,j-1);
     s += is_bomb(v,i  ,j+1);

     s += is_bomb(v,i+1,j-1);
     s += is_bomb(v,i+1,j  );
     s += is_bomb(v,i+1,j+1);
     return s;
}

void reveal( vector<string> &v, unsigned int i, unsigned int j )
{
     if (i<v.size() && j < v.at(0).size())
     {
	  v.at(i).at(j) = 'c';
     }
}

bool verify( vector<string> v )
{
     unsigned int i,j;
     unsigned int r=v.size();
     unsigned int c=v.at(0).size();
     
     do {
	  if (0)
	  {
	       cout << "Before:" << endl;
	       for (auto s : v) cout << s << endl;
	  }

	  unsigned int c0 = count_c(v);
	  for (i=0; i<r; i++)
	  {
	       for (j=0; j<c; j++)
	       {
		    if (0)
		    {
			 cout << "is_revealed " << is_revealed(v,i,j) << endl;
			 cout << "score " << score(v,i,j) << endl;
		    }

		    if (is_revealed(v,i,j) && score(v,i,j) == 0)
		    {
			 reveal(v,i-1,j-1);
			 reveal(v,i-1,j);
			 reveal(v,i-1,j+1);
			 reveal(v,i  ,j-1);
			 reveal(v,i  ,j+1);
			 reveal(v,i+1,j-1);
			 reveal(v,i+1,j);
			 reveal(v,i+1,j+1);
		    }
	       }
	  }
	  if (0)
	  {
	       cout << "After:" << endl;
	       for (auto s : v) cout << s << endl;
	  }
	  unsigned int c1 = count_c(v);


	  if (c0==c1) {
	       //cout << "No progress"<< endl;
	       break;
	  }
     } while (true);
     
     return count_c(v) + count_bombs(v) == r*c;
}

unsigned int count_bits(uint32_t m )
{
     if (m==0) return 0;
     return 1+count_bits(m&(m-1));
}

bool verify_impossible( unsigned int r, unsigned int c, unsigned int m)
{
     unsigned int rc = r*c;
     unsigned int i,j;

     if (rc > 5) return true;

     uint32_t u;
     for (u=0; u<(1<<rc); u++)
     {
	  if (count_bits(u) == m)
	  {
	       vector<string> v;
	       uint32_t uu = u;
	       for (i=0; i<r; i++)
	       {
		    string s;
		    for (j=0; j<c; j++)
		    {
			 if (uu&1)
			 {
			      s += '*';
			 }
			 else
			 {
			      s += '.';
			 }
			 uu>>=1;
		    }
		    v.push_back(s);
	       }

	       for (i=0; i<r; i++)
	       {
		    for (j=0; j<c; j++)
		    {
			 if (is_bomb(v,i,j) == false)
			 {
			      vector<string> vv=v;
			      vv.at(i).at(j)='c';


			      if (verify(vv))
			      {
				   cout << "Found a solution when not expected" << endl;
				   cout << "Solution was" << endl;
				   for (auto z : vv) cout << z << endl;

				   return false;
			      }
			 }
		    }
	       }
	  }
     }
     return true;
}
	  

vector<string> populate( unsigned int r, unsigned int c, 
			 unsigned int vr, unsigned int vc, 
			 unsigned int d )
{
     vector<string> a;

     unsigned int i,j;


     for (i=0; i<r; i++)
     {
	  string s;
	  for (j=0; j<c; j++)
	  {
	       char ch='.';
	       if (i==0 && j==0)
		    ch = 'c';
	       else if (i < vr-1 && j < vc-1)
		    ch = '.';
	       else if (d==0 && i<vr && j<vc)
		    ch = '.';
	       else if (i < vr-1 && j == vc-1 && d <= vc-2 )
		    ch = '.';
	       else if (vr > 2 && vc > 2 && d > vc-2 && i < vr-(d-vc+3))
		    ch = '.';
	       else if (i == vr-1 && (j < vc-d || (d>0 && j<2)) )
		    ch = '.';
	       else
		    ch = '*';
	       s += ch;
	  }
	  a.push_back(s);
     }

     if (count_bombs(a) != r*c-(vr*vc-d)) {
	  cout << "Error!!" << endl;
	  cout << "r " << r << ", c " << c << ", ";
	  cout << "vr " << vr << ", vc " << vc << ", ";
	  cout << "d " << d << endl;
	  for (auto u : a) cout << u << endl;
	  exit(1);
     }
     return a;
}


static vector<string> solve( unsigned int r, unsigned int c, unsigned int m )
{
     if (c<r) return transpose(solve(c,r,m));

     // we have r < c;

     vector<string> a;

     unsigned int rc = r*c;
     unsigned int v = rc-m;

     unsigned int i,j;
     unsigned int d;

     if (v == 1)
     {
	  a = populate(r,c,1,1,0);
     }
     else if (r == 1)
     {
	  a = populate(r,c,1,v,0);
     }
     else if (v%r == 0 && v != r)
     {
	  a = populate(r,c,r,v/r,0);
     }
     else if (v==4)
     {
	  a = populate(r,c,2,2,0);
     }
     else
     {
	  for (i=3; i<=r; i++)
	  {
	       j = 1+(v-1)/i;
	       d = i*j-v;

	       if ( j<=c && d <= i+j-5 &&
		    (j>=3 || (j==2 && d==0)) )
	       {
		    a = populate(r,c,i,j,d);
		    break;
	       }
	  }
     }

     if (1)
     {
	  if (a.size())
	  {
	       if (count_bombs(a) != m)
	       {
		    cerr << "Bad answer" << endl;
		    exit(1);
	       }

	       if (verify(a) == false)
	       {
		    cerr << "Cannot verify" << endl;
		    exit(1);
	       }
	  }
	  else
	  {
	       if (verify_impossible(r,c,m) == false)
	       {
		    cerr << r <<"," << c << "," << m << " is not impossible" << endl;
		    exit(1);
	       }
	  }
     }
     
     return a;
}

void gen_test(void )
{
     unsigned int nn=20;
     cout << nn*nn*(nn+1)*(nn+1)/4 << endl;

     unsigned int i,j,m;
     for (i=1; i<=nn; i++)
     {
	  for (j=1; j<=nn; j++)
	  {
	       for (m=0; m<i*j; m++)
	       {
		    cout << i << " ";
		    cout << j << " ";
		    cout << m << " ";
		    cout << endl;
	       }
	  }
     }
}

int main( int argc, char ** argv )
{
     if (argc > 1)
     {
	  gen_test();
	  return 0;
     }

     unsigned int n;
     unsigned int i;

     cin >> n;

     for (i=1; i<=n; i++) {

	  unsigned int r,c,m;

	  cin >> r >> c >> m;

	  vector<string> a = solve(r,c,m);

	  cout << "Case #" << i << ":" << endl;
	  
	  if (a.size()== 0) 
	       cout << "Impossible" << endl;
	  else
	       for (auto s : a) cout<< s << endl;
     }

     return 0;
}

