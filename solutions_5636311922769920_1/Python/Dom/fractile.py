import ju

results = []
FILE = "D-large"
f = ju.jopen(FILE)

T = int(f.readline())
print T
for t in range(T):
    K,C,S = map(int,f.readline().split())
    if float(K)/float(C)>float(S):
        results += ["IMPOSSIBLE"]
        print K,C,S,":","IMPOSSIBLE"
        continue
    totalLength = K**C
    result = ""
    checkedKs = 0
    while checkedKs < K:
        nextCheck = 1
        for c in range(C):
            addition = (K**c)*checkedKs
            if nextCheck + addition > totalLength:
                break
            checkedKs += 1
            nextCheck += addition

        result += str(nextCheck) + " "
    print K,C,S,":", result
    results += [result[:-1]]
print results

ju.jout(FILE, results)
