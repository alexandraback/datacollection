#include<cstdio>
int main(){
	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		int Row,Col,Mines;
		bool Possible = true;
		scanf("%d%d%d",&Row,&Col,&Mines);
		int Left = Row * Col - Mines;
		printf("Case #%d:\n",Case++);
		if(Left == 1){
			for(int i = 1;i <= Row;++i){
				for(int j = 1;j <= Col;++j){
					if(i == 1 && j == 1)putchar('c');
					else putchar('*');
				}
				putchar('\n');
			}
		}else if(Row == 1){
			putchar('c');
			for(int i = Col - 1;i > 0;--i){
				if(--Left > 0)putchar('.');
				else putchar('*');
			}
			putchar('\n');
		}else if(Col == 1){
			puts("c");
			for(int i = Row - 1;i > 0;--i){
				if(--Left > 0)puts(".");
				else puts("*");
			}
		}else if(Row == 2){
			if(Mines % 2 == 1 || Left == 2)Possible = false;
			else{
				for(int row = 0;row < 2;++row){
					for(int i = 0;i < Col;++i){
						if(row == 0 && i == 0)putchar('c');
						else if(i < Left / 2)putchar('.');
						else putchar('*');
					}
					putchar('\n');
				}
			}
		}else if(Col == 2){
			if(Mines % 2 == 1 || Left == 2)Possible = false;
			else{
				for(int i = 0;i < Row;++i){
					for(int row = 0;row < 2;++row){
						if(row == 0 && i == 0)putchar('c');
						else if(i < Left / 2)putchar('.');
						else putchar('*');
					}
					putchar('\n');
				}
			}
		}else{
			if(Left == 2 || Left == 3 || Left == 5 || Left == 7)Possible = false;
			else{
				if(Left <= Col * 2 + 1){
					if(Left % 2 == 1){
						Left -= 3;
						for(int row = 0;row < Row;++row){
							for(int col = 0;col < Col;++col){
								if(row == 0 && col == 0)putchar('c');
								else if(row < 2){
									if(col < Left / 2)putchar('.');
									else putchar('*');
								}else if(row == 2){
									if(col < 3)putchar('.');
									else putchar('*');
								}else{
									putchar('*');
								}
							}
							putchar('\n');
						}
					}else{
						for(int row = 0;row < Row;++row){
							for(int col = 0;col < Col;++col){
								if(row == 0 && col == 0)putchar('c');
								else if(row < 2){
									if(col < Left / 2)putchar('.');
									else putchar('*');
								}else{
									putchar('*');
								}
							}
							putchar('\n');
						}
					}
				}else{
					bool flag = false;
					int temp = Left;
					if(Left % Col == 1)flag = true;
					--Left;
					for(int row = 0;row < Row;++row){
						for(int col = 0;col < Col;++col){
							if(row == 0 && col == 0)putchar('c');
							else{
								if(flag && row == temp / Col - 1 && col == Col - 1){
									putchar('*');
								}else{
									if(Left-- > 0)putchar('.');
									else putchar('*');
								}
							}
						}
						putchar('\n');
					}
				}
			}
		}
		if(!Possible)puts("Impossible");
	}
	return 0;
}
