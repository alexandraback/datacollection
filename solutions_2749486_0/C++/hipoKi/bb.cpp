#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	freopen("b-s.in","r",stdin);
	freopen("b-s.out","w",stdout);
	
	int t;
	cin >> t;
	for(int s = 0; s < t; s++)
	{
		long long int x, y;
		cin >> x >> y;
		long long int pos[2];
		pos[0] = 0;
		pos[1] = 0;
		int mayor;
		long long int salto = 1;
		cout << "Case #" << s+1<< ": ";
		while(true)
		{
			long long int deltaX = abs(pos[0] - x);
			long long int deltaY = abs(pos[1] - y);
			if(deltaX > deltaY)
			{
				mayor = 0;
			} else {
				mayor = 1;
			}
			if(deltaX == 0 && deltaY == 0)
				break;
			if(deltaX == salto)
			{
				if(pos[0] > x)
				{
					pos[0] = pos[0] - salto;
					cout << 'W';
					salto++;
				} else {
					pos[0] = pos[0] + salto;
					cout << 'E';
					salto++;				
				}
			} else if(deltaY == salto) {
				if(pos[1] > y)
				{
					pos[1] = pos[1] - salto;
					cout << 'S';
					salto++;
				} else {
					pos[1] = pos[1] + salto;
					cout << 'N';
					salto++;
				}
			} else {
				if(mayor == 0)
				{
					if((pos[0] > x && deltaX >= salto )|| (pos[0] < x && deltaX < salto))
					{
						pos[0] = pos[0] - salto;
						cout << 'W';
						salto++;
					} else {
						pos[0] = pos[0] + salto;
						cout << 'E';
						salto++;				
					}
				} else {
					if((pos[1] > y && deltaY >= salto) || (pos[1] < y && deltaY < salto))
					{
						pos[1] = pos[1] - salto;
						cout << 'S';
						salto++;
					} else {
						pos[1] = pos[1] + salto;
						cout << 'N';
						salto++;				
					}				
				}
			}
		}

		cout << endl;
	}
	
	return 0;
	
}
