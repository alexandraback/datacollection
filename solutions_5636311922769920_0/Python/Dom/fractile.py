import ju

results = []
FILE = "D-small-attempt1"
f = ju.jopen(FILE)

T = int(f.readline())
for t in range(T):
    K,C,S = map(int,f.readline().split())
    result = ""
    for k in range(K):
        if len(result) > 0:
            result += " "
        result += str(k+1)
    results += [result]
print results

ju.jout(FILE, results)
