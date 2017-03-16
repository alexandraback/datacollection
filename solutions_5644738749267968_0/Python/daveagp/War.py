inputf = open("D-small-attempt0.in")

def lie(N, K):
    K.sort()
    N = set(N)
    score = 0
    for k in K:
        mincover = 100
        for n in N:
            if n>k and n<mincover: mincover=n
        if mincover == 100: break
        N.remove(mincover)
        score += 1
    return score

cases = int(inputf.readline())
for case in range(1, cases+1):
    n = int(inputf.readline())
    N = [float(token) for token in inputf.readline().split(" ")]
    K = [float(token) for token in inputf.readline().split(" ")]
    print("Case #"+str(case)+": "+str(lie(N[:], K[:]))+" "+str(n-lie(K, N)))

