import sys

def solve(i):
    a, b, c = map(int, fin.readline().rstrip().split())
    if (a, b, c) == (4, 4, 2) or (a, b, c) == (4, 2, 4):
        ans = "RICHARD"
        
    elif a >= 7:
        ans = "RICHARD"
    elif max(b, c) < a:
        ans = "RICHARD"
    elif min(b, c) < (a + 1) // 2:
        ans = "RICHARD"
    elif b % a != 0 and c % a != 0:
        ans = "RICHARD"
    else:
        ans = "GABRIEL"
        
    print("Case #%d:"%(i + 1), ans, file=fout)


fin = open("../Downloads/D-small-attempt%d.in"%(int(input())))
fout = open('d.out', 'w')
n = int(fin.readline())
for i in range(n):
    solve(i)
fout.close()
    