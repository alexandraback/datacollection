# include <stdio.h>
# include <algorithm>
# include <vector>


using namespace std ;


#define A first
#define B second.first
#define C second.second


typedef pair<int, pair<int, int> > NODE ;


int lawn[105][105], lawn2[105][105] ;


int main ()
{
	int T, Case, r, c, n, m, i, j ;
	int ans ;
	NODE node ;
	vector <NODE> vec ;
	
	freopen ("B-small-attempt0.in", "r", stdin) ;
	freopen ("B-small-attempt0.out", "w", stdout) ;
	
	scanf ("%d", &T) ;
	for (Case = 1 ; Case <= T ; Case++)
	{
		scanf ("%d%d", &n, &m) ;
		vec.clear() ;
		for(i = 0 ; i < n ; i++)
			for (j = 0 ; j < m ; j++)
				scanf ("%d", &lawn[i][j]) ;
		for (i = 0 ; i < n ; i++){
			r = 0 ;
			for (j = 0 ; j < m ; j++) r = max(r, lawn[i][j]) ;
			node.A = r, node.B = i, node.C = 0 ;
			vec.push_back (node) ;
		}
		for (j = 0 ;j < m ; j++){
			c = 0 ;
			for (i = 0 ; i < n ; i++) c = max(c, lawn[i][j]) ;
			node.A = c, node.B = j, node.C = 1 ;
			vec.push_back(node) ;
		}
		sort(vec.begin(), vec.end()) ;
		for (i = 0 ; i < n ; i++) for (j = 0 ;j < m ; j++)
			lawn2[i][j] = 100 ;
		for (i = vec.size() - 1 ; i >= 0 ; i--)
		{
			node = vec[i] ;
			if (node.C == 0){
				for (j = 0 ; j < m ; j++)
					lawn2[node.B][j] = node.A ;
			}
			else
			{
				for (j = 0 ;j < n ; j++)
					lawn2[j][node.B] = node.A ;
			}
		}
		ans = 0 ;
		for (i = 0 ; i < n ; i++)
			for (j = 0 ;j < m  ; j++) if (lawn2[i][j] != lawn[i][j]) ans = 1 ;
		if (ans) printf ("Case #%d: No\n", Case) ;
		else printf ("Case #%d: Yes\n", Case) ;
	}
	return 0 ;
}
