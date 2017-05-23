with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for j in range(T):
            K, C, S = [int(x) for x in f.readline().split()]
            tests = []
            for i in range(K):
                tests.append(1 + i*(K**(C-1)))
            output = " ".join([str(x) for x in tests])
            g.write("Case #%d: %s\n" % ((j + 1), output))