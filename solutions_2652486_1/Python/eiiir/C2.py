filename = "C-small-2-attempt0.in" # change later
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
    f7 = 0
    f6 = 0
    isthere6 = 0
    isthere3 = 0
    for p in s:
        i = int(p)
        tmp = i
        count = 0
        while tmp%3 == 0:
            count = count + 1
            tmp = tmp/3
            f6 = 1
        if count > f3:
            f3 = count
        
        tmp = i
        count = 0
        while tmp%5 == 0:
            count = count + 1
            tmp = tmp/5
        if count > f5:
            f5 = count
            
        tmp = i
        count = 0
        while tmp%7 == 0:
            count = count + 1
            tmp = tmp/7
        if count > f7:
            f7 = count
        
        tmp = i
        count = 0
        while tmp%2 == 0:
            count = count + 1
            tmp = tmp/2
            if f6 == 1:
                f6 = 2
        if count > f2:
            f2 = count
        
        if f6 == 1:
            isthere3 = 1
        if f6 == 2:
            isthere6 = 1
    
    charcount = 0
    for j in range(f7):
        sys.stdout.write("7")
        charcount = charcount+1
    for j in range(f5):
        sys.stdout.write("5")
        charcount = charcount+1
    
    if isthere3 == 1:
        sys.stdout.write("3")
        charcount = charcount+1
        f3 = f3 -1
    
    while f3 > 0 and f2 > 0:
        sys.stdout.write("6")
        charcount = charcount+1
        f3 = f3 -1
        f2 = f2 -1
    
    while charcount < N:
        if f2 > N - charcount + 2:
            sys.stdout.write("8")
            charcount = charcount+1
            f2 = f2 -3
        elif f2 > N - charcount + 1:
            sys.stdout.write("4")
            charcount = charcount+1
            f2 = f2 -2
        else:
            sys.stdout.write("2")
            charcount = charcount+1
            f2 = f2 -1
    print ""
    
