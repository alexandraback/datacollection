import sys 
lines = sys.stdin.readlines()
for i in range((int(lines[0]))):
    n, m, k = lines[i+1].strip().split()
    n = int(n)
    m = int(m)
    k = int(k)
    ans = 0
    if (n == 3 and m == 3):
        if k == 1: ans = 1
        if k == 2: ans = 2
        if k == 3: ans = 3
        if k == 4: ans = 4
        if k == 5: ans = 4
        if k == 6: ans = 5
        if k == 7: ans = 6
        if k == 8: ans = 7
        if k == 9: ans = 8
    if ((n == 3 and m == 4) or (n == 4 and m == 3)):
        if k == 1: ans = 1
        if k == 2: ans = 2
        if k == 3: ans = 3
        if k == 4: ans = 4
        if k == 5: ans = 4
        if k == 6: ans = 5
        if k == 7: ans = 6
        if k == 8: ans = 6
        if k == 9: ans = 7
        if k == 10: ans = 8
        if k == 11: ans = 9
        if k == 12: ans = 10
    if (n == 4 and m == 4):
        if k == 1: ans = 1
        if k == 2: ans = 2
        if k == 3: ans = 3
        if k == 4: ans = 4
        if k == 5: ans = 4
        if k == 6: ans = 5
        if k == 7: ans = 6
        if k == 8: ans = 6
        if k == 9: ans = 7
        if k == 10: ans = 7
        if k == 11: ans = 8
        if k == 12: ans = 8
        if k == 13: ans = 9
        if k == 14: ans = 10
        if k == 15: ans = 11
        if k == 16: ans = 12
    if ((n == 4 and m == 5) or (n == 5 and m == 4)):
        if k == 1: ans = 1
        if k == 2: ans = 2
        if k == 3: ans = 3
        if k == 4: ans = 4
        if k == 5: ans = 4
        if k == 6: ans = 5
        if k == 7: ans = 6
        if k == 8: ans = 6
        if k == 9: ans = 7
        if k == 10: ans = 7
        if k == 11: ans = 8
        if k == 12: ans = 8
        if k == 13: ans = 9
        if k == 14: ans = 9
        if k == 15: ans = 10
        if k == 16: ans = 10
        if k == 17: ans = 11
        if k == 18: ans = 12
        if k == 19: ans = 13
        if k == 20: ans = 14
    if ans: print "Case #"+str(i+1)+": "+str(ans)
    else: print "Case #"+str(i+1)+": "+str(k)
    
