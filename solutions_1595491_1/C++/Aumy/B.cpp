# include <iostream>
# include <vector>
# include <map>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>
# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <utility>
# include <string>
# include <queue>

using namespace std;

# define I(n)   scanf("%d",&(n))
# define read(x) freopen(x,"r",stdin)
# define write(x) freopen(x,"w",stdout)
int N,S,p,t[110];

int find(){
    int m=0;
    for(int i=0;i<N;i++)
    {
        int x = t[i]/3;
        if ( t[i] % 3 == 0 )
        {
            if ( x >= p ) m++;
            else if ( S > 0 && x+1 >= p && x-1 >=0){
                m++;
                S--;
            }
        }
        else if ( t[i] % 3 == 1 )
        {
            if ( x+1 >= p ) m++;
        }
        else if ( t[i] % 3 == 2 )
        {
            if ( x+1 >= p ) m++;
            else if( S>0 && x+2 >= p ) {
                m++;
                S--;
            }
        }
    }
    return m;
}
int main()
{
	read("B-large.in");
    write("out.txt");
	int T;
	I(T);
	for(int cas=1;cas<=T;cas++)
	{

	    cin>>N>>S>>p;
	    for(int i=0;i<N;i++) cin>>t[i];
	    sort(t,t+N);


	    cout<<"Case #"<<cas<<": "<<find()<<endl;
	}
	return 0;
}
