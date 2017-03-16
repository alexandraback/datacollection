/*
 * magician.cxx
 * 
 * Copyright 2014 Albert Bendicho
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <iostream>

void sequentialBoard( int R, int C, int M )
{
    int i, j, empty;
    empty=R*C-M;
	for (i=0;i<R;i++) {
		for (j=0;j<C;j++) {
			if (M>0) { std::cout<<"*"; M--; } else 
			if (empty>1) { std::cout<<"."; empty--; } else
			std::cout<<"c";
		}
		std::cout<<"\n";
	};
} 

int main()
{
    int T, t;
    int R, C, M;
    int empty,i,j,sequentialZone,fullrows,fullcols,cornerhole,pending,pendingPairs,availableRows;
    char board[50][50];

	std::cin >> T ;
	
	for ( t=0; t<T; t++) {
		//clean 
		for(i=0;i<50;i++) {
			for(j=0;j<50;j++) {
				board[i][j]='.';
			}
		}
		//read case
		std::cin >> R >> C >> M ;

		//print case
		std::cout << "Case #" << (t+1) << ":\n" ;//<< R << " " << C << " " << M << "\n";
		
		empty=R*C-M;
		switch (empty) {
			case 0 : //never to occur, but who knows!
				std::cout << "Impossible\n"; 
				break;
			case 1 :
				sequentialBoard (R,C,M);
				break;
			default :
				switch (std::min(R,C)) {
					case 1 :
						sequentialBoard (R,C,M);
						break;
					case 2 :
						if (( empty % 2 == 0 ) and ( empty > 2 )) {
							if (C==2) {
								sequentialBoard (R,C,M);
							} else {
								for(j=0;j<M/2;j++) std::cout<<'*';
								for(j=M/2;j<C;j++) std::cout<<'.';
								std::cout<<"\n";
								for(j=0;j<M/2;j++) std::cout<<'*';
								for(j=M/2;j<C-1;j++) std::cout<<'.';								
								std::cout<<"c\n";
							}
						} else std::cout << "Impossible\n";
						break;
					default: 
						switch (empty) {
							case 2:
							case 3:
							case 5:
							case 7:
								std::cout << "Impossible\n";
								break;
							default:
								sequentialZone=(R-2)*(C-2);
								if (M<=sequentialZone) {
									for (i=0;i<R;i++) {
										for (j=0;j<C-2;j++) {
											if (M>0) {
												std::cout<<"*";
												M--;
											} else {
												std::cout<<".";
											}
										}
										if(i==R-1) {std::cout<<".c\n";} else {std::cout<<"..\n";};
									}
								} else {
									pending=M-sequentialZone;
									cornerhole=((pending % 2)==1);
									if (cornerhole) pending++;
									pendingPairs = pending / 2;
									availableRows=(cornerhole?R-3:R-2);
									if (availableRows>=pendingPairs) fullrows=pendingPairs ; else fullrows=availableRows;
									pendingPairs = pendingPairs - fullrows;
									if (pendingPairs>0) fullcols=pendingPairs; else fullcols=0;
						
									for(i=0;i<R-2;i++)
										for(j=0;j<C-2;j++)
											board[i][j]='*';
									if (cornerhole) board[R-3][C-3]='.';
						
									for(i=0;i<fullrows;i++) {
										board[i][C-2]='*';
										board[i][C-1]='*';
									};
									for(j=0;j<fullcols;j++) {
										board[R-2][j]='*';
										board[R-1][j]='*';
									};
									board[R-1][C-1]='c';
									for (i=0;i<R;i++) {
										for (j=0;j<C;j++) {
											std::cout<<(board[i][j]);
										}
										std::cout<<"\n";
									}
									
								}
						}
				} //switch minRC
		} //switch emtpy

	}//end case t
}//end main
