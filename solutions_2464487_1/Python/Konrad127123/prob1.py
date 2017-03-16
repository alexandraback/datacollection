#!/usr/bin/python
#from math import *

def isqrt(n):
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

# This opens a handle to your file, in 'r' read mode
file_handle = open('mynumbers.txt', 'r')

# Read in all the lines of your file into a list of lines
lines_list = file_handle.readlines()
# Extract dimensions from first line. Cast values to integers from strings.
#T = (int(val) for val in lines_list[0].split())

T = int(lines_list[0])

# cols, rows = (int(val) for val in lines_list[0].split())
# Do a double-nested list comprehension to get the rest of the data into your matrix

# my_data = [[int(val) for val in line.split()] for line in lines_list[1:]]


for i in range(1, T+1):
    r,t = (int(val) for val in lines_list[i].split())
    ans = (isqrt((2*r-1)*(2*r-1)+8*t)-(2*r-1))/4
    print "Case #%d: %d"%(i,ans)
