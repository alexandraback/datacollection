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
 
int main()
{
    int i, T, t;
    long double C, F, X;
    long double totalX, newTotalX, deltaX, secondsNext, accumulated;

	std::cin >> T ;
	
	std::cout.precision(7);
	std::cout << std::fixed;
	for ( t=0; t<T; t++) {
		//clean 
		totalX=0;
		accumulated=0;
		//read case
		std::cin >> C >> F >> X ;
		
		i=0;
		deltaX = X / ( i * F + 2 );

		totalX = accumulated + deltaX ; 
		secondsNext = C / ( i * F + 2 );
		accumulated += secondsNext;
		
		i = 1 ;
		deltaX = X / ( i * F + 2 );
		newTotalX = accumulated + deltaX;
		while ( newTotalX < totalX ) {
//			std::cout << "discarding " << totalX << "\n";
			totalX = newTotalX;

			secondsNext = C / ( i * F + 2 );
			accumulated += secondsNext;
		
			i++ ;
			deltaX = X / ( i * F + 2 );
			newTotalX = accumulated + deltaX;
		}
		//print case
		std::cout << "Case #" << (t+1) << ": " << totalX << "\n";
	}
}
