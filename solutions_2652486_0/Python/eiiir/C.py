filename = "C-small-1-attempt1.in" # change later
import sys
f = open(filename)
T = int(f.readline())
s = f.readline()
s = s.split()
R = int(s[0])
N = int(s[1])
M = int(s[2])
K = int(s[3])

print "Case #1:"
for r in range(1,R+1):
    s = f.readline()
    s = s.split()
    f2 = 0
    f3 = 0
    f5 = 0
    for p in s:
        i = int(p)
        if i%27 == 0 and f3 < 3:
            f3 = 3
        elif i%9 == 0 and f3 < 2:
            f3 = 2
        elif i%3 == 0 and f3 < 1:
            f3 = 1
        
        if i%125 == 0 and f5 < 3:
            f5 = 3
        elif i%25 == 0 and f5 < 2:
            f5 = 2
        elif i%5 == 0 and f5 < 1:
            f5 = 1
        
        if i%64 == 0 and f2 < 6:
            f2 = 6
        elif i%32 == 0 and f2 < 5:
            f2 = 5
        elif i%16 == 0 and f2 < 4:
            f2 =4
        elif i%8 == 0 and f2 < 3:
            f2 = 3
        elif i%4 == 0 and f2 < 2:
            f2 =2
        elif i%2 == 0 and f2 < 1:
            f2 = 1
    
    charcount = 0
    for j in range(f5):
        sys.stdout.write("5")
        charcount = charcount+1
    for j in range(f3):
        sys.stdout.write("3")
        charcount = charcount +1
    while charcount < 3:
        if f2 > 2:
            sys.stdout.write("4")
            f2 = f2 - 2
        else:
            sys.stdout.write("2")
            f2 = f2 - 1
        charcount  = charcount+1
    print ""
    
