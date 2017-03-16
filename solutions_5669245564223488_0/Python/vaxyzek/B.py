import os,sys, itertools
from collections import Counter

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

#sys.setrecursionlimit(2000)

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "B-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

def red(s):
	ns = ''
	p = -1
	for c in s:
		if c != p:
			ns = ns + c
		p = c
	return ns

def isvalid(s):
	u = [0] * 27
	p = -1
	#print s
	for c in s:
		o = ord(c) - ord('a')
		#print c, o
		if c != p and u[o]:
			#print "not"
			return False
		p = c
		u[o] = 1
	return True

T = int(ifile.readline().strip())
for t in range(T):
	N = int(ifile.readline().strip())
	cars = ifile.readline().strip().split()
	#print cars
	#if t < 25:
	#if t >= 25 and t < 50:
	#if t >= 50 and t < 75:
	if t >= 75 and t < 100:
		connect = [[0] * N for n in range(N)]

		ncars = []
		for car in cars:
			ncars.append(red(car))

		r = 0
		for P in itertools.permutations(range(N)):
			s = ''
			for p in P:
				s = s + ncars[p]
			if isvalid(s):
				#print P, s
				r = r + 1

		print t
		ans = "Case #" + str(t+1) + ": " + str(r)
		print ans
		#print bin(A), bin(B)
		#print c
		ofile.write(ans + "\n")
		#break