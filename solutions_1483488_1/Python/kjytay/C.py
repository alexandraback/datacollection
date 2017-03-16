import math

def rotate(s):
    """Takes a string s, moves its rightmost char to the leftmost position."""
    return s[-1] + s[:-1]

def rotateleft(s):
    """Takes a string s, moves its leftmost char to the rightmost position."""
    return s[1:] + s[0]

# read file
f = open("C-large.in", "r")
g = open("C-large-ans.txt", "w")

N = int(f.readline())  # number of cases
k = 0
while k < N:
    temp = f.readline()
    templst = temp.split()
    A,B = int(templst[0]), int(templst[1])
    cnt = 0   # no of eligible (n,m) pairs
    for n in range(A,B):
        strn = str(n)
        m = rotate(strn)
        while m != strn:
            if n < int(m) <= B:
                cnt += 1
            m = rotate(m)
    g.write("Case #" + str(k+1) + ": " + str(cnt) + "\n")
    k += 1
