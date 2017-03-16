import sys

f = open('A.in')
#f = sys.stdin
cases = int(f.readline())

for case in range(cases):
    [R,C,W] = [int(x) for x in f.readline().split()]

    numguess = C/W
    prelim = numguess * R

    if C % W == 0:
        ans = prelim + W-1
    else:
        ans =  prelim + W
   
    print "Case #"+ str(case+1)+ ": " + str(ans)
