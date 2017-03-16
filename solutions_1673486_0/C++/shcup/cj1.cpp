#include "iostream"

using namespace std;

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	
    int t,id = 1;
    cin >> t;
    
    double right,gai[100000],count,min;
    int i,j,k,a,b;
    
    while(t--)
    {
		cin >> a >> b;
		for(i = 0;i < a ;i ++)
			cin >> gai[i];
		right = gai[0];
		min = 1 + b + 1; //直接回车 
		for(i = a - 1; i >= 0; i--)
		{
			count = right * (i * 2 + b - a + 1) + (1 - right) * (i * 2 + b - a + 1 + b + 1);
			if(count < min)
				min = count;
			if(i == 0)
				break;
			right = right * gai[a - i]; 
		}
		
		cout << "Case #" << id ++ << ": ";
		printf("%.6lf\n",min);
    }
    
   // getchar();
  //  getchar();
    return 1;
} 
