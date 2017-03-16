
fin = open("B-small-attempt0 (1).in")
fout = open("B.out", "w")
T = int(fin.readline())

for t in range(1, T+1):
    A, B, K = map(int, fin.readline().split(" "))
    
    ans = 0
    for a in range(A):
        for b in range(B):
            if a&b < K:
                ans += 1
    fout.write("Case #%d: %d\n" %(t, ans))