T = int(raw_input().strip())

for cas in range(1,T+1):
    print "Case #" + str(cas) + ":",
    R,C,W = raw_input().strip().split()
    R = int(R)
    C = int(C)
    W = int(W)

    x = 0
    y = 0
    ans = 0

    for r in range(R):
        for c in range(W-1,C,W):
            ans += 1
            if(r == R-1):
                if(c == C-1):
                    ans += W-1
                elif(c+W >= C):
                    ans += W
    print ans
