#include <cstdio>
#include <deque>
#include <cmath>

using namespace std;

typedef struct{
	int x, y;
} Coords;

int main(){
	int t, cases, r, c, m, i, j, x, y, sum;
	char matrix[50][50];
	Coords aux;	

	scanf("%d", &t);

	for(cases = 1; cases <= t; cases++){
		
		deque<Coords> deck;

		scanf("%d %d %d", &r, &c, &m);
		

		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++)
				matrix[i][j] = '*';

		m = c * r - m - 1;
		double mAux = m;

		if(m <= 0){
			printf("Case #%d:\n", cases);
			printf("Impossible\n");
			continue;
		}

		matrix[0][0] = 'c';

		aux.x = 0;
		aux.y = 0;

		deck.push_back(aux);

		while(!deck.empty()){
			int cont = 0;
			sum = 0;
			x = deck.front().x;
			y = deck.front().y;

			if(y + 1 < c && matrix[x][y + 1] != '.'){
				sum++;
			}

			if(y + 1 < c && x + 1 < r  && matrix[x + 1][y + 1] != '.')
				sum++;

			if(x + 1 < r && matrix[x + 1][y] != '.')
				sum++;

			if(x + 1 < r && y - 1 >= 0 && matrix[x + 1][y - 1] != '.')
				sum++;

			if(sqrt(mAux) - (int) sqrt(mAux) == 0.0 && m - sum == 1){
				deck.pop_front();
				continue;
			}


			if(m - sum >= 0){
				m -= sum;

				if(y + 1 < c && matrix[x][y + 1] != '.'){
					matrix[x][y + 1] = '.';
					aux.x = x;
					aux.y = y + 1;
					deck.push_back(aux);
				}

				if(y + 1 < c && x + 1 < r  && matrix[x + 1][y + 1] != '.'){
					matrix[x + 1][y + 1] = '.';
					aux.x = x + 1;
					aux.y = y + 1;
					deck.push_back(aux);
				}

				if(x + 1 < r && matrix[x + 1][y] != '.'){
					matrix[x + 1][y] = '.';
					aux.x = x + 1;
					aux.y = y;
					deck.push_back(aux);
				}

				if(x + 1 < r && y - 1 >= 0 && matrix[x + 1][y - 1] != '.'){
					matrix[x + 1][y - 1] = '.';
					aux.x = x + 1;
					aux.y = y - 1;
					deck.push_back(aux);
				}							
			}

			deck.pop_front();

			if(m == 0)
				break;
		}

		printf("Case #%d:\n", cases);

		if(m == 0){
			for(i = 0; i < r; i++){
				for(j = 0; j < c; j++){
					printf("%c", matrix[i][j]);
				}
				printf("\n");
			}
		} else
			printf("Impossible\n");
	}

	return 0;
}
