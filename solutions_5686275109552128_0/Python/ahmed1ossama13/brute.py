fin = open("/home/ahmed_ossama/Desktop/Code jam/B/B-small-attempt5.in", "r")
fout = open("/home/ahmed_ossama/Desktop/Code jam/B/B.out", "w")
def solve(L):
    if(L.count(0) == len(L)):
        return 0
    n = len(L)
    H = list(L)
    for i in range(len(L)):
        if (H[i] > 0):
            H[i] -= 1
    ans = 1 + solve(H)
    H = list(L)
    if (H[n - 1] >= 2):
        x = H[n - 1]
        H.remove(x)
        if (x == 9):
           H.append(3)
           H.append(3)
           H.append(3)
           H.sort()
           ans = min(ans, 2 + solve(H))
           H.remove(3)
           H.remove(3)
           H.remove(3)
        H.append(x//2)
        H.append(x//2 + x%2)
        H.sort()
        ans = min(ans, 1+ solve(H))
    return ans
T = int(fin.readline())
for t in range(1, T + 1):
    n = int(fin.readline())
    L = list(map(int,fin.readline().split()))
    L.sort()
    ans = solve(L)
    fout.write("Case #"+str(t)+": "+str(ans)+"\n")
fout.close()
