import sys
T = int(sys.stdin.readline())
for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    K, C, S = sys.stdin.readline().split()
    K, C, S = int(K), int(C), int(S)
    assert S==K
    step = K**(C-1)
    pos = 1
    for i in range(K):
        sys.stdout.write("%d " % pos)
        pos += step
    sys.stdout.write("\n")
        
