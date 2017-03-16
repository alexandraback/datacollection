#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdlib.h>
#include <string>

struct lawn
{
	unsigned int w;
	unsigned int h;
	unsigned char squares [100] [100];
	unsigned char colmax [100];
	unsigned char rowmax [100];
};

void calculatemaxes (lawn &lawn)
{
	// rows
	for (unsigned int y = 0; y < lawn.h; y++)
	{
		lawn.rowmax [y] = 0;
		for (unsigned int x = 0; x < lawn.w; x++)
		{
			if (lawn.squares [y] [x] > lawn.rowmax [y])
			{
				lawn.rowmax [y] = lawn.squares [y] [x];
			}
		}
	}
	
	// columns
	for (unsigned int x = 0; x < lawn.w; x++)
	{
		lawn.colmax [x] = 0;
		for (unsigned int y = 0; y < lawn.h; y++)
		{
			if (lawn.squares [y] [x] > lawn.colmax [x])
			{
				lawn.colmax [x] = lawn.squares [y] [x];
			}
		}
	}
}

bool islawnpossible (const lawn &lawn)
{
	for (unsigned int y = 0; y < lawn.h; y++)
	{
		for (unsigned int x = 0; x < lawn.w; x++)
		{
			if (lawn.squares [y] [x] == lawn.colmax [x]) { continue; }
			if (lawn.squares [y] [x] == lawn.rowmax [y]) { continue; }
			return false;
		}
	}
	return true;
}

int main ()
{
	std::ifstream in ("b.in");
	std::ofstream out ("b.out");

	unsigned int testcount;
	in >> testcount;

	for (unsigned int i = 0; i < testcount; i++)
	{
		// read lawn
		lawn lawn;
		in >> lawn.h;
		in >> lawn.w;

		unsigned int height = 0;
		for (unsigned int y = 0; y < lawn.h; y++)
		{
			for (unsigned int x = 0; x < lawn.w; x++)
			{
				in >> height;
				lawn.squares [y] [x] = height;
			}
		}

		calculatemaxes (lawn);
		
		out << "Case #" << (i + 1) << ": " << (islawnpossible (lawn) ? "YES" : "NO") << std::endl;
	}

	return 0;
}

