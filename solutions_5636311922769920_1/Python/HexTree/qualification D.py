with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for j in range(T):
            K, C, S = [int(x) for x in f.readline().split()]
            if S*C < K:
                g.write("Case #%d: %s\n" % ((j + 1), "IMPOSSIBLE"))
                continue

            counter = 0
            tests = []

            while counter < K:
                loc = 0
                bound = K-counter
                for i in range(min(C, bound)):
                    loc += counter*(K**(C-1-i))
                    counter += 1
                tests.append(loc+1)

            output = " ".join([str(x) for x in tests])
            g.write("Case #%d: %s\n" % ((j + 1), output))