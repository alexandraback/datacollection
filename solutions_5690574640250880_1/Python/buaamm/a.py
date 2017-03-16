# -*- coding: utf-8 -*-
# Google Code Jam
# Create Date: 2014-04-10
# Created by: buaamm
#--------------------------------------------------------------------
import sys
import os

def nextint():
	return (int)(fr.readline())

def next():
	return fr.readline()

def write(s):
	fw.write(s)
	
def writeline(s):
	fw.write(s + "\n")

def repeat(s, r):
	for i in range(r):
		fw.write(s)

def reprep(s, len, r):
	for i in range(r):
		repeat(s, len)
		write("\n")
		
		
def draw_single(n,m):
	write("c")
	repeat("*", m-1)
	write("\n")
	reprep("*", m, n-1)
def draw_line(a,b):
	repeat(".", a)
	repeat("*", b)
	write("\n")

#--------------------------------------------------------------------
def solve():
	n,m,mine = map(int, next().strip().split() )
	space = n * m - mine
	# k: space count
	if n == 1: #Dekiru All
		write("c")
		repeat(".", space-1)
		repeat("*", mine)
		write("\n")
		return
	if m == 1: #Dekiru All
		write("c\n")
		repeat(".\n", space-1)
		repeat("*\n", mine)
		return
	if n == 2: #Dekiru 1 4 6 8 ...
		if space == 1:
			draw_single(n,m)
			return
		if space >= 4 and (space % 2 == 0):
			tmp = space/2
			write("c")
			repeat(".", tmp - 1)
			repeat("*", m - tmp)
			write("\n")
			repeat(".", tmp)
			repeat("*", m - tmp)
			write("\n")
			return
		write("Impossible\n")
		return
	if m == 2: #Dekiru 1 4 6 8 ...
		if space == 1:
			draw_single(n,m)
			return
		if space >= 4 and (space % 2 == 0):
			tmp = space/2
			write("c.\n")
			repeat("..\n", tmp - 1)
			repeat("**\n", n - tmp)
			return
		write("Impossible\n")
		return
	if space == 1:
		draw_single(n,m)
		return
	if space <= 3 or space == 5 or space == 7:
		write("Impossible\n")
		return
	# n m >= 3
	# space == 4 6 8 9...
	if space == 4 or space == 6:
		tmp = space/2
		write("c")
		draw_line(tmp-1, m - tmp)
		draw_line(tmp,   m - tmp)
		for i in range(n-2): draw_line(0, m)
		return
	# space == 8,9,10,11,12,13,14,15...
	if space == 8 or space == 9:
		tmp = space-6
		write("c")
		draw_line(2, m - 3)
		draw_line(3, m - 3)
		draw_line(tmp, m - tmp)
		for i in range(n-3): draw_line(0, m)
		return
	# space == 10,11,12,13,14,15...
	assert n >= 4 or m >= 4
	if space == 10 or space == 11 or space == 12:
		if m == 3:
			write("c")
			draw_line(2, m-3)
			draw_line(3, m-3)
			c3 = 2 if (space == 10) else 3
			draw_line(c3, m-c3)
			c4 = 2 if (space <= 11) else 3
			draw_line(c4, m-c4)
			for i in range(n-4): draw_line(0, m)
			return
		tmp = space - 8
		write("c")
		draw_line(3, m-4)
		draw_line(4, m-4)
		draw_line(tmp, m-tmp)
		for i in range(n-3):  draw_line(0, m)
		return
	if space == 13:
		if m == 3:
			write("c")
			draw_line(2, m-3)
			draw_line(3, m-3)
			draw_line(3, m-3)
			draw_line(2, m-2)
			draw_line(2, m-2)
			for i in range(n-5):  draw_line(0, m)
			return
		if n == 3:
			write("c")
			draw_line(4, m-5)
			draw_line(5, m-5)
			draw_line(3, m-3)
			for i in range(n-3):  draw_line(0, m)
			return
		write("c")
		draw_line(3, m-4)
		draw_line(4, m-4)
		draw_line(3, m-3)
		draw_line(2, m-2)
		for i in range(n-4):  draw_line(0, m)
		return
		
	# space == 14,15...
	rev = 0
	if n < m:
		n,m = m,n
		rev = 1
	d = space / m
	remain = space % m
	ans = [0] * n
	for i in range(n):
		ans[i] = ["*"] * m
		
	# Special
	print "space = %d\n" % space
	if space <= 2*m+1:
		if space % 2 == 0:
			for i in range(2):
				for j in range(space/2):
					ans[i][j] = "."
		else:
			for i in range(2):
				for j in range(space/2 - 1):
					ans[i][j] = "."
			for j in range(3):
				ans[2][j] = "."
		ans[0][0] = "c"
	elif remain != 1:
		for i in range(d):
			ans[i] = ["."] * m
		ans[0][0] = "c"
		for i in range(remain):
			ans[d][i] = "."
	else:
		for i in range(d-1):
			ans[i] = ["."] * m
		ans[0][0] = "c"
		for i in range(m-1):
			ans[d-1][i] = "."
		for i in range(2):
			ans[d][i] = "."
	rans = ans
	if rev == 1:
		rans = map(list, zip(*ans))
		n,m = m,n
	print ans, rans
	for i in range(n):
		for j in range(m):
			write(rans[i][j])
		write("\n")
	
	#write("?????????????????\n")
		

	
#--------------------------------------------------------------------
if __name__ == "__main__": ##__name__: [filename].py
	print "Hello, Main."
else:
	global fr, fw
	#fr = open('mm.in', 'r')
	#fw = open('mm.out', 'w')
	#prob_name = "A-small-practice"
	prob_name = "C-large"

	fr = open(prob_name + '.in', 'r')
	fw = open(prob_name + '.out', 'w')
	cas = (int)(fr.readline())
	for cs in range(cas):
		write("Case #%d:\n" % (cs+1) )
		solve()
	fr.close()
	fw.close()
#--------------------------------------------------------------------


