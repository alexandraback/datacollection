def countSheep(N):
    seen = {}

    for i in range(10):
        seen[str(i)] = False

    current = 0
    count = 0

    while True:
        current = current + N
        for c in str(current):
            if not seen[c]:
                seen[c] = True
                count = count + 1
        if (count == 10):
            return current


T = int(raw_input())

for i in range(1,T+1):
    N = int(raw_input())
    if N == 0:
        print "Case #"+str(i)+": INSOMNIA"
        continue
    print "Case #"+str(i)+": "+str(countSheep(N))
