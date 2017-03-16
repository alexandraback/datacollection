input_file = "A-large"
input_file += raw_input("Input file number and file extension:\n")
output_file = "output"+input_file+".txt"



inp = open(input_file, 'r')
out = open(output_file, 'w')
T = int(inp.readline())

for test in xrange(1, T + 1):
    arr = [int(item) for item in inp.readline().split()]
    N = arr[0]
    arr = arr[1:]
    X = sum(arr)
    m = [-1 for dex in range(N)]
    for ix in xrange(N):
        J = sorted([j for dex,j in enumerate(arr) if dex!=ix])
        S = [J[0]]
        for dex in xrange(1, len(J)):
            S.append(J[dex] + S[dex - 1])
        oldm = float("inf")
        for cx in xrange(N-1):
            c = cx + 1
            nowm = float(S[cx]+X-c*arr[ix])/((c+1)*X)
            if J[cx] > float(S[cx]+(1-nowm)*X)/c:
                break
            oldm = nowm
        if oldm < 0:
            oldm = 0
        m[ix] = oldm
            
    m = [100*item for item in m] 
    ans = " ".join([str(item) for item in m])
    out.write("Case #" + str(test) + ": " + ans + "\n")


out.close()
inp.close()
print "Done!"
