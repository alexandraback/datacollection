
# -*- coding: cp932 -*-

import sys
import math

inputfile = "C-large.in"
#inputfile = "sample.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

no_ans = "Impossible"

for tc in range(tc_num):
    l = f.readline().split()
    R = int(l[0])
    C = int(l[1])
    M = int(l[2])
    T = R * C
    E = T - M
    
    ans = no_ans
    if E == 1:
        ans = "c" + "*" * (C-1)
        ans += ("\n" + "*" * C) * (R-1)
    elif R == 1:
        if M < C:
            ans = "c" + "." * (C-M-1) + "*" * M
    elif C == 1:
        if M < R:
            ans = "c" + "\n." * (R-M-1) + "\n*" * M
    elif R == 2:
        if M % 2 == 0 and T - M >= 4:
            ans = "c" + "." * (C-1-M//2) + "*" * int(M//2) + "\n"
            ans += "." * (C-M//2) + "*" * (M//2)
    elif C == 2:
        if M % 2 == 0 and T - M >= 4:
            ans = "c" + "."
            ans += "\n.." * (R-1-M//2)
            ans += "\n**" * (M//2)
    elif E < 8:
        if E == 4:
            ans = "c" + "." + "*" * (C - 2)
            ans += "\n.." + "*" * (C - 2)
            ans += ("\n" + "*" * C) * (R - 2)
        elif E == 6:
            ans = "c" + ".." + "*" * (C - 3)
            ans += "\n..." + "*" * (C - 3)
            ans += ("\n" + "*" * C) * (R - 2)
        elif E == 8:
            ans = "c" + ".." + "*" * (C - 3)
            ans += "\n..." + "*" * (C - 3)
            ans += "\n.." + "*" * (C - 2)
            ans += ("\n" + "*" * C) * (R - 3)
        #else: # Impossible
    else:
        m = [[0 for i in range(C)] for j in range(R)]
        rest = M
        for r in range(R-2):
            if rest == 0: break
            for c in range(C-2):
                if r == R-3 and c == C-3: break
                m[r][c] = 1
                rest -= 1
                if rest == 0: break
            
        for r in range(R-3):    
            if rest <= 1: break
            m[r][C-1] = 1
            m[r][C-2] = 1
            rest -= 2
        
        for c in range(C-3):    
            if rest <= 1: break
            m[R-1][c] = 1
            m[R-2][c] = 1
            rest -= 2
        
        if rest == 1:
            m[R-3][C-3] = 1
            rest -= 1
            
        
        ans = "c"
        for r in range(R):
            if r > 0: ans += "\n"
            for c in range(C):
                if r == 0 and c == 0: continue
                ans += "." if m[R-1-r][C-1-c] == 0 else "*"
                    
    print("Case #" + str(tc+1) + ":\n" + ans)

   
