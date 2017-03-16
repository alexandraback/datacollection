#include "iostream"

using namespace std;

struct level
{
	int need1,need2;
	bool finish1,finish2;
	bool tmp;
};

int cmp(const void * a,const void * b)
{
	if((*(level *)a).need1 > (*(level *)b).need1 )
	//if(a.need1 > b.need1)
		return 1;
	else
		return -1;
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	
    int t,id = 1;
    cin >> t;
    
    level l[1000];
    int n,i,j,k,have;
    
    while(t--)
    {
		cin >> n;
		for(i = 0;i < n; i++)
		{
			cin >> l[i].need1 >> l[i].need2;
			l[i].finish1 = l[i].finish2 = false;
		}
		
	//	qsort(l,n,sizeof(level),cmp);
		
		int count = 0,step = 0;
		have = 0;
		while(count < n)
		{

			int min = 0xfffffff;
			for(i = 0;i < n; i++)
				if(l[i].finish2 == false && l[i].need2 < min)
				{
					min = l[i].need2;
					j = i;
				}
			if(min <= have)
			{
				count++;

				step ++;
			//	have = have - min;
				l[j].finish2 = true;
				if(l[j].finish1 == true)
					have = have + 1;
				else
					have = have + 2;
				continue;
			}
			
			
			for(i = 0;i < n; i++)
				l[i].tmp = false;
			int sum = 0;
			for(i = 0 ;i < n && sum < min - have; i++)
				if(l[i].finish2 == false && l[i].finish1 == false && l[i].need1 <= have )
				{
					sum = sum + 1;
					l[i].tmp = true;
				}
			if(sum >= min - have)
			{
				step = sum + step;
				have = have + sum;
				
				for(i = 0;i < n; i++)
					if(l[i].tmp == true)
					{
					//	have = have - l[i].need1;
						l[i].finish1 = true; 
					}
			}
			else
				break;	
		}
		
		if(count < n)
		{
			cout << "Case #" << id ++ << ": "<< "Too Bad" << endl;
		}
		else
			cout << "Case #" << id ++ << ": "<< step << endl;
    }
    
  //  getchar();
   // getchar();
    return 1;
} 
