from sys import *
from math import *

def check_tiles(n, depth, check):
	i = 0
	tiles = []
	while i < n:
		tile = 0
		p = 0
		while i < n and p < depth:
			tile = tile + i * int(pow(n, p))
			i = i + 1
			p = p + 1
		tiles.append(tile+1)
	if check < len(tiles):
		return "IMPOSSIBLE"
	else:
		return " ".join(str(tile) for tile in tiles)

fin = open(argv[1] + ".in", 'r') 
fout = open(argv[1] + ".out", 'w')

ncases = int(fin.readline())
for c in range(ncases):
	info = fin.readline().split()
	n = int(info[0])
	depth = int(info[1])
	check = int(info[2])
	fout.write("Case #" + str(c+1) + ": " + check_tiles(n, depth, check) + "\n")

fin.close()
fout.close()


	
