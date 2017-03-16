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
#include <set>
 
int main()
{
    int i, T, t, N;
    std::set<long int> Naomiw,Naomidw,Kenw,Kendw;
    int w,dw;
    long double d;
    
	std::cin >> T ;
	
	for ( t=0; t<T; t++) {
		//clean 
		Naomiw.clear(); //redundant, but clean
		Kenw.clear(); //redundant, but clean
		Naomidw.clear(); //redundant, but clean
		Kendw.clear(); //redundant, but clean
		w=0;
		dw=0;
		//read case
		std::cin >> N ;
		for (i=0;i<N;i++) { 
			std::cin >> d ;
			Naomiw.insert(d * 100000);
			Naomidw.insert(d * 100000);
		}
		for (i=0;i<N;i++) { 
			std::cin >> d ;
			Kenw.insert(d * 100000);
			Kendw.insert(d * 100000);
		}
		
		for (i=0;i<N;i++) {
			std::set<long int>::iterator bnaomi;
			std::set<long int>::iterator bken;
			bnaomi=Naomiw.end();
			bnaomi--;
			bken=Kenw.upper_bound(*bnaomi);
			if (bken==Kenw.end()) bken=Kenw.begin();
//			std::cout << *bnaomi <<" "<< *bken << "\n";
			if (*bnaomi>*bken) w++;
			Naomiw.erase(bnaomi);
			Kenw.erase(bken);
		}

		for (i=0;i<N;i++) {
			std::set<long int>::iterator bnaomi;
			std::set<long int>::iterator bken;
			bnaomi=Naomidw.begin();
			bken=Kendw.begin();
			if(*bnaomi>*bken) {
				dw++;
				Naomidw.erase(bnaomi);
				Kendw.erase(bken);
			} else {
				Naomidw.erase(bnaomi);
				bken=Kendw.end();
				bken--;
				Kendw.erase(bken);				
			}
		}

//		std::cout << "Naomi w won: "<< w << "\n";
				

		//print case
		std::cout << "Case #" << (t+1) << ": " << dw << " " << w << "\n";
	}
}
