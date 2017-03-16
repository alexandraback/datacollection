def solve(testNum):
    c,f,x = [float(x) for x in input().split()]
    r = 2.0
    bestTime = x/r
    currentTime = 0.0
    while True:
        currentTime += c/r
        r += f
        if currentTime + x/r < bestTime:
            bestTime = currentTime + x/r
        else:
            break
    print("Case #%d: %.7f"%(testNum,bestTime))

for i in range(1,int(input())+1): solve(i)
